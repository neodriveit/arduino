int rLed = 9, 
    gLed = 10, 
    bLed=11;
    
int rPWM,
    gPWM,
    bPWM;

void setup() {
  
Serial.begin(9600);
pinMode(rLed,OUTPUT);
pinMode(gLed,OUTPUT);
pinMode(bLed,OUTPUT);

digitalWrite(rLed,HIGH);
digitalWrite(gLed,HIGH);
digitalWrite(bLed,HIGH);
}

void loop() {
  int xAxis = analogRead(A0);
  int yAxis = analogRead(A1);
  rPWM=map(xAxis,0,400,0,100);
  analogWrite(rLed,rPWM);
  //gPWM=map(yAxis,0,400,0,100);
  //analogWrite(gLed,gPWM);
  bPWM=map(yAxis,0,400,0,100);
  analogWrite(bLed,bPWM);
  Serial.print("x");
  Serial.print(xAxis);
  Serial.print(" y");
  Serial.print(yAxis);
  Serial.println();
 
}
