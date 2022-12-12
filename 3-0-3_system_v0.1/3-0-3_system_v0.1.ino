void setup() {

pinMode(13,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);

pinMode(9,INPUT_PULLUP);
pinMode(10,INPUT_PULLUP);
pinMode(11,INPUT_PULLUP);
pinMode(12,INPUT_PULLUP);
}

void loop() {
  
 if(digitalRead(12)==HIGH) 
  {
    digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    
    digitalWrite(13,HIGH);
  }else
  {
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    
    digitalWrite(13,LOW);
  }
  
    
 if(digitalRead(9)==HIGH) 
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    
    digitalWrite(13,HIGH);
  }else
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    
    digitalWrite(13,LOW);
  }
  
}
