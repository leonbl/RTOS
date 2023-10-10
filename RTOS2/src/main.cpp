#include <Arduino.h>
int staro_stanje;
void setup()
{
  pinMode(A1, INPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  int stanje = digitalRead(A1);
  if (staro_stanje == 1 && stanje == 0)
  {
    digitalWrite(10, !digitalRead(10));
  }
  staro_stanje = stanje;
}
