#include <iostream>

using namespace std;

int main()
{
	intro();
		if (intro == 0)
			exit(0);
		else if (intro == 1)
			add_movies();
		else if (itnro == 2)
			rent();
		else
			intro();
			

	return 0;
}

int intro(int ask);
{
	int ask;
	cout >> "Do you wish to enter a movie to the datase or find a movie to rent? (1 - enter, 2 - find, or 0 - exit)
	cin >> ask;
}