#include <Arduino.h>

int n = 0;
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  if (n % 4 == 0)
    digitalWrite(10, !digitalRead(10));
  if (n % 2 == 0)
    digitalWrite(11, !digitalRead(11));
  digitalWrite(12, !digitalRead(12));
  delay(125);
  n++;
}
