#include <Servo.h>
#include <IRremote.h>
int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;
int fan = 7;
int bulb = 8;
int bulb_s = 0;
int fan_s = 0;
Servo s;
void setup()
{
   pinMode(fan, OUTPUT);
   pinMode(bulb, OUTPUT);
   s.attach(9);
   Serial.begin(9600);
   irrecv.enableIRIn();
   digitalWrite(fan, HIGH);
   digitalWrite(bulb, HIGH);
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); 
  if(results.value == 3772829743) 
  {
             s.write(0);
             delay(500);
             s.write(90);
  }
  if(results.value == 3772833823) 
  {
             s.write(180);
             delay(500);
             s.write(90);
  }
  if(results.value == 3772790473) 
  {
        digitalWrite(bulb, LOW);
  }
    if(results.value == 3772786903) 
  {
        digitalWrite(fan, LOW);
  }
    if(results.value == 3772819543) 
  {
        digitalWrite(bulb, HIGH);
  }
    if(results.value == 3772803223) 
  {
        digitalWrite(fan, HIGH);
  }
  }
}
