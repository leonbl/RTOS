#include <Arduino.h>
#include <STM32FreeRTOS.h>

void tA(void *pvParameters);
void tB(void *pvParameters);
SemaphoreHandle_t sem1;
SemaphoreHandle_t sem2;

void vklopiLed(int n){
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(n, HIGH);
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(115200);
  Serial.println("Satrt...");
  sem1 = xSemaphoreCreateMutex();
  xSemaphoreGive(sem1);
  sem2 = xSemaphoreCreateMutex();
  xSemaphoreGive(sem2);
  xTaskCreate(tA, "ta", 128, NULL, 2, NULL);
  xTaskCreate(tB, "ta", 128, NULL, 2, NULL);
  vTaskStartScheduler();
}

void loop() {
}

void tA(void *pvParameters){
  while(1){
    if(xSemaphoreTake(sem1, 10)==pdTRUE){
      xSemaphoreGive(sem1);
      vklopiLed(12);
      vTaskDelay(1000);
      if(xSemaphoreTake(sem2, 10)==pdTRUE){
        Serial.println("task A");
        delay(1000);
        xSemaphoreGive(sem2);
      }
      
    }
  }
}

void tB(void *pvParameters){
  while(1){
    if(xSemaphoreTake(sem2, 10)==pdTRUE){
      xSemaphoreGive(sem2);
      vklopiLed(13);
      vTaskDelay(1000);
      if(xSemaphoreTake(sem1, 10)==pdTRUE){
        Serial.println("task B");
        delay(1000);
        xSemaphoreGive(sem1);
      }
    }
  }
}