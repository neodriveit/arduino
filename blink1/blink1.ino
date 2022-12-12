
#define POT A0
#define LM35 A5
#define BUTT1 A5
#define PIR A5
#define BUZZER 1
int rLed = 13;
int yLed = 12;
int gLed = 11;
int buttonState=0;
int pirState=0;


void setup() {
  
Serial.begin(9600);//Uruchomienie komunikacji przez USART


pinMode(rLed, OUTPUT);
digitalWrite(rLed, LOW); 
pinMode(yLed, OUTPUT);
digitalWrite(yLed, LOW); 
pinMode(gLed, OUTPUT);
digitalWrite(gLed, LOW);   

pinMode(BUTT1, INPUT); 
pinMode(PIR, INPUT); 
digitalWrite(PIR, LOW); 
pinMode(BUZZER, OUTPUT);
pinMode(A0, INPUT);

  
 
  
}

void loop(){ 

  pirState = digitalRead(PIR);
  if(pirState==HIGH) {
    digitalWrite(gLed, HIGH);
    delay(1000);
  }else {
    digitalWrite(gLed, LOW);
    delay(1000);
  }
   
}






void ledy() {
int speed =70;

  digitalWrite(7, HIGH); 
  delay(speed);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(speed);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  delay(speed);
  digitalWrite(5, LOW);  
  digitalWrite(4, HIGH); 
  delay(speed);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  delay(speed);
  digitalWrite(3, LOW);

}


int pot(){


int odP = 0;

  odP = analogRead(A0);//Odczytujemy wartość napięcia
 // Serial.println(odP);//Wysyłamy ją do terminala

if(odP==0){digitalWrite(5, HIGH); delay(333); digitalWrite(5, LOW); delay(333);}
if(odP>0) digitalWrite(5, HIGH); else digitalWrite(5, LOW);
if(odP>=333) digitalWrite(6, HIGH); else digitalWrite(6, LOW);
if(odP>667) digitalWrite(7, HIGH); else digitalWrite(7, LOW);

}


  void temp(){


  //Przeliczenie odczytu ADC na temperaturę zgodnie z opisem z kursu
  float temperatura = ((analogRead(LM35) * 5.0) / 1024.0) * 100;
 
  //Wyslanie przez UART aktualnej temperatury
  Serial.print("Aktualna temperatura: ");
  Serial.print(temperatura);
  Serial.println("*C");
 
  delay(200);
  }

  void irc(){

    
 
  int irc = analogRead(A4);
 
  //Wyslanie przez UART aktualnej temperatury
  Serial.print(irc);
  Serial.print("\n");
  }
 
void buzzer(){
  
  int freq = map(analogRead(POT), 0, 1023, 10, 17000);
  tone(BUZZER, freq);
  
}

void button(){
  


buttonState = digitalRead(BUTT1);
if( buttonState==LOW) {
  
  digitalWrite(rLed, HIGH);
  
}else {
  
  digitalWrite(rLed, LOW);
  
  }
}
