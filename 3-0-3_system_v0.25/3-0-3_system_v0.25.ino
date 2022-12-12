/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>HEADER<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

#define HEADSERVO 6
#define BUZZER 8
#define DIST_TRIG 26
#define DIST_ECHO 27
#define xAXIS A0
#define yAXIS A1
#define JOY_SW 52
#define HEAD A15

#include <Servo.h> 
Servo headServo; int pos=90;

/*                                              ----------ENGINES----------                                                   */
//engines control pins
int rf=2,rb=3,lf=4,lb=5,rs=9,ls=10;
    
//nodemcu control pins
int f = 25,
    b = 24,
    tl = 23,
    tr = 22;
    
//time rotation
int timeRotation = 3800,
    angle360=timeRotation,
    angle180=timeRotation/2,
    angle90=timeRotation/4,
    angle45=timeRotation/8;


/*                                             ------------ELSE-------------                                                  */
int ec = 10;//engine correction
int node_conn = -1; //nodemcu connection variable

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SETUP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void setup() {

toneStartSystem();
stopEngines();
Serial.begin(9600);
headServo.attach(HEADSERVO);
pinMode(BUZZER,OUTPUT);
pinMode(DIST_TRIG,OUTPUT);digitalWrite(DIST_TRIG,LOW);
pinMode(DIST_ECHO,INPUT);
pinMode(JOY_SW,INPUT_PULLUP);
// pinMode(NODEMCU_CONTROL_PIN,INPUT);
pinMode(rf,OUTPUT);pinMode(rb,OUTPUT);pinMode(lf,OUTPUT);pinMode(lb,OUTPUT);pinMode(rs,OUTPUT);pinMode(ls,OUTPUT);//engines control pins
pinMode(f,INPUT);pinMode(b,INPUT);pinMode(tl,INPUT);pinMode(tr,INPUT);//nodemcu control pins

headServo.write(pos);delay(1000);

}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOOP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOOP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOOP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOOP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOOP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOOP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOOP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void loop() {  
int dist;
//distanceRead();
if(digitalRead(JOY_SW)==LOW) {dist=distanceRead();toneDist(dist);}
//delay(2000);

//if(digitalRead(NODEMCU_CONTROL_PIN)==HIGH)
//{
  
if(node_conn<=0){toneConnected();node_conn=1;}
if(digitalRead(f)==HIGH) forward(255); else stopEngines();
if(digitalRead(b)==HIGH) backward(); else stopEngines();
if(digitalRead(tl)==HIGH) rotateLeft(); else stopEngines();
if(digitalRead(tr)==HIGH) rotateRight(); else stopEngines();

//}//if(NODEMCU_CONTROL_PIN)
//else if(node_conn==1){toneDisconnected();node_conn=0;}
}//loop()

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>FUNCTIONS<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/*                                              ----------MOVEMENT----------                                                  */
void forward(int speed){
clearEnginesStates();
digitalWrite(rf,HIGH);analogWrite(rs,speed);
digitalWrite(lf,HIGH);analogWrite(ls,speed);
delay(10);
}

void backward(){
clearEnginesStates();
digitalWrite(rb,HIGH);
digitalWrite(lb,HIGH);
delay(10);
}

void rotateRight(){
clearEnginesStates();
digitalWrite(rf,HIGH);analogWrite(rs,255);
digitalWrite(lb,HIGH);analogWrite(ls,255);
delay(10);
}
void rotateRight(int time){
clearEnginesStates();
digitalWrite(rf,HIGH);analogWrite(rs,255);
digitalWrite(lb,HIGH);analogWrite(ls,255);
delay(time);
}
void rotateLeft(){
clearEnginesStates();
digitalWrite(lf,HIGH);analogWrite(ls,255);
digitalWrite(rb,HIGH);analogWrite(rs,255);
delay(10);
}
void rotateLeft(int time){
clearEnginesStates();
digitalWrite(lf,HIGH);analogWrite(ls,255);
digitalWrite(rb,HIGH);analogWrite(rs,255);
delay(time);
}

void turnRightForward(){
clearEnginesStates();
digitalWrite(rf,HIGH);analogWrite(ls,80);
digitalWrite(lf,HIGH);analogWrite(rs,255);
}

void turnLeftForward(){
clearEnginesStates();
digitalWrite(rf,HIGH);analogWrite(ls,255);
digitalWrite(lf,HIGH);analogWrite(rs,80);
}

void turnRightBackward(){
clearEnginesStates();
digitalWrite(rb,HIGH);analogWrite(rs,80);
digitalWrite(lb,HIGH);analogWrite(ls,255);
}

void turnLeftBackward(){
clearEnginesStates();
digitalWrite(rb,HIGH);analogWrite(rs,255);
digitalWrite(lb,HIGH);analogWrite(ls,80);
}

void clearEnginesStates(){
digitalWrite(rf,LOW);digitalWrite(lf,LOW);digitalWrite(rb,LOW);digitalWrite(lb,LOW);
}

void stopEngines(){
digitalWrite(rf,LOW);digitalWrite(lf,LOW);digitalWrite(rb,LOW);digitalWrite(lb,LOW);
}

void headMove(){
int headDelay=5; int stepDelay = 333; int rangeMin=33; int rangeMax=147;
for(pos=rangeMin;pos<rangeMax;pos++){headServo.write(pos);delay(headDelay);if(pos==90)delay(stepDelay);}delay(stepDelay);
for(pos=rangeMax;pos>rangeMin;pos--){headServo.write(pos);delay(headDelay);if(pos==90)delay(stepDelay);}delay(stepDelay);
}

void headMove1(){
int stepDelay = 1500; int minRange=33; int maxRange=147;
headServo.write(minRange);delay(stepDelay);
headServo.write(90);delay(stepDelay);
headServo.write(maxRange);delay(stepDelay);
headServo.write(90);delay(stepDelay);
}
void headJoystick(){
int xAxis = analogRead(xAXIS);
int yAxis = analogRead(yAXIS);
pos=map(yAxis,0,1023,33,147);
headServo.write(pos);
}
/*                                                 ---------SENSORS---------                                               */
int distanceRead(){
digitalWrite(DIST_TRIG, LOW);delayMicroseconds(2);
digitalWrite(DIST_TRIG, HIGH);delayMicroseconds(10);
digitalWrite(DIST_TRIG, LOW);
int time = pulseIn(DIST_ECHO, HIGH);
int distance = time/58;
Serial.print(distance);
Serial.println(" cm");
delay(500);
return(distance);
}
/*                                                 ----------TONES----------                                               */
void toneStartSystem(){
delay(50);
tone(BUZZER,900);delay(200);noTone(BUZZER);
}
void toneConnected(){
delay(50);
double startTone = 1100;
for(int i=0;i<6;i++){
tone(BUZZER,startTone);
delay(50);
startTone+=100;
}//for
noTone(BUZZER);
}

void toneDisconnected(){
delay(50);
double startTone = 1700;
for(int i=0;i<10;i++){
tone(BUZZER,startTone);
delay(50);
startTone-=100;
}//for
noTone(BUZZER);
}

void toneError(){
delay(50);
tone(BUZZER,100);delay(650);
noTone(BUZZER);
}

void tone_m() {tone(BUZZER,3000);delay(900);noTone(BUZZER);delay(300);}
void tone_dm() {tone(BUZZER,3000);delay(200);noTone(BUZZER);delay(300);}
void tone_cm() {tone(BUZZER,3000);delay(30);noTone(BUZZER);delay(300);}

void toneDist(int dist_cm){
delay(50);
dist_cm-=8;
int m,dm,cm;
cm=dist_cm%10;
dm=((dist_cm-cm)/10)%10;
m=((dist_cm-cm-dm*10)/100)%10;
for(int i=0;i<m;i++)tone_m();delay(1000);
for(int i=0;i<dm;i++)tone_dm();delay(1000);
for(int i=0;i<cm;i++){tone_cm();}
noTone(BUZZER);
}
