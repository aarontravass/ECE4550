#include <Arduino_FreeRTOS.h>

void Task1( void *pvParameters );
void Task2( void *pvParameters );
void Task3( void *pvParameters );

void setup() {
  // put your setup code here, to run once:
// initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }

  // Now set up two tasks to run independently.
  xTaskCreate(
    Task1
    ,  "Task1"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
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
  // put your main code here, to run repeatedly:

}

void Task1(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  for (;;)
  {
    // read the input on analog pin 0:
    vTaskDelay(2000 / portTICK_PERIOD_MS);  
    Serial.println("Task 1");
  }
}

void Task2(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  for (;;)
  {
    // read the input on analog pin 0:
    vTaskDelay(3000 / portTICK_PERIOD_MS);  
    Serial.println("Task 2");
  }
}

void Task3(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  for (;;)
  {
    // read the input on analog pin 0:
    vTaskDelay(5000 / portTICK_PERIOD_MS);  
    Serial.println("Task 3");
  }
}
