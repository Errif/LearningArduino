// Include the servo library
#include <Servo.h>

// Create a servo object
Servo servo;

// Declare constants for input and output
const byte potPin = A0;
const byte servoPin = 9;

int pos;

void setup() {
  
  // Attach the servo on pin 9 to the servo object
  servo.attach(servoPin);
  pinMode(potPin, INPUT);
  
}

void loop() {

  // Read potentiometer value and map scale
  pos = map(analogRead(potPin),0,1023,0,180);

  // Move servo
  servo.write(pos);

  delay(15);
  
}
