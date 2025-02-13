// Tetris - large bricks

void t2_tetris_loop()  // tetris 2 also has a narrower play field 7 vs 10
{ 
// reset global variables
score = 0; // unsigned int
lines = 0; // unsigned int
removed = 0; // unsigned int
// local variables
unsigned long speed = t2_getSpeed();
unsigned long oldTime = millis();
unsigned int board[t2_nRows];
// clear and set arrays used for getRandomBrick
for (int i = 0; i < 7; i++) missedBrickCnt[i] = 0;
for (int i = 0; i < 4; i++) lastBricks[i] = 8;
Blynk.virtualWrite(V10, score); // clear score display (0-999) on Blynk controller tab 2
fastBlankDisplay();
terminal.println("Tetris 2 started.");
terminal.println();
terminal.flush();
Blynk.run();
delay(10);
randomSeed(millis());  // seed random number generator
t2_clearScreen();
memset(board, 0, sizeof(unsigned int) * t2_nRows);  // this shoud clear the board[] array
byte next = t2_getRandomBrick(); // added
//byte next = 3; // for testing
t2_drawNext(next);
t2_drawDisplay(); // added for flip dot display
FallingBrick brick = {
  //.id = (byte)random(7),
  .id = t2_getRandomBrick(), // added
  .rotation = 0,
  //.location = {.x = 4, .y = 0}  // 
  .location = {.x = 2, .y = 6} // moved start location down board 6 spots for preview brick room - see below too
  // 2 centers on board top to bottom - see below too
  };
FallingBrick copy;

// tetris while loop
while (true) { 
  // wait for input
  esp_task_wdt_reset();  // added
  Blynk.run(); // will run approx every 25ms while using tetris for faster button responses
  if (t2_wasPressed(&LEFT)) {
    if (t2_move(&copy, &brick, 0, &left, board)) {
      memcpy(&brick, &copy, sizeof(FallingBrick));
      t2_drawBoard(board, &brick);
      t2_drawDisplay(); // draw display after each buttom press
      }
    }
  if (t2_wasPressed(&RIGHT)) {
    if(t2_move(&copy, &brick, 0, &right, board)) {
      memcpy(&brick, &copy, sizeof(FallingBrick));
      t2_drawBoard(board, &brick);
      t2_drawDisplay(); 
      }
    }
  if (t2_wasPressed(&ROTATE_CCW)) { // added
    if(t2_move(&copy, &brick, 3, &identity, board)) {  // does 3 rotate CCW??  *******
      memcpy(&brick, &copy, sizeof(FallingBrick));
      t2_drawBoard(board, &brick);
      t2_drawDisplay(); 
      }
    }
  if (t2_wasPressed(&ROTATE_CW)) {
    if(t2_move(&copy, &brick, 1, &identity, board)) {
      memcpy(&brick, &copy, sizeof(FallingBrick));
      t2_drawBoard(board, &brick);
      t2_drawDisplay(); 
      }
    }
  if (t2_wasPressed(&DROP)) { 
    while(true){
      if (t2_move(&copy, &brick, 0, &down, board)) {
        memcpy(&brick, &copy, sizeof(FallingBrick));
        t2_drawBoard(board, &brick);
        t2_drawDisplay(); 
        delay(75);  // no Blynk.run delay so smoother run down
        }
      else break;
      }
    }
  if (t2_wasPressed(&PAUSE)) {
    if (pauseFlag == 0){
      pauseFlag = 1;
      setCell(0, 0, 1);  // set paused indicator dot at 0, 0 
      terminal.println("Paused...");
      terminal.flush();
      Blynk.run();
      while(true){
        delay25ms(); // refreshes wdt and checks Blynk (inclding LED) 
        if (t2_wasPressed(&PAUSE)) {
          pauseFlag = 0;
          terminal.println("... Resuming");
          terminal.flush();
          Blynk.run();
          setCell(0, 0, 0);  // clear pause indicator dot
          break;  
          }
        }
      delay1s();
      }
    }
  // timer - row move down
  if ((millis() - oldTime) > speed) {  
    oldTime = millis();
    if (t2_move(&copy, &brick, 0, &down, board)) {
      memcpy(&brick, &copy, sizeof(FallingBrick));
      }
    else {
      //Serial.println(F("Could not move down; merging."));  // for testing
      t2_printBrick(&brick);
      t2_merge(&brick, board); // jw revised removed variable now global - function updates removed
      lines += removed;  // unsigned int removed
      // revised - score now based on lines removed
      switch (removed) {
        case 0:  
          score = score;
          break;
        case 1:
          score = score + 1;
          break;
        case 2:
          score = score + 3;
          break;
        case 3:
          score = score + 5;
          break;
        case 4:
          score = score + 10;
          break;
        default:  // optional, if nothing else matches, do the default
          score = score;
          break;
        }
      // print score and lines removed
      if (removed == 4) {
        terminal.println("Tetris!");
        }
      if (removed != 0){
        Blynk.virtualWrite(V10, score); // display score on Blynk controller tab 0-999
        terminal.flush();
        Blynk.run();
        }
      // speed based on total lines removed
      speed = t2_getSpeed(); // revised - uses lines global variable
      // draw next brick     
      brick.id = next;
      brick.rotation = 0;
      brick.location.x = 2; // 2 centers on board - it was 4 in t1 - see above too
      //brick.location.y = 0;  
      brick.location.y = 6; // moved start location down board 6 spots for preview brick room - see above too
      // get and draw next brick 
      next = t2_getRandomBrick();
      //next = 3; // for testing
      t2_drawNext(next);
      if (!t2_move(&copy, &brick, 0, &down, board)) {
        esp_task_wdt_reset();  // reset wdt
        t2_gameOver(); // revised - uses globals lines and score
        return; // return from tetris program
        }
      }
    // update board
    t2_drawBoard(board, &brick);
    t2_drawDisplay();
    }
  } 
}
// end of tetris loop

byte t2_getRandomBrick(){ // added
// get random number and select if not one of last four bricks 
// try up to 5 times
for (int i = 0; i < 5; i++){ //  6 often used here instead
  randomBrick = (byte)random(7); // byte randomBrick
  if (randomBrick != lastBricks[0] && randomBrick != lastBricks[1]  // byte lastBricks[4]
     && randomBrick != lastBricks[2] && randomBrick != lastBricks[3]){
    // terminal.println("found new brick"); // for testing
    break;
    }
  }
// if it has been more than 10 for any brick override selection
for (int i = 0; i < 7; i++){
  if (missedBrickCnt[i] >= 10) {  // int missedBrickCnt[7]
    randomBrick = byte(i);  // select this brick
    break;
    }
  }
// once randomBrick is selected, update last bricks and missed brick counts
lastBricks[3] = lastBricks[2]; //byte lastBricks[4]
lastBricks[2] = lastBricks[1];
lastBricks[1] = lastBricks[0];
lastBricks[0] = randomBrick;
// update missed brick counts
for (int i = 0; i < 7; i++){
  missedBrickCnt[i] ++;
  }
// set missed brick count for current brick to 0
missedBrickCnt[(int)randomBrick] = 0;
return randomBrick; // byte randomBrick
}

void t2_clearScreen() { // this is the t2_screen data that gets constantly refreshed 
// a column consists of bits stored as unsigned integer
for (int row = 0; row < t2_nRows; row++) {
  t2_screen[row] = 0;
  }
// clear t2_grid0
for (int row = 0; row < t2_nRows; row++) { // t2_screen t2_nRows by t2_nColumns
  for (int col = 0; col < t2_nColumns; col++) {
    t2_grid0[row][col] = 0;
    }
  }
}

void t2_setPixel(unsigned int row, unsigned int col, bool on) { 
  if (on) {
    t2_screen[row] |= (0x8000 >> col);
  } else {
    t2_screen[row] &= ((0x8000 >> col) ^ 0xff);
  }
}

void t2_drawDisplay() // added
{
// this takes the t2_screen data and loads into t2_grid1 for the display
// this then compares t2_grid1 to t2_grid0 to see if change - if so display change made.
// then t2_grid1 becomes t2_grid0.
// in t2_screen, a column consists of 16 bits stored as unsigned integer
// actual display is sideways so columns and rows reversed.  display has row 0 on top, col 0 on left
// Serial.println("t2_screen");
for (int row = 0; row < t2_nRows; row++) { // t2_screen is t2_nRows (rows) by 7 columns
  for (int col = 8; col < t2_nColumns; col++) { // jw shift t2_screen by 8 to fit on top of display - will need to move preview block location
    // below for ref - returns value of kth bit of n based on function
    t2_grid1[row][col-8] = (t2_screen[row] >> col) % 2; // just checks odd 1 or even 0 after shift 
    // Serial.print(t2_grid1[row][col-8]);  // this can be useful output
    if (t2_grid1[row][col-8] != t2_grid0[row][col-8]){
      // void setCell(int column, int row, int dot) - for reference - reverse row and columns
      // void setSquare(int column, int row, int dot) - for reference - reverse row and columns
      // - 8 shifts 16 bits wide to fit on 7 bit wide t2_screen with 7 bit game field and no border
      // set square doubles this to 14 bits wide
      setSquare(row + 2, col-8, t2_grid1[row][col-8]);  // function for setting or blanking flip dot cell - 1 is yellow, 0 is black// void setCell(int column, int row, int dot) - for reference - reverse row and columns
      // + 2 starts preview 4 single spaces over from left - for changing board position
      }
    }
  // Serial.println(); // return after each line
  // Serial.println(t2_screen[row], HEX);
  // Serial.println();
  }
// Serial.println(); // space end of group
// move t2_grid1 to t2_grid0 for next generation
for (int row = 0; row < t2_nRows; row ++){
  for (int col = 0; col < t2_nColumns; col++){
    t2_grid0[row][col] = t2_grid1[row][col];
    }
  }
}

void setSquare(int ssColumn, int ssRow, int ssDot)  // added for larger bricks
{
// void setSquare(int column, int row, int dot) - for reference - reverse row and columns
// when using starting position should be 1/2 of single dot position (e.g use 10 instead of 20)
// adding +1 (4x) to columns moves screen to bottom of display as 63 is an odd number of columns
setCell((ssColumn * 2)+1, (ssRow * 2), ssDot);
setCell((ssColumn * 2)+1, (ssRow * 2) + 1, ssDot);
setCell((ssColumn * 2)+1 + 1, (ssRow * 2), ssDot);
setCell((ssColumn * 2)+1 + 1, (ssRow * 2) + 1, ssDot);
}

// Updated code below uses Blynk pushbutton values
// Returns true if the button went from not pressed to pressed.
bool t2_wasPressed(Button *button) {  // jw updated for Blynk - no debounce needed
  int value = button->valueRead; 
  if ((value != 0) && (value != button->lastState)) {
    
    button->lastState = value;
    return true;
    }
  else {
    button->lastState = value;
    return false;
    }
}

bool  t2_islongpressed(Button *button) { // not used
  return button->currState == HIGH && (millis() - button->lastChanged) >= 400;
}

void t2_drawBoard(unsigned int *board, FallingBrick *brick) {
  Shape shape;
  t2_materialize(&shape, brick);
  for (byte i = 5; i < t2_nRows; i++) {  // note - do not clear preview section ******
    t2_screen[i] &= 0x801F; // clear the board section of the t2_screen  
    t2_screen[i] |= ((board[i] >> 1) & 0x7fe0); 
  }
  for (byte i = 0; i < 4; i++) {
    t2_setPixel(shape.vertex[i].y, shape.vertex[i].x + 1, true); // setPixel sets t2_screen
  }
}

void t2_drawNext(byte id) {
  // clear preview area: 
  for (byte row = 0; row < 5; row++) { 
    //t2_screen[row] &= 0xfff0; //
    t2_screen[row] &= 0x0000; // moved to first 5 rows
  }
  // paint the next tetromino:
  for (byte i = 0; i < 4; i++) {  // setPixel sets t2_screen
    //setPixel(brickdefs[id].shape[0].vertex[i].y + 2, brickdefs[id].shape[0].vertex[i].x + 13, true); // was to the right side on top
    t2_setPixel(brickdefs[id].shape[0].vertex[i].y + 0, brickdefs[id].shape[0].vertex[i].x + 3, true); // now centered ***** and changed y+1 to y+0
  }
}

bool t2_fits(FallingBrick *brick, unsigned int *board) {
  Shape shape;
  t2_materialize(&shape, brick);
  for (byte i = 0; i < 4; i++) {
    if (shape.vertex[i].y < 0 || shape.vertex[i].y >= t2_nRows || shape.vertex[i].x < 0 || shape.vertex[i].x >= t2_width || 
        (board[shape.vertex[i].y] & (0x8000 >> shape.vertex[i].x))) {
      return false;
    }
  }
  return true;
}

void t2_materialize(Shape *dest, FallingBrick *brick) {
  for (byte i = 0; i < 4; i++) {
    dest->vertex[i].x = brickdefs[brick->id].shape[brick->rotation].vertex[i].x + brick->location.x;
    dest->vertex[i].y = brickdefs[brick->id].shape[brick->rotation].vertex[i].y + brick->location.y;
  }
}

bool t2_move(FallingBrick *dest, FallingBrick *src, int rot, Vertex *vector, unsigned int *board) {
  memcpy(dest, src, sizeof(FallingBrick));
  dest->rotation = (dest->rotation + rot) % 4; // this rotates the display +1 is CW, +3 is CCW
  dest->location.x += vector->x;
  dest->location.y += vector->y;
  return t2_fits(dest, board);
}

void t2_printBrick(FallingBrick *brick) {  
  Shape shape;
  t2_materialize(&shape, brick);
  /*Serial.print(F("Shape: "));  // below is this for testing program without display
  for (int i = 0; i < 4; i++) {
    Serial.print(F("("));
    Serial.print(shape.vertex[i].x, DEC);
    Serial.print(F(", "));
    Serial.print(shape.vertex[i].y, DEC);
    Serial.print(F(") "));
  }
  Serial.println(brick->rotation);
  */
}

void t2_merge(FallingBrick *brick, unsigned int *board) {  // removes completed lines and updates removed global value
  // unsigned int removed;
  removed = 0;
  Shape shape;
  t2_materialize(&shape, brick);
  for (byte i = 0; i < 4; i++) {
    board[shape.vertex[i].y] |= (0x8000 >> shape.vertex[i].x);
  }
  // remove completed lines:
  int row = t2_nRows - 1;
  for (int i = t2_nRows - 1; i >= 0; i--) {
    if (board[i] < 0xfe00) {  // this works with 7 lines - unsigned int board[]
      board[row--] = board[i];
    } else {
      removed++;
    }
  }
  for (; row >= 0; row--) {
    board[row] = 0;
  }
  return;  // no return value - global removed is updated instead
}

/*
 * Returns the speed based on specified number of removed lines.
 * Speed in measured in milliseconds.
 */
unsigned int t2_getSpeed() {// revised uses global variable lines
  int a = -3 * lines + 600;
  // 100 lines is 10 levels and will be 2x faster - start is 600 - min is 300
  unsigned int b = max(a, 300);
  return b;
  //return 600;  // for testing
}

void t2_gameOver() // revised for esp32 eeprom and Blynk app scoring
{
// print score and lines removed
terminal.println();
terminal.println("Game Over");
terminal.print("score = ");
terminal.print(score);
terminal.print("   ");
terminal.print("lines removed = ");
terminal.println(lines);
// test if score is new high score
if (score > t2_highScore_int){
  terminal.println("New High Score!");
  terminal.println();
  t2_highScore_int = score; // update int score
  // convert to string - leaving out 0 after % does not pad with 0s
  sprintf(t2_highScore_str, "%d", t2_highScore_int);  // update str score
  terminal.flush();
  Blynk.run();
  
  EEPROMWrite();
  }
//terminal.println();
terminal.flush();
Blynk.run();
return; 
}

/*
Note - Tetris code above based on software available
at https://medium.com/@erikvanzijst/custom-16x16-matrix-display-pcb-96c40290c8bc
and licensed as follows:  

Copyright (c) 2020 Erik van Zijst <erik.van.zijst@gmail.com>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Thank you Erik!
*/

