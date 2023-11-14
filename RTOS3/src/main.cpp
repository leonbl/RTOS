#include <Arduino.h>
#include <STM32FreeRTOS.h>
void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);
void TaskBlink3(void *pvParameters);

void setup() {
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  xTaskCreate(TaskBlink1, "abc",128,NULL,2,NULL);
  xTaskCreate(TaskBlink2, "abc1",128,NULL,2,NULL);
  xTaskCreate(TaskBlink3, "abc2",128,NULL,2,NULL);
  vTaskStartScheduler();
  while(1);
}

void loop() {
}

void TaskBlink1(void *pvParameters){
  pinMode(10, OUTPUT);
  while(1){
    digitalWrite(10, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(10, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void TaskBlink2(void *pvParameters){
  pinMode(11, OUTPUT);
  while(1){
    digitalWrite(11, HIGH);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(11, LOW);
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void TaskBlink3(void *pvParameters){
  pinMode(12, OUTPUT);
  while(1){
    digitalWrite(12, HIGH);
    vTaskDelay(55 / portTICK_PERIOD_MS);
    digitalWrite(12, LOW);
    vTaskDelay(55 / portTICK_PERIOD_MS);
  }
}