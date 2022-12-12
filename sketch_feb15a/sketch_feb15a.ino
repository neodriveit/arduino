#define rLed 13
#define yLed 12
#define gLed 11
#define BUZZER A5

double buttonState = 0;
double buttonState1 = 0;
double buttonState2 = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  pinMode(BUZZER,OUTPUT);
  pinMode(A0,INPUT);  
  pinMode(A1,INPUT);  
  pinMode(A2,INPUT);
  pinMode(rLed, OUTPUT);
  pinMode(yLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  digitalWrite(rLed, HIGH);
  digitalWrite(yLed, LOW);
  digitalWrite(gLed, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(A0);
if( buttonState==LOW ) {
  
  digitalWrite(rLed, LOW);
}else {
  
  digitalWrite(rLed, HIGH);
  tone(BUZZER,261.63);
}
buttonState1 = digitalRead(A1);
if( buttonState1==LOW ) {
  
  digitalWrite(yLed, LOW);
}else {
  
  digitalWrite(yLed, HIGH);
  tone(BUZZER,277.18);
}

buttonState2 = digitalRead(A2);
if( buttonState2==LOW ) {
  
  digitalWrite(gLed, LOW);
}else {
  
  digitalWrite(gLed, HIGH);
  tone(BUZZER,392.00);
}


if(buttonState==LOW && buttonState1==LOW && buttonState2==LOW) noTone(BUZZER);
 /* int time = 100;
  tone(BUZZER, 1000);
  delay(time);
    tone(BUZZER, 2000);
  delay(time);
      tone(BUZZER, 3000);
  delay(time);  
  tone(BUZZER, 4000);
  delay(time);
    tone(BUZZER, 5000);
  delay(time);
      tone(BUZZER, 6000);
  delay(time);
  */
}
