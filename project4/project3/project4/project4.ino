#include "scheduler.h"

TaskHandle_t xHandle1 = NULL;
TaskHandle_t xHandle2 = NULL;

SemaphoreHandle_t xSemaphore = NULL;

static void testFunc1( void *pvParameters )
{
  xSemaphore = xSemaphoreCreateMutex();
  
  Serial.println("t1");
}

static void testFunc2( void *pvParameters )
{
  char c2 = 'b';
  TakeSemaphore( xSemaphore, &c2 );
  
    
  Serial.println("semaphore taken");
   SemaphoreGive( xSemaphore, &c2); // Now free the Serial Port for others.
  
  Serial.println("t2");

}


// the loop function runs over and over again forever

void setup() {
  Serial.begin(38400);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("Serial has started!");

  char c1 = 'a';
  char c2 = 'b';
  char c3 = 'c';
  char c4 = 'd';

  vSchedulerInit();

  vSchedulerPeriodicTaskCreate(testFunc1, "t1", configMINIMAL_STACK_SIZE, &c1, 1, &xHandle1, pdMS_TO_TICKS(0), pdMS_TO_TICKS(400), pdMS_TO_TICKS(100), pdMS_TO_TICKS(400),&xSemaphore );
  vSchedulerPeriodicTaskCreate(testFunc2, "t2", configMINIMAL_STACK_SIZE, &c2, 2, &xHandle2, pdMS_TO_TICKS(50), pdMS_TO_TICKS(200), pdMS_TO_TICKS(150), pdMS_TO_TICKS(500), &xSemaphore);
  

  vSchedulerStart();

  /* If all is well, the scheduler will now be running, and the following line
    will never be reached. */
  Serial.println("reaches here");
  for ( ;; );

}

void loop() {

}
