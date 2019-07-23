const byte ledPins[4] = {9, 10, 11};

void setup() {
  // Use GPIO pn 6, 9, 10, 11 as output
  for(int i = 0; i <= 2; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  
  // Fade to RED
  for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[0], i);
    delay(5);
  }

  // Fade from red to green
  for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[0], 255 - i);
    analogWrite(ledPins[1],  i);
    delay(5);
  }

  // Fade from green to blue
  for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[1], 255 - i);
    analogWrite(ledPins[2],  i);
    delay(5);
  }

  // Fade away
    // Fade to RED
  for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[2], 255 - i);
    delay(5);
  }

  // Fade to white (all colors)
    for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[0], i);
    analogWrite(ledPins[1], i);
    analogWrite(ledPins[2], i);
    delay(5);
  }

  // Fade to white (all colors)
  for(int i = 0; i <= 255; i++){
    analogWrite(ledPins[0], 255 - i);
    analogWrite(ledPins[1], 255 - i);
    analogWrite(ledPins[2], 255 - i);
    delay(5);
  }
  
}
