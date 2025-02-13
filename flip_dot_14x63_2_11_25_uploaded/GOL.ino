// Conway's Game of Life
/*
Rules:

The universe of the Game of life is an infinite two-dimensional orthogonal grid of square cells,
each of which is in one of two possible states, live or dead.

Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, 
or diagonally adjacent.

At each step in time, the following transitions occur:
  1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
  2. Any live cell with two or three live neighbours lives on to the next generation.
  3. Any live cell with more than three live neighbours dies, as if by over-population.
  4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

void GOL(int startState, int wrapOn){ // can specify start state when function is called 
// and whether the dispay edges wrap (1) or not (0)
// flip dot display size
// int grid0[63][14] - global arrays for use in this and other functions
// int grid1[63][14]
// int grid2[63][14] 
// int maxColumns = 63; // 63 columns 0-62  // not used
// int maxRows = 14; // 14 rows 0-13
int columnStart = 0;
int columnEnd = 62;
int rowStart = 0;
int rowEnd = 13;
int generations = 0;
int count;
int currentValue;
int differenceFound0 = 0;
int differenceFound1 = 0;

terminal.println(); // add space
terminal.println ("GOL started - enter end to end game");
terminal.flush();
Blynk.run();
// blank flip dot display
fastBlankDisplay();
// clear grid1 and grid2
for (int col = columnStart; col <= columnEnd; col++){
  for (int row = rowStart; row <= rowEnd; row++){
    grid1[col][row] = 0;
    grid2[col][row] = 0;
    }
  }
// seed grid1
if (startState == 0){ // full display random 
  srand(millis());
  for (int col = columnStart; col <= columnEnd; col++){
    for (int row = rowStart; row <= rowEnd; row++){
      grid1[col][row] = (rand() % 2) & 0x01;
      }
    } 
  }
if (startState == 1){  // line row 7
  for (int col = columnStart; col <= columnEnd; col++){
    grid1[col][7] = 1;
    }
  }
if (startState == 2){  // line column 7
  for (int row =rowStart; row <= rowEnd; row++){
    grid1[7][row] = 1;
    }
  }
if (startState == 3){  // glider 0 7 14 21 28 35 42 49 rotator at 56
  grid1[0][1] = 1;
  grid1[0][3] = 1;
  grid1[1][2] = 1;
  grid1[1][3] = 1;
  grid1[2][2] = 1;
  grid1[7][1] = 1;
  grid1[7][3] = 1;
  grid1[8][2] = 1;
  grid1[8][3] = 1;
  grid1[9][2] = 1;
  grid1[14][1] = 1;
  grid1[14][3] = 1;
  grid1[15][2] = 1;
  grid1[15][3] = 1;
  grid1[16][2] = 1;
  grid1[21][1] = 1;
  grid1[21][3] = 1;
  grid1[22][2] = 1;
  grid1[22][3] = 1;
  grid1[23][2] = 1;
  grid1[28][1] = 1;
  grid1[28][3] = 1;
  grid1[29][2] = 1;
  grid1[29][3] = 1;
  grid1[30][2] = 1;
  grid1[35][1] = 1;
  grid1[35][3] = 1;
  grid1[36][2] = 1;
  grid1[36][3] = 1;
  grid1[37][2] = 1;
  grid1[42][1] = 1;
  grid1[42][3] = 1;
  grid1[43][2] = 1;
  grid1[43][3] = 1;
  grid1[44][2] = 1;
  grid1[49][1] = 1;
  grid1[49][3] = 1;
  grid1[50][2] = 1;
  grid1[50][3] = 1;
  grid1[51][2] = 1;
  grid1[56][4] = 1;  // add rotator for destruction
  grid1[56][5] = 1;
  grid1[56][6] = 1;
  }  
if (startState == 4){  // large circles centered each display
  grid1[7][6] = 1;
  grid1[7][7] = 1;
  grid1[7][8] = 1;
  grid1[8][5] = 1;
  grid1[8][9] = 1;
  grid1[9][4] = 1;
  grid1[9][10] = 1;
  grid1[10][4] = 1;
  grid1[10][10] = 1;
  grid1[11][4] = 1;
  grid1[11][10] = 1;
  grid1[12][5] = 1;
  grid1[12][9] = 1;
  grid1[13][6] = 1;
  grid1[13][7] = 1;
  grid1[13][8] = 1;
  grid1[28][6] = 1;
  grid1[28][7] = 1;
  grid1[28][8] = 1;
  grid1[29][5] = 1;
  grid1[29][9] = 1;
  grid1[30][4] = 1;
  grid1[30][10] = 1;
  grid1[31][4] = 1;
  grid1[31][10] = 1;
  grid1[32][4] = 1;
  grid1[32][10] = 1;
  grid1[33][5] = 1;
  grid1[33][9] = 1;
  grid1[34][6] = 1;
  grid1[34][7] = 1;
  grid1[34][8] = 1;
  grid1[49][6] = 1;
  grid1[49][7] = 1;
  grid1[49][8] = 1;
  grid1[50][5] = 1;
  grid1[50][9] = 1;
  grid1[51][4] = 1;
  grid1[51][10] = 1;
  grid1[52][4] = 1;
  grid1[52][10] = 1;
  grid1[53][4] = 1;
  grid1[53][10] = 1;
  grid1[54][5] = 1;
  grid1[54][9] = 1;
  grid1[55][6] = 1;
  grid1[55][7] = 1;
  grid1[55][8] = 1;
  }  
if (startState < 0 || startState > 4){  // check range
  terminal.println(); // add space
  terminal.println ("GOL seed out of range 0-4.  Game ended.");
  terminal.flush();
  Blynk.run();
  return;
  }

// display start grid1
  for (int col = columnStart; col <= columnEnd; col ++){
    for (int row = rowStart; row <= rowEnd; row++){
      setCell(col, row, grid1[col][row]);  // function for setting or blanking flip dot cell - 1 is yellow, 0 is black
      }
    }
delay2s();

// start  game
while (generations <= 400){ // stop after 400 generations
  for (int col = columnStart; col <= columnEnd; col ++){
    for (int row = rowStart; row <= rowEnd; row++){
      currentValue = grid1[col][row]; // get new count based on current grid
      count = countNeighbors(col, row, wrapOn); 
      if (currentValue == 1){ // update new grid based on counts
        if (count <= 1 || count >= 4) grid2[col][row] = 0; // under over population
        if (count == 2 || count == 3) grid2[col][row] = 1; // healthy population
        }
      else {
        if (count == 3) grid2[col][row] = 1; // healthy population and reproduction
        }
      }
    }
  // display updated grid2
  for (int col = columnStart; col <= columnEnd; col ++){
    for (int row = rowStart; row <= rowEnd; row++){
      if (grid2[col][row] != grid1[col][row]){
        setCell(col, row, grid2[col][row]);  // function for setting or blanking flip dot cell - 1 is yellow, 0 is black
        }
      //else delay(1); // delay for not setting cell
      }
    }
  // move grid2 to grid1 for next generation and grid 1 to grid 0
  // while doing this check to see if there is a difference between 2 and either 1 or 0
  differenceFound0 = 0;
  differenceFound1 = 0;
  for (int col = columnStart; col <= columnEnd; col ++){
    for (int row = rowStart; row <= rowEnd; row++){
      if (grid0[col][row] != grid2[col][row]) differenceFound0 = 1;
      grid0[col][row] = grid1[col][row];
      if (grid1[col][row] != grid2[col][row]) differenceFound1 = 1;
      grid1[col][row] = grid2[col][row];
      }
    }
  if (differenceFound0 == 0 || differenceFound1 == 0) { // end game if either grid0 or 1 are the same
    // this includes checking for two-state 3 dot spinners
    break; 
    }
  generations++;  // update generation count
  if (generations % 25 == 0){ // print update every 25 generations
    terminal.print("generations = ");  // this size display usually completes in 300 or less generations
    terminal.println(generations);
    terminal.flush();
    Blynk.run();
    }  
  if (strcmp(cmd_str, "end") == 0) { // returns 0 if equal
    break;
    }
  delay500ms(); // delay between generations - update wdt and blynk
  }  
terminal.print("generations = ");  // this size display usually completes in 300 or less generations
terminal.println(generations);  // print final generations count
terminal.println ("GOL ended");
terminal.flush();
Blynk.run();
return;
}

int countNeighbors(int x, int y, int wrapOn) // uses global grid1
{
int cnt = 0;
if (wrapOn == 1){ // grid wrap on
  for (int i = -1; i <= 1; i++){
    for (int j = -1; j <= 1; j++){
      int col = (x + i + 63) % 63; // clever function allows grid wrap -1 is 62 63 is 0
      int row = (y + j + 14) % 14; //  clever  function allows grid wrap -1 is 13 14 is 0
      cnt = cnt + grid1[col][row];
      } 
    }
  cnt = cnt - grid1[x][y]; // subtract out current cell value as only counting neighbors
  }
else { // grid wrap off
  for (int i = -1; i <= 1; i++){
    for (int j = -1; j <= 1; j++){
      int col = x + i; // no grid wrap
      int row = y + j;
      if (col >= 0 && col <= 62 && row >= 0 && row <= 13) { // check range as no grid wrap
        cnt = cnt + grid1[col][row];
        }
      } 
    }
  cnt = cnt - grid1[x][y]; // subtract out current cell value as only counting neighbors
  }
return cnt; 
}

