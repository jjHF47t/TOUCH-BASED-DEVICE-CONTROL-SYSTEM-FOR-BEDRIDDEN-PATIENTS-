#include "types.h"      // Include user-defined data type definitions (e.g., u32)

/*---------------------------------------------------------
 * Function : delay_us()
 * Purpose  : Generate an approximate delay in microseconds
 * Input    : tdly - Delay time in microseconds
 *--------------------------------------------------------*/
void delay_us(u32 tdly)
{
    // Multiply by 12 to approximate a 1-microsecond delay
    // (depends on processor clock frequency and compiler optimization)
    tdly *= 12;

    // Busy-wait loop until the counter reaches zero
    while (tdly--);
}


/*---------------------------------------------------------
 * Function : delay_ms()
 * Purpose  : Generate an approximate delay in milliseconds
 * Input    : tdly - Delay time in milliseconds
 *--------------------------------------------------------*/
void delay_ms(u32 tdly)
{
    // Multiply by 12000 to convert milliseconds into loop iterations
    // (based on an assumed CPU clock frequency)
    tdly *= 12000;

    // Busy-wait loop until the counter reaches zero
    while (tdly--);
}


/*---------------------------------------------------------
 * Function : delay_s()
 * Purpose  : Generate an approximate delay in seconds
 * Input    : tdly - Delay time in seconds
 *--------------------------------------------------------*/
void delay_s(u32 tdly)
{
    // Multiply by 12,000,000 to convert seconds into loop iterations
    // (assuming approximately 12 MHz execution rate)
    tdly *= 12000000;

    // Busy-wait loop until the counter reaches zero
    while (tdly--);
}

