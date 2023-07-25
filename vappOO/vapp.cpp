#include <iostream>
#include "car.h"
#include "boat.h"
#include "plane.h"

using namespace std;

static const int nVehicles{6};

int main (void)
{
	Vehicle		*vehicles[6];
	
	vehicles[0] = new Car("Ford", 2000);
	vehicles[1] = new Car("Chevy", 3000);
	vehicles[2] = new Boat("Old Ironsides", Boat::BoatType::SAIL, 0, 100);
	vehicles[3] = new Boat("Sea Horse", Boat::BoatType::POWER, 1, 24);
	vehicles[4] = new Plane("B-52", 8, 150, "Boeing");
	vehicles[5] = new Plane("B-2", 2, 45, "Northrop");

	for (unsigned int i{0}; i < nVehicles; i++) {
		vehicles[i]->print(cout);
		vehicles[i]->printSpeed(cout);
		cout << endl;
		}

	for (unsigned int i{0}; i < nVehicles; i++)
		delete vehicles[i];
	
	return 0;
}
