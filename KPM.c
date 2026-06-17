// KPM.c - 4x4 Matrix Keypad Driver

#include "defines.h"        // Bit manipulation macros
#include <LPC21xx.h>        // LPC214x register definitions
#include "types.h"          // User-defined data types
#include "lcd.h"            // LCD functions (optional for displaying keys)
#include "KPM_defines.h"    // Keypad pin definitions

/*-------------------------------------------------------
 * 4x4 Keypad Lookup Table
 * Each row and column combination corresponds to one key.
 *
 *      Col0 Col1 Col2 Col3
 * Row0   1    2    3    +
 * Row1   4    5    6    -
 * Row2   7    8    9    *
 * Row3   C    0    =    /
 *------------------------------------------------------*/
u8 KpmLUT[4][4] =
{
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '*'},
    {'C', '0', '=', '/'}
};


/*-------------------------------------------------------
 * Function : InitKPM()
 * Purpose  : Configure keypad row pins as outputs.
 *------------------------------------------------------*/
void InitKPM(void)
{
    // Configure P1.16 to P1.19 (ROW0 to ROW3) as output pins
    WRITENIBBLE(IODIR1, ROW0, 15);
}


/*-------------------------------------------------------
 * Function : ColScan()
 * Purpose  : Detect whether any key is pressed.
 * Returns  : 0 -> Key pressed
 *            1 -> No key pressed
 *------------------------------------------------------*/
u8 ColScan(void)
{
    // Read all four column pins.
    // If any column becomes LOW, a key is pressed.
    if ((READNIBBLE(IOPIN1, COL0)) < 15)
        return 0;
    else
        return 1;
}


/*-------------------------------------------------------
 * Function : RowCheck()
 * Purpose  : Determine which keypad row contains
 *            the pressed key.
 * Returns  : Row number (0 to 3)
 *------------------------------------------------------*/
u8 RowCheck(void)
{
    u8 rno;

    // Check each row one by one
    for (rno = 0; rno <= 3; rno++)
    {
        // Drive one row LOW while keeping others HIGH
        WRITENIBBLE(IOPIN1, ROW0, ~(1 << rno));

        // If a column becomes active, key is in this row
        if (ColScan() == 0)
        {
            break;
        }
    }

    // Restore all rows to inactive state
    WRITENIBBLE(IOPIN1, ROW0, 0x0);

    // Return detected row number
    return rno;
}


/*-------------------------------------------------------
 * Function : ColCheck()
 * Purpose  : Determine which keypad column contains
 *            the pressed key.
 * Returns  : Column number (0 to 3)
 *------------------------------------------------------*/
u8 ColCheck(void)
{
    u8 cno;

    // Check each column individually
    for (cno = 0; cno <= 3; cno++)
    {
        // Active LOW column indicates pressed key
        if (STATUSBIT(IOPIN1, (COL0 + cno)) == 0)
        {
            break;
        }
    }

    // Return detected column number
    return cno;
}


/*-------------------------------------------------------
 * Function : KeyScan()
 * Purpose  : Detect a key press and return its value.
 * Returns  : ASCII value of the pressed key.
 *------------------------------------------------------*/
u8 KeyScan(void)
{
    u8 keyv;   // Stores final key value
    u8 rno;    // Row number
    u8 cno;    // Column number

    // Wait until any key is pressed
    while (ColScan());

    // Identify the row containing the pressed key
    rno = RowCheck();

    // Identify the column containing the pressed key
    cno = ColCheck();

    // Fetch corresponding character from lookup table
    keyv = KpmLUT[rno][cno];

    // Wait until key is released (debounce handling)
    while (!ColScan());

    // Return detected key
    return keyv;
}


/*-------------------------------------------------------
 * Function : ReadNum()
 * Purpose  : Read a multi-digit number from the keypad.
 *            Numeric keys ('0'–'9') are accepted.
 *            Press 'C' to finish input.
 * Returns  : Unsigned integer entered by the user.
 *------------------------------------------------------*/
u32 ReadNum(void)
{
    u8 key;        // Stores current key
    u32 sum = 0;   // Accumulates entered number

    while (1)
    {
        // Read one key from keypad
        key = KeyScan();

        // Check if key is a digit
        if ((key >= '0') && (key <= '9'))
        {
            // Build decimal number:
            // Example: 1 -> 12 -> 123
            sum = (sum * 10) + (key - '0');
        }

        // Stop reading when 'C' (confirm) is pressed
        else if (key == 'C')
        {
            break;
        }
    }

    // Return the entered number
    return sum;
}

