#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)
  // Required for Serial on Zero based boards
  #define Serial SERIAL_PORT_USBVIRTUAL
#endif


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
#include <Adafruit_VC0706.h>

//camera
#define cameraconnection Serial1
Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);

//neopixel global variables
#define LED_PIN         10          //D10
#define LED_COUNT       23          // 16 on ring + 7 on jewel = 23
#define DELAYVAL        100         // Time (in milliseconds) to pause between pixels, dropped from 500 from adafruit examples//RGB values for orange and blue LEDS  
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
uint32_t orange = strip.Color(121, 62, 26);
uint32_t blue = strip.Color(26, 117, 116);

//screen global variables
#define RA8875_INT 9
#define RA8875_CS A5
#define RA8875_RESET A4
#define BUFFPIXEL 100     //this is bumped from 20 from the Adafruit examples. The M0 has way more RAM (32K) vs the Uno's ATmega328P (2K), but we're doing a lot of thinking here. TBD on final number
Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);


// SD
#define YOUR_SD_CS 4
  // Try to select the best SD card configuration.
#if HAS_SDIO_CLASS
#define SD_CONFIG SdioConfig(FIFO_SDIO)
#elif ENABLE_DEDICATED_SPI
#define SD_CONFIG SdSpiConfig(YOUR_SD_CS, DEDICATED_SPI, SD_SCK_MHZ(16))
#else  // HAS_SDIO_CLASS
#define SD_CONFIG SdSpiConfig(YOUR_SD_CS, SHARED_SPI, SD_SCK_MHZ(16))
#endif  // HAS_SDIO_CLASS
static ArduinoOutStream cout(Serial);

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
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

    Serial.println("Hello World");
  
//Pinmodes
  pinMode(10, OUTPUT); //neopixels
  pinMode(9, INPUT); //RA8875 interrupt pin
  pinMode(0, OUTPUT); //DAC for speaker
  pinMode(A4, OUTPUT); //RA8875 RST
  pinMode(A5, OUTPUT); //RA8875 CS

//neopixels
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'


  uint32_t t = millis();
  if (!SD.cardBegin(SD_CONFIG)) {
    cout << F(
           "\nSD initialization failed.\n"
           "Do not reformat the card!\n"
           "Is the card correctly inserted?\n"
           "Is there a wiring/soldering problem?\n");
    if (isSpi(SD_CONFIG)) {
      cout << F(
           "Is SD_CS_PIN set to the correct value?\n"
           "Does another SPI device need to be disabled?\n"
           );
    }
  if (SD.sdErrorCode()) {
    cout << F("SD errorCode: ") << hex << showbase;
    printSdErrorSymbol(&Serial, SD.sdErrorCode());
    cout << F(" = ") << int(SD.sdErrorCode()) << endl;
    cout << F("SD errorData = ") << int(SD.sdErrorData()) << endl;
  }
    return;
  }

  Serial.println("SD initialization done.");  Serial.println("RA8875 start");

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

// Try to locate the camera
  Serial.println("VC0706 Camera snapshot test");
  if (cam.begin()) {
    Serial.println("Camera Found:");
  } else {
    Serial.println("No camera found?");
    return;
  }

// Print out the camera version information (optional)
  char *reply = cam.getVersion();
  if (reply == 0) {
    Serial.print("Failed to get version");
  } else {
    Serial.println("-----------------");     Serial.print(reply);     Serial.println("-----------------");
  }

    cam.setImageSize(VC0706_640x480);        

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
