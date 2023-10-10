#include <Arduino.h>
int zakasni = 50, stevec = 10;
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  for (stevec = 10; stevec <= 13; stevec++)
  {
    digitalWrite(stevec, LOW);
    delay(zakasni);
    digitalWrite(stevec, HIGH);
  }
  for (stevec = 13; stevec >= 10; stevec--)
  {
    digitalWrite(stevec, LOW);
    delay(zakasni);
    digitalWrite(stevec, HIGH);
  }
}
