#include <stdio.h>
#include <pthread.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "event_groups.h"

/* Local includes. */
#include "console.h"

#define PRINT_FREQUENCY_MS pdMS_TO_TICKS(1000UL) // timer frequency

static TimerHandle_t timer_0_print = NULL;                    // timer handle
static void timer_print_callback(TimerHandle_t timer_handle); // timer callback

static TaskHandle_t task_0_print = NULL;     // print task handle
static void task_0_main(void *pvParameters); // task main loop

static EventGroupHandle_t event_group_0; //event group handle (has 32 bits via configUSE_16_BIT_TICKS)

void main_event_bits(void)
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

    event_group_0 = xEventGroupCreate();

    if (event_group_0 == NULL)
    {
        printf("Event group alloc failed");
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

    xEventGroupSetBits(event_group_0, (1 << 5));
    printf("TImer 0 set event bit 5 \r\n");
}

static void task_0_main(void *pvParameters)
{

    while (1)
    {

        EventBits_t set_bits = xEventGroupWaitBits(event_group_0, (1 << 5), pdTRUE, pdFALSE, portMAX_DELAY);

        printf("Task 0 unblocked on bit 5 set\r\n");
    }
}