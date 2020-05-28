#include "Arduino.h"
#include "seven_seg_display.h"


SevenSegmentDisplay::SevenSegmentDisplay(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int pinDot){
  pins[0] = pinA;
  pins[1] = pinB;
  pins[2] = pinC;
  pins[3] = pinD;
  pins[4] = pinE;
  pins[5] = pinF;
  pins[6] = pinG;
  pins[7] = pinDot;
}

int SevenSegmentDisplay::getIndex(char c){  
  /* Convert a character into index into the 7 segment display. 
   *  This is just so it's easy to do the digital display
   */
   c = toUpperCase(c);
   return c - 'A';
  
}

void SevenSegmentDisplay::setSegmentState(String s, int state = LOW){
  for(int i = 0; i < s.length(); i++){
    digitalWrite(pins[getIndex(s[i])], state);
  }
}

void SevenSegmentDisplay::displayLastDigit(int n){
  /* Zero out all the LEDs before writing the correct digit
   *  If a number greater than 9 is given, only the last digit is displayed
   *  alongwith the dot to indicate an ERROR state
   */

  setSegmentState("ABCDEFG", HIGH);
  digitalWrite(pins[7], HIGH); // the dot is handled separately
  
  if(n > 9){ // set ERROR state
    digitalWrite(pins[7], LOW); 
  }

  switch(n%10){
    case 0:
      setSegmentState("ABCDEF");
      break;
  
    case 1: 
      setSegmentState("BC");
      break;
      
    case 2:
      setSegmentState("ABDEG");
      break;
      
    case 3:    
      setSegmentState("ABCDG");
      break;

    case 4:
      setSegmentState("BCFG");
      break;
      
    case 5:
      setSegmentState("ACDFG");
      break;

    case 6:
      setSegmentState("ACDEFG");
      break;

    case 7:
      setSegmentState("ABC");
      break;

    case 8:
      setSegmentState("ABCDEFG");
      break;

    case 9:
      setSegmentState("ABCDFG");
      break;
  }
  
}
