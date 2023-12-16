#include <Servo.h>
#include <SPI.h>  
#include <Wire.h>  
#include <Adafruit_GFX.h>  
#include <Adafruit_SSD1306.h>  

#define screen_width 128 // OLED display width, in pixels  
#define screen_height 64 // OLED display height, in pixels  
#define OLED_RESET 4  
Adafruit_SSD1306 oled(screen_width, screen_height);

Servo myservo;
String myCmd;
 
void setup() {
 Serial.begin(9600);
 myservo.attach(9);
 
 if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);         // wait for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(1);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(0, 10);        // position to display
  oled.println("    COLOUR SORTER "); // text to display
  oled.display();               // show on OLED
} 

void loop() {
  
  myCmd=Serial.readStringUntil('\r');
   
  if(myCmd=="blue"){
  myservo.write(0);
  oled.setTextSize(1);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(15, 35);        // position to display
  oled.println(" COLOUR : BLUE "); // text to display
  oled.display();                // show on OLED
  delay(50);
   }
     
  if(myCmd=="green"){
  myservo.write(90);
  oled.setTextSize(1);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(15,35);        // position to display
  oled.println(" COLOUR : GREEN "); // text to display
  oled.display();               // show on OLED
   delay(50);
  } 
  
  if(myCmd=="red"){
  myservo.write(180);
  oled.setTextSize(1);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(15,35);        // position to display
  oled.println(" COLOUR : RED "); // text to display
  oled.display();               // show on OLED 
   delay(50);
  } 
}
