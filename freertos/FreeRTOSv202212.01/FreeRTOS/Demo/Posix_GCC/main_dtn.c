#include <stdio.h>
#include <pthread.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

/* Local includes. */
#include "console.h"

#define PRINT_FREQUENCY_MS pdMS_TO_TICKS(1000UL) // timer frequency

static TimerHandle_t timer_0_print = NULL;                    // timer handle
static void timer_print_callback(TimerHandle_t timer_handle); // timer callback

static TaskHandle_t task_0_print = NULL; // print task handle
void task_0_main(void *pvParameters);    // task main loop

void main_dtn(void)
{

    timer_0_print = xTimerCreate("Print Timer",         // friendly debug name
                                 PRINT_FREQUENCY_MS,    // frequency of timer callback
                                 pdTRUE,                // automatically reload
                                 NULL,                  // timer ID (not used)
                                 timer_print_callback); // callback function
    
    task_0_print = xTaskCreate(task_0_main,
                                "Print task",
                                configMINIMAL_STACK_SIZE,
                                NULL,
                                tskIDLE_PRIORITY + 1,
                                task_0_print
                                );

    if (timer_0_print != NULL)
    {
        xTimerStart(timer_0_print, 0);
    }

    vTaskStartScheduler();

    /* If all is well, the scheduler will now be running, and the following
     * line will never be reached.  If the following line does execute, then
     * there was insufficient FreeRTOS heap memory available for the idle and/or
     * timer tasks	to be created. */
    for (;;)
    {
    }
}

static void timer_print_callback(TimerHandle_t timer_handle)
{
    //printf("Timer called \r\n");
    xTaskNotify(task_0_print, 1, );
}

void task_0_main(void *pvParameters)
{

    while (1)
    {
        vTaskDelay(PRINT_FREQUENCY_MS);
        printf("Task continued \r\n");
    }
}
