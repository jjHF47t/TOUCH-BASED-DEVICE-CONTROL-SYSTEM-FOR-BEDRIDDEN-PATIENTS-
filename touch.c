#include <LPC21xx.h>          // LPC214x microcontroller register definitions
#include <string.h>           // Standard string manipulation functions

#include "touch.h"            // Touch panel function declarations
#include "lcd.h"              // LCD driver functions
#include "uart.h"             // UART communication functions
#include "delay.h"            // Delay functions

/*--------------- Global variables declared in main_project.c ---------------*/

// UART receive buffer containing touch panel data
extern char str[23];

// Buffers used to store extracted X, Y, and Z coordinate strings
extern char x_buf[10], y_buf[10], z_buf[10];

// UART receive buffer index
extern unsigned int i;

// Flag indicating that a complete UART string has been received
extern unsigned int r_flag;

// System ON/OFF control flag
extern int enable;

// Buzzer ON/OFF status
extern int buzzer;

// Fan ON/OFF status
extern int d1;

// Light ON/OFF status
extern int d2;

// Previous touch X-coordinate
extern int prev_x;

// Previous touch Y-coordinate
extern int prev_y;

// Flag indicating whether the current touch has already been processed
extern int touch_processed;


/*---------------------- Touch Processing Function ----------------------*/

void Touch_Process(void)
{
    int j, k;                 // Loop variables

    // Variables to store converted X, Y, and Z coordinates
    int xint, yint, zint;

    // Clear receive flag before waiting for new touch data
    r_flag = 0;

    // Reset UART receive buffer index
    i = 0;

    // Wait until UART ISR receives a complete touch packet
    while (r_flag == 0);

    // Small delay for stable data reception
    delay_s(1);

    /*--------------- Extract X coordinate string ---------------*/

    // Copy X value from received UART string
    for (j = 0; j < 6; j++)
        x_buf[j] = str[j];

    // Append string terminator
    x_buf[j] = '\0';


    /*--------------- Extract Y coordinate string ---------------*/

    // Copy Y value from received UART string
    for (k = 0, j = 8; j < 13; j++, k++)
        y_buf[k] = str[j];

    // Append string terminator
    y_buf[k] = '\0';


    /*--------------- Extract Z coordinate string ---------------*/

    // Copy Z value from received UART string
    for (k = 0, j = 15; j < 20; j++, k++)
        z_buf[k] = str[j];

    // Append string terminator
    z_buf[k] = '\0';

    // Clear receive flag for next UART packet
    r_flag = 0;

    // Reset receive index
    i = 0;


    /*--------------- Convert ASCII digits to integers ---------------*/

    // Convert X coordinate from ASCII characters to integer
    xint = ((x_buf[4] - 48) * 10 + (x_buf[5] - 48));

    // Convert Y coordinate from ASCII characters to integer
    yint = ((y_buf[3] - 48) * 10 + (y_buf[4] - 48));

    // Convert pressure (Z coordinate) from ASCII characters to integer
    zint = ((z_buf[3] - 48) * 10 + (z_buf[4] - 48));


    /*--------------- Touch Edge Detection ---------------*/

    // Process only when finger is touching the panel
    if (zint < 15)
    {
        // Check whether this is a new touch position
        if (prev_x != xint || prev_y != yint)
        {
            // Store current touch coordinates
            prev_x = xint;
            prev_y = yint;

            // Mark touch as pending for processing
            touch_processed = 1;
        }
    }


    /*--------------- Process each touch only once ---------------*/

    if (touch_processed == 1)
    {
        // Prevent repeated processing of same touch
        touch_processed = 0;

        /*--------------- Zone 1 : System Enable/Disable ---------------*/

        // Upper-left region toggles overall control enable
        if ((xint < 11) && (yint >= 14))
        {
            // Toggle enable flag
            enable ^= 1;
        }

        /*--------------- Zone 2 : Buzzer Control ---------------*/

        // Upper-right region toggles buzzer
        else if ((xint > 11) && (yint >= 14))
        {
            // Operate only if system is enabled
            if (enable)
            {
                // Toggle buzzer state
                buzzer ^= 1;

                if (buzzer)
                    // Turn ON buzzer connected to P0.25
                    IOSET0 = (1 << 25);
                else
                    // Turn OFF buzzer
                    IOCLR0 = (1 << 25);
            }
        }

        /*--------------- Zone 3 : Fan ON ---------------*/

        // Middle-left region turns fan ON
        else if ((xint < 11) && (yint < 14 && yint >= 8))
        {
            if (enable)
            {
                // Update fan status
                d1 = 1;

                // Set P0.23 HIGH
                IOSET0 = (1 << 23);
            }
        }

        /*--------------- Zone 3 : Fan OFF ---------------*/

        // Middle-right region turns fan OFF
        else if ((xint > 11) && (yint < 14 && yint >= 8))
        {
            if (enable)
            {
                // Update fan status
                d1 = 0;

                // Clear P0.23
                IOCLR0 = (1 << 23);
            }
        }

        /*--------------- Zone 4 : Light ON ---------------*/

        // Bottom-left region turns light ON
        else if ((xint < 11) && (yint < 8))
        {
            if (enable)
            {
                // Update light status
                d2 = 1;

                // Set P0.22 HIGH
                IOSET0 = (1 << 22);
            }
        }

        /*--------------- Zone 4 : Light OFF ---------------*/

        // Bottom-right region turns light OFF
        else if ((xint > 11) && (yint < 8))
        {
            if (enable)
            {
                // Update light status
                d2 = 0;

                // Clear P0.22
                IOCLR0 = (1 << 22);
            }
        }
    }


    /*--------------- Reset when touch is released ---------------*/

    // If finger is removed from touch panel
    if (zint >= 15)
    {
        // Reset previous touch coordinates
        prev_x = -1;
        prev_y = -1;

        // Allow next touch to be processed
        touch_processed = 0;
    }


    /*--------------- Update LCD Status Display ---------------*/

    // Clear LCD screen
    CmdLCD(0x01);

    // Display system control status
    if (enable)
        StrLCD("Control: ON");
    else
        StrLCD("Control: OFF");

    // Move to second line
    CmdLCD(0xC0);

    // Display buzzer status
    if (buzzer)
        StrLCD("Buzzer: ON");
    else
        StrLCD("Buzzer: OFF");

    // Move to third line
    CmdLCD(0x94);

    // Display fan status
    if (d1)
        StrLCD("Fan: ON");
    else
        StrLCD("Fan: OFF");

    // Move to fourth line
    CmdLCD(0xD4);

    // Display light status
    if (d2)
        StrLCD("Light: ON");
    else
        StrLCD("Light: OFF");
}

