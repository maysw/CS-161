#include <iostream>

using namespace std;

void towers(int disks, int b[][COLS], int from_col, int to_col, int spare)
{
  if(disks == 1)
  {
  //movewsr ring to destination
  }
  else if (disks >= 1)
  {
    print_array(disks - 1, b, from_col, spare, to_col);
    //move disks-1 to spare, largest ring to destination
    //move disks-1 to destination
  }

}
