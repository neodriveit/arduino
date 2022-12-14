#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// My variables ----------------------------

float dis; // distance
int t; // time, counter value
int echo=4; // sensor's Echo to pin D4
int trig=3; // sensor's Trig to pin D3
float k=1180.0; // conversion factor from time to distance, must be calibrated

// -------------------------------------------

void setup(){
pinMode(trig,OUTPUT); // Trigger
pinMode(echo,INPUT); // Echo

digitalWrite(trig,LOW); // setting trigger to 0

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C
for(;;); // Don't proceed, loop forever
}
display.clearDisplay();
display.setTextSize(1); // Pixel scale, 1=normal
display.setTextColor(SSD1306_WHITE); // Draw white text
display.cp437(true); // Use full 256 char 'Code Page 437' font
display.setCursor(10, 15);
display.display();
}
void loop(){// Main loop ******************************************************************************

delay(200);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
t=0;
while (digitalRead(echo)==0){}; //waiting for Echo to rise
while (digitalRead(echo)==1){ // counting the rounds until echo=1
t++;
if (t>65000){
t=0;
break;
}
}
dis=(float)t/k; // counting distance from time

display.clearDisplay();
display.setCursor(50, 15); // Start at x,y
if (dis<10) {
display.print(dis);
display.print(" ");
display.print("m");
display.display();
} else {
display.print("---");
display.print(" ");
display.print("m");
display.display();
}
}
