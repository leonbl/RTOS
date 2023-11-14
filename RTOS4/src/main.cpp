#include <Arduino.h>
#include <STM32FreeRTOS.h>

uint32_t stevec = 0;
void nitLed1(void *args);
void nitLed2(void *args);
void nitLed3(void *args);
void nitSerijski(void *args);

TaskHandle_t led1_h;
TaskHandle_t led2_h;
TaskHandle_t led3_h;
TaskHandle_t ser_h;

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  xTaskCreate(nitLed1, NULL, 256, NULL, 1, &led1_h);
  xTaskCreate(nitLed2, NULL, 256, NULL, 1, &led2_h);
  xTaskCreate(nitLed3, NULL, 256, NULL, 1, &led3_h);
  xTaskCreate(nitSerijski, NULL, 256, NULL, 1, &ser_h);
  vTaskStartScheduler();
}

void nitLed1(void *pvParameters)
{
  while (1)
  {
    digitalWrite(11, HIGH);
    vTaskDelay(600 / portTICK_PERIOD_MS);
    digitalWrite(11, LOW);
    vTaskDelay(600 / portTICK_PERIOD_MS);
  }
}

void nitLed2(void *args)
{
  while (1)
  {
    digitalWrite(12, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(12, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void nitLed3(void *args)
{
  while (1)
  {
    digitalWrite(13, HIGH);
    vTaskDelay(400 / portTICK_PERIOD_MS);
    digitalWrite(13, LOW);
    vTaskDelay(400 / portTICK_PERIOD_MS);
  }
}

void nitSerijski(void *args)
{
  while (1)
  {
    vTaskDelay(500 / portTICK_PERIOD_MS);
    Serial.print(uxTaskGetStackHighWaterMark(led1_h));
    Serial.print(" ");
    Serial.print(uxTaskGetStackHighWaterMark(led2_h));
    Serial.print(" ");
    Serial.print(uxTaskGetStackHighWaterMark(led3_h));
    Serial.print(" ");
    Serial.println(uxTaskGetStackHighWaterMark(0));
  }
}

void loop() {}
