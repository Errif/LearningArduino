// Include the Button and MorsePulse library
#include <Button.h>
#include <MorsePulse.h>

// Create a button object
Button btnSos(2);

// Create a MorsePulse object
MorsePulse blinker(13, 200);

void setup() {
  // Start button
  btnSos.begin();
}

void loop() {

  // Start blinking
  if (btnSos.pressed()){
    // Blink until btnSos is released
    while(!btnSos.released()){
      blinker.pulseText("sos");
    }
  }
  
}
