#include <stdio.h>
#include <pthread.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "stream_buffer.h"

/* Local includes. */
#include "console.h"

#define PRINT_FREQUENCY_MS pdMS_TO_TICKS(1000UL) // timer frequency

static TimerHandle_t timer_0_print = NULL;                    // timer handle
static void timer_print_callback(TimerHandle_t timer_handle); // timer callback

static TaskHandle_t task_0_print = NULL;     // print from buffer task handle
static void task_0_main(void *pvParameters); // task main loop

static StreamBufferHandle_t stream_buffer_0;

#define BUFFER_DATA_SIZE 32
static uint8_t buffer_data_tx[BUFFER_DATA_SIZE];
static uint8_t buffer_data_rx[BUFFER_DATA_SIZE];

void main_stream_buffer(void)
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

    stream_buffer_0 = xStreamBufferCreate(32, // size in bytes
                                          1); // how many bytes need to be in buffer to trigger unblock


    if (stream_buffer_0 == NULL)
    {
        printf("Stream buffer alloc failed \r\n");
    }

    for (uint8_t i = 0; i < BUFFER_DATA_SIZE; i++)
    {
        buffer_data_tx[i] = i;
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
    printf("Sending to stream_buffer_0 \r\n");

    size_t bytes_sent = xStreamBufferSend(stream_buffer_0,
                                          buffer_data_tx,
                                          8,
                                          pdMS_TO_TICKS(0));

    printf("Sent %i bytes to stream_buffer_0 \r\n", bytes_sent);
}

static void task_0_main(void *pvParameters)
{

    while (1)
    {

        // uint8_t bytes_received = xStreamBufferReceive(stream_buffer_0,
        //                                               buffer_data_rx,
        //                                               BUFFER_DATA_SIZE,
        //                                               portMAX_DELAY);

        // for (uint8_t i = 0; i < bytes_received; i++)
        // {

        //     printf("%i ", buffer_data_rx[i]);
        // }
    }
}