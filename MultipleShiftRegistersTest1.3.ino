#include <MultiShiftRegister.h>

const int latchPin  = 5;
const int clockPin = 6;
const int dataPin = 4;
int numberOfRegisters = 3;
int numberOfActiveLeds = 4;
MultiShiftRegister msr (numberOfRegisters , latchPin, clockPin, dataPin);

int startLed;

int delayTime(10);
int pause(900);

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for(startLed=0-(numberOfActiveLeds-1); startLed<=((numberOfRegisters*8)-1); startLed++){  
    msr.clear_shift(startLed-1);
      
    for(int i=0; i<numberOfActiveLeds; i++){
      msr.set_shift(i+startLed);
      }
  
    delay(delayTime);
      }

  delay(pause);

  for(startLed=((numberOfRegisters*8)-1); startLed>=0-(numberOfActiveLeds-1); startLed--){
    for(int i=0; i<numberOfActiveLeds; i++){
      msr.set_shift(i+startLed);
      }

      msr.clear_shift(startLed+numberOfActiveLeds);

    delay(delayTime);
    }

  delay(pause);
}
