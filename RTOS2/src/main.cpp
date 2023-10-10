#include <Arduino.h>
int staro_stanje;
int lucka = 10;
void setup()
{
  pinMode(A1, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  int stanje = digitalRead(A1);
  if (staro_stanje == 1 && stanje == 0)
  {
    lucka++;
    if(lucka==10)digitalWrite(13, HIGH);
    digitalWrite(lucka, LOW);
    digitalWrite(lucka-1, HIGH);
    if(lucka>=13) lucka=9;

  }
  delay(100);
  staro_stanje = stanje;
}
