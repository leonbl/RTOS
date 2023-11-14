#include <Arduino.h>
#include <STM32FreeRTOS.h>

uint32_t stevec = 0; 

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  xTaskCreate(nitLed1,NULL,256,NULL,1,NULL);
  xTaskCreate(nitLed2,NULL,256,NULL,1,NULL);
  xTaskCreate(nitLed3,NULL,256,NULL,1,NULL);
  xTaskCreate(nitSerijski,NULL,256,NULL,1,NULL);
  vTaskStartScheduler();
}

void nitLed1(void *args){
  while(1){
    digitalWrite(11, HIGH);
    vTaskDelay(600/portTICK_PERIOD_MS);
    digitalWrite(11, LOW);
    vTaskDelay(600/portTICK_PERIOD_MS);
  }
}

void nitLed2(void *args){
  while(1){
    digitalWrite(12, HIGH);
    vTaskDelay(500/portTICK_PERIOD_MS);
    digitalWrite(12, LOW);
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}

void nitLed3(void *args){
  while(1){
    digitalWrite(13, HIGH);
    vTaskDelay(400/portTICK_PERIOD_MS);
    digitalWrite(13, LOW);
    vTaskDelay(400/portTICK_PERIOD_MS);
  }
}

void nitSerijski(void *args){
  while(1){
    Serial.println(stevec++);
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}

void loop(){}

