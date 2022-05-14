#include "scheduler.h"

TaskHandle_t xHandle1 = NULL;
TaskHandle_t xHandle2 = NULL;
TaskHandle_t xHandle3 = NULL;



static void testFunc1( void *pvParameters )
{
  
  (void) pvParameters;
  int i, a;
  for ( i = 0; i < 10000; i++ )
  {
    a = 1 + i * a;
  }
  vTaskDelay(pdMS_TO_TICKS(3000));
  //Serial.println("Running task t1");
  
}

static void testFunc2( void *pvParameters )
{

  (void) pvParameters;
  int i, a;
  for (i = 0; i < 10000; i++ )
  {
    a = 1 +  i * a * a * a;
  }
  vTaskDelay(pdMS_TO_TICKS(2680));
  //Serial.println("Running task t2");
  

}

static void testFunc3( void *pvParameters )
{
  //Serial.println("t3");
  (void) pvParameters;
  int i, a = 0;
  for (i = 0; i < 10000; i++ )
  {
    a = 1 + i;
  }
  vTaskDelay(pdMS_TO_TICKS(2000));
  //Serial.println("Running task t3");
}





// the loop function runs over and over again forever

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("Serial has started!");
  char c1 = 'a';
  char c2 = 'b';
  char c3 = 'c';

  vSchedulerInit();
                                                                                                            //          T                C                 D
  vSchedulerPeriodicTaskCreate(testFunc1, "t1", configMINIMAL_STACK_SIZE, &c1, 1, &xHandle1, pdMS_TO_TICKS(0), pdMS_TO_TICKS(7800), pdMS_TO_TICKS(3000), pdMS_TO_TICKS(7800));
  vSchedulerPeriodicTaskCreate(testFunc2, "t2", configMINIMAL_STACK_SIZE, &c2, 2, &xHandle2, pdMS_TO_TICKS(50), pdMS_TO_TICKS(5560), pdMS_TO_TICKS(2680), pdMS_TO_TICKS(2000));
  vSchedulerPeriodicTaskCreate(testFunc3, "t3", configMINIMAL_STACK_SIZE, &c3, 3, &xHandle3, pdMS_TO_TICKS(0), pdMS_TO_TICKS(7560), pdMS_TO_TICKS(2000), pdMS_TO_TICKS(7560));
  
  vSchedulerStart();

  /* If all is well, the scheduler will now be running, and the following line
    will never be reached. */
  Serial.println("reaches here");
  for ( ;; );

}

void loop() {

}
