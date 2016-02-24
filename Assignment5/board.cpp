/********************************************************
 **Program: board.cpp
 **Author: William Mays
 **Date: 11/26/14
 **Description: N x N matrix taken as input, N -1 x N-1 matrix is output with each new element being the sum of the four nearby elements from the previous matrix.
 **Input: Get a nuber for the rows and columns to make the arrays
 **Output: The N x N matrix and the N-1 x N-1 matrix
 ********************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib> 

using namespace std;

/*********************************
**Function; dimension()
**Description: Fills up array with correct numbers reading from left to right and down a row as the end of each row is met.
**Parameters: **dim and n
**Pre-Conditions: N x N user inputted matrix
**Post-Conditions: A definite array is defined for further use
********************************/
int dimension(int **dim, int n)
{
   int numb = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
		   dim[i][j] = numb;
		   numb++;
		}
	}
}
/*******************************
** Function: nxn()
** Description: Prints the array from user input
** Parameters: **dim, n
** Pre-Conditions: NxN user inputted matrix size and code from dimension function to determine the actual function
** Post-Conditions: Printed array to be passed to recursive and iteration functions.
*******************************/ 
void nxn(int **dim, int n)
{
	for(int i = 0; i < n;i++)
	{	
		for(int j = 0; j < n; j++)
		{
			cout << dim[i][j] << " ";
		}
	cout << endl;
	}
}
/******************************
** Function: nxn2()
** Description: Prints the ending array.
** Parameters: **dim, n
** Pre-Conditions: Based on iteration, N-1 x N-1 matrix printed
** Post-Conditions: None
********************************/
void nxn2(int **next_dim, int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-1; j++)
		{
			cout << next_dim[i][j] << " ";
		}
	cout << endl;
	}
}
/****************************
** Function: calculate_result()
** Description: Uses iteration to determine the N-1 x N-1 matrix
** Parameters: **dim, n
** Pre-Conditions: NxN matrix from user input
** Post-Conditions: Defined n-1 x n-1 matrix created
******************************/
void calculate_result(int **dim, int **next_dim, int n)
{
	int i, j;
	for(i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			next_dim[i][j] = (dim[i][j] + dim[i][j+1] + dim[i+1][j] + dim[i+1][j+1]);
		}
   }
}
/****************************
** Function: recursive_calculate_result
** Description: Uses recursion to determine the N-1 x N-1 matrix
** Parameters: **dim, n
** Pre-Conditions: NxN matrix from user input
** Post-Conditions: Defined N-1xN-1 matrix created
******************************/
void recursive_calculate_result(int **dim, int **next_dim, int i, int j, int n)
{
	if (i == n - 1)
		return;
	else if (j == n - 1)
		return;
	else
	{
		next_dim[i][j] = (dim[i][j] + dim[i][j+1] + dim[i+1][j] + dim[i+1][j+1]);
		recursive_calculate_result(dim, next_dim, i+1, j+1, n);
	}
}

/******************************
** Function: main()
** Description: Gets user input and contains code with pointers to correct arrays to connect the pointer to the desired array.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Matrix made is a N x N matrix from user input.
** ****************************/
int main(){
	int n, i, j;
	cout << "How many rows and columns would you like to use? "<<endl;
	cin >> n;
	int **dim; int **next_dim;
	dim = new int *[n];
	next_dim = new int *[n-1];
		for(i = 0; i < n; ++i)
		{
			dim[i] = new int[n];
		}
		for(i = 0; i < n - 1; ++i)
		{
			next_dim[i] = new int[n];
		}
	dimension(dim, n);
	cout << "Here is the NxN board: " << endl;
	nxn(dim, n);
	cout << endl;
	cout << "Here is the N-1xN-1 board: " << endl; 
	calculate_result(dim, next_dim, n);
	recursive_calculate_result(dim, next_dim, 0, 0, n);
	nxn2(next_dim, n);
	return 0;
}
