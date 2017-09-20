# SevenSegmentShiftDisplay.h

Library for running a seven segment display over a 8bit shift register

```
   _7_ 
 6|   |4 
  |_5_| 
  |   | 
 1|___|3 
    2	 
```

This is the default wireing scheme.
For a custom one you need to send the object a new set
of instructions how to show a specific number.
You can do this with the SetCustomNumbers(uint8_t nums[])
with the index determening the number and value bits the leds.


## Public functions:

### SevenSegmentShiftDisplay(int dataPin, int clockPin, int latchPin);
Creates a instance of the class.
#### Parameters:
- int dataPin: The pin number for the serial data
- int clockPin: The pin number for the clock
- int latchPin: The pin number for the latch

### void SetNumber(int num);
Sets the display to the given number
#### Parameters:
- int num: The number to be displayed. Must be between 0 and 9.

### void SetCustomNumbers(uint8_t numbers[10]);
Sets custom byte formats for the numbers.
