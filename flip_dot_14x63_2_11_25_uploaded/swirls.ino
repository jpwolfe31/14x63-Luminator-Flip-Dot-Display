// swirl 1 dotsxy
const int swirl1xy[100][2] = {
{0,5},  
{2,7}, 
{4,8}, 
{6,9}, 
{8,10}, 
{10,11}, 
{12,11}, 
{14,11}, 
{16,10}, 
{18,9}, 
{20,8}, 
{21,7}, 
{23,5}, 
{25,4}, 
{27,3}, 
{29,3}, 
{31,4}, 
{33,5}, 
{34,7}, 
{34,9}, 
{33,11}, 
{31,12}, 
{29,13}, 
{27,13}, 
{25,12}, 
{23,11}, 
{22,9}, 
{21,7}, 
{21,5}, 
{22,3}, 
{23,2}, 
{25,1}, 
{27,0}, 
{29,0}, 
{31,0}, 
{33,1}, 
{35,2}, 
{37,4}, 
{39,6}, 
{41,8}, 
{43,9}, 
{45,10}, 
{47,10}, 
{49,9}, 
{51,8}, 
{53,6}, 
{55,5}, 
{57,4}, 
{59,4}, 
{61,5}, 
{62,14}
};

void swirl1()
{
int i = 0;
fastBlankDisplay();
delay1s();
while (swirl1xy[i][0] != 62){
  setCell (swirl1xy[i][0], swirl1xy[i][1], 1); // void setCell(int column, int row, int dot) dot - 1 is yellow
  delay(25);
  i++;
  }
}

void swirl2()
{
int i = 0;
delay2s();
fastBlankDisplay();
delay1s();
while (swirl1xy[i][0] != 62){
  setCell (swirl1xy[i][0], (13 - swirl1xy[i][1]), 1); // void setCell(int column, int row, int dot) dot - 1 is yellow
  delay(25);
  i++;
  }
}

