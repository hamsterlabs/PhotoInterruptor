#include "Arduino.h"

#ifndef PhotoInterruptor_h
#define PhotoInterruptor_h

class PhotoInterruptor
{

  private:
    int sentryLED = 0;          // LED to turn on when the beam is broken
    int lightsOn = 0;           // LED control, power for interruptor circuit
    int samplePin = 0;          // LED to check the transistor
    bool beamBroken = false;    // true for broken beam
  
  public:
    PhotoInterruptor(int lightson, int samplepin);
    void init( int lightson, int samplepin  );                   //
    void controlLED(bool led_on);    // turns on the circuit so you can sample it
    bool sample();                   // returns beamBroken on (true) or off (false)
    void setSentryLED(int digOutPin);   // Digital output to trigger (optional)
};
#endif
