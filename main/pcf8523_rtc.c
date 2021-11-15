/*
Title: PCF8523_RTC
Creator: Arsalan Syed
libraries required: Wire.c 
Last Update: Jan 23th, 2021, by Arsalan Syed

This file contains the functions required to operate a real time clock(RTC) module named PCF8523, with a 
ATMEGA328p-au, using the wire.h Arduino library. 

*/
#ifndef Wire
  #include "Wire.h"
#endif

#define PCF8523_ADDR 0x68

int currentMinutes;
int currentHours;

byte bcdToDec(byte value) {
  //converts from binary coded decimal to decimal
  return ((value / 16) * 10 + value % 16);
}

byte decToBcd(byte value){
  //Converts from a decimal value to binary coded decimal
  return (value / 10 * 16 + value % 10);
}

void readRTC(){
  //retrieves the current minute and hour from the PF8523 module
  
  Wire.beginTransmission(PCF8523_ADDR);
  Wire.write(0x04);
  Wire.endTransmission();
  
  Wire.requestFrom(PCF8523_ADDR, 2);
  currentMinutes = Wire.read();
  currentHours = Wire.read();

  currentMinutes = bcdToDec(currentMinutes);
  currentHours = bcdToDec(currentHours);
  
}


void setPCF8523(int hour, int minute)
// this sets the time and date to the PCF8563. Note that all time settings, such as minutes, seconds, etc. must be 
// set for this module to work.
{

  //every time/date setting besdies minutes, hours and seconds were arbritrarily picked because they 
  //are not needed.
  
  int second = 0; 
  int dayOfWeek = 3;
  int dayOfMonth =3;
  int month = 3;
  int year = 2015; 
  int PCF8523_CONTROL_1_REG;

  Wire.beginTransmission(PCF8523_ADDR);
  Wire.write(0x00); //control 1 register
  Wire.endTransmission(); 

  Wire.requestFrom(PCF8523_ADDR, 1);
  PCF8523_CONTROL_1_REG = Wire.read();

  Wire.beginTransmission(PCF8523_ADDR);
  Wire.write(PCF8523_CONTROL_1_REG | (1<<3)); //set bit 3, enabling 12-hour mode
  Wire.endTransmission();
  
  Wire.beginTransmission(PCF8523_ADDR);
  Wire.write(0x03); //seconds register
  Wire.write(decToBcd(second));  
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));     
  Wire.write(decToBcd(dayOfMonth));
  Wire.write(decToBcd(dayOfWeek));  
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.endTransmission();

}
