// Tetris - small bricks

void t1_tetris_loop()
{ 
// reset global variables
score = 0; // unsigned int
lines = 0; // unsigned int
removed = 0; // unsigned int
// local variables
unsigned long speed = t1_getSpeed(); 
unsigned long oldTime = millis();
unsigned int board[t1_nRows];
// clear and set arrays used for getRandomBrick
for (int i = 0; i < 7; i++) missedBrickCnt[i] = 0;
for (int i = 0; i < 4; i++) lastBricks[i] = 8;
fastBlankDisplay();
Blynk.virtualWrite(V10, score); // clear score display (0-999) on Blynk controller tab 2 
terminal.println("Tetris 1 started.");
terminal.println();
terminal.flush();
Blynk.run();
delay(10);
randomSeed(millis()); // seed random number generator
t1_clearScreen(); 
memset(board, 0, sizeof(unsigned int) * t1_nRows);  // this shoud clear the board[] array
byte next = t1_getRandomBrick(); // added
//byte next = 3; // for testing
for (byte i = 7; i < t1_nRows; i++) { // start at 7
  t1_screen[i] = 0x8010; // paint background 16 bits wide and shifted 3 left in drawDisplay() 
  // to get display centered on actual 14 wide display
  }
t1_drawNext(next);
t1_drawDisplay(); // added for flip dot display
FallingBrick brick = {
  //.id = 3, // for testing
  .id = t1_getRandomBrick(), // added
  .rotation = 0,
  //.location = {.x = 4, .y = 0}
  .location = {.x = 4, .y = 6} // moved down t1_screen by 6 for preview brick room - see below too
  };
FallingBrick copy;

// tetris while loop
while (true) { 
  // wait for input
  esp_task_wdt_reset();  // added
  Blynk.run(); // will run approx every 25ms while using tetris for faster button responses
  if (t1_wasPressed(&LEFT)) {
    if (t1_move(&copy, &brick, 0, &left, board)) {
      memcpy(&brick, &copy, sizeof(FallingBrick));
      t1_drawBoard(board, &brick);
      t1_drawDisplay(); // draw display after each buttom press
      }
    }
  if (t1_wasPressed(&RIGHT)) {
    if(t1_move(&copy, &brick, 0, &right, board)) {
      memcpy(&brick, &copy, sizeof(FallingBrick));
      t1_drawBoard(board, &brick);
      t1_drawDisplay(); 
      }
    }
  if (t1_wasPressed(&ROTATE_CCW)) {  // added
    if(t1_move(&copy, &brick, 3, &identity, board)) {  
      memcpy(&brick, &copy, sizeof(FallingBrick));
      t1_drawBoard(board, &brick);
      t1_drawDisplay(); 
      }
    }
  if (t1_wasPressed(&ROTATE_CW)) {
    if(t1_move(&copy, &brick, 1, &identity, board)) {
      memcpy(&brick, &copy, sizeof(FallingBrick));
      t1_drawBoard(board, &brick);
      t1_drawDisplay(); 
      }
    }
  if (t1_wasPressed(&DROP)) { 
    while(true){
      if (t1_move(&copy, &brick, 0, &down, board)) {
        memcpy(&brick, &copy, sizeof(FallingBrick));
        t1_drawBoard(board, &brick);
        t1_drawDisplay(); 
        delay(75);  // eliminate Blynk.run delay for smoother run down display
        }
      else break;
      }
    }
  if (t1_wasPressed(&PAUSE)) {
    if (pauseFlag == 0){
      pauseFlag = 1;
      setCell(0, 0, 1); // set paused indicator dot at 0, 0 
      terminal.println("Paused...");
      terminal.flush();
      Blynk.run();
      while(true){
        delay25ms(); // refreshes wdt and checks Blynk (inclding LED) 
        if (t1_wasPressed(&PAUSE)) {
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
    if (t1_move(&copy, &brick, 0, &down, board)) {
      memcpy(&brick, &copy, sizeof(FallingBrick));
      }
    else {
      //Serial.println(F("Could not move down; merging.")); // for testing
      t1_printBrick(&brick);
      t1_merge(&brick, board); // jw revised removed variable now global - function updates removed
      lines += removed; // unsigned int removed
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
          score = score + 10;  // tetris!
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
      speed = t1_getSpeed(); // revised - uses lines global variable
      // draw next brick     
      brick.id = next;
      brick.rotation = 0;
      brick.location.x = 4; // 4 centers on board
      //brick.location.y = 0;  
      brick.location.y = 6; // start location down board 6 spots to make room for preview brick - see above too
      // get and draw next brick 
      next = t1_getRandomBrick();
      //next = 3; // for testing
      t1_drawNext(next);
      // if next brick cannot be drawn game over
      if (!t1_move(&copy, &brick, 0, &down, board)) {
        esp_task_wdt_reset();  // reset wdt
        t1_gameOver();  // revised - uses globals lines and score
        return; // return from tetris program
        }
      }
    // update board
    t1_drawBoard(board, &brick);
    t1_drawDisplay();
    }
  } 
}
// end of tetris loop

byte t1_getRandomBrick(){ // added
// get random number and select if not one of last four bricks 
// try up to 5 times
for (int i = 0; i < 5; i++){ //  6 often used here instead
  randomBrick = (byte)random(7);  // byte randomBrick
  if (randomBrick != lastBricks[0] && randomBrick != lastBricks[1] // byte lastBricks[4]
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
lastBricks[3] = lastBricks[2]; // byte lastBricks[4]
lastBricks[2] = lastBricks[1];
lastBricks[1] = lastBricks[0];
lastBricks[0] = randomBrick;
// update missed brick counts
for (int i = 0; i < 7; i++){
  missedBrickCnt[i] ++;
  }
// set missed brick count for current brick to 0
missedBrickCnt[(int)randomBrick] = 0;
return randomBrick;  // byte randomBrick
}

void t1_clearScreen() { // this is the t1_screen data that gets constantly refreshed 
// a column consists of bits stored as unsigned integer
for (int row = 0; row < t1_nRows; row++) {
  t1_screen[row] = 0;
  }
// clear t1_grid0
for (int row = 0; row < t1_nRows; row++) { // t1_screen t1_nRows by t1_nColumns
  for (int col = 0; col < t1_nColumns; col++) {
    t1_grid0[row][col] = 0;
    }
  }
}

void t1_setPixel(unsigned int row, unsigned int col, bool on) { 
  if (on) {
    t1_screen[row] |= (0x8000 >> col);
  } else {
    t1_screen[row] &= ((0x8000 >> col) ^ 0xff);
  }
}

void t1_drawDisplay() // added
{
// this takes the t1_screen data and loads into t1_grid1 for the display
// this then compares t1_grid1 to t1_grid0 to see if change - if so display change made.
// then t1_grid1 becomes t1_grid0.
// in t1_screen, a column consists of 16 bits stored as unsigned integer
// actual display is sideways so columns and rows reversed.  display has row 0 on top, col 0 on left
// Serial.println("t1_screen"); // for testing
for (int row = 0; row < t1_nRows; row++) { // t1_screen is t1_nRows (rows) by 16 columns
  for (int col = 3; col < t1_nColumns; col++) { // shift t1_screen by 4 to fit on actual display
    // below for ref - returns value of kth bit of n based on function
    t1_grid1[row][col-3] = (t1_screen[row] >> col) % 2; // just checks odd 1 or even 0 after shift 
    // Serial.print(t1_grid1[row][col-3]);  // good output for testing
    if (t1_grid1[row][col-3] != t1_grid0[row][col-3]){
      // void setCell(int column, int row, int dot) - for reference - reverse row and columns
      // - 3 shifts 16 bits wide to fit on 14 bit wide t1_screen  with 10 game field plus 2 border lines)
      setCell(row + 22, col-3, t1_grid1[row][col-3]);  // function for setting or blanking flip dot cell - 1 is yellow, 0 is black
      // + 22 starts preview 22 single spaces over from left - for changing board position
      }
    }
  // Serial.println(); // return after each line
  // Serial.println(t1_screen[row], HEX);
  // Serial.println();
  }
// Serial.println(); // space end of group
// move t1_grid1 to t1_grid0 for next generation
for (int row = 0; row < t1_nRows; row ++){
  for (int col = 0; col < t1_nColumns; col++){
    t1_grid0[row][col] = t1_grid1[row][col];
    }
  }
}

// Updated code below uses Blynk pushbutton values
// Returns true if the button went from not pressed to pressed.
bool t1_wasPressed(Button *button) {  // updated for Blynk - no debounce needed
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

bool  t1_islongpressed(Button *button) { // not used
  return button->currState == HIGH && (millis() - button->lastChanged) >= 400;
}

void t1_drawBoard(unsigned int *board, FallingBrick *brick) {
  Shape shape;
  t1_materialize(&shape, brick);
  for (byte i = 5; i < t1_nRows; i++) {  // note - do not clear preview section ******
    t1_screen[i] &= 0x801F; // clear the board section of the t1_screen  
    t1_screen[i] |= ((board[i] >> 1) & 0x7fe0); 
  }
  for (byte i = 0; i < 4; i++) {
    t1_setPixel(shape.vertex[i].y, shape.vertex[i].x + 1, true); // setPixel sets t1_screen
  }
}

void t1_drawNext(byte id) {
  // clear preview area 
  for (byte row = 0; row < 5; row++) { 
    t1_screen[row] &= 0x0000; // moved to first 5 rows
  }
  // paint the next brick
  for (byte i = 0; i < 4; i++) {  // setPixel sets t1_screen
    //setPixel(brickdefs[id].shape[0].vertex[i].y + 2, brickdefs[id].shape[0].vertex[i].x + 13, true); // was to the right side on top
    t1_setPixel(brickdefs[id].shape[0].vertex[i].y + 0, brickdefs[id].shape[0].vertex[i].x + 5, true); // now centered
  }
}

bool t1_fits(FallingBrick *brick, unsigned int *board) {
  Shape shape;
  t1_materialize(&shape, brick);
  for (byte i = 0; i < 4; i++) {
    if (shape.vertex[i].y < 0 || shape.vertex[i].y >= t1_nRows || shape.vertex[i].x < 0 || shape.vertex[i].x >= t1_width || 
        (board[shape.vertex[i].y] & (0x8000 >> shape.vertex[i].x))) {
      return false;
    }
  }
  return true;
}

void t1_materialize(Shape *dest, FallingBrick *brick) {
  for (byte i = 0; i < 4; i++) {
    dest->vertex[i].x = brickdefs[brick->id].shape[brick->rotation].vertex[i].x + brick->location.x;
    dest->vertex[i].y = brickdefs[brick->id].shape[brick->rotation].vertex[i].y + brick->location.y;
  }
}

bool t1_move(FallingBrick *dest, FallingBrick *src, int rot, Vertex *vector, unsigned int *board) {
  memcpy(dest, src, sizeof(FallingBrick));
  dest->rotation = (dest->rotation + rot) % 4; // this rotates the display +1 is CW, +3 is CCW
  dest->location.x += vector->x;
  dest->location.y += vector->y;
  return t1_fits(dest, board);
}

void t1_printBrick(FallingBrick *brick) {  
  Shape shape;
  t1_materialize(&shape, brick);
  /* Serial.print(F("Shape: "));  // below is this for testing program without display
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

void t1_merge(FallingBrick *brick, unsigned int *board) { // removes completed lines and updates removed global value
  // unsigned int removed;
  removed = 0;
  Shape shape;
  t1_materialize(&shape, brick);
  for (byte i = 0; i < 4; i++) {
    board[shape.vertex[i].y] |= (0x8000 >> shape.vertex[i].x);
  }
  // remove completed lines:
  int row = t1_nRows - 1;
  for (int i = t1_nRows - 1; i >= 0; i--) {
    if (board[i] < 0xffc0) {  // unsigned int board[]
      board[row--] = board[i];
    } else {
      removed++;
    }
  }
  for (; row >= 0; row--) {
    board[row] = 0;
  }
  return;  // remove updated as a global variable - no return value needed
}

/*
 * Returns the speed based on specified number of removed lines.
 * Speed in measured in milliseconds.
 */
unsigned int t1_getSpeed() {// revised - uses global variable lines
  int a = -3 * lines + 600;  // lines is an unsigned int
  // 100 lines is 10 levels and will be 2x faster - start is 600 - min is 300
  unsigned int b = max(a, 300);
  return b;
  //return 600;  // for testing
}

void t1_gameOver() // revised for esp32 eeprom and Blynk app scoring
{
terminal.println();
terminal.println("Game Over");
terminal.print("score = ");
terminal.print(score);
terminal.print("   ");
terminal.print("lines removed = ");
terminal.println(lines);
// test if score is new high score
if (score > t1_highScore_int){
  terminal.println("New High Score!");
  terminal.println();
  t1_highScore_int = score; // update int score
  // convert to string - leaving out 0 after % does not pad with 0s
  sprintf(t1_highScore_str, "%d", t1_highScore_int);  // update str score
  terminal.flush();
  Blynk.run();
  EEPROMWrite();
  }
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
