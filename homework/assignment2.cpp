/******************************************************************************
**Program: Assignment 2
**Author: William Mays
**Date: 10/22/14
**Description: This program ask the user to input how many test scores they wish to average as well as averaging
all of the scores for them
**Input:
**Output:
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int main(){

  //declare variables 
  double test_num;
  double test_total = 0.0;
  double test_score;
  double average;
  
  //ask user for number of tests
  cout << "Please enter how many test you wish to average today: ";
  cin >> test_num;

  //start getting test scores and make sure they are from 0 - 100
  for (double x = 0.0; x < test_num; x++) 
     if (x <= test_num)
     {
       cout << "Please enter a test score between 0 - 100: ";
       cin >> test_score;
        /*make sure it is a number
        for(int y = 0; y < test_score.length(); y++) 
	if(!((test_score.at(x) >= '0') && (test_score.at(x) <='9')))
	{
      	  //not a good number
	  cout << "You did not enter a number" << endl;
	  //make user re enter test score
	  cout << "Please enter a test score between 0 -100: ";
        }
        else
	{
	  atoi(test_score.c_str( ));
	}*/
      //make sure the number is between 0 and 100
	if (test_score > 100.0)
        {
	  cout << "Not a possible score" << endl;
	  //make user re enter test score
	  cout << "Please enter a test score between 0 - 100" << endl;
          cin >> test_score;
	}
      else if (test_score < 0.0)
        {
	  cout << "Not a possible score" << endl;
	  //make user re enter the test score
	  cout << "Please enter a test score between 0 - 100: ";
	  cin >> test_score;
        }
      else	
	{
	  //add test score to the past test scores 
	  test_total = test_score + test_total;
	}
    }
    else ( x < test_num);
    {
      //calculate test average 
      average = test_total / test_num;
      //display test average		
      cout << "The average of your test scores is: " << average << endl;
    }

    return 0;

}
