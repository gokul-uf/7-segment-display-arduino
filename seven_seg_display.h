// let's assume that the display is common Anode.
// Why? Because that's what I have :-P


/* TODOs
 *  1.Add the displayHex method for displaying hexadecimal
 *  2. Add a displayCharacter method for displaying characters
 *  3. Maybe add a displayString?
 */
#ifndef SEVEN_SEG_DISPLAY_H
#define SEVEN_SEG_DISPLAY_H

#include "Arduino.h"

class SevenSegmentDisplay {
  public:
    SevenSegmentDisplay(int pinA, int pinB, int pinC, int pinD,
                             int pinE, int pinF, int pinG, int pinDot);
    void displayLastDigit(int n);

  private:
    int getIndex(char c);
    void setSegmentState(String s, int state = LOW);
    int pins[8];


};

#endif
