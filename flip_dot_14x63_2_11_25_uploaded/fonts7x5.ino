// ascii code
// control characters 0-31 plus 127
// printable characters 32-126
const static byte font_data_7x5[] = {
  0x55, 0x2A, 0x55, 0x2A, 0x55,  // 0x00 (checker 0) (was ascii nul)
  0x2A, 0x55, 0x2A, 0x55, 0x2A,  // 0x01 (checker 1) (was ascii soh)
  0x00, 0x14, 0x00, 0x00, 0x00,  // 0x02 (time left :) (was ascii stx)
  0x00, 0x00, 0x00, 0x14, 0x00,  // 0x03 (time right :) (was ascii etx)
  0x18, 0x3C, 0x7E, 0x3C, 0x18,  // 0x04 (eot)
  0x1C, 0x57, 0x7D, 0x57, 0x1C,  // 0x05 (enq)
  0x1C, 0x5E, 0x7F, 0x5E, 0x1C,  // 0x06 (ack)
  0x00, 0x18, 0x3C, 0x18, 0x00,  // 0x07 (bel)
  0xFF, 0xE7, 0xC3, 0xE7, 0xFF,  // 0x08 (bs)
  0x00, 0x18, 0x24, 0x18, 0x00,  // 0x09 (tab)
  0xFF, 0xE7, 0xDB, 0xE7, 0xFF,  // 0x0A (lf)
  0x30, 0x48, 0x3A, 0x06, 0x0E,  // 0x0B (vt)
  0x26, 0x29, 0x79, 0x29, 0x26,  // 0x0C (np)
  0x40, 0x7F, 0x05, 0x05, 0x07,  // 0x0D (cr)
  0x40, 0x7F, 0x05, 0x25, 0x3F,  // 0x0E (so)
  0x5A, 0x3C, 0xE7, 0x3C, 0x5A,  // 0x0F (si)
  0x7F, 0x3E, 0x1C, 0x1C, 0x08,  // 0x10 (dle)
  0x08, 0x1C, 0x1C, 0x3E, 0x7F,  // 0x11 (dc1)
  0x14, 0x22, 0x7F, 0x22, 0x14,  // 0x12 (dc2)
  0x5F, 0x5F, 0x00, 0x5F, 0x5F,  // 0x13 (dc3)
  0x06, 0x09, 0x7F, 0x01, 0x7F,  // 0x14 (dc4)
  0x00, 0x66, 0x89, 0x95, 0x6A,  // 0x15 (nak)
  0x60, 0x60, 0x60, 0x60, 0x60,  // 0x16 (syn)
  0x94, 0xA2, 0xFF, 0xA2, 0x94,  // 0x17 (etb)
  0x08, 0x04, 0x7E, 0x04, 0x08,  // 0x18 (can)
  0x10, 0x20, 0x7E, 0x20, 0x10,  // 0x19 (em)
  0x08, 0x08, 0x2A, 0x1C, 0x08,  // 0x1A (eof)
  0x08, 0x1C, 0x2A, 0x08, 0x08,  // 0x1B (esc)
  0x1E, 0x10, 0x10, 0x10, 0x10,  // 0x1C (fs)
  0x0C, 0x1E, 0x0C, 0x1E, 0x0C,  // 0x1D (gs)
  0x30, 0x38, 0x3E, 0x38, 0x30,  // 0x1E (rs)
  0x06, 0x0E, 0x3E, 0x0E, 0x06,  // 0x1F (us)
  0x00, 0x00, 0x00, 0x00, 0x00,  // 0x20 space
  0x00, 0x00, 0x5F, 0x00, 0x00,  // 0x21 !
  0x00, 0x07, 0x00, 0x07, 0x00,  // 0x22 "
  0x14, 0x7F, 0x14, 0x7F, 0x14,  // 0x23 #
  0x24, 0x2A, 0x7F, 0x2A, 0x12,  // 0x24 $
  0x23, 0x13, 0x08, 0x64, 0x62,  // 0x25 %
  0x36, 0x49, 0x56, 0x20, 0x50,  // 0x26 &
  0x00, 0x08, 0x07, 0x03, 0x00,  // 0x27 '
  0x00, 0x1C, 0x22, 0x41, 0x00,  // 0x28 (
  0x00, 0x41, 0x22, 0x1C, 0x00,  // 0x29 )
  0x2A, 0x1C, 0x7F, 0x1C, 0x2A,  // 0x2A *
  0x08, 0x08, 0x3E, 0x08, 0x08,  // 0x2B +
  0x00, 0x40, 0x20, 0x00, 0x00,  // 0x2C ,
  //0x00, 0x80, 0x70, 0x30, 0x00,  // 0x2C alt , font
  0x00, 0x08, 0x08, 0x08, 0x00,  // 0x2D -
  0x00, 0x00, 0x40, 0x00, 0x00,  // 0x2E .
  //0x00, 0x00, 0x60, 0x60, 0x00,  // 0x2E alt . font
  0x20, 0x10, 0x08, 0x04, 0x02,  // 0x2F /
  0x3E, 0x41, 0x41, 0x41, 0x3E,  // 0x30 0
  //0x3E, 0x51, 0x49, 0x45, 0x3E,  // 0x30 alt 0 font
  0x00, 0x42, 0x7F, 0x40, 0x00,  // 0x31 1
  0x42, 0x61, 0x51, 0x49, 0x46,  // 0x32 2
  0x22, 0x41, 0x49, 0x49, 0x36,  // 0x33 3
  //0x21, 0x41, 0x49, 0x4D, 0x33,  // 0x33 alt 3 font
  0x18, 0x14, 0x12, 0x7F, 0x10,  // 0x34 4
  0x27, 0x45, 0x45, 0x45, 0x39,  // 0x35 5
  0x3C, 0x4A, 0x49, 0x49, 0x30,  // 0x36 6
  0x01, 0x01, 0x79, 0x05, 0x03,  // 0x37 7
  0x36, 0x49, 0x49, 0x49, 0x36,  // 0x38 8
  0x06, 0x49, 0x49, 0x29, 0x1E,  // 0x39 9
  0x00, 0x00, 0x14, 0x00, 0x00,  // 0x3A :
  0x00, 0x40, 0x24, 0x00, 0x00,  // 0x3B ;
  0x00, 0x08, 0x14, 0x22, 0x41,  // 0x3C <
  0x00, 0x14, 0x14, 0x14, 0x00,  // 0x3D =
  0x00, 0x41, 0x22, 0x14, 0x08,  // 0x3E >
  0x02, 0x01, 0x59, 0x09, 0x06,  // 0x3F ?
  0x3E, 0x41, 0x5D, 0x59, 0x4E,  // 0x40 @
  0x7C, 0x12, 0x11, 0x12, 0x7C,  // 0x41 A
  0x7F, 0x49, 0x49, 0x49, 0x36,  // 0x42 B
  0x3E, 0x41, 0x41, 0x41, 0x22,  // 0x43 C
  0x7F, 0x41, 0x41, 0x41, 0x3E,  // 0x44 D
  0x7F, 0x49, 0x49, 0x49, 0x41,  // 0x45 E
  0x7F, 0x09, 0x09, 0x09, 0x01,  // 0x46 F
  0x3E, 0x41, 0x41, 0x51, 0x73,  // 0x47 G
  0x7F, 0x08, 0x08, 0x08, 0x7F,  // 0x48 H
  0x00, 0x41, 0x7F, 0x41, 0x00,  // 0x49 I
  0x20, 0x40, 0x41, 0x3F, 0x01,  // 0x4A J
  0x7F, 0x08, 0x14, 0x22, 0x41,  // 0x4B K
  0x7F, 0x40, 0x40, 0x40, 0x40,  // 0x4C L
  0x7F, 0x02, 0x1C, 0x02, 0x7F,  // 0x4D M
  0x7F, 0x04, 0x08, 0x10, 0x7F,  // 0x4E N
  0x3E, 0x41, 0x41, 0x41, 0x3E,  // 0x4F O
  0x7F, 0x09, 0x09, 0x09, 0x06,  // 0x50 P
  0x3E, 0x41, 0x51, 0x21, 0x5E,  // 0x51 Q
  0x7F, 0x09, 0x19, 0x29, 0x46,  // 0x52 R
  0x26, 0x49, 0x49, 0x49, 0x32,  // 0x53 S
  0x01, 0x01, 0x7F, 0x01, 0x01,  // 0x54 T
  0x3F, 0x40, 0x40, 0x40, 0x3F,  // 0x55 U
  0x1F, 0x20, 0x40, 0x20, 0x1F,  // 0x56 V
  0x3F, 0x40, 0x38, 0x40, 0x3F,  // 0x57 W
  0x63, 0x14, 0x08, 0x14, 0x63,  // 0x58 X
  0x03, 0x04, 0x78, 0x04, 0x03,  // 0x59 Y
  0x61, 0x51, 0x49, 0x45, 0x43,  // 0x5A Z 90
  //0x61, 0x59, 0x49, 0x4D, 0x43,  // 0x5A alt Z font
  0x00, 0x7F, 0x41, 0x41, 0x41,  // 0x5B [
  0x02, 0x04, 0x08, 0x10, 0x20,  // 0x5C backslash
  // (do not use actual backslash char here as it commented out following line) 
  0x00, 0x41, 0x41, 0x41, 0x7F,  // 0x5D ]
  0x04, 0x02, 0x01, 0x02, 0x04,  // 0x5E ^
  0x40, 0x40, 0x40, 0x40, 0x40,  // 0x5F _
  0x00, 0x03, 0x07, 0x08, 0x00,  // 0x60 ` (grave accent)
  0x20, 0x54, 0x54, 0x78, 0x40,  // 0x61 a 97
  0x7F, 0x28, 0x44, 0x44, 0x38,  // 0x62 b
  0x38, 0x44, 0x44, 0x44, 0x28,  // 0x63 c
  0x38, 0x44, 0x44, 0x28, 0x7F,  // 0x64 d
  0x38, 0x54, 0x54, 0x54, 0x18,  // 0x65 e
  0x00, 0x08, 0x7E, 0x09, 0x02,  // 0x66 f
  0x18, 0xA4, 0xA4, 0x9C, 0x78,  // 0x67 g
  0x7F, 0x08, 0x04, 0x04, 0x78,  // 0x68 h
  0x00, 0x44, 0x7D, 0x40, 0x00,  // 0x69 i
  0x20, 0x40, 0x40, 0x3D, 0x00,  // 0x6A j
  0x7F, 0x10, 0x28, 0x44, 0x00,  // 0x6B k
  0x00, 0x41, 0x7F, 0x40, 0x00,  // 0x6C l
  0x7C, 0x04, 0x78, 0x04, 0x78,  // 0x6D m
  0x7C, 0x08, 0x04, 0x04, 0x78,  // 0x6E n
  0x38, 0x44, 0x44, 0x44, 0x38,  // 0x6F o
  0xFC, 0x18, 0x24, 0x24, 0x18,  // 0x70 p
  0x18, 0x24, 0x24, 0x18, 0xFC,  // 0x71 q
  0x7C, 0x08, 0x04, 0x04, 0x08,  // 0x72 r
  0x48, 0x54, 0x54, 0x54, 0x24,  // 0x73 s
  0x04, 0x04, 0x3F, 0x44, 0x24,  // 0x74 t
  0x3C, 0x40, 0x40, 0x20, 0x7C,  // 0x75 u
  0x1C, 0x20, 0x40, 0x20, 0x1C,  // 0x76 v
  0x3C, 0x40, 0x30, 0x40, 0x3C,  // 0x77 w
  0x44, 0x28, 0x10, 0x28, 0x44,  // 0x78 x
  0x0C, 0x10, 0x10, 0x10, 0x7C,  // 0x79 y
  0x44, 0x64, 0x54, 0x4C, 0x44,  // 0x7A z
  0x00, 0x08, 0x36, 0x41, 0x00,  // 0x7B {
  0x00, 0x00, 0x77, 0x00, 0x00,  // 0x7C |
  0x00, 0x41, 0x36, 0x08, 0x00,  // 0x7D }
  0x02, 0x01, 0x02, 0x04, 0x02};  // 0x7E ~
  // not included 
  // 0x7F (127) would be ascii DEL (delete)
  // 0s80 (128) to 0xFF (255) are extended ascii used in 1981 IBM PC.

void get_char_fd_array_7x5(char char_out)
{
byte char_base_addr;
char_base_addr = byte(char_out);
for (int c = 0; c <= 4; c++){
  for (int r = 0; r <= 6; r++){
    fd_array_7x5[c][r] = ((font_data_7x5[(char_base_addr * 5) + c]) >> r) & 0x01; //bitwise and
    }  
  }
}

void displayLine_7x5() // displays input_str - one line up to 10 chars max
{ 
int strLength = strlen(input_str);  // includes '\0'
blankDisplay();
//clearTimeDisplay();  // turn time display off
for (int charNum = 0; charNum <= 9; charNum ++){
  if (charNum <= strLength){
    displayCharacter_7x5(charNum, toupper(input_str[charNum])); 
    }
    else{
      displayCharacter_7x5(charNum, ' '); // fill blanks
      }
    delay(25);  // for each character
    }
  return;
  }  

void scrolling_7x5_1()  // scrolling with setColumn
{
int numChar = strlen(input_str);
numChar = min(numChar, 50);  // 50 chars max
//int charCnt = 0; 
//int fontColCnt = 0;
fastBlankDisplay();
// clear array
for (int i = 0; i < 450; i++){ // columns
  colArray[i] = 0; 
  }
esp_task_wdt_reset();
// load scrolling font array with blank column between each character
for (int k = 0; k < numChar; k++){
  get_char_fd_array_7x5(input_str[k]);
  // load scrolling array 
  for (int l = 0; l < 6; l++){ // 6 columns to include blank column
    for (int m = 0; m < 7; m++){ // 7 rows
      // colArray holds up to 50 characters int colArray[450]
      if (l !=5){// blank column after each character
        // int modifyBit(int n, int k, int b) 
        // start at display column 63 starting on forth row
        colArray[63 + (k*6) + l] = modifyBit(colArray[63 + (k*6) + l], m + 4, fd_array_7x5[l][m]); 
        }
      }
    }
  }  
esp_task_wdt_reset();
// display scrolling font array
for (int base = 0; base < 63 + (numChar * 6) + 3; base = base + 3){  // base has 3 column speed
  // top range +3 allows full display clear
  for (int columnInput = 0; columnInput < 63; columnInput++){
    setColumnGroup_7x5(columnInput, colArray[base+columnInput]);  // display columns
    }
  esp_task_wdt_reset();
  }
return;
}  

void scrolling_7x5_2() // scrolling with setCell 
{// this also clears the display by scrolling off
int numChar = strlen(input_str);
numChar = min(numChar, 150);  // 150 chars max for now - 1000 columns in array
//int fontColCnt = 0;
int dotInput = 0;
fastBlankDisplay();
esp_task_wdt_reset();
// clear array
for (int i = 0; i < 1000; i++){ // columns
  for (int j = 0; j < 7; j++){ // rows
    scrolling_fd_array_7x5[i][j] = 0; 
    }
  esp_task_wdt_reset();
  }

// load scrolling font array with blank column between each character
for (int k = 0; k < numChar; k++){
  // get font array
  get_char_fd_array_7x5(input_str[k]);
  // load scrolling array 
  for (int p = 0; p < 6; p++){ // 6 columns to include blank column
    for (int m = 0; m < 7; m++){ // 7 rows
      // byte scrolling_fd_array_7x5 holds up to 150 characters [1000][7]
      if (p !=5)  {// 5th line is left blank  - byte fd_array_7x5[c][r]
        scrolling_fd_array_7x5[63 + (k*6) + p][m] = fd_array_7x5[p][m]; // start at column 63
        esp_task_wdt_reset();
        }
      }
    }
  }
esp_task_wdt_reset();
// print out array - for testing
//for (int n = 0; n < 450; n++){ // columns
//  for (int q = 0; q <= 6; q++){ // rows
//    Serial.print(scrolling_fd_array_7x5[n][q]);
//    }
//  Serial.println();
//  }
// display scrolling font array
for (int base = 0; base < 63 + (numChar * 6) + 3; base = base + 3){ // base has 3 column speed
  // top range +3 allows full display clear
  for (int columnInput = 0; columnInput < 63; columnInput++){ // display full screen each base increment
    for (int rowInput = 0; rowInput < 7; rowInput++){
      dotInput = scrolling_fd_array_7x5[base + columnInput][rowInput]; 
      // below is faster but causes somewhat eratic scroll speed
      //if (dotInput != scrolling_fd_array_7x5[base + columnInput - 3][rowInput]){ // do not redraw dots for speed
        setCell(columnInput, rowInput + 4, dotInput); // shift rows down 4 from top on display
        //}
      }  
    esp_task_wdt_reset();
    }
  esp_task_wdt_reset();
  }
return;
}

void displaySplitWords_7x5()
{
// display split words of input_str 
fastBlankDisplay();
delay1s();
word_cnt = 0;
int row_length = 10; // using 7x5 font for 10 characters
char *pch; 
// split the string on these delimiters into "tokens"
strcpy(input_str2, input_str); // new string needed as strtok is destructive
//pch = strtok (input_str2," ,"); 
pch = strtok (input_str2," "); // removed commas - now spaces only
sprintf(word_str[word_cnt], "%s", pch);
//Serial.println(word_str[word_cnt]);  // for testing
while(1)
  {
  pch = strtok (NULL, " ,"); // continue to split the string on these delimiters
  if (pch == NULL) {break;}  // this configuration was needed for while loop to work
  word_cnt++;
  sprintf(word_str[word_cnt], "%s", pch);
  }
// print out words  for testing
//Serial.println(input_str);
//Serial.println(word_cnt+1);
//Serial.println();
for (int i = 0; i <= word_cnt; i++) {  // note - first word is [0]
  word_str_length[i] = strlen(word_str[i]);
  if (word_str_length[i] >= row_length - 2) { 
    // above subtract two to add '-' and due to starting row posiiton at 0 not 1
    // make room for additional word
    for (int j = word_cnt; j > i; j--) {
      strcpy(word_str[j+1], word_str[j]);
      }
    // trim end and hyphenate first part
    // note - the following generates a warning - "accessing 1 byte at offsets [0, 2688] and [0, 2688] may overlap 1 byte at offset 0" ??
    strcpy(word_str[i+1], word_str[i]);
    word_str[i][11] = '-';
    word_str[i][12] = '\0';
    // copy and trim front of second part 
    for (int m = 0; m <= (word_str_length[i] - (row_length - 1)); m++){
      word_str[i+1][m] = word_str[i+1][m + (row_length - 1)]; // capture null character
      //Serial.println(word_str[i+1][m]);
      }
    // update new string lengths
    word_str_length[i] = strlen(word_str[i]);
    word_str_length[i+1] = strlen(word_str[i+1]);
    // update loop variables for added word
    i++;;
    word_cnt++;
    //Serial.println(word_str_length[i]);
    }
  }
// for testing
//for (int i = 0; i <= word_cnt; i++) { 
//  Serial.print(word_str[i]);
//  Serial.print("  ");
//  Serial.println(word_str_length[i]);
//  }
//Serial.println();
// assemble row lines
int new_row_flag = 1;
row_number = 0;
for (int i = 0; i <= word_cnt; i++) {
  if (new_row_flag == 1){ // this really is only for the first row
    strcpy(row_display_array[row_number], word_str[i]);
    //Serial.println(row_display_array[row_number]);
    new_row_flag = 0;
    }
  else { 
    if ((strlen(row_display_array[row_number]) + word_str_length[i]) <= (row_length - 1)) { 
      // row length includes '\0'
      // two '\0' make up for space and last '\0'
      strcat(row_display_array[row_number], " ");  // add space between words
      strcat(row_display_array[row_number], word_str[i]);
      //Serial.println(row_display_array[row_number]);
      }
    else {  // make new row
      row_number++; 
      strcpy(row_display_array[row_number], word_str[i]);
      //Serial.println(row_display_array[row_number]);
      new_row_flag = 0;
      }
    }
  }
// add spaces to fill each row
for (int i = 0; i <= row_number; i++){
  int k;
  int j = row_length - 1 - strlen(row_display_array[i]);
  for (k = 0; k <= j; k++) {
    strcat(row_display_array[i], " ");  // add space after word(s)
    }
  //Serial.print(row_display_array[i]);
  //Serial.println("end");
  }

// display each row with delay
blankDisplay();
for (int i = 0; i <= row_number; i++){
  for (int charNum = 0; charNum <=9; charNum++){ 
    displayCharacter_7x5(charNum, toupper(row_display_array[i][charNum])); // [32][20]
    }
  delay3s();
  }
}

void displayCharacter_7x5(int charNum, char charOut)
{
// for 7x5 font
int dotInput;
get_char_fd_array_7x5(charOut); // populates fd_array 7x5 with charOut
// display font
for (int columnInput = 0; columnInput <= 4; columnInput++){ // font is 5 by 7
  for (int rowInput = 0; rowInput <= 6; rowInput++){
    dotInput = fd_array_7x5[columnInput][rowInput]; // get dot value
    // 1 space between chars.  Also start at column 2 and row 4
    setCell(columnInput + 2 + (charNum * (5+1)), (rowInput + 4), dotInput); // adjust columns by charNum
    }  
  }
return;
}

void displayTimeString_7x5()
{ // text displayed in global input_str
// for 7x5 font - screen otherwise blanked
int numChar = strlen(input_str);
// clear array
for (int i = 0; i < 63; i++){ // columns
  colArray[i] = 0; 
  }
// get font array
// void setColumnGroup(int column, int rowStates)
for (int k = 0; k < numChar; k++){
  get_char_fd_array_7x5(input_str[k]);  // populated fd_array_7x5
  // load colArray 
  for (int l = 0; l < 6; l++){ // 6 columns to include blank column
    for (int m = 0; m < 7; m++){ // 7 rows
      // colArray holds up to 50 characters int colArray[450]
      if (l !=5){// blank column after each character
        // int modifyBit(int n, int k, int b) 
        // start at display column 2 on row 4
        colArray[(k*6) + l + 2] = modifyBit(colArray[(k*6) + l + 2], m + 4, fd_array_7x5[l][m]); 
        }
      }
    }
  }  
// display font array
for (int columnInput = 0; columnInput < 63; columnInput++){
  setColumnGroup(columnInput, colArray[columnInput]);  // display columns
  //setColumnGroup_7x5(columnInput, colArray[columnInput]);  // display columns
  }
return;
}  
