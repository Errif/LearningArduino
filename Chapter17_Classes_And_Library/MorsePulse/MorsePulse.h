#ifndef MorsePulse_h
#define MorsePulse_h

#include "Arduino.h"

class MorsePulse{
  public:
    MorsePulse(byte ledPin, unsigned long morseSpeed);
    void pulseLetter(char character);
    void pulseText(String text);

  private:
    byte _ledPin;
    unsigned long _morseSpeed;
    void shortPulse(byte pulses);
    void longPulse(byte pulses);
    void nextWord();
    void nextLetter();
};


#endif
