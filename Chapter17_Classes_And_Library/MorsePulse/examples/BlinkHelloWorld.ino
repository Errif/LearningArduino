// Include the MorsePulse library
#include <MorsePulse.h>

// Create a MorsePulse object on GPIO pin 13 with 200 ms Morse pulses
MorsePulse blinker(13, 200);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  // Blink "Hello World"
  blinker.pulseText("Hello World");

}
