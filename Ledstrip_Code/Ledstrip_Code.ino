// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 8); // RX, TX

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        3 // On Trinket or Gemma, suggest changing this to 1
char inputBuffer[16];
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 500 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
  // mySerial.begin(9600);
}

void loop() {
  //  // Set all pixel colors to 'off'
  if (int s = Serial.available()) {

    Serial.readBytes(inputBuffer, sizeof(inputBuffer));
    int pixel = atoi(inputBuffer);
    // memset(inputBuffer, 0, sizeof(inputBuffer));
    //
    pixels.clear();
    pixels.setPixelColor(pixel, pixels.Color(255, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    Serial.println(pixel);
  }
}
