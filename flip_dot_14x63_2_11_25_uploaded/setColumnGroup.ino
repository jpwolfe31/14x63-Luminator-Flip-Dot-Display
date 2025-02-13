// setColumnGroup functions for interfacing with MCP23017 and Display

// Cx_Source 15V and Rx 0v - dot flips yellow
// Cx_Sink 0V and Rx 15V - dot flips black
// Off is no output to column or row
// Rx controls pulse length of 500us
// yellow is 11 turn off row source (active low) and on sink (active high)
// black is 00 turn on row source (active low) and off sink (active high)
// off is 10 turn off row source (active low) and sink ( active high)

// a bit faster for some operations - mostly blanking and filling by columns

void setColumnGroup(int column, int rowStates)
{
int mcpRowOutput[4] = {0, 0, 0, 0};  // array for holding desired outputs
// turn off mcps
mcpOff();
// create mcpOutput for rows (will then be used with column source and then column sink)
// to turn on and off groups of 4 rows
//rows 0-3
if (findBit(rowStates, 0) == 1){ // 1 is yellow, 0 is black
    mcpRowOutput[0] = mcpRowOutput[0] | 0b10101011;  // initalizes byte and turns on row sink
    }
    else mcpRowOutput[0] = mcpRowOutput[0] & 0b10101000;  // initalizes byte and turns on row source
if (findBit(rowStates, 1) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[0] = mcpRowOutput[0] | 0b00001100;  // turns on row sink
  }
  else mcpRowOutput[0] = mcpRowOutput[0] & 0b11110011;  // turns on row source
if (findBit(rowStates, 2) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[0] = mcpRowOutput[0] | 0b00110000;  // turns on row sink
  }
  else mcpRowOutput[0] = mcpRowOutput[0] & 0b11001111;  // turns on row source
if (findBit(rowStates, 3) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[0] = mcpRowOutput[0] | 0b11000000;  // turns on row sink
  }
  else mcpRowOutput[0] = mcpRowOutput[0] & 0b00111111;  // turns on row source 
//rows 4-6
if (findBit(rowStates, 4) == 1){ // 1 is yellow, 0 is black
    mcpRowOutput[1] = mcpRowOutput[1] | 0b10101011;  // initalizes byte and turns on row sink
    }
    else mcpRowOutput[1] = mcpRowOutput[1] & 0b10101000;  // initalizes byte and turns on row source
if (findBit(rowStates, 5) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[1] = mcpRowOutput[1] | 0b00001100;  // turns on row sink
  }
  else mcpRowOutput[1] = mcpRowOutput[1] & 0b11110011;  // turns on row source
if (findBit(rowStates, 6) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[1] = mcpRowOutput[1] | 0b00110000;  // turns on row sink
  }
  else mcpRowOutput[1] = mcpRowOutput[1] & 0b11001111;  // turns on row source
// rows 7-10
if (findBit(rowStates, 7) == 1){ // 1 is yellow, 0 is black
    mcpRowOutput[2] = mcpRowOutput[2] | 0b10101011;  // initalizes byte and turns on row sink
    }
    else mcpRowOutput[2] = mcpRowOutput[2] & 0b10101000;  // initalizes byte and turns on row source
if (findBit(rowStates, 8) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[2] = mcpRowOutput[2] | 0b00001100;  // turns on row sink
  }
  else mcpRowOutput[2] = mcpRowOutput[2] & 0b11110011;  // turns on row source
if (findBit(rowStates, 9) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[2] = mcpRowOutput[2] | 0b00110000;  // turns on row sink
  }
  else mcpRowOutput[2] = mcpRowOutput[2] & 0b11001111;  // turns on row source
if (findBit(rowStates, 10) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[2] = mcpRowOutput[2] | 0b11000000;  // turns on row sink
  }
  else mcpRowOutput[2] = mcpRowOutput[2] & 0b00111111;  // turns on row source 
// rows 11-13
if (findBit(rowStates, 11) == 1){ // 1 is yellow, 0 is black
    mcpRowOutput[3] = mcpRowOutput[3] | 0b10101011;  // initalizes byte and turns on row sink
    }
    else mcpRowOutput[3] = mcpRowOutput[3] & 0b10101000;  // initalizes byte and turns on row source
if (findBit(rowStates, 12) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[3] = mcpRowOutput[3] | 0b00001100;  // turns on row sink
  }
  else mcpRowOutput[3] = mcpRowOutput[3] & 0b11110011;  // turns on row source
if (findBit(rowStates, 13) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[3] = mcpRowOutput[3] | 0b00110000;  // turns on row sink
  }
  else mcpRowOutput[3] = mcpRowOutput[3] & 0b11001111;  // turns on row source

// select column high
switch (column) {
  case 0: {col0y(); break;} // turn on column source and sink off
  case 1: {col1y(); break;} 
  case 2: {col2y(); break;} 
  case 3: {col3y(); break;} 
  case 4: {col4y(); break;} 
  case 5: {col5y(); break;} 
  case 6: {col6y(); break;} 
  case 7: {col7y(); break;} 
  case 8: {col8y(); break;} 
  case 9: {col9y(); break;} 
  case 10: {col10y(); break;} 
  case 11: {col11y(); break;} 
  case 12: {col12y(); break;} 
  case 13: {col13y(); break;} 
  case 14: {col14y(); break;} 
  case 15: {col15y(); break;} 
  case 16: {col16y(); break;} 
  case 17: {col17y(); break;} 
  case 18: {col18y(); break;} 
  case 19: {col19y(); break;} 
  case 20: {col20y(); break;} 
  case 21: {col21y(); break;}
  case 22: {col22y(); break;} 
  case 23: {col23y(); break;} 
  case 24: {col24y(); break;} 
  case 25: {col25y(); break;} 
  case 26: {col26y(); break;} 
  case 27: {col27y(); break;} 
  case 28: {col28y(); break;} 
  case 29: {col29y(); break;} 
  case 30: {col30y(); break;} 
  case 31: {col31y(); break;} 
  case 32: {col32y(); break;} 
  case 33: {col33y(); break;} 
  case 34: {col34y(); break;} 
  case 35: {col35y(); break;} 
  case 36: {col36y(); break;} 
  case 37: {col37y(); break;} 
  case 38: {col38y(); break;} 
  case 39: {col39y(); break;} 
  case 40: {col40y(); break;} 
  case 41: {col41y(); break;} 
  case 42: {col42y(); break;}
  case 43: {col43y(); break;} 
  case 44: {col44y(); break;} 
  case 45: {col45y(); break;} 
  case 46: {col46y(); break;} 
  case 47: {col47y(); break;} 
  case 48: {col48y(); break;} 
  case 49: {col49y(); break;} 
  case 50: {col50y(); break;} 
  case 51: {col51y(); break;} 
  case 52: {col52y(); break;} 
  case 53: {col53y(); break;} 
  case 54: {col54y(); break;} 
  case 55: {col55y(); break;} 
  case 56: {col56y(); break;} 
  case 57: {col57y(); break;} 
  case 58: {col58y(); break;} 
  case 59: {col59y(); break;} 
  case 60: {col60y(); break;} 
  case 61: {col61y(); break;} 
  case 62: {col62y(); break;} 
  default: {break;}
  }

// note - balances all offs and ons to be approximately 1200us

// turn on rows 0-3  each tranmission takes 350us
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(mcpRowOutput[0]);
i2c1.endTransmission(); //ends communication with slave device
delayMicroseconds(400);  // default is 200us
// turn on rows 4-6
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(mcpRowOutput[1]);
i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(cgdel);  // note not used anymore *****
// turn off rows 0-3 
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
// rows 0-3 pulse 200us plus 350us plus 200us plus 350 for 1100us total
// turn on rows 7-10
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(mcpRowOutput[2]);
i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(cgdel);
// turn off rows 4-6
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
// rows 4-6 pulse 200us plus 350us plus 350us plus 200us plus 350us for 1450us total
// turn on rows 11-13
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(mcpRowOutput[3]);
i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(cgdel);
// turn off rows 7-10
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
// rows 7-10 pulse 200us plus 350us plus 350us plus 200us plus 350us for 1450us total
delayMicroseconds(400);  // adjustment for no turn on
// turn off rows 11-13
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
// rows 11-13 pulse 200us plus 350us plus 200us plus 350us for 1100us total

// select column low
switch (column) {
  case 0: {col0b(); break;} // turn on column source and sink off
  case 1: {col1b(); break;} 
  case 2: {col2b(); break;} 
  case 3: {col3b(); break;} 
  case 4: {col4b(); break;} 
  case 5: {col5b(); break;} 
  case 6: {col6b(); break;} 
  case 7: {col7b(); break;} 
  case 8: {col8b(); break;} 
  case 9: {col9b(); break;} 
  case 10: {col10b(); break;} 
  case 11: {col11b(); break;} 
  case 12: {col12b(); break;} 
  case 13: {col13b(); break;} 
  case 14: {col14b(); break;} 
  case 15: {col15b(); break;} 
  case 16: {col16b(); break;} 
  case 17: {col17b(); break;} 
  case 18: {col18b(); break;} 
  case 19: {col19b(); break;} 
  case 20: {col20b(); break;} 
  case 21: {col21b(); break;}
  case 22: {col22b(); break;} 
  case 23: {col23b(); break;} 
  case 24: {col24b(); break;} 
  case 25: {col25b(); break;} 
  case 26: {col26b(); break;} 
  case 27: {col27b(); break;} 
  case 28: {col28b(); break;} 
  case 29: {col29b(); break;} 
  case 30: {col30b(); break;} 
  case 31: {col31b(); break;} 
  case 32: {col32b(); break;} 
  case 33: {col33b(); break;} 
  case 34: {col34b(); break;} 
  case 35: {col35b(); break;} 
  case 36: {col36b(); break;} 
  case 37: {col37b(); break;} 
  case 38: {col38b(); break;} 
  case 39: {col39b(); break;} 
  case 40: {col40b(); break;} 
  case 41: {col41b(); break;} 
  case 42: {col42b(); break;}
  case 43: {col43b(); break;} 
  case 44: {col44b(); break;} 
  case 45: {col45b(); break;} 
  case 46: {col46b(); break;} 
  case 47: {col47b(); break;} 
  case 48: {col48b(); break;} 
  case 49: {col49b(); break;} 
  case 50: {col50b(); break;} 
  case 51: {col51b(); break;} 
  case 52: {col52b(); break;} 
  case 53: {col53b(); break;} 
  case 54: {col54b(); break;} 
  case 55: {col55b(); break;} 
  case 56: {col56b(); break;} 
  case 57: {col57b(); break;} 
  case 58: {col58b(); break;} 
  case 59: {col59b(); break;} 
  case 60: {col60b(); break;} 
  case 61: {col61b(); break;} 
  case 62: {col62b(); break;} 
  default: {break;}
  }

// turn on rows 0-3
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(mcpRowOutput[0]);
i2c1.endTransmission(); //ends communication with slave device
delayMicroseconds(400);
// turn on rows 4-6
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(mcpRowOutput[1]);
i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(cgdel);
// turn off rows 0-3
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
// turn on rows 7-10
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(mcpRowOutput[2]);
i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(cgdel);
// turn off rows 4-6
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
// turn on rows 11-13
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(mcpRowOutput[3]);
i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(cgdel);
// turn off rows 7-10
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
delayMicroseconds(400); //  adjustment for no turn on
// turn off rows 11-13
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device

switch (column) {
  case 0: {col0o(); break;} // turn column source and sink off
  case 1: {col1o(); break;} 
  case 2: {col2o(); break;} 
  case 3: {col3o(); break;} 
  case 4: {col4o(); break;} 
  case 5: {col5o(); break;} 
  case 6: {col6o(); break;} 
  case 7: {col7o(); break;} 
  case 8: {col8o(); break;} 
  case 9: {col9o(); break;} 
  case 10: {col10o(); break;} 
  case 11: {col11o(); break;} 
  case 12: {col12o(); break;} 
  case 13: {col13o(); break;} 
  case 14: {col14o(); break;} 
  case 15: {col15o(); break;} 
  case 16: {col16o(); break;} 
  case 17: {col17o(); break;} 
  case 18: {col18o(); break;} 
  case 19: {col19o(); break;} 
  case 20: {col20o(); break;} 
  case 21: {col21o(); break;}
  case 22: {col22o(); break;} 
  case 23: {col23o(); break;} 
  case 24: {col24o(); break;} 
  case 25: {col25o(); break;} 
  case 26: {col26o(); break;} 
  case 27: {col27o(); break;} 
  case 28: {col28o(); break;} 
  case 29: {col29o(); break;} 
  case 30: {col30o(); break;} 
  case 31: {col31o(); break;} 
  case 32: {col32o(); break;} 
  case 33: {col33o(); break;} 
  case 34: {col34o(); break;} 
  case 35: {col35o(); break;} 
  case 36: {col36o(); break;} 
  case 37: {col37o(); break;} 
  case 38: {col38o(); break;} 
  case 39: {col39o(); break;} 
  case 40: {col40o(); break;} 
  case 41: {col41o(); break;} 
  case 42: {col42o(); break;}
  case 43: {col43o(); break;} 
  case 44: {col44o(); break;} 
  case 45: {col45o(); break;} 
  case 46: {col46o(); break;} 
  case 47: {col47o(); break;} 
  case 48: {col48o(); break;} 
  case 49: {col49o(); break;} 
  case 50: {col50o(); break;} 
  case 51: {col51o(); break;} 
  case 52: {col52o(); break;} 
  case 53: {col53o(); break;} 
  case 54: {col54o(); break;} 
  case 55: {col55o(); break;} 
  case 56: {col56o(); break;} 
  case 57: {col57o(); break;} 
  case 58: {col58o(); break;} 
  case 59: {col59o(); break;} 
  case 60: {col60o(); break;} 
  case 61: {col61o(); break;} 
  case 62: {col62o(); break;} 
  default: {break;}
  }
}

// bit operators
// clears the kth bit of n
int clearBit(int n, int k)
{
    return (n & (~(1 << k)));
} 
// sets the kth bit of n
int setBit(int n, int k)
{
    return ((1 << k) | n);
}
// returns value of kth bit of n
int findBit(int n, int k)
{
    return ((n >> k) % 2); // just checks odd or even after shift
}
// toggles kth bit of n
int toggleBit(int n, int k)
{
    return (n ^ (1 << k));
}
// returns modified n with value of b in kth bit
int modifyBit(int n, int k, int b) 
{ 
    int mask = 1 << k; 
    return ((n & ~mask) | (b << k));  // ~ is bitwise not or compliment 
    // also the same as n ^ 0xff or n ^ (-1) (exclusive or)
}


void setColumnGroup_7x5(int column, int rowStates)  // same as above but only changes rows 4 to 10 for the 7x5 font
{
int mcpRowOutput[4] = {0, 0, 0, 0};  // array for holding desired outputs
// turn off mcps
mcpOff();
// create mcpOutput for rows (will then be used with column source and then column sink)
// to turn on and off groups of 4 rows
//rows 0-3
//if (findBit(rowStates, 0) == 1){ // 1 is yellow, 0 is black
//    mcpRowOutput[0] = mcpRowOutput[0] | 0b10101011;  // initalizes byte and turns on row sink
//    }
//    else mcpRowOutput[0] = mcpRowOutput[0] & 0b10101000;  // initalizes byte and turns on row source
//if (findBit(rowStates, 1) == 1){ // 1 is yellow, 0 is black
//  mcpRowOutput[0] = mcpRowOutput[0] | 0b00001100;  // turns on row sink
//  }
//  else mcpRowOutput[0] = mcpRowOutput[0] & 0b11110011;  // turns on row source
//if (findBit(rowStates, 2) == 1){ // 1 is yellow, 0 is black
//  mcpRowOutput[0] = mcpRowOutput[0] | 0b00110000;  // turns on row sink
//  }
// else mcpRowOutput[0] = mcpRowOutput[0] & 0b11001111;  // turns on row source
//if (findBit(rowStates, 3) == 1){ // 1 is yellow, 0 is black
//  mcpRowOutput[0] = mcpRowOutput[0] | 0b11000000;  // turns on row sink
//  }
//  else mcpRowOutput[0] = mcpRowOutput[0] & 0b00111111;  // turns on row source 
//rows 4-6
if (findBit(rowStates, 4) == 1){ // 1 is yellow, 0 is black
    mcpRowOutput[1] = mcpRowOutput[1] | 0b10101011;  // initalizes byte and turns on row sink
    }
    else mcpRowOutput[1] = mcpRowOutput[1] & 0b10101000;  // initalizes byte and turns on row source
if (findBit(rowStates, 5) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[1] = mcpRowOutput[1] | 0b00001100;  // turns on row sink
  }
  else mcpRowOutput[1] = mcpRowOutput[1] & 0b11110011;  // turns on row source
if (findBit(rowStates, 6) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[1] = mcpRowOutput[1] | 0b00110000;  // turns on row sink
  }
  else mcpRowOutput[1] = mcpRowOutput[1] & 0b11001111;  // turns on row source
// rows 7-10
if (findBit(rowStates, 7) == 1){ // 1 is yellow, 0 is black
    mcpRowOutput[2] = mcpRowOutput[2] | 0b10101011;  // initalizes byte and turns on row sink
    }
    else mcpRowOutput[2] = mcpRowOutput[2] & 0b10101000;  // initalizes byte and turns on row source
if (findBit(rowStates, 8) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[2] = mcpRowOutput[2] | 0b00001100;  // turns on row sink
  }
  else mcpRowOutput[2] = mcpRowOutput[2] & 0b11110011;  // turns on row source
if (findBit(rowStates, 9) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[2] = mcpRowOutput[2] | 0b00110000;  // turns on row sink
  }
  else mcpRowOutput[2] = mcpRowOutput[2] & 0b11001111;  // turns on row source
if (findBit(rowStates, 10) == 1){ // 1 is yellow, 0 is black
  mcpRowOutput[2] = mcpRowOutput[2] | 0b11000000;  // turns on row sink
  }
  else mcpRowOutput[2] = mcpRowOutput[2] & 0b00111111;  // turns on row source 
// rows 11-13
//if (findBit(rowStates, 11) == 1){ // 1 is yellow, 0 is black
//    mcpRowOutput[3] = mcpRowOutput[3] | 0b10101011;  // initalizes byte and turns on row sink
//    }
//    else mcpRowOutput[3] = mcpRowOutput[3] & 0b10101000;  // initalizes byte and turns on row source
//if (findBit(rowStates, 12) == 1){ // 1 is yellow, 0 is black
//  mcpRowOutput[3] = mcpRowOutput[3] | 0b00001100;  // turns on row sink
//  }
//  else mcpRowOutput[3] = mcpRowOutput[3] & 0b11110011;  // turns on row source
//if (findBit(rowStates, 13) == 1){ // 1 is yellow, 0 is black
//  mcpRowOutput[3] = mcpRowOutput[3] | 0b00110000;  // turns on row sink
//  }
//  else mcpRowOutput[3] = mcpRowOutput[3] & 0b11001111;  // turns on row source

// select column high
switch (column) {
  case 0: {col0y(); break;} // turn on column source and sink off
  case 1: {col1y(); break;} 
  case 2: {col2y(); break;} 
  case 3: {col3y(); break;} 
  case 4: {col4y(); break;} 
  case 5: {col5y(); break;} 
  case 6: {col6y(); break;} 
  case 7: {col7y(); break;} 
  case 8: {col8y(); break;} 
  case 9: {col9y(); break;} 
  case 10: {col10y(); break;} 
  case 11: {col11y(); break;} 
  case 12: {col12y(); break;} 
  case 13: {col13y(); break;} 
  case 14: {col14y(); break;} 
  case 15: {col15y(); break;} 
  case 16: {col16y(); break;} 
  case 17: {col17y(); break;} 
  case 18: {col18y(); break;} 
  case 19: {col19y(); break;} 
  case 20: {col20y(); break;} 
  case 21: {col21y(); break;}
  case 22: {col22y(); break;} 
  case 23: {col23y(); break;} 
  case 24: {col24y(); break;} 
  case 25: {col25y(); break;} 
  case 26: {col26y(); break;} 
  case 27: {col27y(); break;} 
  case 28: {col28y(); break;} 
  case 29: {col29y(); break;} 
  case 30: {col30y(); break;} 
  case 31: {col31y(); break;} 
  case 32: {col32y(); break;} 
  case 33: {col33y(); break;} 
  case 34: {col34y(); break;} 
  case 35: {col35y(); break;} 
  case 36: {col36y(); break;} 
  case 37: {col37y(); break;} 
  case 38: {col38y(); break;} 
  case 39: {col39y(); break;} 
  case 40: {col40y(); break;} 
  case 41: {col41y(); break;} 
  case 42: {col42y(); break;}
  case 43: {col43y(); break;} 
  case 44: {col44y(); break;} 
  case 45: {col45y(); break;} 
  case 46: {col46y(); break;} 
  case 47: {col47y(); break;} 
  case 48: {col48y(); break;} 
  case 49: {col49y(); break;} 
  case 50: {col50y(); break;} 
  case 51: {col51y(); break;} 
  case 52: {col52y(); break;} 
  case 53: {col53y(); break;} 
  case 54: {col54y(); break;} 
  case 55: {col55y(); break;} 
  case 56: {col56y(); break;} 
  case 57: {col57y(); break;} 
  case 58: {col58y(); break;} 
  case 59: {col59y(); break;} 
  case 60: {col60y(); break;} 
  case 61: {col61y(); break;} 
  case 62: {col62y(); break;} 
  default: {break;}
  }

// note - modified from orignal to balance all offs and ons to be approximately 1200us

// turn on rows 0-3  each tranmission takes 350us
//i2c1.beginTransmission(0x20); //starts talking to slave device
//i2c1.write(0x00); // IODIRA is 0x00 in Bank0
//i2c1.write(mcpRowOutput[0]);
//i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(400);  // default is 200us
// turn on rows 4-6
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(mcpRowOutput[1]);
i2c1.endTransmission(); //ends communication with slave device
delayMicroseconds(400);
//delayMicroseconds(cgdel);  // note not used anymore *****
// turn off rows 0-3 
//i2c1.beginTransmission(0x20); //starts talking to slave device
//i2c1.write(0x00); // IODIRA is 0x00 in Bank0
//i2c1.write(0b10101010);
//i2c1.endTransmission(); //ends communication with slave device
// rows 0-3 pulse 200us plus 350us plus 200us plus 350 for 1100us total
// turn on rows 7-10
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(mcpRowOutput[2]);
i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(cgdel);
// turn off rows 4-6
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
delayMicroseconds(400);
// rows 4-6 pulse 200us plus 350us plus 350us plus 200us plus 350us for 1450us total
// turn on rows 11-13
//i2c1.beginTransmission(0x21); //starts talking to slave device
//i2c1.write(0x01); // IODIRB is 0x01 in Bank0
//i2c1.write(mcpRowOutput[3]);
//i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(cgdel);
// turn off rows 7-10
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
// rows 7-10 pulse 200us plus 350us plus 350us plus 200us plus 350us for 1450us total
//delayMicroseconds(400);  // adjustment for no turn on
// turn off rows 11-13
//i2c1.beginTransmission(0x21); //starts talking to slave device
//i2c1.write(0x01); // IODIRB is 0x01 in Bank0
//i2c1.write(0b10101010);
//i2c1.endTransmission(); //ends communication with slave device
// rows 11-13 pulse 200us plus 350us plus 200us plus 350us for 1100us total

// select column low
switch (column) {
  case 0: {col0b(); break;} // turn on column source and sink off
  case 1: {col1b(); break;} 
  case 2: {col2b(); break;} 
  case 3: {col3b(); break;} 
  case 4: {col4b(); break;} 
  case 5: {col5b(); break;} 
  case 6: {col6b(); break;} 
  case 7: {col7b(); break;} 
  case 8: {col8b(); break;} 
  case 9: {col9b(); break;} 
  case 10: {col10b(); break;} 
  case 11: {col11b(); break;} 
  case 12: {col12b(); break;} 
  case 13: {col13b(); break;} 
  case 14: {col14b(); break;} 
  case 15: {col15b(); break;} 
  case 16: {col16b(); break;} 
  case 17: {col17b(); break;} 
  case 18: {col18b(); break;} 
  case 19: {col19b(); break;} 
  case 20: {col20b(); break;} 
  case 21: {col21b(); break;}
  case 22: {col22b(); break;} 
  case 23: {col23b(); break;} 
  case 24: {col24b(); break;} 
  case 25: {col25b(); break;} 
  case 26: {col26b(); break;} 
  case 27: {col27b(); break;} 
  case 28: {col28b(); break;} 
  case 29: {col29b(); break;} 
  case 30: {col30b(); break;} 
  case 31: {col31b(); break;} 
  case 32: {col32b(); break;} 
  case 33: {col33b(); break;} 
  case 34: {col34b(); break;} 
  case 35: {col35b(); break;} 
  case 36: {col36b(); break;} 
  case 37: {col37b(); break;} 
  case 38: {col38b(); break;} 
  case 39: {col39b(); break;} 
  case 40: {col40b(); break;} 
  case 41: {col41b(); break;} 
  case 42: {col42b(); break;}
  case 43: {col43b(); break;} 
  case 44: {col44b(); break;} 
  case 45: {col45b(); break;} 
  case 46: {col46b(); break;} 
  case 47: {col47b(); break;} 
  case 48: {col48b(); break;} 
  case 49: {col49b(); break;} 
  case 50: {col50b(); break;} 
  case 51: {col51b(); break;} 
  case 52: {col52b(); break;} 
  case 53: {col53b(); break;} 
  case 54: {col54b(); break;} 
  case 55: {col55b(); break;} 
  case 56: {col56b(); break;} 
  case 57: {col57b(); break;} 
  case 58: {col58b(); break;} 
  case 59: {col59b(); break;} 
  case 60: {col60b(); break;} 
  case 61: {col61b(); break;} 
  case 62: {col62b(); break;} 
  default: {break;}
  }

// turn on rows 0-3
//i2c1.beginTransmission(0x20); //starts talking to slave device
//i2c1.write(0x00); // IODIRA is 0x00 in Bank0
//i2c1.write(mcpRowOutput[0]);
//i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(400);
// turn on rows 4-6
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(mcpRowOutput[1]);
i2c1.endTransmission(); //ends communication with slave device
delayMicroseconds(400);
//delayMicroseconds(cgdel);
// turn off rows 0-3
//i2c1.beginTransmission(0x20); //starts talking to slave device
//i2c1.write(0x00); // IODIRA is 0x00 in Bank0
//i2c1.write(0b10101010);
//i2c1.endTransmission(); //ends communication with slave device
// turn on rows 7-10
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(mcpRowOutput[2]);
i2c1.endTransmission(); //ends communication with slave device
//delayMicroseconds(cgdel);
// turn off rows 4-6
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
// turn on rows 11-13
//i2c1.beginTransmission(0x21); //starts talking to slave device
//i2c1.write(0x01); // IODIRB is 0x01 in Bank0
//i2c1.write(mcpRowOutput[3]);
//i2c1.endTransmission(); //ends communication with slave device
delayMicroseconds(400);
//delayMicroseconds(cgdel);
// turn off rows 7-10
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010);
i2c1.endTransmission(); //ends communication with slave device
// delayMicroseconds(400); //  adjustment for no turn on
// turn off rows 11-13
//i2c1.beginTransmission(0x21); //starts talking to slave device
//i2c1.write(0x01); // IODIRB is 0x01 in Bank0
//i2c1.write(0b10101010);
//i2c1.endTransmission(); //ends communication with slave device

switch (column) {
  case 0: {col0o(); break;} // turn column source and sink off
  case 1: {col1o(); break;} 
  case 2: {col2o(); break;} 
  case 3: {col3o(); break;} 
  case 4: {col4o(); break;} 
  case 5: {col5o(); break;} 
  case 6: {col6o(); break;} 
  case 7: {col7o(); break;} 
  case 8: {col8o(); break;} 
  case 9: {col9o(); break;} 
  case 10: {col10o(); break;} 
  case 11: {col11o(); break;} 
  case 12: {col12o(); break;} 
  case 13: {col13o(); break;} 
  case 14: {col14o(); break;} 
  case 15: {col15o(); break;} 
  case 16: {col16o(); break;} 
  case 17: {col17o(); break;} 
  case 18: {col18o(); break;} 
  case 19: {col19o(); break;} 
  case 20: {col20o(); break;} 
  case 21: {col21o(); break;}
  case 22: {col22o(); break;} 
  case 23: {col23o(); break;} 
  case 24: {col24o(); break;} 
  case 25: {col25o(); break;} 
  case 26: {col26o(); break;} 
  case 27: {col27o(); break;} 
  case 28: {col28o(); break;} 
  case 29: {col29o(); break;} 
  case 30: {col30o(); break;} 
  case 31: {col31o(); break;} 
  case 32: {col32o(); break;} 
  case 33: {col33o(); break;} 
  case 34: {col34o(); break;} 
  case 35: {col35o(); break;} 
  case 36: {col36o(); break;} 
  case 37: {col37o(); break;} 
  case 38: {col38o(); break;} 
  case 39: {col39o(); break;} 
  case 40: {col40o(); break;} 
  case 41: {col41o(); break;} 
  case 42: {col42o(); break;}
  case 43: {col43o(); break;} 
  case 44: {col44o(); break;} 
  case 45: {col45o(); break;} 
  case 46: {col46o(); break;} 
  case 47: {col47o(); break;} 
  case 48: {col48o(); break;} 
  case 49: {col49o(); break;} 
  case 50: {col50o(); break;} 
  case 51: {col51o(); break;} 
  case 52: {col52o(); break;} 
  case 53: {col53o(); break;} 
  case 54: {col54o(); break;} 
  case 55: {col55o(); break;} 
  case 56: {col56o(); break;} 
  case 57: {col57o(); break;} 
  case 58: {col58o(); break;} 
  case 59: {col59o(); break;} 
  case 60: {col60o(); break;} 
  case 61: {col61o(); break;} 
  case 62: {col62o(); break;} 
  default: {break;}
  }
}

