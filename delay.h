// delay.h - Header file for software delay functions

#ifndef DELAY_H
#define DELAY_H

#include "types.h"      // Include user-defined data types (u32)

/*-------------------------------------------------------
 * Function : delay_us()
 * Purpose  : Generates an approximate delay in microseconds.
 * Input    : Time duration in microseconds.
 *------------------------------------------------------*/
void delay_us(u32);

/*-------------------------------------------------------
 * Function : delay_ms()
 * Purpose  : Generates an approximate delay in milliseconds.
 * Input    : Time duration in milliseconds.
 *------------------------------------------------------*/
void delay_ms(u32);

/*-------------------------------------------------------
 * Function : delay_s()
 * Purpose  : Generates an approximate delay in seconds.
 * Input    : Time duration in seconds.
 *------------------------------------------------------*/
void delay_s(u32);

#endif  // End of DELAY_H include guard

