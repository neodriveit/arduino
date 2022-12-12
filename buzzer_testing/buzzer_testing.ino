#define BUZZER 11

void setup() {
pinMode(BUZZER,OUTPUT);
double startTone = 1100;
for(int i=0;i<6;i++){
tone(BUZZER,startTone);
delay(50);
startTone+=100;
}//for
noTone(BUZZER);

delay(3000);
for(int i=0;i<6;i++){
tone(BUZZER,startTone);
delay(50);
startTone-=100;
}//for
noTone(BUZZER);
}


void loop() {

}
