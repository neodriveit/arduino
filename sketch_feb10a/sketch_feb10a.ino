#include <RC5.h>
#define rLed 13
#define yLed 12
#define gLed 11
#define IR 1

RC5 rc5(IR);
byte address; 
byte command;
byte toggle;

void setup() {

  Serial.begin(9600);
  pinMode(rLed, OUTPUT);
  pinMode(yLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  digitalWrite(rLed, LOW);
  digitalWrite(yLed, LOW);
  digitalWrite(gLed, LOW);

  Serial.println("Zainicjowano");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rLed, HIGH);

 

    //Jeśli odebrano komendę
  if (rc5.read(&toggle, &address, &command))
  {
    Serial.print("A:");
    Serial.print(address);
    Serial.print(" K:");
    Serial.print(command);
    Serial.print(" T:");
    Serial.println(toggle);
  }
  
}
