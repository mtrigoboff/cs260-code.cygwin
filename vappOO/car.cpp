#include "car.h"

using namespace std;

Car::Car(char* name, int weight) :
	Vehicle{name, 1},
	weight{weight}
{
}

Car::~Car(void)
{
}

void Car::print(ostream& out)
{
	Vehicle::print(out);
	out << "weight:   " << weight << " lbs" << endl;
}

void Car::printSpeed(ostream& out)
{
	out << speedHdr << 200000 / weight << " mph" << endl;
}
