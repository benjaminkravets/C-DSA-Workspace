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
static void task_0_main(void *pvParameters);    // task main loop

void main_dtn(void)
{

    timer_0_print = xTimerCreate("Print Timer",         // friendly debug name
                                 PRINT_FREQUENCY_MS,    // frequency of timer callback
                                 pdTRUE,                // automatically reload
                                 NULL,                  // timer ID (not used)
                                 timer_print_callback); // callback function

    if (timer_0_print != NULL)
    {
        xTimerStart(timer_0_print, 0);
    }
    else
    {
        printf("Timer alloc failed \r\n");
    }

    BaseType_t task_created = xTaskCreate(task_0_main,              // entry function
                                          "Print task",             // debug name
                                          configMINIMAL_STACK_SIZE, // stack size (words)
                                          NULL,                     // parameters to entry function
                                          tskIDLE_PRIORITY + 1,     // priority
                                          &task_0_print);           // task handle
    if (task_created != pdPASS)
    {
        printf("Task alloc failed \r\n");
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
    static uint32_t notification_value = 0;

    if (xTaskNotify(task_0_print, notification_value, eSetBits) == pdPASS)
    {
        printf("Notified task 0 \r\n");
    }
    else
    {
        printf("Could not notify task 0");
    }
    notification_value += 1;
}

static void task_0_main(void *pvParameters)
{
    uint32_t task_0_notification_value;

    while (1)
    {

        xTaskNotifyWait(0x00,
                        ULONG_MAX,
                        &task_0_notification_value,
                        portMAX_DELAY);

        vTaskDelay(PRINT_FREQUENCY_MS);
        printf("Task 0 received: %i \r\n", task_0_notification_value);
    }
}
