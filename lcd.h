#ifndef LCD_H
#define LCD_H

#include "types.h"     // Include user-defined data type definitions (u8, u32, s32, f32, etc.)

/*-------------------------------------------------------
 * Function : WriteLCD()
 * Purpose  : Writes one byte (command or data) to the LCD.
 * Input    : data - 8-bit value to send to the LCD.
 *------------------------------------------------------*/
void WriteLCD(u8 data);

/*-------------------------------------------------------
 * Function : CmdLCD()
 * Purpose  : Sends a command to the LCD instruction register.
 * Input    : cmd - LCD command byte.
 *------------------------------------------------------*/
void CmdLCD(u8 cmd);

/*-------------------------------------------------------
 * Function : CharLCD()
 * Purpose  : Displays a single ASCII character on the LCD.
 * Input    : ascii - Character to display.
 *------------------------------------------------------*/
void CharLCD(u8 ascii);

/*-------------------------------------------------------
 * Function : InitLCD()
 * Purpose  : Initializes the LCD in 8-bit mode and prepares
 *            it for displaying data.
 *------------------------------------------------------*/
void InitLCD(void);

/*-------------------------------------------------------
 * Function : StrLCD()
 * Purpose  : Displays a null-terminated string on the LCD.
 * Input    : str - Pointer to the string.
 *------------------------------------------------------*/
void StrLCD(u8 *str);

/*-------------------------------------------------------
 * Function : U32LCD()
 * Purpose  : Displays an unsigned 32-bit integer.
 * Input    : n - Unsigned integer value.
 *------------------------------------------------------*/
void U32LCD(u32 n);

/*-------------------------------------------------------
 * Function : S32LCD()
 * Purpose  : Displays a signed 32-bit integer.
 * Input    : n - Signed integer value.
 *------------------------------------------------------*/
void S32LCD(s32 n);

/*-------------------------------------------------------
 * Function : BinLCD()
 * Purpose  : Displays a number in binary format.
 * Input    : n   - Number to display.
 *            nbd - Number of bits to display.
 *------------------------------------------------------*/
void BinLCD(u32 n, u8 nbd);

/*-------------------------------------------------------
 * Function : BuildCGRAM()
 * Purpose  : Creates custom characters in the LCD's CGRAM.
 * Input    : p      - Pointer to character pattern data.
 *            nBytes - Number of bytes to write.
 *------------------------------------------------------*/
void BuildCGRAM(u8 *p, u8 nBytes);

/*-------------------------------------------------------
 * Function : f32LCD()
 * Purpose  : Displays a floating-point number.
 * Input    : fnum - Floating-point value.
 *            ndp  - Number of digits after decimal point.
 *------------------------------------------------------*/
void f32LCD(f32 fnum, u8 ndp);

/*-------------------------------------------------------
 * Function : OctLCD()
 * Purpose  : Displays a number in octal format.
 * Input    : n - Unsigned integer value.
 *------------------------------------------------------*/
void OctLCD(u32 n);

/*-------------------------------------------------------
 * Function : HexLCD()
 * Purpose  : Displays a number in hexadecimal format.
 * Input    : n - Unsigned integer value.
 *------------------------------------------------------*/
void HexLCD(u32 n);

/*-------------------------------------------------------
 * Function : ScrollTitle()
 * Purpose  : Scrolls a predefined text message across
 *            the LCD display.
 *------------------------------------------------------*/
void ScrollTitle(void);

#endif   // End of LCD_H include guard

