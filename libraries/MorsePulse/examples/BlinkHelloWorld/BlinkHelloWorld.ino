#include <MorsePulse.h>

MorsePulse blinker(13, 200);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  blinker.pulseText("Hello World");
}
