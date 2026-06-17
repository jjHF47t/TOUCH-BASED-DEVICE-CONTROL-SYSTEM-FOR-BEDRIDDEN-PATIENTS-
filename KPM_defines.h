// KPM_defines.h - 4x4 Matrix Keypad Pin Definitions

#ifndef KPM_DEFINES_H
#define KPM_DEFINES_H

/*-------------------------------------------------------
 * Keypad Row Pin Definitions
 * These pins are configured as outputs and are used
 * to drive each row of the 4x4 matrix keypad.
 *------------------------------------------------------*/

// Row 0 connected to Port 1, Pin 16 (P1.16)
#define ROW0 16

// Row 1 connected to Port 1, Pin 17 (P1.17)
#define ROW1 17

// Row 2 connected to Port 1, Pin 18 (P1.18)
#define ROW2 18

// Row 3 connected to Port 1, Pin 19 (P1.19)
#define ROW3 19


/*-------------------------------------------------------
 * Keypad Column Pin Definitions
 * These pins are configured as inputs and are used
 * to detect which key has been pressed.
 *------------------------------------------------------*/

// Column 0 connected to Port 1, Pin 20 (P1.20)
#define COL0 20

// Column 1 connected to Port 1, Pin 21 (P1.21)
#define COL1 21

// Column 2 connected to Port 1, Pin 22 (P1.22)
#define COL2 22

// Column 3 connected to Port 1, Pin 23 (P1.23)
#define COL3 23

#endif   // End of KPM_DEFINES_H include guard

