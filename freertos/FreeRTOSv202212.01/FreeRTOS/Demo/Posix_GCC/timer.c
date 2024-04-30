#include <stdio.h>
#include <pthread.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

/* Local includes. */
#include "console.h"

#define PRINT_FREQUENCY_MS pdMS_TO_TICKS(1000UL)

static TimerHandle_t print_timer = NULL;
static void timer_print_callback(TimerHandle_t );

void main_timer(void)
{

/*     
    print_timer = xTimerCreate("Print Timer",      // friendly debug name
                               PRINT_FREQUENCY_MS, // frequency of timer callback
                               pdTRUE,
                               NULL,
                               )
 */
    vTaskStartScheduler();

    /* If all is well, the scheduler will now be running, and the following
     * line will never be reached.  If the following line does execute, then
     * there was insufficient FreeRTOS heap memory available for the idle and/or
     * timer tasks	to be created.  See the memory management section on the
     * FreeRTOS web site for more details. */
    for (;;)
    {
    }
    
}
/*-----------------------------------------------------------*/
