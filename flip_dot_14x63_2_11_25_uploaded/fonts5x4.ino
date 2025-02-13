// ascii code
// only 0-9 / \ ( ) + = < > * checkers clock tick : " , ' - only 
const static byte font_data_5x4[] = {
  0b1010,
  0b0101,
  0b1010,
  0b0101,
  0b1010,
  // 0x00 (checker 0) (was ascii nul)
  0b0101,
  0b1010,
  0b0101,
  0b1010,
  0b0101,
  // 0x01 (checker 1) (was ascii soh)
  0b0000,
  0b0100,
  0b0000,
  0b0100,
  0b0000,
  // 0x02 (time left :) (was ascii stx)
  0b0000,
  0b0010,
  0b0000,
  0b0010,
  0b0000,
  // 0x03 (time right :) (was ascii etx)
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x04 // placeholders - as not used
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x05 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x06 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x07 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x08 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x09 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x0A 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x0B 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x0C 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x0D 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x0E 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x0F 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x10 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x11 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x12 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x13 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x14 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x15
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x16 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x17 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x18 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x19 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x1A 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x1B 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x1C 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x1D 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x1E 
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x1F 
  0b0000,
  0b0000,
  0b0000,
  0b0000,
  0b0000,
  // 0x00, 0x00, 0x00, 0x00, 0x00, // 0x20 space
  0b0010,
  0b0010,
  0b0010,
  0b0000,
  0b0010,
  //0x00, 0x00, 0x5F, 0x00, 0x00,  // 0x21 !
  0b0101,
  0b0101,
  0b0000,
  0b0000,
  0b0000,
  //0x00, 0x07, 0x00, 0x07, 0x00,  // 0x22 "
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x23 #  // placeholders - not used
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x24 $
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x25 %
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x26 &
  0b0010,
  0b0100,
  0b0000,
  0b0000,
  0b0000,
  //0x00, 0x08, 0x07, 0x03, 0x00, // 0x27 '
  0b0010,
  0b0100,
  0b1000,
  0b0100,
  0b0010,
  // 0x00, 0x1C, 0x22, 0x41, 0x00, // 0x28 (
  0b0100,
  0b0010,
  0b0001,
  0b0010,
  0b0100,
  //0x00, 0x41, 0x22, 0x1C, 0x00, // 0x29 )
  0b0000,
  0b0110,
  0b1111,
  0b0110,
  0b0000,
  // 0x2A, 0x1C, 0x7F, 0x1C, 0x2A, // 0x2A *
  0b0000,
  0b0010,
  0b0111,
  0b0010,
  0b0000,
  //0x08, 0x08, 0x3E, 0x08, 0x08, // 0x2B +
  0b0000,
  0b0000,
  0b0000,
  0b0010,
  0b0100,
  //0x00, 0x40, 0x20, 0x00, 0x00,  // 0x2C ,
  //0x00, 0x80, 0x70, 0x30, 0x00,  // 0x2C alt , font
  0b0000,
  0b0000,
  0b0110,
  0b0000,
  0b0000,
  //0x00, 0x08, 0x08, 0x08, 0x00, // 0x2D -
  0b0000,
  0b0000,
  0b0000,
  0b0000,
  0b0010,
  //0x00, 0x00, 0x40, 0x00, 0x00,  // 0x2E .
  //0x00, 0x00, 0x60, 0x60, 0x00,  // 0x2E alt . font
  0b0001,
  0b0010,
  0b0010,
  0b0100,
  0b1000,
  //0x20, 0x10, 0x08, 0x04, 0x02,  // 0x2F / forward slash
  0b0110,
  0b1001,
  0b1001,
  0b1001,
  0b0110,
  //0x3E, 0x41, 0x41, 0x41, 0x3E,  // 0x30 0
  //0x3E, 0x51, 0x49, 0x45, 0x3E,  // 0x30 alt 0 font
  0b0010,
  0b0110,
  0b0010,
  0b0010,
  0b0111,
  // 0x00, 0x42, 0x7F, 0x40, 0x00,  // 0x31 1
  0b1110,
  0b0001,
  0b0110,
  0b1000,
  0b1111,
  //0x42, 0x61, 0x51, 0x49, 0x46,  // 0x32 2
  0b1110,
  0b0001,
  0b0110,
  0b0001,
  0b1110,
  //0x22, 0x41, 0x49, 0x49, 0x36,  // 0x33 3
  //0x21, 0x41, 0x49, 0x4D, 0x33,  // 0x33 alt 3 font
  0b0010,
  0b0110,
  0b1010,
  0b1111,
  0b0010,
  //0x18, 0x14, 0x12, 0x7F, 0x10,  // 0x34 4
  0b1111,
  0b1000,
  0b1110,
  0b0001,
  0b1110,
  //0x27, 0x45, 0x45, 0x45, 0x39,  // 0x35 5
  0b0110,
  0b1000,
  0b1110,
  0b1001,
  0b0110,
  //0x3C, 0x4A, 0x49, 0x49, 0x30,  // 0x36 6
  0b1111,
  0b0001,
  0b0010,
  0b0100,
  0b0100,
  //0x01, 0x01, 0x79, 0x05, 0x03,  // 0x37 7
  0b0110,
  0b1001,
  0b0110,
  0b1001,
  0b0110,
  //0x36, 0x49, 0x49, 0x49, 0x36,  // 0x38 8
  0b0110,
  0b1001,
  0b0110,
  0b0001,
  0b0110,
  //0x06, 0x49, 0x49, 0x29, 0x1E,  // 0x39 9
  0b0000,
  0b0010,
  0b0000,
  0b0010,
  0b0000,
  //0x00, 0x00, 0x14, 0x00, 0x00,  // 0x3A :
  0b0000,
  0b0010,
  0b0000,
  0b0010,
  0b0100,
  //0x00, 0x40, 0x24, 0x00, 0x00,  // 0x3B ;
  0b0010,
  0b0100,
  0b1000,
  0b0100,
  0b0010,
  //0x00, 0x08, 0x14, 0x22, 0x41,  // 0x3C <
  0b0000,
  0b0110,
  0b0000,
  0b0110,
  0b0000,
  //0x00, 0x14, 0x14, 0x14, 0x00,  // 0x3D =
  0b0100,
  0b0010,
  0b0001,
  0b0010,
  0b0100,
  //0x00, 0x41, 0x22, 0x14, 0x08,  // 0x3E >
  0b0110,
  0b1001,
  0b0010,
  0b0000,
  0b0010,
  //0x02, 0x01, 0x59, 0x09, 0x06,  // 0x3F ?
  0x00, 0x00, 0x00, 0x00, 0x00, // 0x40 @ // placeholder - not used
  // 5x5 caps below not used - just placeholders for now
  0b00100,
  0b01010,
  0b11111,
  0b10001,
  0b10001,
  //0x7C, 0x12, 0x11, 0x12, 0x7C,  // 0x41 A
  0b11110,
  0b10001,
  0b11110,
  0b10001,
  0b11110,
  //0x7F, 0x49, 0x49, 0x49, 0x36,  // 0x42 B
  0b01111,
  0b10000,
  0b10000,
  0b10000,
  0b01111,
  //0x3E, 0x41, 0x41, 0x41, 0x22,  // 0x43 C
  0b11110,
  0b10001,
  0b10001,
  0b10001,
  0b11110,
  //0x7F, 0x41, 0x41, 0x41, 0x3E,  // 0x44 D
  0b11111,
  0b10000,
  0b11100,
  0b10000,
  0b11111,
  //0x7F, 0x49, 0x49, 0x49, 0x41,  // 0x45 E
  0b11111,
  0b10000,
  0b11100,
  0b10000,
  0b10000,
  //0x7F, 0x09, 0x09, 0x09, 0x01,  // 0x46 F
  0b01111,
  0b10000,
  0b10011,
  0b10001,
  0b01110,
  //0x3E, 0x41, 0x41, 0x51, 0x73,  // 0x47 G
  0b10001,
  0b10001,
  0b11111,
  0b10001,
  0b10001,
  //0x7F, 0x08, 0x08, 0x08, 0x7F,  // 0x48 H
  0b01110,
  0b00100,
  0b00100,
  0b00100,
  0b01110,
  //0x00, 0x41, 0x7F, 0x41, 0x00,  // 0x49 I
  0b00111,
  0b00010,
  0b00010,
  0b10010,
  0b01100,
  //0x20, 0x40, 0x41, 0x3F, 0x01,  // 0x4A J
  0b10010,
  0b10100,
  0b11000,
  0b10100,
  0b10010,
  //0x7F, 0x08, 0x14, 0x22, 0x41,  // 0x4B K
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b11111,
  //0x7F, 0x40, 0x40, 0x40, 0x40,  // 0x4C L
  0b10001,
  0b11011,
  0b10101,
  0b10001,
  0b10001,
  //0x7F, 0x02, 0x1C, 0x02, 0x7F,  // 0x4D M
  0b10001,
  0b11001,
  0b10101,
  0b10011,
  0b10001,
  //0x7F, 0x04, 0x08, 0x10, 0x7F,  // 0x4E N
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b01110,  
  //0x3E, 0x41, 0x41, 0x41, 0x3E,  // 0x4F O
  0b11110,
  0b10001,
  0b11110,
  0b10000,
  0b10000,  
  //0x7F, 0x09, 0x09, 0x09, 0x06,  // 0x50 P
  0b01110,
  0b10001,
  0b10001,
  0b10010,
  0b01101,  
  //0x3E, 0x41, 0x51, 0x21, 0x5E,  // 0x51 Q
  0b11110,
  0b10001,
  0b11110,
  0b10010,
  0b10001,  
  //0x7F, 0x09, 0x19, 0x29, 0x46,  // 0x52 R
  0b01111,
  0b10000,
  0b01110,
  0b00001,
  0b11110,  
  //0x26, 0x49, 0x49, 0x49, 0x32,  // 0x53 S
  0b11111,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  //0x01, 0x01, 0x7F, 0x01, 0x01,  // 0x54 T
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b01110,
  //0x3F, 0x40, 0x40, 0x40, 0x3F,  // 0x55 U
  0b10001,
  0b10001,
  0b10001,
  0b01010,
  0b00100,
  //0x1F, 0x20, 0x40, 0x20, 0x1F,  // 0x56 V
  0b10001,
  0b10001,
  0b10101,
  0b10101,
  0b01010,
  //0x3F, 0x40, 0x38, 0x40, 0x3F,  // 0x57 W
  0b10001,
  0b01010,
  0b00100,
  0b01010,
  0b10001,
  //0x63, 0x14, 0x08, 0x14, 0x63,  // 0x58 X
  0b10001,
  0b01010,
  0b00100,
  0b00100,
  0b00100,
  //0x03, 0x04, 0x78, 0x04, 0x03,  // 0x59 Y
  0b11111,
  0b00010,
  0b00100,
  0b01000,
  0b11111,
  //0x61, 0x51, 0x49, 0x45, 0x43,  // 0x5A Z 90
  //0x61, 0x59, 0x49, 0x4D, 0x43,  // 0x5A alt Z font
  0x00, 0x00, 0x00, 0x00, 0x00,    // 0x5B [ // placeholder - not used
  0b1000,
  0b0100,
  0b0100,
  0b0010,
  0b0001,
  //0x02, 0x04, 0x08, 0x10, 0x20,  // 0x5C back slash
  // (do not use backslash char here as it commented out following line) 
  0x00, 0x00, 0x00, 0x00, 0x00,  // 0x5D ]  placeholder - not used
  0x00, 0x00, 0x00, 0x00, 0x00,  // 0x5E ^ 
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  // 0x40, 0x40, 0x40, 0x40, 0x40,  // 0x5F _
  0x00, 0x00, 0x00, 0x00, 0x00 // 0x60 ` (grave accent) // - placeholder - not used
  // not included lower case letters
  // 0x7F (127) would be ascii DEL (delete)
  // 0s80 (128) to 0xFF (255) are extended ascii used in 1981 IBM PC.
  };

void get_char_fd_array_5x4(char char_out)
{
byte char_base_addr;
char_base_addr = byte(char_out);
//columns first, then rows unlike 7x5 font - 7x5 and 5x4 fonts presented differently
  for (int r = 0; r <= 4; r++){
    // (3-c) to feed in other direction from 7x5 font
    for (int c = 0; c <=3; c++){ 
      fd_array_5x4[c][r] = ((font_data_5x4[(char_base_addr * 5) + r]) >> (3-c)) & 0x01; //bitwise and
      }  
  }
}

void displayCharacter_5x4(int charNum, char charOut)
{
// for 5x4 font
int dotInput;
get_char_fd_array_5x4(charOut); // populates fd_array 5x4 with charOut
// display font
for (int columnInput = 0; columnInput <= 3; columnInput++){ // font is 5 by 4
  for (int rowInput = 0; rowInput <= 4; rowInput++){
    dotInput = fd_array_5x4[columnInput][rowInput]; // get dot value
    // 1 space between chars.  Also start at column 2 and row 5
    setCell(columnInput + 2 + (charNum * (4+1)), (rowInput + 5), dotInput); // adjust columns by charNum
    }  
  }
return;
}

void displayCharacter_5x4s(int charNum, char charOut, int columnStart)
{
// for 5x4 font sideways (up to 3 characters on a 14 row high display)
int dotInput;
get_char_fd_array_5x4(charOut); // populates fd_array 5x4 with charOut
// display font
// start at row 13 (column 13) and go up display after 3 char to row 0 (column 0)
for (int columnInput = 13; columnInput >= 10; columnInput--){ // font is 5 by 4
  for (int rowInput = 0; rowInput <= 4; rowInput++){
    dotInput = fd_array_5x4[13 - columnInput][rowInput]; // get dot value
    // 1 space between chars.  columnstart is offset from left of display
    //void setCell(int column, int row, int dot) - for ref
    setCell(rowInput + columnStart, columnInput - (charNum * (4+1)), dotInput); // adjust rows by charNum
    }  
  }
return;
}


