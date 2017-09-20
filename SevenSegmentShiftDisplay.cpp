#include "Arduino.h"
#include "SevenSegmentShiftDisplay.h"

SevenSegmentShiftDisplay::SevenSegmentShiftDisplay(int dataPin, int clockPin, int latchPin){
	this._dataPin = dataPin;
	this._clockPin = clockPin;
	this._latchPin = latchPin;
	this.SetNumber(-1)
}

void SevenSegmentShiftDisplay::SetNumber(int num){
	if(num == -1){
		shiftOut(0x00);
	} else if (num >= 0 && num <= 9){		
		shiftOut(numbers[num]);
	}
}

void SevenSegmentShiftDisplay::SetCustomNumbers(uint8_t numbers[]){
	if(sizeof(numbers) == 10){
		this._numbers = numbers;
	}
}

void SevenSegmentShiftDisplay::shiftOut(uint8_t b){
	
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  digitalWrite(latchPin, 0);
  digitalWrite(dataPin, 0);
  digitalWrite(clockPin, 0);

  for (i=7; i>=0; i--)  {
    digitalWrite(clockPin, 0);

    if ( b & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(dataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(clockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(dataPin, 0);
  }

  //stop shifting
  digitalWrite(latchPin, 1);
  digitalWrite(clockPin, 0);
}