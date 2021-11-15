/*
Title: Hour_Functions
Creator: Arsalan Syed
libraries required: Wire.c

Description:
This file is part of the Word-Watch V2 project.
This file contains all the functions which are called to glow the letters 
associated with hours. All the LEDs associated with spelling out hours are 
controlled by the MCP23008 I/O expander, which is controlled through I2C. 
*/

#include "Wire.h"
#include "hour_functions.h"

#define MCP23008_ADDRESS 0x20
#define MCP23008_GPIO_REG 0x09
#define MCP23008_IODIR_REG 0x00

#define HOUR1 (uint8_t)0x80 //pin 7
#define HOUR2 (uint8_t)0x40 //pin 6
#define HOUR3 (uint8_t)0x08 //pin 3
#define HOUR4 (uint8_t)0x10 //pin 4
#define HOUR5 (uint8_t)0x20 //pin 5
#define HOUR6 (uint8_t)0x04 //pin 2     
#define HOUR7 (uint8_t)0x02 //pin 1
#define HOUR8 (uint8_t)0x01 //pin 0



void MCP23008_setPinAsOutput(uint8_t pin1, uint8_t pin2){
  /*sets pins specified with a '1' as output, and those specified with a '0' 
  as input example: byte pins = 0b00000001 sets pins 1-7 to input, and pin 0 
  as output */

 
  
  byte pins = ~(pin1 | pin2);
  // inverts the pins because the MCP23008 harware actually requires that output
  // pins be specified by '0' and input pins specified by  '1'
  // our method uses the inverse because it allows us to be consistant with our 
  // methods to set pins as output and then set them as High.

  /*example of our methodology : MCP23008_setPinAsOutput(HOUR1) sets the pin 
                                 associated with HOUR1 as output 
                                 MCP23008_set(HOUR1) sets the pin associated 
                                 with HOUR1 high.  */

  /* wheras if we did not invert 'byte pins' we would have to do this:
    example of our methodology : MCP23008_setPinAsOutput(~HOUR1) sets the pin 
                                 associated with HOUR1 as output 
                                 MCP23008_set(HOUR1) sets the pin associated 
                                 with HOUR1 high.  */

  
  Wire.beginTransmission(MCP23008_ADDRESS);
  Wire.write(MCP23008_IODIR_REG);   
  Wire.write(pins);
  Wire.endTransmission();
  
}


void MCP23008_set(uint8_t input){
  
  
  Wire.beginTransmission(MCP23008_ADDRESS);
  Wire.write(MCP23008_GPIO_REG);            //access address for GPIO access
  Wire.write(input);                        //setting voltage. 1 = high, 0 = low 
  Wire.endTransmission();
  
}

void MCP23008_reset_all_pins(){
  Wire.beginTransmission(MCP23008_ADDRESS);
  Wire.write(MCP23008_GPIO_REG);           //access address for GPIO access
  Wire.write((uint8_t)0x00);               //setting voltage. 1 = high, 0 = low 
  Wire.endTransmission();
}

void set_HourPins_INPUT(){
  //sets all pins to INPUT
  MCP23008_setPinAsOutput(0x00,0x00);
}


void one_hour(int i){
  //involves pins "hour 1" and "hour 5" 

  i = i%2;
  MCP23008_setPinAsOutput(HOUR1, HOUR5);
  
  switch(i){
    case 0:
     MCP23008_set(HOUR5); //glows 'O' and 'N'
     break;

    case 1:
     MCP23008_set(HOUR1); // glow 'E' and 'ONE_EXTRA' 
     break; 
  }
}


void two_hour(int i){
  //involves pins 'hour 3' and 'hour 6'
  MCP23008_setPinAsOutput(HOUR3, HOUR6);
  i = i%2;
  switch(i){
    case 0:
     MCP23008_set(HOUR3); //glows 'w' and 'two_extra'
     break;

    case 1:
     MCP23008_set(HOUR6); //glows 'T' and 'o'
     break;

  }
}

void three_hour(int i){
  //involves pins 'hour 3' and 'hour 5' and 'hour 4'
  i = i %3;
  switch(i){
    case 0:
      MCP23008_setPinAsOutput(HOUR3, HOUR5);
      MCP23008_set(HOUR3); //glows 'E' and 2ndE' 
      break;
    case 1:
      MCP23008_set(HOUR5); //glows 'R' and H'
      break;
    case 2:
      MCP23008_setPinAsOutput(HOUR3, HOUR4);
      MCP23008_set(HOUR4); //glows 'T' and 'Three_extra'
      break;
 }
}

void four_hour(int i){
  //involves pins 'hour 1' and 'hour 6'
  
  MCP23008_setPinAsOutput(HOUR1, HOUR6);
  i = i %2;
  switch(i){
    case 0:
      MCP23008_set(HOUR1); //glows 'O' and R' 
      break;
    case 1:
      MCP23008_set(HOUR6); //glows 'F' and 'U' 
      break;
 }
}

void five_hour(int i){
  //involves pins 'hour 2' and 'hour 6'
  
  MCP23008_setPinAsOutput(HOUR2, HOUR6);
  i = i %2;
  switch(i){
    case 0:
      MCP23008_set(HOUR2); //glows 'I' and E' 
      break;
    case 1:
      MCP23008_set(HOUR6); //glows 'F' and 'V' 
      break;
 }
}

void six_hour(int i){
  //involves pins 'hour 2' and 'hour 5'
  MCP23008_setPinAsOutput(HOUR2, HOUR5);
  i = i %2;
  switch(i){
    case 0:
      MCP23008_set(HOUR2); //glows 'X' and six_extra' 
      break;
    case 1:
      MCP23008_set(HOUR5); //glows 'S' and 'I' 
      break;
 }
}

void seven_hour(int i){
  //involves pins 'hour 1' and 'hour 2' and 'hour 8' 
  i = i%3;

  switch(i){
    case 0:
      MCP23008_set(HOUR1); //glows 'S' and 'seven_extra'
      MCP23008_setPinAsOutput(HOUR1, HOUR8);
      break;
      
    case 1:
      MCP23008_set(HOUR8); //glows 'V' and 'E'
      break;
      
    case 2:
      MCP23008_set(HOUR2); //glows 'N' and '2ndE'
      MCP23008_setPinAsOutput(HOUR2, HOUR8);
      break;
  }
  
}

void eight_hour(int i){
  //involves pins 'hour 1' and and 'hour 2' and 'hour 7'
  i = i%3;
  switch(i){
    case 0:
      MCP23008_set(HOUR1); //glows 'E' and 'H'
      MCP23008_setPinAsOutput(HOUR1, HOUR7);
      break;
      
    case 1:
      MCP23008_set(HOUR7); //glows 'G' and 'I'
      break;
      
    case 2:
      MCP23008_set(HOUR2); //glows 'T' and 'Eight_Extra'
      MCP23008_setPinAsOutput(HOUR2, HOUR7);
      break;
  }
  
}

void nine_hour(int i){
  //involves pins 'hour 2' and 'hour 3' and 'hour 8'

  i = i%2;
  switch(i){
    case 0:
      MCP23008_setPinAsOutput(HOUR2, HOUR8);
      MCP23008_set(HOUR8); //glows 'N' and 'I'
      break;
      
    case 1:
      MCP23008_setPinAsOutput(HOUR3, HOUR8);
      MCP23008_set(HOUR8); //glows '2nd N' and 'E'
      break;
      
  }
}

void ten_hour(int i){
  //involves pins 'hour 1' and 'hour 4' 

  MCP23008_setPinAsOutput(HOUR1, HOUR4);
  
  i = i%2;
  switch(i){
    case 0:
      MCP23008_set(HOUR1); //glows 'T' and 'E'
      break;
      
    case 1:
      MCP23008_set(HOUR4); //glows 'N' and 'Ten_Extra'
      break;
  }
}

void eleven_hour(int i){
  //involves pins 'hour 2' and 'hour 3' and 'hour 7'
  i = i%3;
  switch(i){
    case 0:
      MCP23008_setPinAsOutput(HOUR2, HOUR7);
      MCP23008_set(HOUR7); //glows 'E' and 'L'
      break;
      
    case 1:
      MCP23008_setPinAsOutput(HOUR3, HOUR7);
      MCP23008_set(HOUR3); //glows 'N' and 'third E'
      break;

    case 2:
      MCP23008_set(HOUR7); //glows '2nd E' and 'V'
      break;
  
 }
}

void twelve_hour(int i){
  //involves pins 'hour 2' and 'hour 3' and 'hour 4'

  i = i%3;
  switch(i){
    case 0:
      MCP23008_setPinAsOutput(HOUR2, HOUR4);
      MCP23008_set(HOUR2); //glows 'E' and 'L'
      break;
      
    case 1:
      MCP23008_set(HOUR4); //glows 'E' and 'T'
      break;

    case 2:
      MCP23008_reset_all_pins();
      MCP23008_setPinAsOutput(HOUR3, HOUR4);
      MCP23008_set(HOUR3); //glows '2nd E' and 'V'
      break;
 }
}
