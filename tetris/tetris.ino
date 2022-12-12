#include <LedControl.h>
LedControl lc=LedControl(12,11,10,1);
int speed = 200;
int speedkey = 140;
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

byte dot[2] = {B01100000,B01000000};
int row = 7;
unsigned long czas = millis();
byte matrix[8];
int brick[2] = B11;

void loop() {
  matrix[7]=B00000000;
  int m = 0;
  for(m=0;m<8;m++) lc.setColumn(0,m,matrix[m]);
  lc.setColumn(0,row,dot[0]);
  lc.setColumn(0,row-1,dot[1]);
  if(digitalRead(A0)==HIGH) 
  {
    if(!(dot[0]&B00000001==B00000001||dot[1]&B00000001==B00000001))
    {
    dot[0]>>=1;
    dot[1]>>=1;
    lc.setColumn(0,row,dot[0]);
    lc.setColumn(0,row-1,dot[1]);
    delay(speedkey);
    }//if(bits)
  }//if(A0)

if(digitalRead(A2)==HIGH) 
  {
    {
    dot[0]<<=1;
    dot[1]<<=1;
    lc.setColumn(0,row,dot[0]);
    lc.setColumn(0,row-1,dot[1]);
    delay(speedkey);
    }
  }//if(A2)


if(digitalRead(A1)==HIGH) 
{
  
}//if(A1)

/*
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
    delay(speed);
  }//if(row<0)
}
*/
}//loop
