/*
SevenSegmentShiftDisplay.harderr
Library for running a seven segment display over a 8bit shift register

   _7_
 6|   |4	This is the default wireing scheme.
  |_5_|     For a custom one you need to send the object a new set
  |   |     of instructions how to show a specific number.
 1|___|3	You can do this with the setCustomNumbers(uint8_t nums[])
    2		with the index determening the number and value bits the leds.
*/
#ifndef SevenSegmentShiftDisplay_h
#define SevenSegmentShiftDisplay_h

#include "Arduino.h"

class SevenSegmentShiftDisplay {
	public:
		SevenSegmentShiftDisplay(int dataPin, int clockPin, int latchPin)
		void SetNumber(int num);
		void setCustomNumbers(uint8_t numbers[])
	private:
		void shiftOut(uint8_t data);
		int _dataPin;
		int _clockPin;
		int _latchPin;
		uint8_t _numbers[10] = {B11011110, B00011000 , B10110110, B10111100, B01111000, B11101100, B11101110, B10011000, B11111110, B11111100};
}

#endif