#define receiverpin 1     // pin Arduino, do którego został podłączony odbiornik IR
#include <IRremote.h>       // biblioteka
IRrecv irrecv(receiverpin); 
decode_results results;

void setup()
{
Serial.begin(9600);
   irrecv.enableIRIn(); // uruchamia odbiornik podczerwieni
}

void loop()
{
if (irrecv.decode()) // sprawdza, czy otrzymano sygnał IR
   {
Serial.print(results.value);
      Serial.println(" ");
irrecv.resume(); // odbiera następną wartość
      delay(100);
}

}
