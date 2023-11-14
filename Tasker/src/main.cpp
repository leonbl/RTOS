#include <Arduino.h>
#include"Tasker.h"
Tasker task;
void led1();
void led2();
void led3();


void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  task.setInterval(led1,500);
  task.setInterval(led2,100);
  task.setInterval(led3,55);
}

void led1(){
  digitalWrite(10, !digitalRead(10));
}
void led2(){
  digitalWrite(11, !digitalRead(11));
}
void led3(){
  digitalWrite(12, !digitalRead(12));
}

void loop() {
  task.loop();
}

