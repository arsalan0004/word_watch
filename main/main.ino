/*
Title: main
Creator: Arsalan Syed
libraries required: Wire.c
Last Update: Jan 23st, 2021, by Arsalan Syed

Description:
This is the main script of the Word_watch project V2. The file contains functions which are monitor if a button has
been clicked, which would indicate if the watch should turn on and tell the time. When the button is clicked the watch
will turn for a brief, specified time, and then turn off again. By 'turning off' it is meant that the ATMEGA328p-au
will go into deep sleep mode to conserve energy. This state should only draw 19 uA, so the ATMEGA chip should be able
to run for years while being in sleep. There will also be functions included which will allow the user to change the time.


/**
 * issues: 'n' of ten needs to be resoldered
 *
 *          -twenty causes an extra LED under it to turn on 
 *          design - the extra LEDS in the back shine to the front.. they should be placed in an inconspicuous spot, or under letters that
 *          are going to be covered by something. gaaahhhhh
 *

*/
#include "Hour_Functions.h"
#include "Minute_Functions.h"
#include "Indicator_Functions.h"
#include "PCF8523_RTC.h"

#define ROUND_TO_NEXT_HOUR -1
#define INTERRUPT_PIN 3
#define BUTTON_PIN    4  //PD4; active low 


#define GLOW_FRAMES  500
#define CONFIG_GLOW_FRAMES 100


void setup() {
  Wire.begin();
  Wire.setClock(400000);
  MCP23008_reset_all_pins();
  setPCF8523(12,00);
  pinMode(INTERRUPT_PIN, INPUT);                                      
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN),buttonPressed,RISING); 
  readRTC();
  goToSleep();
}

void loop() {
 //wake up
 detachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN)); //detach interrupt so that we don't cause an interrupt storm
 
 /*find out how long the button has been clicked down for*/
 int delayTime = millis();
 while(digitalRead(BUTTON_PIN) == HIGH);
 delayTime = millis() - delayTime;

 if(delayTime <300){// if the button has been clicked for less than 300 ms
    readRTC();
    showTime(currentHours,currentMinutes, GLOW_FRAMES); //show the currentTime
 }
 else if(delayTime >=300){ //if the button has been pressed for more than 300 ms then get ready to change the time
    boolean timeConfig = true; 
    readRTC(); //read the time
    
    currentMinutes = roundMin(currentMinutes); //convert from the precice time told by the RTC to a time the watch can display
    while(timeConfig){
      showTime(currentHours, currentMinutes, CONFIG_GLOW_FRAMES); //flash the time
      if(digitalRead(BUTTON_PIN) == HIGH){
        
        /*figure out how long the button is held down for*/
        delayTime = millis();
        while(digitalRead(BUTTON_PIN) == HIGH); 
        delayTime = millis() - delayTime;
        
        if(delayTime > 100){ //button held down for more than 100 ms, therefore we exit time configuration
          timeConfig = false;
          break;
        }
        else if (delayTime <= 100){ //increment the time by 5 minutes
          currentMinutes = roundMin(currentMinutes +5);
          if(currentMinutes == -1){ //roundMin() returns -1 when minutes has reached 60, otherwise rounds the mins to closest 5 minutes
            currentMinutes = 0;
            currentHours++;
            if(currentHours >12){
              currentHours = 1; //roll over the hours
            }
        }
          setPCF8523(currentHours,currentMinutes); //set the new time.
      }
    }
  }
}
 attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN),buttonPressed,RISING); 
 goToSleep();
}
void buttonPressed(){
  //wake up and go through a single loop

  
}


/*validates all hour:minute combinations, including indications such as 'it', 'is', 'past' and 'to'*/
void testAllTime(){
  for(int h = 1; h<=12; h++){
    for(int m = 0; m<60; m++){
      showTime(h,m, GLOW_FRAMES);
    }

}

}

void showTime(int h, int m, int showPeriod){

  /*pointers to minutes and hours functions*/
  void (*min_ptr)(int);
  void (*hour_ptr)(int);
  void (*indicator_ptr)(int);


  //process minutes
  int rm = roundMin(m); //round the minutes to the closest 5th
  min_ptr = getAddrOfMinFunction(rm);


  if(rm == -1){
    indicator_ptr = oclock;
    hour_ptr = getAddrOfHourFunction(h+1);  //ex. if it's 1:58, we want to round to the next hour
  }
  else if(rm == 0){
    indicator_ptr = oclock;
    hour_ptr = getAddrOfHourFunction(h);
    }
  else if(rm <=30){
    indicator_ptr = past;
    hour_ptr = getAddrOfHourFunction(h);
    }
  else if(rm >30){
    indicator_ptr = to;
    hour_ptr = getAddrOfHourFunction(h+1); //why? Because if it's 1:45 you want to say '15 minutes to 2'
    }

  if(min_ptr == NULL){
    for(int i = 0; i<showPeriod; i++){
      it_is(i);
      (*hour_ptr)(i);
      (*indicator_ptr)(i);
    }
   } else {
      //when minutes != 0 use this loop
      for(int i = 0; i<showPeriod; i++){
        it_is(i);
        (*hour_ptr)(i);
        (*min_ptr)(i);
        (*indicator_ptr)(i);
      }
   }
     /*after completing, set all pins as input*/
     MCP23008_reset_all_pins();
     set_IndicatorPins_INPUT();
     set_MinPins_INPUT();

}

void goToSleep(){

  //set every pin as input (except sda, sla)
  for(int ii = 0; ii< 20; ii++){
    if(ii == 18 || ii == 19){
      //SDA and SLA lines should not be set as input
      continue;
    }else{
      pinMode(ii, INPUT);
    }
    }

  //turn off ADC
  ADCSRA &= ~(1 <<7); //write a zero to the ADC enable bit in the ADC and Status Register A byte

  //enable sleep
  SMCR |= (1<<2); //power down mode
  SMCR |= 1; //enable sleep

  //turn off BOD
  MCUCR != (3 <<5); //set both the BODS and BODSE bits in the MCU control register
  MCUCR = (MCUCR & ~(1 << 5)) | (1 <<6); //must set the BODS bit and clear the BODSE bit at the same time

  __asm__ __volatile__("sleep");

}

void wakeUp(){

}


int roundMin(int m){
  //rounds minutes to the closest 5 minute denomination
  int rm;
  int fractionOfFive = m%5; //how close are we to the next 5? ex. m= 12, fractionofFive = 2, therefore, round down
  if(fractionOfFive >=3){
    rm = m - (m%5) + 5;
  }else{
    rm = m - (m%5);
  }

  if(rm == 60){
    rm = -1;
  }
  return rm;
}

int getAddrOfHourFunction(int hour){
  int addrOfHourFunction;

  hour = ((hour-1)%12)+1;
  
  switch(hour){
    case 1:
      addrOfHourFunction = &one_hour;
      break;
    case 2:
      addrOfHourFunction = &two_hour;
      break;
    case 3:
      addrOfHourFunction = &three_hour;
      break;
    case 4:
      addrOfHourFunction = &four_hour;
      break;
    case 5:
      addrOfHourFunction = &five_hour;
      break;
    case 6:
      addrOfHourFunction = &six_hour;
      break;
    case 7:
      addrOfHourFunction = &seven_hour;
      break;
    case 8:
      addrOfHourFunction = &eight_hour;
      break;
    case 9:
      addrOfHourFunction = &nine_hour;
      break;
    case 10:
      addrOfHourFunction = &ten_hour;
      break;
    case 11:
      addrOfHourFunction = &eleven_hour;
      break;
    case 12:
      addrOfHourFunction = &twelve_hour;
      break;
  }
  return addrOfHourFunction;
}


int getAddrOfMinFunction(int m){
  int addrOfMinFunction;
  m = -abs(m-30) + 30 ;
  switch(m){
    case ROUND_TO_NEXT_HOUR:
      addrOfMinFunction = NULL;
      break;
    case 0:
      addrOfMinFunction = NULL;
      break;
    case 5:
      addrOfMinFunction = &five_Minutes;
      break;
    case 10:
      addrOfMinFunction = &ten_Minutes;
      break;
    case 15:
      addrOfMinFunction = &fifteen_Minutes;
      break;
    case 20:
      addrOfMinFunction = &twenty_Minutes;
      break;
    case 25:
      addrOfMinFunction = &twentyFive_Minutes;
      break;
    case 30:
      addrOfMinFunction = &thirty_Minutes;
      break;
  }
  return addrOfMinFunction;
}
