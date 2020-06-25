/*
 * miniMACRO6C github.com/leafcutterlabs/miniMACRO6C/
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#include <Bounce2.h>

#define BUTTON_PIN_0 15 //SCK 
#define BUTTON_PIN_1 16 //MOSI
#define BUTTON_PIN_2 11 //B7
#define BUTTON_PIN_3 LED_BUILTIN_TX //D5 
#define BUTTON_PIN_4 1 //D3 
#define BUTTON_PIN_5 0 //D2 

// Instantiate a Bounce object
Bounce debouncer0 = Bounce(); 
Bounce debouncer1 = Bounce(); 
Bounce debouncer2 = Bounce(); 
Bounce debouncer3 = Bounce(); 
Bounce debouncer4 = Bounce(); 
Bounce debouncer5 = Bounce(); 

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  Serial.println("Connected:");
  pinMode(BUTTON_PIN_0,INPUT_PULLUP);
  debouncer0.attach(BUTTON_PIN_0);
  debouncer0.interval(5); // interval in ms
  pinMode(BUTTON_PIN_1,INPUT_PULLUP);
  debouncer1.attach(BUTTON_PIN_1);
  debouncer1.interval(5); // interval in ms
  pinMode(BUTTON_PIN_2,INPUT_PULLUP);
  debouncer2.attach(BUTTON_PIN_2);
  debouncer2.interval(5); // interval in ms
  pinMode(BUTTON_PIN_3,INPUT_PULLUP);
  debouncer3.attach(BUTTON_PIN_3);
  debouncer3.interval(5); // interval in ms
  pinMode(BUTTON_PIN_4,INPUT_PULLUP);
  debouncer4.attach(BUTTON_PIN_4);
  debouncer4.interval(5); // interval in ms
  pinMode(BUTTON_PIN_5,INPUT_PULLUP);
  debouncer5.attach(BUTTON_PIN_5);
  debouncer5.interval(5); // interval in ms
  display.clearDisplay();

  // draw a single pixel
  display.drawPixel(10, 10, WHITE);
  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  display.display();
  delay(2000);
  display.clearDisplay();

  // text display tests
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("TYPE!");
  display.display();
  delay(2000);
}

void loop() {
  //display.println("junk");
  display.display();
  
  //Serial.println("0");
  debouncer0.update();
  debouncer1.update();
  debouncer2.update();
  debouncer3.update();
  debouncer4.update();
  debouncer5.update();
  
  if (debouncer0.fell()){
    Serial.println("0");
  }
  if (debouncer0.rose()){
  }
  if (debouncer1.fell()){
    Serial.println("1");
  }
  if (debouncer1.rose()){
  }
  if (debouncer2.fell()){
    Serial.println("2");
  }
  if (debouncer2.rose()){
  }
  if (debouncer3.fell()){
    Serial.println("3");
  }
  if (debouncer3.rose()){
  }
  if (debouncer4.fell()){
    Serial.println("4");
  }
  if (debouncer4.rose()){
  }
  if (debouncer5.fell()){
    Serial.println("5");
  }
  if (debouncer5.rose()){
  }
}
