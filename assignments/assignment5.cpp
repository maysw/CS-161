

#include <iostream>
#include <cstring>
#include <cstdlib> 


//Prototypes for all functions
int dimension(int**, int);
void calc_result_iterative(int**, int**, int);
void calc_result_recursion(int**, int**, int, int, int);
void array1(int**, int);
void array2(int**, int);
using namespace std;

int main(){
int rows, cols, n, i, j;
cout << "How many rows and columns would you like to use? "<<endl;
cin >> n;
int **dim; int **next_dim;
dim = new int *[n];
next_dim = new int *[n-1];
		for( i = 0; i < n; ++i){
			dim[i] = new int[n];
		}
		for( i = 0; i < n - 1; ++i)
		{
			next_dim[i] = new int[n];

		}

dimension(dim, n);
array1(dim, n);
calc_result_iterative(dim, next_dim, n);
cout << endl;
calc_result_recursion(dim, next_dim, 0, 0, n);
array2(next_dim, n);

	return 0;
}

int dimension(int **dim, int n){
   int numb = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
		
		   dim[i][j] = numb;
		   numb++;
		
		}
	
	}
}
 
void array1(int **dim, int n){

	for(int i = 0; i < n;i++){
	
		for(int j = 0; j < n; j++){
			cout << dim[i][j] << " ";
		}
	cout << endl;
	}

}
void array2(int **next_dim, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1; j++)
		{
			cout << next_dim[i][j] << " ";
		}
	cout << endl;
	}

}

void calc_result_iterative(int **dim, int **next_dim, int n){
	int i, j;
   for(i = 0; i < n - 1; i++){
   	for (j = 0; j < n - 1; j++){

	next_dim[i][j] = (dim[i][j] + dim[i][j+1] + dim[i+1][j] + dim[i+1][j+1]);
	
	}
 
   }
}

void calc_result_recursion(int **dim, int **next_dim, int i, int j, int n){

   if (i == n - 1)
   	return;
   else if (j == n - 1)
        return;
   else{
   
   	next_dim[i][j] = (dim[i][j] + dim[i][j+1] + dim[i+1][j] + dim[i+1][j+1]);
	calc_result_recursion(dim, next_dim, i+1, j+1, n);
   
   }
}
