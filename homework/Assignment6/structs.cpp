/********************************************************
** Program: structs.cpp
** Author: William Mays
** Date: 12/4/14
** Description: Using a struct, N x N matrix taken as input, 
** N -1 x N-1 matrix is output with each new element being the sum 
** of the four nearby elements from the previous matrix.
** Input: Rows and columns to make up the matrix.
** Output: The N x N matrix and the appropriate N-1 x N-1 matrix
*********************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib> 

using namespace std;
/****************************
** Struct: my_matrix
** Description: Defines the variables to be used to create the NxN and the N-1xN-1 board
** Parameters: **m1, **m2 n
******************************/
struct my_matrix
{
	int n;
	int **m1;
	int **m2;
};
/****************************
** Function: calculate_result_iterative()
** Description: Uses iteration to determine the N-1 x N-1 matrix
** Parameters: **m1, **m2, n
** Pre-Conditions: NxN matrix from user input
** Post-Conditions: Defined n-1 x n-1 matrix created
******************************/
void calc_result_iterative(int **m1, int **m2, int n)
{
	int i, j;
	for(i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			m2[i][j] = (m1[i][j] + m1[i][j+1] + m1[i+1][j] + m1[i+1][j+1]);
		}
	}
}
/****************************
** Function: recursive_calculate_result
** Description: Uses recursion to determine the N-1 x N-1 matrix
** Parameters: **m1, **m2, n, i, j
** Pre-Conditions: NxN matrix from user input
** Post-Conditions: Defined N-1xN-1 matrix created
******************************/
void calc_result_recursion(int **m1, int **m2, int n, int i, int j)
{
	if (i == n - 1)
	{
		return;
	}
	else if (j == n - 1)
	{
		return;
	}
	else
	{
		m2[i][j] = (m1[i][j] + m1[i][j+1] + m1[i+1][j] + m1[i+1][j+1]);
		calc_result_recursion(m1, m2, n, i+1, j+1);
	}
}
/*******************************
** Function: make_matrix()
** Description: Creates the array from user input
** Parameters: **&a, n
** Pre-Conditions: NxN user inputted matrix size and code from dimension function to determine the actual function
** Post-Conditions: Printed array to be passed to recursive and iteration functions.
*******************************/
void make_matrix (int **&a, int n)
{
	int numb = 0;
	a = new int *[n];
	for( int i = 0; i < n; ++i)
	{
		a[i] = new int[n];
	}	
}
/*******************************
** Function: print_matrix()
** Description: Prints the array from user input
** Parameters: **a, n
** Pre-Conditions: NxN user inputted matrix size and code from dimension function to determine the actual function
** Post-Conditions: Printed array to be passed to recursive and iteration functions.
*******************************/
void print_matrix(int **a, int n){
	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << a[i][j] << "	";
		}
	cout << endl;
	}
}
/*********************************
**Function; dimension()
**Description: Fills up array with correct numbers reading from left to right and down a row as the end of each row is met.
**Parameters: **m1, n
**Pre-Conditions: N x N user inputted matrix
**Post-Conditions: A definite array is defined for further use
********************************/
int dimensions (int **m1, int n)
{
	int numb = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
		   m1[i][j] = numb;
		   numb++;
		}
	}
}

/******************************
** Function: main()
** Description: Gets user input and contains code with pointers to correct arrays to connect the pointer to the desired array.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Matrix made is a N x N matrix from user input.
*******************************/
int main()
{
	int n, i, j;
	my_matrix board;
	cout << "How big of a board would you like to use?" << endl;
	cin >> board.n;
	cout << endl << "Here is the N x N board:" << endl;
	make_matrix (board.m1, board.n);
	dimensions (board.m1, board.n);
    print_matrix(board.m1, board.n);
	cout << endl << "Here is the N-1 x N-1 board:" << endl; 
	make_matrix (board.m2, board.n-1);
	calc_result_iterative(board.m1, board.m2, board.n);
	print_matrix (board.m2, board.n-1);
	calc_result_recursion(board.m1, board.m2, board.n, 0, 0);
	return 0;
}
