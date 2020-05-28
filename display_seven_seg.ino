#include "seven_seg_display.h"
SevenSegmentDisplay sevenSegmentDisplay(2, 3, 4, 5, 6, 7, 8, 9);
int counter;
void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i < 10; i++){
    pinMode(i, OUTPUT);
  }
  counter = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  sevenSegmentDisplay.displayLastDigit(counter);
  delay(500);
  counter++;
  counter %= 10;
}
