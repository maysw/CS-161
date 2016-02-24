#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

#define Water_Weight 62.4;

int main() {
	//Variables needed to calculate buoyancy
	float radius, bforce, volume;
	int weight;
	//double Water_Weight 62.4;
		
	//prompt user for weight and radius of sphere
	cout << "Please enter the weight (lbs):";
	cin >> weight;

	cout << "Please enter the radius:";
	cin >> radius;

	//Calculate the volume and buoyancy force
	volume = 4./3. * M_PI * pow(radius, 3);
	bforce = volume * Water_Weight;

	//determine if the sphere will sink or float
	if (bforce >= weight)
	{
	   cout << "The sphere will float! \n";
	}
	else
     	{
	   cout << "The sphere will sink!\n";
	}
	return 0;
}
