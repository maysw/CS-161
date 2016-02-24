#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int count_up(int x , int y)
{
  for(y = 0; y <= x; y++)
  { 
    cout << y << endl;
  }
  cout << endl;
}

int count_down(int x)
{
  for (x; x >= 0; x--)
  {
     cout << x << endl;
  }
  cout << endl;
}

int count_between(int x, int y)
{
  if (x > y)
  {
    for (y; y <= x; y++)
    {
    //	sleep(3);
       cout << y << endl;
    }
  }
  else if (x < y )
    {
      for(x; x <= y; x++)
      {
    //	sleep(3);
        cout << x << endl;
      }
    }
}
int num_pos(string num_str)
{
    for(int x = 0; x < num_str.length(); x++)
    if(!((num_str.at(x) >= '0') && (num_str.at(x) <= '9')))
    {
      cout << "You did not enter a positive number";
      return -1;
    }
  return atoi(num_str.c_str( ));
}

int get_number()
{
   int x;
   string a;
   cin >> a;
   x = num_pos(a);
   while (x == -1){
      cout << "Invalid. Please enter two positive numbers";
      cin >> a;
      x = num_pos(a);
   }
  return x;   
}

void get_both_num(int& x, int& y)
{
  cout << "Please enter two positive numbers: ";
  x = get_number();
  y = get_number();
}

int main( )
{
  int firstNum;
  int secondNum;
  
  get_both_num(firstNum, secondNum);
  count_up(firstNum, secondNum);
  count_down(firstNum);
  count_between(firstNum, secondNum);
  return 0;
}
