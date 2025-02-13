// ascii code
// control characters 0-31 plus 127
// printable characters 32-126
const static byte font_data_11x6[] = {
  0b010101,
  0b101010,
  0b010101,
  0b101010,
  0b010101,
  0b101010,
  0b010101,
  0b101010,
  0b010101,
  0b101010,
  0b010101,
  // 0x00 (checker 0) (was ascii nul)
  0b101010,
  0b010101,
  0b101010,
  0b010101,
  0b101010,
  0b010101,
  0b101010,
  0b010101,
  0b101010,
  0b010101,
  0b101010,
  // 0x01 (checker 1) (was ascii soh)
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b001000,
  0b000000,
  0b001000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  // 0x02 (time left :) (was ascii stx)
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000100,
  0b000000,
  0b000100,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  // 0x03 (time right :) (was ascii etx)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, // 0x04 // placeholders - as not used
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, // 0x05 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, // 0x06 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, // 0x07 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, // 0x08 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, // 0x09 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, // 0x0A 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, // 0x0B 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, // 0x0C 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, // 0x0D 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, // 0x0E 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, // 0x0F 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, // 0x10 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, // 0x11 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, // 0x12 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, // 0x13 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, // 0x14 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, // 0x15
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, // 0x16 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, // 0x17 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, // 0x18 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, // 0x19 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1A, // 0x1A 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, // 0x1B 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, // 0x1C 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1D, // 0x1D 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, // 0x1E 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, // 0x1F 
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  // 0x00, 0x00, 0x00, 0x00, 0x00, // 0x20 space
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000000,
  0b000100,
  //0x00, 0x00, 0x5F, 0x00, 0x00,  // 0x21 !
  0b010010,
  0b010010,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  //0x00, 0x07, 0x00, 0x07, 0x00,  // 0x22 "
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, // 0x23 #  // placeholders - not used
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, // 0x24 $
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, // 0x25 %
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, // 0x26 &
  0b000010,
  0b000100,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  //0x00, 0x08, 0x07, 0x03, 0x00, // 0x27 '
  0b000100,
  0b001000,
  0b010000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b010000,
  0b001000,
  0b000100,
  // 0x00, 0x1C, 0x22, 0x41, 0x00, // 0x28 (
  0b001000,
  0b000100,
  0b000010,
  0b000001,
  0b000001,
  0b000001,
  0b000001,
  0b000001,
  0b000010,
  0b000100,
  0b001000,
  //0x00, 0x41, 0x22, 0x1C, 0x00, // 0x29 )
  0b000000,
  0b000000,
  0b000100,
  0b010101,
  0b001110,
  0b011111,
  0b001110,
  0b010101,
  0b000100,
  0b000000,
  0b000000,
  // 0x2A, 0x1C, 0x7F, 0x1C, 0x2A, // 0x2A *
  0b000000,
  0b000000,
  0b000000,
  0b000100,
  0b000100,
  0b011111,
  0b000100,
  0b000100,
  0b000000,
  0b000000,
  0b000000,
  //0x08, 0x08, 0x3E, 0x08, 0x08, // 0x2B +
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000100,
  0b001000,
  //0x00, 0x40, 0x20, 0x00, 0x00,  // 0x2C ,
  //0x00, 0x80, 0x70, 0x30, 0x00,  // 0x2C alt , font
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b011110,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  //0x00, 0x08, 0x08, 0x08, 0x00, // 0x2D -
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000100,
  //0x00, 0x00, 0x40, 0x00, 0x00,  // 0x2E .
  //0x00, 0x00, 0x60, 0x60, 0x00,  // 0x2E alt . font
  0b000001,
  0b000010,
  0b000010,
  0b000100,
  0b000100,
  0b001000,
  0b001000,
  0b010000,
  0b010000,
  0b100000,
  0b100000,
  //0x20, 0x10, 0x08, 0x04, 0x02,  // 0x2F / forward slash
  0b011110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b011110,
  //0x3E, 0x41, 0x41, 0x41, 0x3E,  // 0x30 0
  //0x3E, 0x51, 0x49, 0x45, 0x3E,  // 0x30 alt 0 font
  0b000100,
  0b001100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b001110,
  // 0x00, 0x42, 0x7F, 0x40, 0x00,  // 0x31 1
  0b011110,
  0b100001,
  0b000001,
  0b000001,
  0b000001,
  0b000010,
  0b000100,
  0b001000,
  0b010000,
  0b100000,
  0b111111,
  //0x42, 0x61, 0x51, 0x49, 0x46,  // 0x32 2
  0b011110,
  0b100001,
  0b000001,
  0b000001,
  0b000001,
  0b000110,
  0b000001,
  0b000001,
  0b000001,
  0b100001,
  0b011110,
  //0x22, 0x41, 0x49, 0x49, 0x36,  // 0x33 3
  //0x21, 0x41, 0x49, 0x4D, 0x33,  // 0x33 alt 3 font
  0b000010,
  0b000110,
  0b001010,
  0b010010,
  0b100010,
  0b100010,
  0b111111,
  0b000010,
  0b000010,
  0b000010,
  0b000010,
  //0x18, 0x14, 0x12, 0x7F, 0x10,  // 0x34 4
  0b111111,
  0b100000,
  0b100000,
  0b100000,
  0b111110,
  0b000001,
  0b000001,
  0b000001,
  0b000001,
  0b100001,
  0b011110,
  //0x27, 0x45, 0x45, 0x45, 0x39,  // 0x35 5
  0b011110,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b111110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b011110,
  //0x3C, 0x4A, 0x49, 0x49, 0x30,  // 0x36 6
  0b111111,
  0b000001,
  0b000001,
  0b000010,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  //0x01, 0x01, 0x79, 0x05, 0x03,  // 0x37 7
  0b011110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b011110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b011110,
  //0x36, 0x49, 0x49, 0x49, 0x36,  // 0x38 8
  0b011110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b011110,
  0b000001,
  0b000001,
  0b000001,
  0b000001,
  0b011110,
  //0x06, 0x49, 0x49, 0x29, 0x1E,  // 0x39 9
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000100,
  0b000000,
  0b000100,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  //0x00, 0x00, 0x14, 0x00, 0x00,  // 0x3A :
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000100,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000100,
  0b001000,
  //0x00, 0x40, 0x24, 0x00, 0x00,  // 0x3B ;
  0b000000,
  0b000000,
  0b000100,
  0b001000,
  0b010000,
  0b100000,
  0b010000,
  0b001000,
  0b000100,
  0b000000,
  0b000000,
  //0x00, 0x08, 0x14, 0x22, 0x41,  // 0x3C <
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b011110,
  0b000000,
  0b011110,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  //0x00, 0x14, 0x14, 0x14, 0x00,  // 0x3D =
  0b000000,
  0b000000,
  0b001000,
  0b000100,
  0b000010,
  0b000001,
  0b000010,
  0b000100,
  0b001000,
  0b000000,
  0b000000,
  //0x00, 0x41, 0x22, 0x14, 0x08,  // 0x3E >
  0b011110,
  0b100001,
  0b000001,
  0b000001,
  0b000010,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  //0x02, 0x01, 0x59, 0x09, 0x06,  // 0x3F ?
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, // 0x40 @ // placeholder - not used
  0b001100,
  0b010010,
  0b100001,
  0b100001,
  0b100001,
  0b111111,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  //0x7C, 0x12, 0x11, 0x12, 0x7C,  // 0x41 A
  0b111110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b111110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b111110,
  //0x7F, 0x49, 0x49, 0x49, 0x36,  // 0x42 B
  0b011110,
  0b100001,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100001,
  0b011110,
  //0x3E, 0x41, 0x41, 0x41, 0x22,  // 0x43 C
  0b111110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b111110,
  //0x7F, 0x41, 0x41, 0x41, 0x3E,  // 0x44 D
  0b111111,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b111000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b111111,
  //0x7F, 0x49, 0x49, 0x49, 0x41,  // 0x45 E
  0b111111,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b111000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  //0x7F, 0x09, 0x09, 0x09, 0x01,  // 0x46 F
  0b011110,
  0b100001,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100011,
  0b100001,
  0b100001,
  0b100001,
  0b011110,
  //0x3E, 0x41, 0x41, 0x51, 0x73,  // 0x47 G
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b111111,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  //0x7F, 0x08, 0x08, 0x08, 0x7F,  // 0x48 H
  0b001110,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b001110,
  //0x00, 0x41, 0x7F, 0x41, 0x00,  // 0x49 I
  0b000111,
  0b000010,
  0b000010,
  0b000010,
  0b000010,
  0b000010,
  0b000010,
  0b000010,
  0b100010,
  0b100010,
  0b011100,
  //0x20, 0x40, 0x41, 0x3F, 0x01,  // 0x4A J
  0b100001,
  0b100010,
  0b100100,
  0b101000,
  0b110000,
  0b110000,
  0b110000,
  0b101000,
  0b100100,
  0b100010,
  0b100001,
  //0x7F, 0x08, 0x14, 0x22, 0x41,  // 0x4B K
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b111111,
  //0x7F, 0x40, 0x40, 0x40, 0x40,  // 0x4C L
  0b100001,
  0b100001,
  0b110011,
  0b101101,
  0b101101,
  0b100001,
  0b100000,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  //0x7F, 0x02, 0x1C, 0x02, 0x7F,  // 0x4D M
  0b100001,
  0b100001,
  0b110001,
  0b101001,
  0b101001,
  0b101101,
  0b100101,
  0b100101,
  0b100011,
  0b100001,
  0b100001,
  //0x7F, 0x04, 0x08, 0x10, 0x7F,  // 0x4E N
  0b011110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b011110,  
  //0x3E, 0x41, 0x41, 0x41, 0x3E,  // 0x4F O
  0b111110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b111110,
  0b100000,
  0b100000,
  0b100000,
  0b100000,
  0b100000,  
  //0x7F, 0x09, 0x09, 0x09, 0x06,  // 0x50 P
  0b011110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100101,
  0b100010,
  0b011101,  
  //0x3E, 0x41, 0x51, 0x21, 0x5E,  // 0x51 Q
  0b111110,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b111110,
  0b110000,
  0b101000,
  0b100100,
  0b100010,
  0b100001,  
  //0x7F, 0x09, 0x19, 0x29, 0x46,  // 0x52 R
  0b011110,
  0b100001,
  0b100000,
  0b100000,
  0b100000,
  0b011110,
  0b000001,
  0b000001,
  0b000001,
  0b100001,
  0b011110,  
  //0x26, 0x49, 0x49, 0x49, 0x32,  // 0x53 S
  0b011111,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  //0x01, 0x01, 0x7F, 0x01, 0x01,  // 0x54 T
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b011110,
  //0x3F, 0x40, 0x40, 0x40, 0x3F,  // 0x55 U
  0b010001,
  0b010001,
  0b010001,
  0b010001,
  0b010001,
  0b010001,
  0b010001,
  0b010001,
  0b010001,
  0b001010,
  0b000100,
  //0x1F, 0x20, 0x40, 0x20, 0x1F,  // 0x56 V
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b100001,
  0b101101,
  0b101101,
  0b110011,
  0b100001,
  0b100001,
  //0x3F, 0x40, 0x38, 0x40, 0x3F,  // 0x57 W
  0b010001,
  0b010001,
  0b010001,
  0b001010,
  0b000100,
  0b000100,
  0b000100,
  0b001010,
  0b010001,
  0b010001,
  0b010001,
  //0x63, 0x14, 0x08, 0x14, 0x63,  // 0x58 X
  0b010001,
  0b010001,
  0b010001,
  0b001010,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  0b000100,
  //0x03, 0x04, 0x78, 0x04, 0x03,  // 0x59 Y
  0b111111,
  0b000001,
  0b000001,
  0b000001,
  0b000010,
  0b000100,
  0b001000,
  0b010000,
  0b100000,
  0b100000,
  0b111111,
  //0x61, 0x51, 0x49, 0x45, 0x43,  // 0x5A Z 90
  //0x61, 0x59, 0x49, 0x4D, 0x43,  // 0x5A alt Z font
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5B, // 0x5B [ // placeholder - not used
  0b100000,
  0b100000,
  0b010000,
  0b010000,
  0b001000,
  0b001000,
  0b000100,
  0b000100,
  0b000010,
  0b000010,
  0b000001,
  //0x02, 0x04, 0x08, 0x10, 0x20,  // 0x5C back slash
  // (do not use backslash char here as it commented out following line) 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5D,  // 0x5D ]  placeholder - not used
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5E,  // 0x5E ^ 
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b000000,
  0b111111,
  // 0x40, 0x40, 0x40, 0x40, 0x40,  // 0x5F _
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,  // 0x60 ` (grave accent) // - placeholders - not used
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61,  // 0x61 a 97
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62,  // 0x62 b
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63,  // 0x63 c
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64,  // 0x64 d
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x65,  // 0x65 e
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66,  // 0x66 f
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67,  // 0x67 g
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68,  // 0x68 h
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69,  // 0x69 i
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A,  // 0x6A j
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6B,  // 0x6B k
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6C,  // 0x6C l
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6D,  // 0x6D m
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6E,  // 0x6E n
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6F,  // 0x6F o
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70,  // 0x70 p
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71,  // 0x71 q
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72,  // 0x72 r
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73,  // 0x73 s
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74,  // 0x74 t
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75,  // 0x75 u
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76,  // 0x76 v
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77,  // 0x77 w
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78,  // 0x78 x
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79,  // 0x79 y
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7A,  // 0x7A z
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7B,  // 0x7B {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C,  // 0x7C |
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7D,  // 0x7D }
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E};  // 0x7E ~
  // not included 
  // 0x7F (127) would be ascii DEL (delete)
  // 0s80 (128) to 0xFF (255) are extended ascii used in 1981 IBM PC.

void get_char_fd_array_11x6(char char_out)
{
byte char_base_addr;
char_base_addr = byte(char_out);
//columns first, then rows unlike 7x5 font - 11x6 fonts presented differently
  for (int r = 0; r <= 10; r++){
    // (5-c) to feed in other direction from 7x5 font
    for (int c = 0; c <=5; c++){ 
      fd_array_11x6[c][r] = ((font_data_11x6[(char_base_addr * 11) + r]) >> (5-c)) & 0x01; //bitwise and
      }  
  }
}

