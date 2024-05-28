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

StreamBufferHandle_t stream_buffer_0;
static size_t stream_buffer_0_length = 4, stream_buffer_0_trigger = 4;

#define BUFFER_DATA_SIZE 4
//static uint8_t buffer_data_tx[BUFFER_DATA_SIZE];
static uint8_t buffer_data_rx[BUFFER_DATA_SIZE];

void vAFunction( StreamBufferHandle_t xStreamBuffer );


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

    stream_buffer_0 = xStreamBufferCreate(stream_buffer_0_length,   // size in bytes
                                          stream_buffer_0_trigger); // how many bytes need to be in buffer to trigger unblock

    if (stream_buffer_0 == NULL)
    {
        printf("Stream buffer alloc failed \r\n");
    }

    // for (uint8_t i = 0; i < BUFFER_DATA_SIZE; i++)
    // {
    //     buffer_data_tx[i] = i;
    // }

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
    // uint8_t buffer_data_tx[] = {1,2,3,4};
    // size_t bytes_to_send = 1;
    

    // printf("Sending to stream_buffer_0 \r\n");
    vAFunction(stream_buffer_0);

    // size_t bytes_sent = xStreamBufferSend(stream_buffer_0,
    //                                       (void*)buffer_data_tx,
    //                                       bytes_to_send,
    //                                       pdMS_TO_TICKS(100));

    // printf("Sent %li bytes to stream_buffer_0 \r\n", bytes_sent);
}

static void task_0_main(void *pvParameters)
{
    uint8_t rx_data[32];
    uint8_t bytes_received;

    while (1)
    {

        // bytes_received = xStreamBufferReceive(stream_buffer_0,
        //                                               rx_data,
        //                                               sizeof(rx_data),
        //                                               portMAX_DELAY);

        // printf("Received %i bytes \r\n", bytes_received);

        // for (uint8_t i = 0; i < bytes_received; i++)
        // {
        //     printf("%i ", buffer_data_rx[i]);
        // }
    }
}

void vAFunction( StreamBufferHandle_t xStreamBuffer )
{
size_t xBytesSent;
uint8_t ucArrayToSend[] = { 0, 1, 2, 3 };
char *pcStringToSend = "String to send";
const TickType_t x100ms = pdMS_TO_TICKS( 100 );

    /* Send an array to the stream buffer, blocking for a maximum of 100ms to
    wait for enough space to be available in the stream buffer. */
    xBytesSent = xStreamBufferSend( xStreamBuffer,
                                   ( void * ) ucArrayToSend,
                                   sizeof( ucArrayToSend ),
                                   x100ms );

    if( xBytesSent != sizeof( ucArrayToSend ) )
    {
        /* The call to xStreamBufferSend() times out before there was enough
        space in the buffer for the data to be written, but it did
        successfully write xBytesSent bytes. */
    }

    /* Send the string to the stream buffer.  Return immediately if there is not
    enough space in the buffer. */
    xBytesSent = xStreamBufferSend( xStreamBuffer,
                                    ( void * ) pcStringToSend,
                                    strlen( pcStringToSend ), 0 );

    if( xBytesSent != strlen( pcStringToSend ) )
    {
        /* The entire string could not be added to the stream buffer because
        there was not enough free space in the buffer, but xBytesSent bytes
        were sent.  Could try again to send the remaining bytes. */
    }
}