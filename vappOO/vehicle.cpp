#include <cstring>
#include <ostream>
#include "vehicle.h"

using namespace std;

char*	Vehicle::speedHdr = "speed:    ";

Vehicle::Vehicle(char* name, int nEngines) :
	nEngines{nEngines}
{
	strncpy(this->name, name, sizeof(this->name));
}

Vehicle::~Vehicle(void)
{
}

void Vehicle::print(std::ostream& out)
{
	out << "name:     " << name << endl
		<< "#engines: " << nEngines << endl;
}
