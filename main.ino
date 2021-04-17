// Eric D. Schubert, 4/16/2021
// This is a mashup of mostly example code for the Adafruit SSD1306 display and the DHT sensors.
// Currently, this only displays temperature and humidity on a 128x64 SSD1306 display, but more data will be added.
// WORK IN PROGRESS, don't expect much.

#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 

#define DHTPIN 33 
#define DHTTYPE DHT11

int mover = 0; //This is just an indicator for each time the loop function starts

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  dht.begin(); //If you remove this, temperature and humidity are way off

   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display(); // This displays the Adafruit logo. The example code takes the time
                     // to draw it with a bitmap, but it's apparently not even necessary.
                     
  delay(2000); // Pause for 2 seconds

  // Clear the buffer and set text types. This is required before printing text
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  display.println("Booting...");

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);

}

void loop() {

  delay(2000);

  if (mover > 1){
    mover = 0;
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  int f = dht.readTemperature(true);

  // Check if any reads failed and wait for input
  if (isnan(h) || isnan(t) || isnan(f)) {
    display.println(F("Failed to read from DHT sensor!"));
    display.display();
    return;
  }

  if (mover == 0){ // This if-else loop just shows when the loop starts over
    display.println("(-)"); //
      }
  else {
    display.println("(|)");
  }
  
  display.print("Temperature:  ");
  display.print(f);
  display.println(" F");
  display.print("Humidity:     ");
  display.print(h);
  display.println("%");
  
  display.display();

  mover++;
}
