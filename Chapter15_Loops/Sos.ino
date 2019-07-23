// Include the Button library
#include <Button.h>

// Create a button object
Button btnSos(2);

const byte ledPin = 13;

void setup(){

    // Start button
    btnSos.begin();

    // Use ledPin as output
    pinMode(ledPin, OUTPUT);
}

void shortBlink(){
    // Make a single short blink
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
}


void longBlink(){
    // Make a single short blink
    digitalWrite(ledPin, HIGH);
    delay(600);
    digitalWrite(ledPin, LOW);
    delay(200);
}

void morseBlink(char character){
    //Translate character to Morse code
    switch (character)
    {
        case 's':
            shortBlink();
            shortBlink();
            shortBlink();
            break;
    
        case 'o':
            longBlink();
            longBlink();
            longBlink();
            break;
    }
}

void loop(){

    // Start blinking SOS
    if (btnSos.pressed()) {
        
        // Blink until btnSos is released
        while(!btnSos.released()){
            morseBlink('s');
            morseBlink('o');
            morseBlink('s');
        }
        
    }
    

}