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
}

void loop() {
analogWrite(rLed,255-rPWM);
analogWrite(gLed,255-gPWM);
analogWrite(bLed,255-bPWM);
int wide = 100;
    rPWM=random(wide);
    gPWM=random(wide);
    bPWM=random(wide);
    delay(1000);
//for(int i=255;i>0;i--){analogWrite(bLed,i);delay(5);}
//for(int i=255;i>0;i--){analogWrite(rLed,i);delay(5);}
//for(int i=255;i>0;i--){analogWrite(bLed,i);delay(5);}

}
