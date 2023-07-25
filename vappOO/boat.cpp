#include "boat.h"
#include <math.h>
#include <iomanip>

using namespace std;

Boat::Boat(char* name, BoatType type, int nEngines, int length) :
	Vehicle{name, nEngines},
	length{length},
	type{type}
{
}

Boat::~Boat(void)
{
}

void Boat::print(std::ostream& out)
{
	char*	typeName;

	Vehicle::print(out);
	switch (type) {
		case BoatType::SAIL:
			typeName = "Sail";
			break;
		case BoatType::POWER:
			typeName = "Power";
			break;
		}
	out << "type:     " << typeName << endl;
}

void Boat::printSpeed(ostream& out)
{
	out << speedHdr << setprecision(3) << 1.34 * sqrt((float) length) << " knots" << endl;
}
