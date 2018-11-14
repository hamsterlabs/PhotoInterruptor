# PhotoInterruptor

C++ class for using a Photo-transistor and Infrared LED pair for Arduino


# C++ PhotoInterruptor Class

If the beam is broken, sample() returns true because the logic level at the top 
of the transistor is about 5 VDC.

If the beam is not broken, sample() returns false because the logic level is close to 0 VDC.


```
#include "Arduino.h"

#ifndef PhotoInterruptor_h
#define PhotoInterruptor_h

class PhotoInterruptor
{

  private:
    int sentryLED = 0;          // LED to turn on when the beam is broken
    int flash = 11;             // LED half of photointerruptor (pin assignments are set in init()
    int IPin  =  7;             // PhotoTransistor
    bool beamBroken = false;    // true for broken beam
  
  public:
    PhotoInterruptor(int iPin, int ledPin);
    void init( int iPin, int ledPin );
    void controlLED(bool led_on);
    bool sample();
    void setSentryLED(int ledPin);
};
#endif
```
