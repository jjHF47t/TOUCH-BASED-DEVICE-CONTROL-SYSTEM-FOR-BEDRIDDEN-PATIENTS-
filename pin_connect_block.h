#ifndef PIN_CONNECT_BLOCK_H
#define PIN_CONNECT_BLOCK_H

/*-------------------------------------------------------
 * Function : cfgportpinfunc()
 * Purpose  : Configures the function of a specified pin
 *            on the LPC21xx microcontroller.
 *
 * Parameters:
 *   PortNo - Port number (e.g., 0 for Port 0)
 *   PinNo  - Pin number within the selected port
 *   fn     - Function selection for the pin:
 *            0 = GPIO function
 *            1 = Alternate Function 1
 *            2 = Alternate Function 2
 *            3 = Alternate Function 3
 *
 * Example:
 *   cfgportpinfunc(0, 4, 1);
 *   // Configures P0.4 for its Alternate Function 1 (SPI SCLK)
 *------------------------------------------------------*/
void cfgportpinfunc(int PortNo, int PinNo, int fn);

#endif  // End of PIN_CONNECT_BLOCK_H

