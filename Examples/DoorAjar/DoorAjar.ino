#include <PhotoInterruptor.h>

int heartBeep = 0;
const int PowerOn = 5;
const int transistorPin = 6;
const int indicatorLED [4] = {7, 8, 9, 10};
PhotoInterruptor p = PhotoInterruptor(PowerOn, transistorPin);

void setup() {
  pinMode(indicatorLED[0], OUTPUT);
  pinMode(indicatorLED[1], OUTPUT);
  pinMode(indicatorLED[2], OUTPUT);
  pinMode(indicatorLED[3], OUTPUT);
  pinMode(PowerOn, OUTPUT);
  PowerOnSelfTest();
}

void loop() {

  // check to see if the door is ajar
  //   the beam is broken
  if ( p.sample() == true ){
    heartBeep++;
  }
  else {
    reset();
  }

  delay(100);
  digitalWrite(indicatorLED[0], LOW);
  digitalWrite(indicatorLED[1], LOW);
  digitalWrite(indicatorLED[2], LOW);
  digitalWrite(indicatorLED[3], LOW);

  if ( heartBeep > 600 ){
      // audible alarm
      digitalWrite(indicatorLED[3], HIGH);
      delay(300);
      digitalWrite(indicatorLED[3], LOW);
  }

  if ( heartBeep > 450 ){
      // red light
      digitalWrite(indicatorLED[2], HIGH);
  }
  
  if ( heartBeep > 300 ){
      // yellow light
      digitalWrite(indicatorLED[1], HIGH);
  }

  if ( heartBeep > 150 ){
      // green light
      digitalWrite(indicatorLED[0], HIGH);
  }  

  
}

void reset(){
  heartBeep = 0;
  for(int i = 0; i< 4; i++ )
    digitalWrite(indicatorLED[i], LOW);
}

void PowerOnSelfTest() {
    // All four lights on + PowerOn light
    for(int i = 0; i< 4; i++ ){
      digitalWrite(indicatorLED[i], HIGH);
    }
    digitalWrite(PowerOn, HIGH);
    delay(2000);

    // turn off lights one at a time
    for(int i = 0; i< 4; i++ ){
      digitalWrite(indicatorLED[i], LOW);
      delay(350);
    }
    digitalWrite(PowerOn, LOW);
}
