// setCell function for interfacing with MCP23017 and Display

void setCell(int column, int row, int dot){
// column is column 0-63
// row is row 0-13
// dot is 1 (yellow), 0 (black), 2 (off or no change)
// column first as row can drive more than one dot
//   and display moves left to right
// Cx_Source 12V and Rx 0v - dot flips yellow
// Cx_Sink 0V and Rx 12V - dot flips black
// Off is no output to column or row
// Cx controls pulse length of 500us

switch (column) {
  case 0:  // do something when var equals 0, etc to 63
    if (dot == 1){col0y();} // turn on source
    if (dot == 0){col0b();} // turn on sink
    if (dot == 2){col0o();} // turn off source and sink
    break;
  case 1:
    if (dot == 1){col1y();} // turn on source
    if (dot == 0){col1b();} // turn on sink
    if (dot == 2){col1o();} // turn off source and sink
    break;
  case 2:
    if (dot == 1){col2y();} // turn on source
    if (dot == 0){col2b();} // turn on sink
    if (dot == 2){col2o();} // turn off source and sink
    break;
  case 3:
    if (dot == 1){col3y();} // turn on source
    if (dot == 0){col3b();} // turn on sink
    if (dot == 2){col3o();} // turn off source and sink
    break;
  case 4:
    if (dot == 1){col4y();} // turn on source
    if (dot == 0){col4b();} // turn on sink
    if (dot == 2){col4o();} // turn off source and sink
    break;
  case 5:
    if (dot == 1){col5y();} // turn on source
    if (dot == 0){col5b();} // turn on sink
    if (dot == 2){col5o();} // turn off source and sink
    break;
  case 6:
    if (dot == 1){col6y();} // turn on source
    if (dot == 0){col6b();} // turn on sink
    if (dot == 2){col6o();} // turn off source and sink
    break;
  case 7:
    if (dot == 1){col7y();} // turn on source
    if (dot == 0){col7b();} // turn on sink
    if (dot == 2){col7o();} // turn off source and sink
    break;
  case 8:
    if (dot == 1){col8y();} // turn on source
    if (dot == 0){col8b();} // turn on sink
    if (dot == 2){col8o();} // turn off source and sink
    break;
  case 9:
    if (dot == 1){col9y();} // turn on source
    if (dot == 0){col9b();} // turn on sink
    if (dot == 2){col9o();} // turn off source and sink
    break;
  case 10:
    if (dot == 1){col10y();} // turn on source
    if (dot == 0){col10b();} // turn on sink
    if (dot == 2){col10o();} // turn off source and sink
    break;
  case 11:
    if (dot == 1){col11y();} // turn on source
    if (dot == 0){col11b();} // turn on sink
    if (dot == 2){col11o();} // turn off source and sink
    break;
  case 12:
    if (dot == 1){col12y();} // turn on source
    if (dot == 0){col12b();} // turn on sink
    if (dot == 2){col12o();} // turn off source and sink
    break;
  case 13:
    if (dot == 1){col13y();} // turn on source
    if (dot == 0){col13b();} // turn on sink
    if (dot == 2){col13o();} // turn off source and sink
    break;
  case 14:  // do something when var equals 0, etc to 63
    if (dot == 1){col14y();} // turn on source
    if (dot == 0){col14b();} // turn on sink
    if (dot == 2){col14o();} // turn off source and sink
    break;
  case 15:
    if (dot == 1){col15y();} // turn on source
    if (dot == 0){col15b();} // turn on sink
    if (dot == 2){col15o();} // turn off source and sink
    break;
  case 16:
    if (dot == 1){col16y();} // turn on source
    if (dot == 0){col16b();} // turn on sink
    if (dot == 2){col16o();} // turn off source and sink
    break;
  case 17:
    if (dot == 1){col17y();} // turn on source
    if (dot == 0){col17b();} // turn on sink
    if (dot == 2){col17o();} // turn off source and sink
    break;
  case 18:
    if (dot == 1){col18y();} // turn on source
    if (dot == 0){col18b();} // turn on sink
    if (dot == 2){col18o();} // turn off source and sink
    break;
  case 19:
    if (dot == 1){col19y();} // turn on source
    if (dot == 0){col19b();} // turn on sink
    if (dot == 2){col19o();} // turn off source and sink
    break;
  case 20:
    if (dot == 1){col20y();} // turn on source
    if (dot == 0){col20b();} // turn on sink
    if (dot == 2){col20o();} // turn off source and sink
    break;
  case 21:  // do something when var equals 0, etc to 63
    if (dot == 1){col21y();} // turn on source
    if (dot == 0){col21b();} // turn on sink
    if (dot == 2){col21o();} // turn off source and sink
    break;
  case 22:
    if (dot == 1){col22y();} // turn on source
    if (dot == 0){col22b();} // turn on sink
    if (dot == 2){col22o();} // turn off source and sink
    break;
  case 23:
    if (dot == 1){col23y();} // turn on source
    if (dot == 0){col23b();} // turn on sink
    if (dot == 2){col23o();} // turn off source and sink
    break;
  case 24:
    if (dot == 1){col24y();} // turn on source
    if (dot == 0){col24b();} // turn on sink
    if (dot == 2){col24o();} // turn off source and sink
    break;
  case 25:
    if (dot == 1){col25y();} // turn on source
    if (dot == 0){col25b();} // turn on sink
    if (dot == 2){col25o();} // turn off source and sink
    break;
  case 26:
    if (dot == 1){col26y();} // turn on source
    if (dot == 0){col26b();} // turn on sink
    if (dot == 2){col26o();} // turn off source and sink
    break;
  case 27:
    if (dot == 1){col27y();} // turn on source
    if (dot == 0){col27b();} // turn on sink
    if (dot == 2){col27o();} // turn off source and sink
    break;
  case 28:
    if (dot == 1){col28y();} // turn on source
    if (dot == 0){col28b();} // turn on sink
    if (dot == 2){col28o();} // turn off source and sink
    break;
  case 29:
    if (dot == 1){col29y();} // turn on source
    if (dot == 0){col29b();} // turn on sink
    if (dot == 2){col29o();} // turn off source and sink
    break;
  case 30:
    if (dot == 1){col30y();} // turn on source
    if (dot == 0){col30b();} // turn on sink
    if (dot == 2){col30o();} // turn off source and sink
    break;
  case 31:
    if (dot == 1){col31y();} // turn on source
    if (dot == 0){col31b();} // turn on sink
    if (dot == 2){col31o();} // turn off source and sink
    break;
  case 32:
    if (dot == 1){col32y();} // turn on source
    if (dot == 0){col32b();} // turn on sink
    if (dot == 2){col32o();} // turn off source and sink
    break;
  case 33:
    if (dot == 1){col33y();} // turn on source
    if (dot == 0){col33b();} // turn on sink
    if (dot == 2){col33o();} // turn off source and sink
    break;
  case 34:
    if (dot == 1){col34y();} // turn on source
    if (dot == 0){col34b();} // turn on sink
    if (dot == 2){col34o();} // turn off source and sink
    break;
  case 35:  // do something when var equals 0, etc to 63
    if (dot == 1){col35y();} // turn on source
    if (dot == 0){col35b();} // turn on sink
    if (dot == 2){col35o();} // turn off source and sink
    break;
  case 36:
    if (dot == 1){col36y();} // turn on source
    if (dot == 0){col36b();} // turn on sink
    if (dot == 2){col36o();} // turn off source and sink
    break;
  case 37:
    if (dot == 1){col37y();} // turn on source
    if (dot == 0){col37b();} // turn on sink
    if (dot == 2){col37o();} // turn off source and sink
    break;
  case 38:
    if (dot == 1){col38y();} // turn on source
    if (dot == 0){col38b();} // turn on sink
    if (dot == 2){col38o();} // turn off source and sink
    break;
  case 39:
    if (dot == 1){col39y();} // turn on source
    if (dot == 0){col39b();} // turn on sink
    if (dot == 2){col39o();} // turn off source and sink
    break;
  case 40:
    if (dot == 1){col40y();} // turn on source
    if (dot == 0){col40b();} // turn on sink
    if (dot == 2){col40o();} // turn off source and sink
    break;
  case 41:
    if (dot == 1){col41y();} // turn on source
    if (dot == 0){col41b();} // turn on sink
    if (dot == 2){col41o();} // turn off source and sink
    break;
  case 42:  // do something when var equals 0, etc to 63
    if (dot == 1){col42y();} // turn on source
    if (dot == 0){col42b();} // turn on sink
    if (dot == 2){col42o();} // turn off source and sink
    break;
  case 43:
    if (dot == 1){col43y();} // turn on source
    if (dot == 0){col43b();} // turn on sink
    if (dot == 2){col43o();} // turn off source and sink
    break;
  case 44:
    if (dot == 1){col44y();} // turn on source
    if (dot == 0){col44b();} // turn on sink
    if (dot == 2){col44o();} // turn off source and sink
    break;
  case 45:
    if (dot == 1){col45y();} // turn on source
    if (dot == 0){col45b();} // turn on sink
    if (dot == 2){col45o();} // turn off source and sink
    break;
  case 46:
    if (dot == 1){col46y();} // turn on source
    if (dot == 0){col46b();} // turn on sink
    if (dot == 2){col46o();} // turn off source and sink
    break;
  case 47:
    if (dot == 1){col47y();} // turn on source
    if (dot == 0){col47b();} // turn on sink
    if (dot == 2){col47o();} // turn off source and sink
    break;
  case 48:
    if (dot == 1){col48y();} // turn on source
    if (dot == 0){col48b();} // turn on sink
    if (dot == 2){col48o();} // turn off source and sink
    break;
  case 49:
    if (dot == 1){col49y();} // turn on source
    if (dot == 0){col49b();} // turn on sink
    if (dot == 2){col49o();} // turn off source and sink
    break;
  case 50:
    if (dot == 1){col50y();} // turn on source
    if (dot == 0){col50b();} // turn on sink
    if (dot == 2){col50o();} // turn off source and sink
    break;
  case 51:
    if (dot == 1){col51y();} // turn on source
    if (dot == 0){col51b();} // turn on sink
    if (dot == 2){col51o();} // turn off source and sink
    break;
  case 52:
    if (dot == 1){col52y();} // turn on source
    if (dot == 0){col52b();} // turn on sink
    if (dot == 2){col52o();} // turn off source and sink
    break;
  case 53:
    if (dot == 1){col53y();} // turn on source
    if (dot == 0){col53b();} // turn on sink
    if (dot == 2){col53o();} // turn off source and sink
    break;
  case 54:
    if (dot == 1){col54y();} // turn on source
    if (dot == 0){col54b();} // turn on sink
    if (dot == 2){col54o();} // turn off source and sink
    break;
  case 55:
    if (dot == 1){col55y();} // turn on source
    if (dot == 0){col55b();} // turn on sink
    if (dot == 2){col55o();} // turn off source and sink
    break;
  case 56:  // do something when var equals 0, etc to 63
    if (dot == 1){col56y();} // turn on source
    if (dot == 0){col56b();} // turn on sink
    if (dot == 2){col56o();} // turn off source and sink
    break;
  case 57:
    if (dot == 1){col57y();} // turn on source
    if (dot == 0){col57b();} // turn on sink
    if (dot == 2){col57o();} // turn off source and sink
    break;
  case 58:
    if (dot == 1){col58y();} // turn on source
    if (dot == 0){col58b();} // turn on sink
    if (dot == 2){col58o();} // turn off source and sink
    break;
  case 59:
    if (dot == 1){col59y();} // turn on source
    if (dot == 0){col59b();} // turn on sink
    if (dot == 2){col59o();} // turn off source and sink
    break;
  case 60:
    if (dot == 1){col60y();} // turn on source
    if (dot == 0){col60b();} // turn on sink
    if (dot == 2){col60o();} // turn off source and sink
    break;
  case 61:
    if (dot == 1){col61y();} // turn on source
    if (dot == 0){col61b();} // turn on sink
    if (dot == 2){col61o();} // turn off source and sink
    break;
  case 62:
    if (dot == 1){col62y();} // turn on source
    if (dot == 0){col62b();} // turn on sink
    if (dot == 2){col62o();} // turn off source and sink
    break;
  default:  // optional, if nothing else matches, do the default
    break;
  }
switch (row) {
  case 0:  // do something when var equals 0, etc to 63
    if (dot == 1){row0y();} // turn on sink
    if (dot == 0){row0b();} // turn on source
    if (dot == 2){row0o();} // turn off source and sink
    break;
  case 1:
    if (dot == 1){row1y();} // turn on sink
    if (dot == 0){row1b();} // turn on source
    if (dot == 2){row1o();} // turn off source and sink
    break;
  case 2:
    if (dot == 1){row2y();} // turn on sink
    if (dot == 0){row2b();} // turn on source
    if (dot == 2){row2o();} // turn off source and sink
    break;
  case 3:
    if (dot == 1){row3y();} // turn on sink
    if (dot == 0){row3b();} // turn on source
    if (dot == 2){row3o();} // turn off source and sink
    break;
  case 4:
    if (dot == 1){row4y();} // turn on sink
    if (dot == 0){row4b();} // turn on source
    if (dot == 2){row4o();} // turn off source and sink
    break;
  case 5:
    if (dot == 1){row5y();} // turn on sink
    if (dot == 0){row5b();} // turn on source
    if (dot == 2){row5o();} // turn off source and sink
    break;
  case 6:
    if (dot == 1){row6y();} // turn on sink
    if (dot == 0){row6b();} // turn on source
    if (dot == 2){row6o();} // turn off source and sink
    break;
  case 7:
    if (dot == 1){row7y();} // turn on sink
    if (dot == 0){row7b();} // turn on source
    if (dot == 2){row7o();} // turn off source and sink
    break;
  case 8:  // do something when var equals 0, etc to 63
    if (dot == 1){row8y();} // turn on sink
    if (dot == 0){row8b();} // turn on source
    if (dot == 2){row8o();} // turn off source and sink
    break;
  case 9:
    if (dot == 1){row9y();} // turn on sink
    if (dot == 0){row9b();} // turn on source
    if (dot == 2){row9o();} // turn off source and sink
    break;
  case 10:
    if (dot == 1){row10y();} // turn on sink
    if (dot == 0){row10b();} // turn on source
    if (dot == 2){row10o();} // turn off source and sink
    break;
  case 11:
    if (dot == 1){row11y();} // turn on sink
    if (dot == 0){row11b();} // turn on source
    if (dot == 2){row11o();} // turn off source and sink
    break;
  case 12:
    if (dot == 1){row12y();} // turn on sink
    if (dot == 0){row12b();} // turn on source
    if (dot == 2){row12o();} // turn off source and sink
    break;
  case 13:
    if (dot == 1){row13y();} // turn on sink
    if (dot == 0){row13b();} // turn on source
    if (dot == 2){row13o();} // turn off source and sink
    break;
  default:  // optional, if nothing else matches, do the default
    break;
  }
//pulse
delayMicroseconds(pulseTime);  // 0 to 5000 us - usually around 400us (default)
// not including MCP associated delays of around 350us  - 750us total
// trun off drivers
switch (column) {
  case 0: {col0o(); break;} // turn off column source and sink 
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
switch (row) {
  case 0: {row0o(); break;} // turn off row source and sink 
  case 1: {row1o(); break;} 
  case 2: {row2o(); break;} 
  case 3: {row3o(); break;} 
  case 4: {row4o(); break;} 
  case 5: {row5o(); break;} 
  case 6: {row6o(); break;} 
  case 7: {row7o(); break;} 
  case 8: {row8o(); break;} 
  case 9: {row9o(); break;} 
  case 10: {row10o(); break;} 
  case 11: {row11o(); break;} 
  case 12: {row12o(); break;}
  case 13: {row13o(); break;}
  default: {break;}
  }
return;
} // end of setCell


// x MCP for reference

// GPA0 is xx_Sink (active high)
// GPA1 is xx_Source (active low)
// GPA2 is xx_Sink (active high)
// GPA3 is xx_Source (active low)
// GPA4 is xx_Sink (active high)
// GPA5 is xx_Source (active low)
// GPA6 is xx_Sink (active high)
// GPA7 is xx_Source (active low)

// GPB0 is xx_Sink (active high)
// GPB1 is xx_Source (active low)
// GPB2 is xx_Sink (active high)
// GPB3 is xx_Source (active low)
// GPB4 is xx_Sink (active high)
// GPB5 is xx_Source (active low)
// GPB6 is xx_Sink (active high)
// GPB7 is xx_Source (active low)

void row0y(){ // turn on row 0 sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101011); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row0b() { // turn on row 0 source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101000); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row0o(){ // turn off row 0 source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row1y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101110); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row1b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10100010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row1o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row2y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10111010); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row2b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10001010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row2o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row3y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b11101010); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row3b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b00101010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row3o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row4y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101011); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row4b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101000); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row4o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row5y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101110); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row5b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10100010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row5o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row6y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10111010); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row6b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10001010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row6o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row7y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101011); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row7b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101000); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row7o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row8y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101110); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row8b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10100010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row8o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row9y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10111010); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row9b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10001010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row9o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device 
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row10y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b11101010); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row10b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b00101010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row10o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row11y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101011); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row11b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101000); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row11o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row12y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101110); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row12b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10100010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row12o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row13y(){ // turn on row sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10111010); //  turn off row source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row13b() { // turn on row source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10001010); //  turn on row source (active low) and off sink (active high)
i2c1.endTransmission(); //ends communication with slave device
}
void row13o(){ // turn off row source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}

void col0y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col0b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col0o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col1y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col1b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col1o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col2y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col2b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col2o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col3y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b00101010); //  turn on source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col3b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b11101010); //  turn off source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col3o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col4y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col4b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col4o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col5y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col5b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101110); //  turn off column 1 source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col5o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off column 1 source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col6y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col6b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col6o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col7y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col7b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col7o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col8y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col8b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col8o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col9y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col9b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device 
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col9o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device 
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col10y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device 
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b00101010); //  turn on source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col10b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device 
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b11101010); //  turn off source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col10o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col11y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col11b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col11o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device 
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col12y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device 
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col12b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col12o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col13y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col13b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col13o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col14y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col14b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col14o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col15y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col15b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col15o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col16y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col16b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col16o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col17y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b00101010); //  turn on source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col17b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b11101010); //  turn off source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col17o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col18y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col18b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col18o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col19y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device 
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col19b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col19o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col20y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col20b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col20o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
}
void col21y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col21b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col21o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col22y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col22b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col22o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col23y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col23b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col23o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col24y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b00101010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col24b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b11101010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col24o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col25y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col25b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col25o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col26y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col26b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101110); //  turn off column 1 source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col26o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column 1 source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col27y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col27b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col27o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col28y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col28b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col28o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col29y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col29b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col29o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col30y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col30b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device 
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col30o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device 
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col31y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device 
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b00101010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col31b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device 
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b11101010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col31o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col32y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col32b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col32o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device 
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col33y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device 
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col33b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col33o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col34y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col34b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col34o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col35y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col35b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col35o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col36y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col36b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col36o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col37y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col37b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col37o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col38y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b00101010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col38b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b11101010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col38o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col39y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col39b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col39o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col40y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device 
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col40b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col40o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col41y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col41b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col41o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col42y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col42b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col42o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col43y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col43b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col43o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col44y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col44b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col44o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col45y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b00101010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col45b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b11101010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col45o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col46y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col46b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col46o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col47y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col47b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101110); //  turn off column 1 source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col47o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column 1 source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col48y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col48b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col48o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col49y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col49b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col49o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col50y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col50b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col50o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col51y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col51b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device 
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col51o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device 
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col52y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device 
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b00101010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col52b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device 
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b11101010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col52o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col53y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col53b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col53o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device 
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col54y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device 
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col54b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col54o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col55y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col55b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col55o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col56y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col56b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col56o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col57y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col57b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col57o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col58y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col58b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col58o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col59y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b00101010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col59b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b11101010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col59o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col60y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101000); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col60b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101011); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col60o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col61y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device 
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10100010); //  turn on column source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col61b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101110); //  turn off column source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col61o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col62y(){ // turn on column source
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10001010); //  turn on source (active low) and off sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col62b() { // turn on column sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10111010); //  turn off source (active low) and on sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}
void col62o(){ // turn off column source and sink
// Cx_Sink 0V and Rx 12V - dot flips black
// Cx_Source 12V and Rx 0v - dot flips yellow
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}


void mcpConfigure(){
// MCP23017 address b000 on each i2c
// assumes i2c has begun at 400k baud
// MCP address range is 0x20 to 0x27
// this configures 0x20 to 0x24  
// MCP 0x20 is row0-8 and 0x21  is row 8-14  i2c1
// MCP 0x22 is column 0-7, 0x23 is column 8 to 15 and 0x24 is column 16 to 20 i2c1
// **** will need to update mcp addresses of i2c1 to 0-5 for columns on secondary boards

// note - POR default is Bank0 or '0' (16 bit mode)
// note - POR default is SEQOP enabled or '0' 
// need - to set IOCON to Bank0 or '0' (16 bit mode) with no sequental operation use IOCON address 0x0A data 0x20
// note - seq op on is a 0 and off is a 1
// note - with seq op off, address counter toggles between PortA and PortB on subequent writes or reads
// consider adding this to each output port to preconfiure bits for future writes
//   as first write does not operate like later writes
//   i2c1.write(0b10101010); //  turn off column source (active low) and sink (active high)

// mcp 0x00 i2c1 (comments applicable to all below)
i2c1.beginTransmission(0x20);//begins talking to slave device
i2c1.write(0x0A); // selects the IOCON register 0x0A address using Bank0 (16 bit mode) POR default
// changes default to no sequential
i2c1.write(0b00100000); // sets bit 5 to 1 for no seq operation mode 
i2c1.endTransmission(); //ends communication with slave device
delay(50);
// set BANK0 I/O PORTA latch to 0x00   OLATA 0x14 set 0x00
i2c1.beginTransmission(0x20);// begins talking again to slave device
i2c1.write(0x14); // selects the OLATA register address 14 in Bank0 mode
i2c1.write(0x00); // sets all bits to 0
i2c1.endTransmission(); // ends communication with slave device
delay(50);
// set BANK0 I/O PORTA input pins to have 100k pull-ups  GPPUA 0x0C set 0xff
i2c1.beginTransmission(0x20);
i2c1.write(0x0C); // selects the pull-up GPPUA register
i2c1.write(0xff); // 1 sets inputs with 100k pull-ups 
i2c1.endTransmission();
delay(50);
// set BANK0 I/O PORTB latch to 0x00   OLATB 0x15 set 0x00
i2c1.beginTransmission(0x20);// begins talking again to slave device
i2c1.write(0x15); // selects the OLATB register address 1A in Bank0 mode
i2c1.write(0x00); // sets all bits to 0
i2c1.endTransmission(); // ends communication with slave device
delay(50);
// set BANK0 I/O PORTB input pins to have 100k pull-ups  GPPUB 0x0D set 0xff
i2c1.beginTransmission(0x20);
i2c1.write(0x0D); // selects the pull-up GPPUB register
i2c1.write(0xff); // 1 sets inputs with 100k pull-ups 
i2c1.endTransmission();
delay(50);

// mcp 0x01  i2c1
i2c1.beginTransmission(0x21);
i2c1.write(0x0A);
i2c1.write(0b00100000);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x21);
i2c1.write(0x14);
i2c1.write(0x00);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x21);
i2c1.write(0x0C);
i2c1.write(0xff);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x21);
i2c1.write(0x15);
i2c1.write(0x00);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x21);
i2c1.write(0x0D);
i2c1.write(0xff);
i2c1.endTransmission();
delay(50);

// mcp 0x02 i2c1
i2c1.beginTransmission(0x22);
i2c1.write(0x0A);
i2c1.write(0b00100000);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x22);
i2c1.write(0x14);
i2c1.write(0x00);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x22);
i2c1.write(0x0C);
i2c1.write(0xff);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x22);
i2c1.write(0x15);
i2c1.write(0x00);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x22);
i2c1.write(0x0D);
i2c1.write(0xff);
i2c1.endTransmission();
delay(50);

// mcp 0x03  i2c1
i2c1.beginTransmission(0x23);
i2c1.write(0x0A);
i2c1.write(0b00100000);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x23);
i2c1.write(0x14);
i2c1.write(0x00);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x23);
i2c1.write(0x0C);
i2c1.write(0xff);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x23);
i2c1.write(0x15);
i2c1.write(0x00);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x23);
i2c1.write(0x0D);
i2c1.write(0xff);
i2c1.endTransmission();
delay(50);

// mcp 0x04  i2c1
i2c1.beginTransmission(0x24);
i2c1.write(0x0A);
i2c1.write(0b00100000);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x24);
i2c1.write(0x14);
i2c1.write(0x00);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x24);
i2c1.write(0x0C);
i2c1.write(0xff);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x24);
i2c1.write(0x15);
i2c1.write(0x00);
i2c1.endTransmission();
delay(50);
i2c1.beginTransmission(0x24);
i2c1.write(0x0D);
i2c1.write(0xff);
i2c1.endTransmission();
delay(50);

// mcp 0x00 i2c2
i2c2.beginTransmission(0x20);
i2c2.write(0x0A);
i2c2.write(0b00100000);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x20);
i2c2.write(0x14);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x20);
i2c2.write(0x0C);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x20);
i2c2.write(0x15);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x20);
i2c2.write(0x0D);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);

// mcp 0x01  i2c2
i2c2.beginTransmission(0x21);
i2c2.write(0x0A);
i2c2.write(0b00100000);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x21);
i2c2.write(0x14);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x21);
i2c2.write(0x0C);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x21);
i2c2.write(0x15);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x21);
i2c2.write(0x0D);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);

// mcp 0x02 i2c2
i2c2.beginTransmission(0x22);
i2c2.write(0x0A);
i2c2.write(0b00100000);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x22);
i2c2.write(0x14);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x22);
i2c2.write(0x0C);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x22);
i2c2.write(0x15);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x22);
i2c2.write(0x0D);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);

// mcp 0x03  i2c2
i2c2.beginTransmission(0x23);
i2c2.write(0x0A);
i2c2.write(0b00100000);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x23);
i2c2.write(0x14);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x23);
i2c2.write(0x0C);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x23);
i2c2.write(0x15);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x23);
i2c2.write(0x0D);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);

// mcp 0x04  i2c2
i2c2.beginTransmission(0x24);
i2c2.write(0x0A);
i2c2.write(0b00100000);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x24);
i2c2.write(0x14);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x24);
i2c2.write(0x0C);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x24);
i2c2.write(0x15);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x24);
i2c2.write(0x0D);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);

// mcp 0x05  i2c2
i2c2.beginTransmission(0x25);
i2c2.write(0x0A);
i2c2.write(0b00100000);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x25);
i2c2.write(0x14);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x25);
i2c2.write(0x0C);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x25);
i2c2.write(0x15);
i2c2.write(0x00);
i2c2.endTransmission();
delay(50);
i2c2.beginTransmission(0x25);
i2c2.write(0x0D);
i2c2.write(0xff);
i2c2.endTransmission();
delay(50);
}

void mcpOff(){
// i2c1 bus
// MCP 0x20 is row 0 to 6 and 0x21 is row 7 to 13
// MCP 0x22 is column 0 to 6, 0x23 is column 7 to 13 and 0x24 is column 14 to 20
// i2c2 bus
// MCP 0x20 is column 21 to 27, 0x21 is column 28 to 34 and 0x22 is column 35 to 41
// MCP 0x23 is column 42 to 48, 0x24 is column 49 to 55 and 0x25 is column 56 to 62
// Cx_Sink 0V and Rx 15V - dot flips black
// Cx_Source 15V and Rx 0v - dot flips yellow
// off out put is 0b10101010
// rows 0-3 off 9 (4 rows off)
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// rows 4-6 off (3 rows off)
i2c1.beginTransmission(0x20); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// rows 7-10 off
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// rows 11-13 off
i2c1.beginTransmission(0x21); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// columns 0-3 off  
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// columns 4-6 off  
i2c1.beginTransmission(0x22); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// columns 7-10 off  
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// columns 11-13 off
i2c1.beginTransmission(0x23); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// columns 14-17 off  
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x00); // IODIRA is 0x00 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// columns 18-20 off
i2c1.beginTransmission(0x24); //starts talking to slave device
i2c1.write(0x01); // IODIRB is 0x01 in Bank0
i2c1.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c1.endTransmission(); //ends communication with slave device
// columns 21-24 off
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 25-27 off
i2c2.beginTransmission(0x20); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 28-31 off
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// coumns 32-34 off
i2c2.beginTransmission(0x21); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off row source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 35-38 off  
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 39-41 off  
i2c2.beginTransmission(0x22); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 42-45 off  
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 46-48 off
i2c2.beginTransmission(0x23); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 49-52 off  
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 53-55 off
i2c2.beginTransmission(0x24); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 56-59 off  
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x00); // IODIRA is 0x00 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
// columns 60-62 off
i2c2.beginTransmission(0x25); //starts talking to slave device
i2c2.write(0x01); // IODIRB is 0x01 in Bank0
i2c2.write(0b10101010); //  turn off column source (active low) and sink ( active high)
i2c2.endTransmission(); //ends communication with slave device
}


/*
Further notes on MCP23017

To emulate an open-collector configuration clear the output latch (OLAT) bit to a zero
and then use the direction register (IODIR) to set the level on the pin. 
A pull-up resistor is required to pull the pin to voltage when the pin is an input
- To drive a 0: configure the pin as an output (IODIR = 0) so the port drives 
whatever is in OLAT (logic 0 in this case)
- To float a 1: set the pin as an input (IODIR = 1). The output driver is disabled
and the pull-up resistor pulls the pin to a logic 1

Bank0 mode
OLATB 0x15 set 0x00
GPPUB 0x0d set 0xff
IODIRB 0x01 set 0x00

Bank1 mode
OLATA 0A set 0x00
GPPUA 06 set to 0xff
IODIRA 00 set to 0x00

To drive a 1: configure the pin as an output (IODIR = 1) IODIRB 0x01 set 0x01
To drive a 0: configure the pin as an output (IODIR = 0) IODIRB 0x01 set 0x00

Open collector outputs from the MCP enabvle use of diode protection on the column
and row drivers.

For example, if bit 0 is a low drive (active high) and bit 1 is a high drive (active low), a
diode from bit 0 to 1 will keep both drives from turning on as a low on
the high drive input (active low) will turn off the low drive (active high) by pulling its input 
low through the diode.

*/