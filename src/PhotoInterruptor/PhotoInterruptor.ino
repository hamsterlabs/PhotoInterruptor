#include "Arduino.h"
#include "PhotoInterruptor.h"

/*
 * 
 * updated November 25, 2018
 */
PhotoInterruptor::PhotoInterruptor(int lightson, int samplepin){
    init(lightson, samplepin);
}

  
  void PhotoInterruptor::init( int lightson, int samplepin ){
    if ( lightson > 0 && samplepin > 0 )
    {
      this->lightsOn = lightson;
      this->samplePin = samplepin;
      pinMode(this->lightsOn, OUTPUT);
      pinMode(this->samplePin, INPUT);
    }
  }
  
  void PhotoInterruptor::controlLED(bool led_on){
    if ( led_on )
      digitalWrite(lightsOn, HIGH);
    else 
      digitalWrite(lightsOn, LOW);
  }

  bool PhotoInterruptor::sample(){
    // turn on the LED, then check if the beam is broken
    // if the beam is broken it is logical HIGH so return true   ~ 5 VDC
    // if the beam is not broken it is logical LOW, return false ~ 0 VDC
    controlLED(true);
    
    beamBroken = ( digitalRead(samplePin) == HIGH ) ? true : false;

    // if there is a pin to control it is Active Low
    if ( this->sentryLED != 0 ){
      digitalWrite(this->sentryLED, (beamBroken) ? LOW : HIGH );
    }
      
    controlLED(false);
    return beamBroken;   // true if the beam is broken
  }

  void PhotoInterruptor::setSentryLED(int digOutPin){
    this->sentryLED = digOutPin;
    if ( sentryLED > 0 )
      pinMode(this->sentryLED, OUTPUT);
  }

  
