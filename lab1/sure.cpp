#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(){
	int movies, stars, cast, rating, copies;
	string name;
	int netflix_array[14];
	cout << "How many movies do you want to enter to the database? ";
	cin >> movies;
	cout << "\n Enter the name of your movie: "; 
	cin >> name;
	netflix_array[2] = name;
	cout << "How many stars? ";
	cin >> stars;
	netflix_array[4] = stars;
	cout << "How many cast members? ";
	cin >> cast;
	netflix_array[6] = cast;
		for( int i =0; i > cast; i++)
			cout << "Enter cast member: ";
			cin.get();
	cout << "Enter movie rating: ";
	cin >> rating;
	netflix_array[8] = rating;
	cout << "How many copies of this movie? ";
	cin >> copies;
	netflix_array[10] = copies;	
	
	cout << netflix_array << endl;
}