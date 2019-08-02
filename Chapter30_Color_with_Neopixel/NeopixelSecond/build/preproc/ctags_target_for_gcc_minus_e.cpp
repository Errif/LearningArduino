# 1 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Chapter30_Color_with_Neopixel\\NeopixelSecond\\NeopixelSecond.ino"
# 1 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Chapter30_Color_with_Neopixel\\NeopixelSecond\\NeopixelSecond.ino"
// Include the Neopixel library
# 3 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Chapter30_Color_with_Neopixel\\NeopixelSecond\\NeopixelSecond.ino" 2

// Declare and initialize global GPIO pin constant for Neopixel ring
const byte neoPin = 10;

// Declare and initilize global constant for number of pixels
const byte neoPixels = 24;

// Declare and initialize variable for Neopixel brightness
byte neoBright = 100;

Adafruit_NeoPixel ring = Adafruit_NeoPixel(neoPixels, neoPin, ((1<<6) | (1<<4) | (0<<2) | (2)) /*|< Transmit as G,R,B*/);

void setup(){
    // Initilize ring
    ring.begin();
    ring.setBrightness(neoBright);
    ring.show();
}

void loop(){
    // Turn in pixels one by one
    /* for(int i = 0; i < neoPixels; i++){

        ring.setPixelColor(i, ring.Color(0,118,189));

        ring.show();

        delay(42);

    }



    // Turn off pixels one by one

    for(int i = 0; i < neoPixels; i++){

        ring.setPixelColor(i, ring.Color(0,0,0));

        ring.show();

        delay(42);

    } */
# 37 "c:\\Users\\Edvin\\OneDrive\\Programmering\\Arduino\\LearningArduino\\Chapter30_Color_with_Neopixel\\NeopixelSecond\\NeopixelSecond.ino"
    rainbow(8);
    // theaterChaseRainbow(100);

    delay(10);
}

// Rainbow cycle along whole ring. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 3 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 3*65536. Adding 256 to firstPixelHue each time
  // means we'll make 3*65536/256 = 768 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256) {
    for(int i=0; i<ring.numPixels(); i++) { // For each pixel in ring...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the ring
      // (ring.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / ring.numPixels());
      // ring.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through ring.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      ring.setPixelColor(i, ring.gamma32(ring.ColorHSV(pixelHue)));
    }
    ring.show(); // Update ring with new contents
    delay(wait); // Pause for a moment
  }
}

void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0; // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) { // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      ring.clear(); //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of ring in increments of 3...
      for(int c=b; c<ring.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the ring (ring.numPixels() steps):
        int hue = firstPixelHue + c * 65536L / ring.numPixels();
        uint32_t color = ring.gamma32(ring.ColorHSV(hue)); // hue -> RGB
        ring.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      ring.show(); // Update ring with new contents
      delay(wait); // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}
