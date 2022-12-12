 #include <LedControl.h>
LedControl lc=LedControl(12,11,10,1);
int speed = 200;
void setup() {  
  /*
  The MAX72XX is in power-saving mode on startup,
  we have to do a wakeup call
  */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,0);
  /* and clear the display */
  lc.clearDisplay(0);

  pinMode(A0,INPUT);  
  pinMode(A1,INPUT);  
  pinMode(A2,INPUT);
}

byte dot = B00010000;
int row = 7;
unsigned long czas = millis();
byte matrix[8];

void loop() {
  matrix[7]=B00000000;
  int m = 0;
  for(m=0;m<8;m++) lc.setColumn(0,m,matrix[m]);
  if(digitalRead(A0)==HIGH) 
  {
    dot>>=1;
    if(dot==B00000000) dot = B00000001;
    lc.setColumn(0,row,dot);
    delay(speed);
  }
  
  lc.setColumn(0,row,dot);

if(digitalRead(A2)==HIGH) 
  {
    dot<<=1;
    if(dot==B00000000) dot = B10000000;
    lc.setColumn(0,row,dot);
    delay(speed);
  }
  
  lc.setColumn(0,row,dot);

if(digitalRead(A1)==HIGH) 
{
  
  lc.setColumn(0,row,B00000000);
  row--; if(row<0) row = 0;
  lc.setColumn(0,row,dot);
  delay(speed);
}

if(!(dot&matrix[row])==B00000000) 
{
  matrix[row+1] += dot;
  row=7;
}
if(millis()-czas>speed) 
{
  lc.setColumn(0,row,B00000000);
  czas=millis();
  row--; 
  if(row<0)
  {
    matrix[0] += dot;
    if(matrix[0]==B11111111)
    {
      int b;
      for(b=4;b>=0;b--)
      {
      lc.setColumn(0,0,B00000000);
      delay(50);
      lc.setColumn(0,0,B11111111);
      delay(50);
      }//for(b)
      int z;
      for(z=0;z<8;z++)
      {
        if(z>row) matrix[z]=matrix[z+1];
        matrix[7]=B00000000;
      }//for(z)
    }//if(matrix==B11111111) 
    for(m=0;m<8;m++) lc.setColumn(0,m,matrix[m]);
    row=7;
    lc.setColumn(0,row,dot);
    delay(speed*2);
  }//if(row<0)
}

}//loop
