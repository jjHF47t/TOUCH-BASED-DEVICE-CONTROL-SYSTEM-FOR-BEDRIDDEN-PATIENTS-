/*==================== Bit Manipulation Macros ====================*/

// Set (make 1) the bit at position BP in WORD.
// Example: SETBIT(PORT0, 5);  --> Sets bit 5.
#define SETBIT(WORD, BP) (WORD |= (1 << BP))

// Clear (make 0) the bit at position BP in WORD.
// Example: CLRBIT(PORT0, 5); --> Clears bit 5.
#define CLRBIT(WORD, BP) (WORD &= ~(1 << BP))

// Read the status of the bit at position BP.
// Returns 1 if the bit is set, otherwise returns 0.
// Example: STATUSBIT(PORT0, 5)
#define STATUSBIT(WORD, BP) ((WORD >> BP) & 1)

// Write a specific bit value (0 or 1) to bit position BP.
// BIT should be either 0 or 1.
// Example: WRITEBIT(PORT0, 3, 1); --> Sets bit 3.
//          WRITEBIT(PORT0, 3, 0); --> Clears bit 3.
#define WRITEBIT(WORD, BP, BIT) \
    (WORD = ((WORD & ~(1 << BP)) | (BIT << BP)))

// Write a 4-bit nibble into WORD starting at bit position SBP.
// Existing 4 bits at that position are cleared first.
// Example: WRITENIBBLE(REG, 4, 0xA);
#define WRITENIBBLE(WORD, SBP, NIBBLE) \
    (WORD = ((WORD & ~(0xF << SBP)) | (NIBBLE << SBP)))

// Write an 8-bit byte into WORD starting at bit position SBP.
// Existing byte is cleared before writing.
// Example: WRITEBYTE(REG, 8, 0x55);
#define WRITEBYTE(WORD, SBP, BYTE) \
    (WORD = ((WORD & ~(0xFF << SBP)) | (BYTE << SBP)))

// Write a 16-bit half-word into WORD starting at bit position SBP.
// Existing 16 bits are cleared before writing.
// Example: WRITEHWORD(REG, 0, 0x1234);
#define WRITEHWORD(WORD, SBP, HWORD) \
    (WORD = ((WORD & ~(0xFFFF << SBP)) | (HWORD << SBP)))

// Set WORD so that only bit BP is 1 and all other bits are 0.
// Example: SSETBIT(REG, 7); --> REG becomes 0x80.
#define SSETBIT(WORD, BP) (WORD = (1 << BP))

// Set WORD so that only bit BP is 1.
// Note: Despite its name, this macro does NOT clear a bit.
// It is identical to SSETBIT and may be an error in the original code.
// A true clear operation would normally assign 0 or mask the bit.
#define SCLRBIT(WORD, BP) (WORD = (1 << BP))

// Read a 4-bit nibble starting at bit position BP.
// Returns a value between 0 and 15.
// Example: READNIBBLE(REG, 4);
#define READNIBBLE(WORD, BP) ((WORD >> BP) & 0xF)

