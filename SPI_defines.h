/*==================== SPI Pin Definitions ====================*/

// SPI Clock (SCLK) is connected to Port 0, Pin 4 (P0.4)
#define SCLK 4

// SPI Master Input Slave Output (MISO) is connected to P0.5
#define MISO 5

// SPI Master Output Slave Input (MOSI) is connected to P0.6
#define MOSI 6

// Chip Select (CS) signal for the SPI EEPROM is connected to P0.7
#define CS 7


/*==================== Clock Configuration ====================*/

// External oscillator frequency = 12 MHz
#define FOSC 12000000

// CPU Clock (CCLK) = FOSC × 5 = 60 MHz
#define CCLK (FOSC * 5)

// Peripheral Clock (PCLK) = CCLK / 4 = 15 MHz
#define PCLK (CCLK / 4)

// Desired SPI communication speed = 100 kHz
#define SPI_SPEED 100000

// SPI Clock Counter Register value used to generate SPI_SPEED
// LOADVAL = PCLK / SPI_SPEED
#define LOADVAL (PCLK / SPI_SPEED)


/*==================== SPI Control Register Bit Positions ====================*/

// Clock Phase (CPHA) bit position in the SPI Control Register
#define CPHA 3

// Clock Polarity (CPOL) bit position in the SPI Control Register
#define CPOL 4

// Master Mode Select (MSTR) bit position
// Setting this bit configures the LPC214x as SPI Master
#define MSTR 5

// SPI Transfer Complete Flag (SPIF) bit position in the SPI Status Register
// This bit becomes 1 when an SPI transfer is complete
#define SPIF 7


/*==================== SPI EEPROM Command Codes ====================*/

// EEPROM WRITE command (writes data to memory)
#define WRITE 0x02

// EEPROM WRITE ENABLE command (enables write operations)
#define WREN  0x06

// EEPROM WRITE DISABLE command (disables write operations)
#define WRDI  0x04

// EEPROM READ command (reads data from memory)
#define READ  0x03

