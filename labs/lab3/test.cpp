/***************************************************************************
**Program:test.cpp
**Date: 10/13/14
**Author: William Mays
**Descripton: Test.cpp program
**Input:
**Output:
**************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;
int answer;
int truefalse;
int main() 
{
	cout << "Do you like vi as an editor? (Yes: 1 or No: 0): " << endl;
	cin >> answer;
	if (answer == 0)
		cout << "You hate vi!" << endl;
	else
		cout << "You love vi!" << endl;  
return 0;
}
