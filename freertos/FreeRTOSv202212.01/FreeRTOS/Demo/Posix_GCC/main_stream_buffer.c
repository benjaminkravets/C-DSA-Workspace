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

static TaskHandle_t task_0_print = NULL;     // print from buffer task handle
static void task_0_main(void *pvParameters); // task main loop

static TaskHandle_t task_1_print = NULL;     // print from buffer task handle
static void task_1_main(void *pvParameters); // task main loop

StreamBufferHandle_t stream_buffer_0;
static const size_t stream_buffer_0_length = 32, stream_buffer_0_trigger = 24;

void main_stream_buffer(void)
{

    BaseType_t task_0_created = xTaskCreate(task_0_main,              // entry function
                                            "Print task",             // debug name
                                            configMINIMAL_STACK_SIZE, // stack size (words)
                                            NULL,                     // parameters to entry function
                                            tskIDLE_PRIORITY + 2,     // priority
                                            &task_0_print);           // task handle
    if (task_0_created != pdPASS)
    {
        printf("Task alloc failed \r\n");
    }

    BaseType_t task_1_created = xTaskCreate(task_1_main,              // entry function
                                            "Print task",             // debug name
                                            configMINIMAL_STACK_SIZE, // stack size (words)
                                            NULL,                     // parameters to entry function
                                            tskIDLE_PRIORITY + 2,     // priority
                                            &task_1_print);           // task handle
    if (task_1_created != pdPASS)
    {
        printf("Task alloc failed \r\n");
    }

    stream_buffer_0 = xStreamBufferCreate(stream_buffer_0_length,   // size in bytes
                                          stream_buffer_0_trigger); // how many bytes need to be in buffer to trigger unblock

    if (stream_buffer_0 == NULL)
    {
        printf("Stream buffer alloc failed \r\n");
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

static void task_0_main(void *pvParameters)
{

    uint8_t buffer_data_tx[32];
    size_t bytes_to_send = 8;

    for (int8_t i = 0; i < sizeof(buffer_data_tx); i++)
    {
        buffer_data_tx[i] = i;
    }

    // every 500 ms, send data from buffer
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(500));

        printf("Sending to stream_buffer_0 \r\n");

        // send using xStreamBufferSend causes seg fault and does not work with triggering level, cause unknown

        size_t bytes_sent = xStreamBufferSendFromISR(stream_buffer_0,
                                                     (void *)buffer_data_tx,
                                                     bytes_to_send,
                                                     pdMS_TO_TICKS(0));
    }
}

static void task_1_main(void *pvParameters)
{
    uint8_t buffer_data_rx[32];
    size_t bytes_to_receive = 32;

    // trigger receive when buffer threshhold is met (16)
    while (1)
    {

        size_t bytes_received = xStreamBufferReceive(stream_buffer_0,
                                                     (void *)buffer_data_rx,
                                                     bytes_to_receive,
                                                     portMAX_DELAY);

        printf("Received by stream_buffer_0: \r\n");

        for (size_t i = 0; i < bytes_received; i++)
        {
            printf("%i ", buffer_data_rx[i]);
        }
        printf("\r\n");
    }
}