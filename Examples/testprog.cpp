#include "Arduino.h"
#include "PhotoInterruptor.h"

/*
	Test program for the PhotoInterruptor Arduino library
*/

const int PhotoLED = 6;
const int IndicatorLED = 7;
const int IPin = 5;
PhotoInterruptor pi  = PhotoInterruptor(IPin, PhotoLED);

void setup(){
  
  pi.setSentryLED(IndicatorLED);
  
}


void loop(){
 
  pi.sample();
  
}
