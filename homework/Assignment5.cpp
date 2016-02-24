/********************************************************
** Program: assignment_5.cpp
** Author:  
** Date: 3/7/14
** Description: N x N matrix taken as input, N -1 x N-1 matrix is output with 
** each new element being the sum of the four nearby elements from the previous matrix.
** Input: Rows and columns to make up the matrix.
** Output: The N x N matrix and the appropriate N-1 x N-1 matrix
********************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib> 

using namespace std;

int dimension(int**, int);
void calc_result_iterative(int**, int**, int);
void calc_result_recursion(int**, int**, int, int, int);
void array(int**, int);

int main()
{
	int n, i, j;
	cout << "How many rows and columns would you like to use? " << endl;
	cin >> n;
	int **dim; int **next_dim;
	dim = new int *[n];
	next_dim = new int *[n-1];
		for( i = 0; i < n; ++i)
		{
			dim[i] = new int[n];
		}
		for( i = 0; i < n - 1; ++i)
		{
			next_dim[i] = new int[n];
		}
	dimension(dim, n);
	calc_result_recursion(dim, next_dim, i, j, n);
	array(next_dim, n);
	return 0;
}

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

void array(int **next_dim, int n)
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

void calc_result_recursion(int **dim, int **next_dim, int i, int j, int n){

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
	next_dim[i][j] = (dim[i][j] + dim[i][j+1] + dim[i+1][j] + dim[i+1][j+1]);
	calc_result_recursion(dim, next_dim, i+1, j+1, n);
	}
}
