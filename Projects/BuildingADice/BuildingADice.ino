// Include the button and servo library
#include <Button.h>
#include <Servo.h>

#include "pitches.h"
#include "melody.h"

// Create a button object on GPIO pin 13
Button btnRoll(13);

// Create a new servo object
Servo servo;

// Declare global pin constant for buzzer
const byte buzzerPin = 10;

void setup() {

  // Start button
  btnRoll.begin();

  // Attach the servo on 9 to the servo object
  servo.attach(9);

  // Set buzzerPin as output
  pinMode(buzzerPin, OUTPUT);

  // Initialise a pseudi-random number generator
  randomSeed(analogRead(0));

  // Move servo to position zero
  servo.write(0);

  // Go through every number and show steps for calibration
  for(int i = 1; i < 7; i++){
    setDice(i, true);
    delay(500);
  }

  setDice(1, false);
  
  // Open a serial connection
  Serial.begin(9600);

}

void playTone(int melody[], int noreDurations[], int lengths){

  for (int thisNote = 0; thisNote < lengths; thisNote++) {

    // To calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noreDurations[thisNote];

    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the tone playing:
    noTone(buzzerPin);

  }
}

void loop() {

  if (btnRoll.released()) {
    Serial.println("Button was pressed \n");
    upDown();
    setDice(random(1,7), true);
  }
  
  // Read servo position
  // float servoValue = servo.read();

}

void upDown(){

  // Move servo up and down
  setDice(6, false);
  delay(600);
  setDice(1, false);
  delay(600);

}

void setDice(int number, boolean acousticFeedback){

  // Map number 1-6 to degrees for servo between 20 and 140 degrees
  int dicePointer = map(number, 1, 6, 20, 140);

  Serial.print("Rolled: ");
  Serial.println(dicePointer);

  // Move servo to specified angle
  servo.write(dicePointer);

  // Play sound
  delay(500);
  if (acousticFeedback == true){
    // delay(500);
    // for (int i = 0; i < number; i++){
    //   digitalWrite(buzzerPin, HIGH);
    //   delay(50);
    //   digitalWrite(buzzerPin, LOW);
    //   delay(100);
    // }
    if (number == 6){
      playTone(MarioMainThemeMelody, MarioMainThemeNoteDurations, sizeof(MarioMainThemeMelody)/sizeof(int));
    }
    else if (number == 5){
      playTone(TetrisMelody, TetrisNoteDurations, sizeof(TetrisMelody)/sizeof(int));
    }
    else if (number == 4){
      playTone(JingleMelody, JingleNoteDuration, sizeof(JingleMelody)/sizeof(int));
    }
    else if (number == 3){
      playTone(WishMelody, WishNoteDuration, sizeof(WishMelody)/sizeof(int));
    }
    else if (number == 2){
      playTone(SantaMelody, SantaNoteDuration, sizeof(SantaMelody)/sizeof(int));
    }
    else if (number == 1){
      playTone(MySadMelody, MySadNoteDurations, sizeof(MySadNoteDurations)/sizeof(int));
    }
    // else{
    //   playTone(MyMelody2, MyNoteDurations2, sizeof(MyMelody2)/sizeof(int));
    // }
  }
  

}