int rf=2,rb=3,lf=4,lb=5,rs=9,ls=10; //engines control pins

int angle360=3800,
    angle180=1900,
    angle90=950,
    angle45=475;

int ec = 10;
void setup() {

pinMode(rf,OUTPUT);
pinMode(rb,OUTPUT);
pinMode(lf,OUTPUT);
pinMode(lb,OUTPUT);
pinMode(rs,OUTPUT);
pinMode(ls,OUTPUT);

digitalWrite(rf,LOW);
digitalWrite(rb,LOW);
digitalWrite(lf,LOW);
digitalWrite(lb,LOW);

stopEngines();delay(3000);
}

void loop() {
forward(150);delay(1);

/*rotateRight(angle45);

forward(150);delay(2000);
rotateLeft(angle90);
forward(150);delay(4000);
rotateRight(angle90);
forward(150);delay(2000);
rotateLeft(angle90);
forward(150);delay(2000);
rotateLeft(angle90);
forward(150);delay(2000);
rotateLeft(angle90);
forward(150);delay(4000);
rotateRight(angle90);
forward(150);delay(4000);
rotateLeft(angle90);
forward(150);delay(2000);
rotateLeft(angle90+angle45);delay(2000);
rotateRight(angle360);
stopEngines();delay(100000);

forward(150);delay(3000);
rotateRight(1900); 

forward(150);delay(3000);
rotateLeft(1900); 

forward(150);delay(3000);
rotateLeft(950); 
forward(150);delay(3000);
rotateLeft(950); 
forward(150);delay(3000);
rotateLeft(1900); forward(150);delay(3000);
rotateLeft(950); 

int turnDelay = 1000;
turnLeftForward();delay(turnDelay);
turnRightForward();delay(turnDelay);
turnLeftForward();delay(turnDelay);
turnRightForward();delay(turnDelay);
turnLeftForward();delay(turnDelay);
turnRightForward();delay(turnDelay);
turnLeftForward();delay(turnDelay);
turnRightForward();delay(turnDelay);


turnLeftBackward();delay(turnDelay);
turnRightBackward();delay(turnDelay);
turnLeftBackward();delay(turnDelay);
turnRightBackward();delay(turnDelay);
turnLeftBackward();delay(turnDelay);
turnRightBackward();delay(turnDelay);
turnLeftBackward();delay(turnDelay);
turnRightBackward();delay(turnDelay);

stopEngines();delay(3000);

stopEngines();delay(2000);
forward();delay(1500);
rotateRight();delay(2000);
forward();delay(1500);
rotateRight();delay(2000);
stopEngines();delay(2000);
backward();delay(1500);
rotateLeft();delay(2000);
backward();delay(1500);
rotateLeft();delay(2000);
*/
}
 
void forward(int speed){
clearEnginesStates();
digitalWrite(rf,HIGH);analogWrite(rs,speed + ec);
digitalWrite(lf,HIGH);analogWrite(ls,speed);
}

void backward(){
clearEnginesStates();
digitalWrite(rb,HIGH);
digitalWrite(lb,HIGH);
}

void rotateRight(int time){
clearEnginesStates();
digitalWrite(rf,HIGH);analogWrite(rs,255);
digitalWrite(lb,HIGH);analogWrite(ls,255);
delay(time);
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
digitalWrite(rf,LOW);
digitalWrite(lf,LOW);
digitalWrite(rb,LOW);
digitalWrite(lb,LOW);
}

void stopEngines(){
digitalWrite(rf,LOW);
digitalWrite(lf,LOW);
digitalWrite(rb,LOW);
digitalWrite(lb,LOW);
}
