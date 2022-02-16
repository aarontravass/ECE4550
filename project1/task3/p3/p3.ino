#include <Arduino_FreeRTOS.h>

void Task1( void *pvParameters );
void Task2( void *pvParameters );
void Task3( void *pvParameters );

void setup() {
  Serial.begin(9600);
  
  while (!Serial) {
    ; 
  }
  Serial.println("Begin");
 
  xTaskCreate(
    Task1
    ,  "Task1"   
    ,  128  
    ,  NULL
    ,  2  
    ,  NULL );

  xTaskCreate(
    Task2
    ,  "Task2"
    ,  128  // Stack size
    ,  NULL
    ,  3  // Priority
    ,  NULL );

   xTaskCreate(
    Task3
    ,  "Task3"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

}

void loop() {
 

}

void Task1(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  for (;;)
  {
   
    vTaskDelay(2000 / portTICK_PERIOD_MS);  
    Serial.println("Task 1");
  }
}

void Task2(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  for (;;)
  {
  
    vTaskDelay(3000 / portTICK_PERIOD_MS);  
    Serial.println("Task 2");
  }
}

void Task3(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  for (;;)
  {
   
    vTaskDelay(5000 / portTICK_PERIOD_MS);  
    Serial.println("Task 3");
  }
}
