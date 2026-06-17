// KPM.h - Header file for 4x4 Matrix Keypad functions

#ifndef KPM_H
#define KPM_H

#include "types.h"     // Include user-defined data types (u8, u32, etc.)

/*-------------------------------------------------------
 * Function : InitKPM()
 * Purpose  : Initializes the keypad by configuring
 *            the row pins as outputs.
 *------------------------------------------------------*/
void InitKPM(void);

/*-------------------------------------------------------
 * Function : ColScan()
 * Purpose  : Checks whether any key is pressed by
 *            scanning the keypad columns.
 * Returns  : 0 -> Key pressed
 *            1 -> No key pressed
 *------------------------------------------------------*/
u8 ColScan(void);

/*-------------------------------------------------------
 * Function : RowCheck()
 * Purpose  : Determines the row number of the pressed key.
 * Returns  : Row index (0 to 3).
 *------------------------------------------------------*/
u8 RowCheck(void);

/*-------------------------------------------------------
 * Function : ColCheck()
 * Purpose  : Determines the column number of the pressed key.
 * Returns  : Column index (0 to 3).
 *------------------------------------------------------*/
u8 ColCheck(void);

/*-------------------------------------------------------
 * Function : KeyScan()
 * Purpose  : Scans the keypad and returns the ASCII value
 *            of the key that was pressed.
 * Returns  : Pressed key character (e.g., '1', '5', '+', 'C').
 *------------------------------------------------------*/
u8 KeyScan(void);

/*-------------------------------------------------------
 * Function : ReadNum()
 * Purpose  : Reads a multi-digit number entered through
 *            the keypad until the confirmation key ('C')
 *            is pressed.
 * Returns  : Unsigned integer entered by the user.
 *------------------------------------------------------*/
u32 ReadNum(void);

#endif   // End of KPM_H include guard

