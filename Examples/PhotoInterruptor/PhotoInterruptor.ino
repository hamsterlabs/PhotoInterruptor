#include "Arduino.h"
#include "PhotoInterruptor.h"

/*
	Test program for the PhotoInterruptor Arduino library
 Updated 11/25/2018
*/

const int PowerOn = 5;
const int IndicatorLED = 7;
const int transistorPin = 6;
PhotoInterruptor pi  = PhotoInterruptor(PowerOn, transistorPin);

void setup(){
  
  pi.setSentryLED(IndicatorLED);
  
}


void loop(){
 
  pi.sample();
  
}
