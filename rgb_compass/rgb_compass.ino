
// I2C Library
#include <Wire.h>
// QMC5883L Compass Library
#include <QMC5883LCompass.h>

QMC5883LCompass compass;


 int rLed = 9, 
    gLed = 10, 
    bLed=11;
    
int rPWM=0,
    gPWM=0,
    bPWM=0;

void setup() {
 pinMode(rLed,OUTPUT);
pinMode(gLed,OUTPUT);
pinMode(bLed,OUTPUT);

digitalWrite(rLed,HIGH);
digitalWrite(gLed,HIGH);
digitalWrite(bLed,HIGH);
  // Initialize the serial port.
  Serial.begin(9600);
  // Initialize I2C.
  Wire.begin();
  // Initialize the Compass.
  compass.init();
}

void loop() {
  int x, y, z;

  // Read compass values
  compass.read();

  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();
/*
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("   Y: ");
  Serial.print(y);
  Serial.print("   Z: ");
  Serial.println(z);
*/nb 
  int wide = 100;
  rPWM=map(x,-2000,2000,0,wide);
  gPWM=map(y,-2300,2000,0,wide);
  bPWM=map(z,-2000,1500,0,wide);
  
analogWrite(rLed,255-rPWM);
analogWrite(gLed,255-gPWM);
analogWrite(bLed,255-bPWM);
    //rPWM=random(wide);
    //gPWM=random(wide);
    //bPWM=random(wide);
    delay(100);
//for(int i=255;i>0;i--){analogWrite(bLed,i);delay(5);}
//for(int i=255;i>0;i--){analogWrite(rLed,i);delay(5);}
//for(int i=255;i>0;i--){analogWrite(bLed,i);delay(5);}

}
