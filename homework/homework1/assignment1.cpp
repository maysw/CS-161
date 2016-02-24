/*******************************************************************************
**Program: assignment1.cpp
**Author: William Mays
**Date: 10/05/14
**Description: This is my version of assignment 1 for CS 161
**Input:
**Output:
*******************************************************************************/
#include <iostream>
#include <cmath> //gets macros
#include <climits> //use pow
#include <iomanip>
using namespace std;
	//declare variables for later use
	int a; //first test
	int b; //second test
	int c; //third test
	int d; //fourth test
	int e; //fifth test
	int average; //average of all test
	int main ()
		{
		//display all the short variables
		cout << "The smallest signed short is: ";
		cout << pow(-2, sizeof(short) * 8 - 1) + 1 << endl;
	
		cout << "The largest signed short is: ";
		cout << pow(2, sizeof(short) * 8 - 1 ) - 1 << endl;

		cout << "The smallest unsigned short is: 0" << endl;

		cout << "The largest unsigned short is: ";
		cout << pow(2,sizeof(short) * 8) - 1 << endl;
		
		//display all the int variables
		cout << "The smallest signed int is: ";
		cout << pow(-2, sizeof(int) * 8 - 1) + 1 << endl;

		cout << "The largest signed int is: ";
		cout << pow(2, sizeof(int) * 8 - 1) - 1 << endl;

		cout << "The smallest unsigned int is: 0" << endl;

		cout << "The largest unsigned int is: ";
		cout << pow(2, sizeof(int) * 8) - 1 << endl;
		
		//display all the long variables
		cout << "The smallest signed long is: ";
		cout << pow(-2, sizeof(long) * 16 - 1) + 1 << endl;

		cout << "The largest signed long is: ";
		cout << pow(2, sizeof(long) * 16 - 1) - 1 << endl;

		cout << "The smallest unsigned long is: 0" << endl;

		cout << "The largest unsigned long is: ";
		cout <<  pow(2, sizeof(long) * 16) - 1 << endl;
		
		//ask user for their test scores
		cout << "Please enter first test score: " << endl;
		cin >> a;

		cout << "Please enter the second test score: " << endl;
		cin >> b;

		cout << "Please enter the third test score: " << endl;
		cin >> c;

		cout << "Please enter the fourth test score: " << endl;
		cin >> d;

		cout << "Please enter the fifth test score: " << endl;
		cin >> e;
		
		//calculate average of all of the test scores
		average = (a + b + c + d + e) / 5;
		//display the average of all the test scores
		cout << "The average of these five test scores is: "; 
		cout << average << endl;
		return 0;
		}
