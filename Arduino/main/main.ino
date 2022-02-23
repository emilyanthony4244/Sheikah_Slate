//included libraries
#include <BufferedPrint.h>
#include <FreeStack.h>
#include <MinimumSerial.h>
#include <RingBuf.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <sdios.h>
//#include <SD.h>
#include <SPI.h>
SdFat SD;
#include <SamdAudio.h> //https://github.com/AloyseTech/SamdAudio
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Wire.h>
#include "Adafruit_RA8875.h"
#include <Adafruit_STMPE610.h>

//TODO: add camera stuff

//neopixel global variables
#define LED_PIN         10          //D10
#define LED_COUNT       23          // 16 on ring + 7 on jewel = 23
#define DELAYVAL        100         // Time (in milliseconds) to pause between pixels, dropped from 500 from adafruit examples//RGB values for orange and blue LEDS  
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
uint32_t orange = strip.Color(117, 62, 26);
uint32_t blue = strip.Color(26, 117, 116);

//screen global variables
#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9
#define BUFFPIXEL 100     //this is bumped from 20 from the Adafruit examples. The M0 has way more RAM (32K) vs the Uno's ATmega328P (2K), but we're doing a lot of thinking here. TBD on final number
Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);


// SD chip select pin
#define YOUR_SD_CS 4

//speaker global variables
#define NUM_AUDIO_CHANNELS 1                //could be 1,2 or 4 for sound
#define AUDIO_BUFFER_SIZE 1024              //512 works fine for 22.05kh, set buffer size to 1024 for 32khz and 44.1khz for Adafruit M0 with QUAD Flash

const unsigned int sampleRate = 22050;      //hz. indicate sample rate here (use audacity to convert your wav)

//included wav files
const char *chirp = "chirp.wav"; //sheikah sensor chirp
const char *wakeup = "wakeup.wav"; //sound on wakeup

//speaker
SamdAudio AudioPlayer;

//Function prototypes
void neopixelsOn();
void neopixelsBreathe();
void noise(const char wavname);
void bmpDraw(const char *filename, int x, int y);



void setup() {
  // put your setup code here, to run once:
  

//neopixels
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  



//Initialize serial for startup
  Serial.begin(9600);
  if (!SD.begin(YOUR_SD_CS))
  {
    Serial.println("initialization failed!");
    return;
  }

  Serial.println("initialization done.");  Serial.println("RA8875 start");

  /* Initialize the display using 'RA8875_480x80', 'RA8875_480x128', 'RA8875_480x272' or 'RA8875_800x480' */
  if (!tft.begin(RA8875_800x480)) {
    Serial.println("RA8875 Not Found!");
    while (1);
  }

  Serial.println("Found RA8875");

  tft.displayOn(true);
  tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
  tft.PWM1out(255);

  Serial.print("(");   Serial.print(tft.width());   Serial.print(", ");   Serial.print(tft.height());   Serial.println(")");
  tft.graphicsMode();                 // go back to graphics mode
  tft.fillScreen(RA8875_BLACK);
  tft.graphicsMode();


//audio startup
  Serial.print("Initializing Audio Player...");
    AudioPlayer.begin(sampleRate);
      Serial.println(" done.");
  AudioPlayer.play(wakeup, 1); // play wakeup tone
}

void loop() {
  // put your main code here, to run repeatedly:

  neopixelsOn();
  bmpDraw("shiekahsymbol.bmp", 0, 0);

}
