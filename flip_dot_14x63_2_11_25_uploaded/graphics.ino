// add screen open and close and yellow/black dot snake from center out
void graphicsMenu()
{
terminal.println("@01   - fast fill display");
terminal.println("@02   - fast blank display");
terminal.println("@03   - test checker pattern display");
terminal.println("@04   - test columns and rows display");
terminal.println("@05   - random dot display");
terminal.println("@06   - snake display");
terminal.println("@07   - fast snake display");
terminal.println("@08   - fast snake display 3 boards in order");
terminal.println("@09   - fast snake display 3 boards at once");
terminal.println("@10   - fill display with column group");
terminal.println("@11   - more fill display with column group");
terminal.println("@12   - bumper columns");
terminal.println("@13   - curtain close");
terminal.println("@14   - curtain open");
terminal.println("@15   - snake wind out");
terminal.println("@16   - fast snake wind out");
terminal.println("@17   - swirls");

// personal scrolling
terminal.println("@30   - ok ok ok"); 
terminal.println("@31   - hello hello andrew et al");
terminal.println("@32   - lets play cars");
terminal.println("@33   - actually not 5 minutes");
terminal.println("@34   - all day long");
terminal.println("@35   - goodnight all day");
terminal.println("@36   - what are you talking about");
terminal.println("@37   - you are not listening");
terminal.println("@38   - i tell you");
terminal.println("@39   - s hello hello andrew et al");
// scrolling quotes
terminal.println("@50   - art is anything -andy warhol"); // to dos
terminal.println("@51   - you cant always get -rolling stones"); 
terminal.println("@52   - the wolf cares not - plato"); 
terminal.println("@53   - when one tugs - john muir"); 
terminal.println("@54   - the snow is melting into -john muir"); 
terminal.println("@55   - every momment -ts elliot"); 
terminal.println("@56   - is life but a dream."); 
terminal.println("@57   - the right question -plato");
terminal.println("@58   - things are not always what they seem.");
terminal.println("@59   - simplicity is the ultimate -de vinci");
terminal.println("@60   - one small step for man -neil armstrong");
terminal.println("@61   - appreciate the moment.");
terminal.println("@62   - still california dreaming.");
terminal.println("@63   - showing up is 80 percent of -andy warhol");
terminal.println("@64   - water is relentless -john muir");
terminal.println("@65   - may you live every day -jonathan swift"); 
terminal.println("@66   - we live in an age when -oscar wilde");
terminal.println("@67   - the art of being wise is -william james");
terminal.println("@68   - we become what we contemplate -plato");
terminal.println("@70   - youtube 1");


// GOL 
terminal.println("@80   - game of life random");
terminal.println("@81   - game of life row line");
terminal.println("@82   - game of life column line");
terminal.println("@83   - game of life gliders");
terminal.println("@84   - game of life circles");
terminal.println("@85   - game of life random - no wrap");
terminal.println("@86   - game of life row line - no wrap");
terminal.println("@87   - game of life column line - no wrap");
terminal.println("@88   - game of life gliders - no wrap");
terminal.println("@89   - game of life circles- no wrap");
// Tetris
terminal.println("@90   - tetris1");
terminal.println("@91   - tetris2");
terminal.println(); // add line feed
terminal.flush();
Blynk.run();
return;
}

void randomGraphicDisplay()
{
// select and display random graphics
int graphic_lookup[10] = {31, 32, 33, 34, 35, 36, 37, 38, 39};
int number_graphics = 9;
updateTime();
srand(millis()); // seed random number generator with somewhat random number
int j = rand() % number_graphics;
graphic_num = graphic_lookup[j];
while(graphic_num == graphic_num_old) {  // avoid randomly repeating same graphic
  srand(millis()); // seed random number gernerator with somewhat random number
  j = rand() % number_graphics;
  graphic_num = graphic_lookup[j];
  }  
//terminal.println(graphic_num);  // for testing
//terminal.flush();
//Blynk.run();
graphicDisplay();  // graphicDisplay uses graphic_num integer to decode
graphic_num_old = graphic_num;
}

void graphicDisplay()
{
switch(graphic_num) { // uses stored global int graphic_num
  case 1:   fastFillDisplay3x(); break;
  case 2:   fastBlankDisplay3x(); break;
  case 3:   smallChecker(); break;
  case 4:   columnsThenRows(); break;
  case 5:   randomDots(); break;
  case 6:   snake(50); break; // slow snake
  case 7:   snake(1); break; // fast snake
  case 8:   snakesInOrder(10); break;
  case 9:   snakesAtOnce(10); break;
  case 10:  columnGroups(); break;
  case 11:  columnGroupsMore(); break;
  case 12:  bumperColumns(15); break;
  case 13:  curtainClose(); break;
  case 14:  curtainOpen(); break;
  case 15:  snakeWindOut_Y(50); break;
  case 16:  snakeWindOut_Y(1); break;
  case 17:  swirl1(); swirl2(); break;
  case 30:  strcpy(input_str, "OK OK OK"); 
              displaySplitWords_7x5(); break; 
  case 31:  strcpy(input_str, "HELLO ANDREW, AUSTIN, COLE, KIM AND JOHN"); 
               displaySplitWords_7x5(); fastBlankDisplay(); break;
  case 32:  strcpy(input_str, "LETS PLAY CARS"); 
              displaySplitWords_7x5(); break;
  case 33:  strcpy(input_str, "ACTUALLY NOT 5 MINUTES - 12 MINUTES"); 
              displaySplitWords_7x5(); fastBlankDisplay(); break;
  case 34:  strcpy(input_str, "ALL DAY LONG"); 
              displaySplitWords_7x5(); break;
  case 35:  strcpy(input_str, "GOODNIGHT ALL DAY"); 
              displaySplitWords_7x5(); break;
  case 36:  strcpy(input_str, "WHAT ARE YOU TALKING ABOUT"); 
              displaySplitWords_7x5(); break;
  case 37:  strcpy(input_str, "YOU ARE NOT LISTENING");
              displaySplitWords_7x5(); break;
  case 38:  strcpy(input_str, "I TELL YOU");
              displaySplitWords_7x5(); break;
  // scrolling
  case 39:  strcpy(input_str, "HELLO HELLO ANDREW, AUSTIN, COLE, KIM AND JOHN"); 
               scrolling_7x5_2(); break;
  
  // scrolling quotes
  case 50:  strcpy(input_str, "ART IS ANYTHING ART YOU CAN GET AWAY WITH  -ANDY WARHOL."); 
               scrolling_7x5_2(); break;
  case 51:  strcpy(input_str, "YOU CAN'T ALWAYS GET WHAT YOU WANT        BUT IF YOU TRY SOMETIMES        YOU JUST MIGHT FIND        YOU GET WHAT YOU NEED  -ROLLING STONES."); 
               scrolling_7x5_2(); break;
  case 52:  strcpy(input_str, "THE WOLF CARES NOT HOW MANY THE SHEEP BE  -PLATO."); 
               scrolling_7x5_2(); break;
  case 53:  strcpy(input_str, "WHEN ONE TUGS AT A SINGLE STRING IN NATURE HE FINDS IT ATTACHED TO THE REST OF THE WORLD  -JOHN MUIR."); 
               scrolling_7x5_2(); break;
  case 54:  strcpy(input_str, "THE SNOW IS MELTING INTO MUSIC  -JOHN MUIR.");  
               scrolling_7x5_2(); break;
  case 55:  strcpy(input_str, "EVERY MOMENTIS A FRESH BEGINNING  -TS ELLIOT."); 
               scrolling_7x5_2(); break;
  case 56:  strcpy(input_str, "IS LIFE BUT A DREAM."); 
               scrolling_7x5_2(); break;
  case 57:  strcpy(input_str, "THE RIGHT QUESTION IS USUALLY MORE IMPORTANT THAN THE RIGHT ANSWER  -PLATO."); 
               scrolling_7x5_2(); break;
  case 58:  strcpy(input_str, "THINGS ARE NOT ALWAYS WHAT THEY SEEM.");
               scrolling_7x5_2(); break;
  case 59:  strcpy(input_str, "SIMPLICITY IS THE ULTIMATE SOPHISTICATION  -DE VINCI."); 
               scrolling_7x5_2(); break;
  case 60:  strcpy(input_str, "ONE SMALL STEP FOR MAN, ONE GIANT LEAP FOR MANKIND  -NEIL ARMSTRONG."); 
               scrolling_7x5_2(); break;
  case 61:  strcpy(input_str, "APPRECIATE THE MOMENT."); 
               scrolling_7x5_2(); break;
  case 62:  strcpy(input_str, "STILL CALIFORNIA DREAMING."); 
               scrolling_7x5_2(); break;
  case 63:  strcpy(input_str, "SHOWING UP IS 80 PERCENT OF LIFE.  -ANDY WARHOL."); 
               scrolling_7x5_2(); break;
  case 64:  strcpy(input_str, "WATER IS RELENTLESS IN ITS QUEST DOWNWARD  -JOHN MUIR."); 
               scrolling_7x5_2(); break;
  case 65:  strcpy(input_str, "MAY YOU LIVE EVERY DAY OF YOUR LIFE  -JONATHAN SWIFT."); 
               scrolling_7x5_2(); break;
  case 66:  strcpy(input_str, "WE LIVE IN AN AGE WHEN UNNECESSARY THINGS ARE OUR ONLY NECESSITIES  -OSCAR WILDE."); 
               scrolling_7x5_2(); break;
  case 67:  strcpy(input_str, "THE ART OF BEING WISE IS KNOWING WHAT TO OVERLOOK  -WILLIAM JAMES."); 
               scrolling_7x5_2(); break;
  case 68:  strcpy(input_str, "WE BECOME WHAT WE CONTEMPLATE -PLATO."); 
               scrolling_7x5_2(); break;
  
  case 70:  strcpy(input_str, "FLIP DOTS!"); // youtube 1
            displayLine_7x5();
            delay4s();
            fastBlankDisplay3x(); 
            smallChecker(); 
            columnsThenRows();
            snake(25); // slow snake
            strcpy(input_str, " FASTER!  "); 
            displayLine_7x5();
            terminal.println("  done faster");  // this does not print for some reason
            delay2s();  // includes Blynk.run()
            snake(1); // fast snake
            snakesAtOnce(10); 
            columnGroupsMore(); 
            snakeWindOut_Y(10); 
            snakeWindOut_Y(1); 
            curtainOpen();
            strcpy(input_str, "THE END FOR NOW"); 
            scrolling_7x5_2(); // this also clears the display by scrolling off
            swirl2();
            delay2s();
            fastBlankDisplay();
            terminal.println("  done end"); 
            terminal.flush();
            Blynk.run();
            break;
  
  case 80:  GOL(0, 1); break; // random - wrap  // GOL on seperate GLO.ino page
  case 81:  GOL(1, 1); break; // row line
  case 82:  GOL(2, 1); break; // column line
  case 83:  GOL(3, 1); break; // gliders
  case 84:  GOL(4, 1); break; // circles
  case 85:  GOL(0, 0); break; // random - no wrap  
  case 86:  GOL(1, 0); break; // row line
  case 87:  GOL(2, 0); break; // column line
  case 88:  GOL(3, 0); break; // gliders
  case 89:  GOL(4, 0); break; // circles
  case 90:  t1_tetris_loop(); break; // tetris game test on tetris1.ino
  case 91:  t2_tetris_loop(); break; // tetris game test on tetris2.ino
  default:  break; // optional, if nothing else matches, do the default
  }   
}  // end of void graphicDisplay()

// @01
void fastFillDisplay3x()
{
delay200ms();
fastBlankDisplay();
delay200ms();
fastFillDisplay();
delay200ms();
fastBlankDisplay();
delay200ms();
fastFillDisplay();
delay200ms();
fastBlankDisplay();
delay200ms();
fastFillDisplay();
return;
}  

// @02
void fastBlankDisplay3x()
{
delay200ms();
fastFillDisplay();
delay200ms();
fastBlankDisplay();
delay200ms();
fastFillDisplay();
delay200ms();
fastBlankDisplay();
delay200ms();
fastFillDisplay();
delay200ms();
fastBlankDisplay();
return;
}

// @03
void smallChecker()
{
fastBlankDisplay();
int dotInput = 0;
for (int pass = 0; pass < 3; pass++){
  for (int columnInput = 0; columnInput <= 62; columnInput++){ // left to right
    if (dotInput == 1) {dotInput = 0;} // flip first dot input each column
    else {dotInput = 1;}
    for (int rowInput = 0; rowInput <=13; rowInput++){
      setCell(columnInput, rowInput, dotInput);
      if (dotInput == 1) {dotInput = 0;} // flip dot input each row
      else {dotInput = 1;}
      }
  esp_task_wdt_reset();  // reset wdt
  delay(10);
  }
  for (int columnInput = 0; columnInput <= 62; columnInput++){ // right to left
    if (dotInput == 1) {dotInput = 0;} // flip first dot input each column
    else {dotInput = 1;}
    for (int rowInput = 0; rowInput <=13; rowInput++){
      setCell(columnInput, rowInput, dotInput);
      if (dotInput == 1) {dotInput = 0;} // flip dot input each row
      else {dotInput = 1;}
      }
    esp_task_wdt_reset();  // reset wdt
    delay(10);
    }
  }
blankDisplay();
return;
}

// @04
void columnsThenRows()
{   
fastBlankDisplay();
  int dotInput = 1; // y - yellow,  b - black, o - off
  for (int columnInput = 0; columnInput <= 62; columnInput++){
    for (int rowInput = 0; rowInput <=13; rowInput++){
      setCell(columnInput, rowInput, dotInput);
      }  
    delay50ms();  // faster for columns
    }
  dotInput = 0;
  for (int columnInput = 0; columnInput <= 62; columnInput++){
    for (int rowInput = 0; rowInput <=13; rowInput++){
      setCell(columnInput, rowInput, dotInput);
      }  
    delay50ms();
    }
  // rows
  dotInput = 1;
  for (int rowInput = 0; rowInput <=13; rowInput++){
    for (int columnInput = 0; columnInput <= 62; columnInput++){
      setCell(columnInput, rowInput, dotInput);
      }
    delay200ms();
    }
  dotInput = 0;
  for (int rowInput = 0; rowInput <=13; rowInput++){
    for (int columnInput = 0; columnInput <= 62; columnInput++){
      setCell(columnInput, rowInput, dotInput);
      }  
    delay200ms();
    }
return;
}

// 05
void randomDots()
{
fastBlankDisplay();
fullRandom(5000);  
fastBlankDisplay();  // double blank helps to settle magnets after random display
delay(10);
fastBlankDisplay();
return;
}

// @06 - @07
void snake(int fDelay)
{ 
// snake display function - starts top left going down
// fDelay is delay between dots in milliseconds
// 50 is slow, 1 is fast
fastBlankDisplay();
int dotInput = 1;
int columnStart = 0;
int columnEnd = 62;
int rowStart = 0;
int rowEnd = 13;
int moves;
int movesMax = 28;  // 7 times 4 plus - even ending
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  for (int columnInput = columnStart; columnInput <=columnEnd; columnInput++){
    setCell(columnInput, rowEnd, dotInput);
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // top left
  for (int columnInput = columnEnd; columnInput >= columnStart; columnInput--){
    setCell(columnInput, rowStart, dotInput);
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  }
esp_task_wdt_reset();  // reset wdt
fastFillDisplay();  // this is a bit of delay also
// then black snake
esp_task_wdt_reset();  // reset wdt// then black snake
dotInput = 0; // these variables need to be changed or reset
columnStart = 0; 
columnEnd = 62;
rowStart = 0;
rowEnd = 13;
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  for (int columnInput = columnStart; columnInput <=columnEnd; columnInput++){
    setCell(columnInput, rowEnd, dotInput);
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // top left
  for (int columnInput = columnEnd; columnInput >= columnStart; columnInput--){
    setCell(columnInput, rowStart, dotInput);
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  }
esp_task_wdt_reset();  // reset wdt
fastBlankDisplay(); 
// make sure all blank
esp_task_wdt_reset();  // reset wdt
return;
}

// @08
void snakesInOrder(int fDelay)
{ 
// three boards in order
// fDelay is delay in ms between dots   
fastBlankDisplay();
int dotInput = 1;
int columnStart = 0;
int columnEnd = 20;
int rowStart = 0;
int rowEnd = 13;
int moves;
int movesMax = 28;  // 7 times 4 plus - even ending
// Board 0 columns 0-20
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  for (int columnInput = columnStart; columnInput <=columnEnd; columnInput++){
    setCell(columnInput, rowEnd, dotInput);
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // top left
  for (int columnInput = columnEnd; columnInput >= columnStart; columnInput--){
    setCell(columnInput, rowStart, dotInput);
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
}
// Board 1 columns 21-41
dotInput = 1;
columnStart = 21;
columnEnd = 41;
rowStart = 0;
rowEnd = 13;
movesMax = 28; 
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  for (int columnInput = columnStart; columnInput <=columnEnd; columnInput++){
    setCell(columnInput, rowEnd, dotInput);
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // top left
  for (int columnInput = columnEnd; columnInput >= columnStart; columnInput--){
    setCell(columnInput, rowStart, dotInput);
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
}
// Board 3 columns 42-62
dotInput = 1;
columnStart = 42;
columnEnd = 62;
rowStart = 0;
rowEnd = 13;
movesMax = 28;    
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  for (int columnInput = columnStart; columnInput <=columnEnd; columnInput++){
    setCell(columnInput, rowEnd, dotInput);
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // top left
  for (int columnInput = columnEnd; columnInput >= columnStart; columnInput--){
    setCell(columnInput, rowStart, dotInput);
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
}
fastFillDisplay();  // this is a bit of delay also
// then black snake
// Board 0 columns 0-20
dotInput = 0; // these variables need to be changed or reset
columnStart = 0; 
columnEnd = 20;
rowStart = 0;
rowEnd = 13;
movesMax = 28;
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  for (int columnInput = columnStart; columnInput <=columnEnd; columnInput++){
    setCell(columnInput, rowEnd, dotInput);
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // top left
  for (int columnInput = columnEnd; columnInput >= columnStart; columnInput--){
    setCell(columnInput, rowStart, dotInput);
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  }
// Board 1 columns 21 to 41
dotInput = 0; // these variables need to be changed or reset
columnStart = 21; 
columnEnd = 41;
rowStart = 0;
rowEnd = 13;
movesMax = 28;
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  for (int columnInput = columnStart; columnInput <=columnEnd; columnInput++){
    setCell(columnInput, rowEnd, dotInput);
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // top left
  for (int columnInput = columnEnd; columnInput >= columnStart; columnInput--){
    setCell(columnInput, rowStart, dotInput);
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  }
// Board 2 columns 42-62
dotInput = 0; // these variables need to be changed or reset
columnStart = 42; 
columnEnd = 62;
rowStart = 0;
rowEnd = 13;
movesMax = 28;
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  for (int columnInput = columnStart; columnInput <=columnEnd; columnInput++){
    setCell(columnInput, rowEnd, dotInput);
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // top left
  for (int columnInput = columnEnd; columnInput >= columnStart; columnInput--){
    setCell(columnInput, rowStart, dotInput);
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
}
delay1s();
fastBlankDisplay(); 
// make sure all blank
esp_task_wdt_reset();  // reset wdt
return;
}

// @09 3 snakes - 1 per board
void snakesAtOnce(int fDelay){ 
// three boards at once
// fDelay is delay between dots 
fastBlankDisplay();
int dotInput = 1;
int columnStart0 = 0;
int columnEnd0 = 20;
int rowStart = 0;
int rowEnd = 13;
int columnStart1 = 21;
int columnEnd1 = 41;
int columnStart2 = 42;
int columnEnd2 = 62;
int moves;
int movesMax = 28;  // 7 times 4 plus - even ending
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart0, rowInput, dotInput);
    setCell(columnStart1, rowInput, dotInput);
    setCell(columnStart2, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart0++;
  columnStart1++;
  columnStart2++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  int columnInput1 = columnStart1;
  int columnInput2 = columnStart2;
  for (int columnInput0 = columnStart0; columnInput0 <=columnEnd0; columnInput0++){
    setCell(columnInput0, rowEnd, dotInput);
    setCell(columnInput1, rowEnd, dotInput);
    columnInput1++;
    setCell(columnInput2, rowEnd, dotInput);
    columnInput2++;
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd0, rowInput, dotInput);
    setCell(columnEnd1, rowInput, dotInput);
    setCell(columnEnd2, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd0--;
  columnEnd1--;
  columnEnd2--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  columnInput1 = columnEnd1;
  columnInput2 = columnEnd2;
  // top left
  for (int columnInput0 = columnEnd0; columnInput0 >= columnStart0; columnInput0--){
    setCell(columnInput0, rowStart, dotInput);
    setCell(columnInput1, rowStart, dotInput);
    columnInput1--;
    setCell(columnInput2, rowStart, dotInput);
    columnInput2--;
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  }
fastFillDisplay();  // this is a bit of delay also
// these variables need to be changed or reset
dotInput = 0;
columnStart0 = 0;
columnEnd0 = 20;
rowStart = 0;
rowEnd = 13;
columnStart1 = 21;
columnEnd1 = 41;
columnStart2 = 42;
columnEnd2 = 62;
movesMax = 28;  // 7 times 4 plus - even ending
for (moves = 0; moves < movesMax;){     
  //left side down
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnStart0, rowInput, dotInput);
    setCell(columnStart1, rowInput, dotInput);
    setCell(columnStart2, rowInput, dotInput);
    delay(fDelay);
    }
  columnStart0++;
  columnStart1++;
  columnStart2++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // bottom right
  int columnInput1 = columnStart1;
  int columnInput2 = columnStart2;
  for (int columnInput0 = columnStart0; columnInput0 <=columnEnd0; columnInput0++){
    setCell(columnInput0, rowEnd, dotInput);
    setCell(columnInput1, rowEnd, dotInput);
    columnInput1++;
    setCell(columnInput2, rowEnd, dotInput);
    columnInput2++;
    delay(fDelay);
    }
  rowEnd--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowEnd; rowInput >=rowStart; rowInput--){
    setCell(columnEnd0, rowInput, dotInput);
    setCell(columnEnd1, rowInput, dotInput);
    setCell(columnEnd2, rowInput, dotInput);
    delay(fDelay);
    }
  columnEnd0--;
  columnEnd1--;
  columnEnd2--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  columnInput1 = columnEnd1;
  columnInput2 = columnEnd2;
  // top left
  for (int columnInput0 = columnEnd0; columnInput0 >= columnStart0; columnInput0--){
    setCell(columnInput0, rowStart, dotInput);
    setCell(columnInput1, rowStart, dotInput);
    columnInput1--;
    setCell(columnInput2, rowStart, dotInput);
    columnInput2--;
    delay(fDelay);
    }
  rowStart++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  }
fastBlankDisplay(); 
// make sure all blank
esp_task_wdt_reset();  // reset wdt
return;
}

// @10
void columnGroups()
{
int rowStates = 0b11111111111111;  // 14 rows
for (int column = 0;  column <= 62; column++){ // 63 columns
  setColumnGroup(column, rowStates);
  }
delay1s();
fastBlankDisplay();
for (int ipass = 0; ipass <=2; ipass ++){
  rowStates = 0b11001100110011; // sb14
    for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  delay200ms();
  rowStates = 0b00110011001100; 
    for (int column = 0;  column <= 62; column++){
      setColumnGroup(column, rowStates);
      }
  delay200ms();
  }
blankDisplay(); //slow blank
return;
}
  
// @11
void columnGroupsMore()
{  // more fill display with column group
int rowStates = 0b11111111111111;  // sb 14
// slow
for (int column = 0;  column <= 62; column++){
  setColumnGroup(column, rowStates);
  }
delay1s();
rowStates = 0b00000000000000;  // sb 14
  for (int column = 0;  column <= 62; column++){
  setColumnGroup(column, rowStates);
  }
delay1s();
// fast
rowStates = 0b11111111111111;  // sb 14
for (int column = 0;  column <= 62; column++){
  setColumnGroup(column, rowStates);
  }
esp_task_wdt_reset();  // reset wdt
rowStates = 0b00000000000000;  // sb 14
  for (int column = 0;  column <= 62; column++){
  setColumnGroup(column, rowStates);
  }
esp_task_wdt_reset();  // reset wdt
rowStates = 0b11111111111111;  // sb 14
  for (int column = 0;  column <= 62; column++){
  setColumnGroup(column, rowStates);
  }
esp_task_wdt_reset();  // reset wdt
rowStates = 0b00000000000000;  // sb 14
for (int column = 0;  column <= 62; column++){
  setColumnGroup(column, rowStates);
  }
delay1s();
// now fast rows 2x
for (int pass = 0; pass <=1; pass++) {
  rowStates = 0b11001100110011;  // sb 14
  for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b00110011001100;  // sb 14
  for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b11001100110011;  // sb 14
  for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b00110011001100;  // sb 14
  for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b11001100110011;  // sb 14
  for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b00110011001100;  // sb 14
  for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  delay750ms();
  // slow blank here
  blankDisplay();
  // shift
  rowStates = 0b11100111100111;  // sb 14
  for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b00011000011000;  // sb 14
    for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b11100111100111;  // sb 14
    for (int column = 0;  column <= 62; column++){
      setColumnGroup(column, rowStates);
      }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b00011000011000;  // sb 14
    for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b11100111100111;  // sb 14
    for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  esp_task_wdt_reset();  // reset wdt
  rowStates = 0b00011000011000;  // sb 14
  for (int column = 0;  column <= 62; column++){
    setColumnGroup(column, rowStates);
    }
  delay750ms();
  // slow blank here
  blankDisplay();
  }  // end of fast rows
return;
}

// @12
void bumperColumns(int fDelay){
// bumper columns
// fDelay is delay between columns
int columnStart = 0;
int columnEnd = 62;
//int rowStart = 0;
//int rowEnd = 13;
int moves;
int movesMax = 27;  // (63-2) / 2 - middle meet with 7 spaces
// initialize columns
fastBlankDisplay();
delay(10);
moveColumn(columnStart, columnStart, 1); 
moveColumn(columnEnd, columnEnd, 1); 
delay250ms();  // 250ms delay when columns on outside
// move columns in
for (moves = 0; moves < movesMax;){     
  moveColumn(columnStart, columnStart + 1, 2);
  moveColumn(columnEnd, columnEnd - 1, 2);
  columnEnd--; 
  columnStart++;
  // column delay
  delay(fDelay);
  moves++;
  //esp_task_wdt_reset();  // reset wdt
  }
// move columns out
for (moves = 0; moves < movesMax;){     
  moveColumn(columnStart, columnStart - 1, 2);
  moveColumn(columnEnd, columnEnd + 1, 2);
  columnEnd++; 
  columnStart--;
  // column delay
  delay(fDelay);
  moves++;
  //esp_task_wdt_reset();  // reset wdt
  }
delay250ms();
movesMax = 29;  // (63-2) / 2 - middle meet with 3 spaces
// move columns in
for (moves = 0; moves < movesMax;){     
  moveColumn(columnStart, columnStart + 1, 2);
  moveColumn(columnEnd, columnEnd - 1, 2);
  columnEnd--; 
  columnStart++;
  // column delay
  delay(fDelay);
  moves++;
  //esp_task_wdt_reset();  // reset wdt
  }
// move columns out
for (moves = 0; moves < movesMax;){     
  moveColumn(columnStart, columnStart - 1, 2);
  moveColumn(columnEnd, columnEnd + 1, 2);
  columnEnd++; 
  columnStart--;
  // column delay
  delay(fDelay);
  moves++;
  //esp_task_wdt_reset();  // reset wdt
  }
delay250ms();
// move columns in
movesMax = 30;
for (moves = 0; moves < movesMax;){     
  moveColumn(columnStart, columnStart + 1, 2);
  moveColumn(columnEnd, columnEnd - 1, 2);
  columnEnd--; 
  columnStart++;
  // column delay
  delay(fDelay);
  moves++;
  //esp_task_wdt_reset();  // reset wdt
  }
// move columns out
for (moves = 0; moves < movesMax;){     
  moveColumn(columnStart, columnStart - 1, 2);
  moveColumn(columnEnd, columnEnd + 1, 2);
  columnEnd++; columnStart--;
  // column delay
  delay(fDelay);
  moves++;
  //esp_task_wdt_reset();  // reset wdt
  }
delay250ms();
// move columns in
movesMax = 31;  // columns meet in middle
for (moves = 0; moves < movesMax;){     
  moveColumn(columnStart, columnStart + 1, 2);
  moveColumn(columnEnd, columnEnd - 1, 2);
  columnEnd--; columnStart++;
  // column delay
  delay(fDelay);
  moves++;
  esp_task_wdt_reset();  // reset wdt
  }
// blow up columns
for (int rowInput = 0; rowInput <= 13; rowInput++){ 
    setCell(columnEnd, rowInput, 0);
    rowInput++;  // every other center column row goes blank
  }
delay50ms();
centerRandom(100);  
fastBlankDisplay(); // double blank helps to settle magnets after random display
delay25ms();
fastBlankDisplay();
return;
}

// @13
void curtainClose()
{
int rowStates = 0b11111111111111;  // 14 rows
for (int column = 0;  column <= 31; column++){ // 63 columns
  setColumnGroup(column, rowStates);
  setColumnGroup(62-column, rowStates);
    }
  fastFillDisplay();
  return;
}

// @14
void curtainOpen()
{
int rowStates = 0b00000000000000;  // 14 rows
fastFillDisplay();
for (int column = 0;  column <= 31; column++){ // 63 columns
  setColumnGroup(31 - column, rowStates);
  setColumnGroup(column + 31, rowStates);
    }
  fastBlankDisplay();
  return;
}

// @15 - @16
void snakeWindOut_Y(int fDelay)
{ 
// snake display function - starts center going out
// fDelay is delay between dots in milliseconds
// 50 is slow, 1 is fast
fastBlankDisplay();
int dotInput = 1;
int columnStart = 6;
int columnEnd = 56;
int rowStart = 6;
int rowEnd = 7;
int moves;
int movesMax = 28;  // 7 times 4 plus - even ending
for (moves = 0; moves < movesMax;){     
  // top right
  for (int columnInput = columnStart; columnInput <= columnEnd; columnInput++){
    setCell(columnInput, rowStart, dotInput);
    delay(fDelay);
    }
  columnStart--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // right side up
  for (int rowInput = rowStart; rowInput <=rowEnd; rowInput++){
    setCell(columnEnd, rowInput, dotInput);
    delay(fDelay);
    }
  rowStart--;
  moves++;
  esp_task_wdt_reset();  // reset wdt
  // top left
  for (int columnInput = columnEnd; columnInput >= columnStart; columnInput--){
    setCell(columnInput, rowEnd, dotInput);
    delay(fDelay);
    }
  columnEnd++;
  moves++;
  esp_task_wdt_reset();  // reset wdt
   //left side down
  for (int rowInput = rowEnd; rowInput >= rowStart; rowInput--){
    setCell(columnStart, rowInput, dotInput);
    delay(fDelay);
    }
  rowEnd++;
  moves++;
  esp_task_wdt_reset();  // reset wdt 
  }
esp_task_wdt_reset();  // reset wdt
fastFillDisplay();  // this is a bit of delay also
return;
}

// end of main functions


// further supporting functions

void moveColumn(int oldColPos, int newColPos, int order) 
{
// order is 0 for blank first, 1 for write first, 2 for row interleave
if (order == 0){
  for (int rowInput = 0; rowInput <= 13; rowInput++){
    setCell(oldColPos, rowInput, 0);
    }
  for (int rowInput = 0; rowInput <=13; rowInput++){
    setCell(newColPos, rowInput, 1);
    }
  }
if (order == 1){
  for (int rowInput = 0; rowInput <=13; rowInput++){
    setCell(newColPos, rowInput, 0);
    }
  for (int rowInput = 0; rowInput <=13; rowInput++){
    setCell(oldColPos, rowInput, 1);
    }
  }
if (order == 2){
  for (int rowInput = 0; rowInput <= 13; rowInput++){
    setCell(oldColPos, rowInput, 0);
    setCell(newColPos, rowInput, 1);
    }
  }
return;  
} 

void fullRandom(int loops){
// seed random number generator
srand(millis()); 
// create random numbers
for (int i = 0; i < loops; i++){ // run random display
  // fit in display size
  int rRow = rand() % 14;  // 14 rows
  int rColumn = rand() % 63;  // 63 columns
  // determine dot
  int rdotInput = (rand() % 2) & 0x01;
  setCell(rColumn, rRow, rdotInput); // display random cell
  if ((i % 2000) == 0) {esp_task_wdt_reset();}  // clear wdt as needed
  }
}
    
void centerRandom(int loops){
// seed random number generator
srand(millis()); 
// create random numbers
for (int i = 0; i < loops; i++){ // run random display
  // fit in display size
  int rRow = rand() % 14;  // 14 rows
  int rColumn = rand() % 21;  // 63 columns - center display only
  // determine dot
  int rdotInput;
  if (((rand() % 2) & 0x01) == 0x01) {rdotInput = 1;}
  else {rdotInput = 0;}
  setCell(rColumn + 21, rRow, rdotInput); // display random cell - center display only
  if ((i % 2000) == 0) {esp_task_wdt_reset();}  // clear wdt as needed
  delay(5);  // add delay when using center display only
  }
}

  
