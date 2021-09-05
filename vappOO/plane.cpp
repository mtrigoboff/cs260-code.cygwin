#include "plane.h"

using namespace std;

Plane::Plane(char *name, int nEngines, int wingspan) :
	Vehicle(name, nEngines),
	wingspan(wingspan)
{
	this->wingspan = wingspan;
}

Plane::~Plane(void)
{
}

void Plane::print(ostream& out)
{
	Vehicle::print(out);
	out << wingspan << " feet" << endl;
}

void Plane::printSpeed(ostream& out)
{
	out << 20 * wingspan / nEngines << " mph" << endl;
}
