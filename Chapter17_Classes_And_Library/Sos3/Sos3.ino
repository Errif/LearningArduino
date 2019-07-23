// Include the Button and MorsePulse library
#include <Button.h>
#include <MorsePulse.h>

// Create a button object
Button btnSos(2);

// Create new MorsePulse objects
MorsePulse blinker(13, 200);
MorsePulse beeper(10, 200);

void setup() {
  // Start button
  btnSos.begin();
}

void loop() {

  // Start blinking
  if (btnSos.pressed()){
    // Blink until btnSos is released
    while(!btnSos.released()){
      // blinker.pulseText("sos");
      beeper.pulseText("sos");
    }
  }
  
}
