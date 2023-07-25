#include <cstring>
#include "plane.h"

using namespace std;

Plane::Plane(char *name, int nEngines, int wingspan, char* cmpny) :
	Vehicle(name, nEngines),
	wingspan(wingspan)
{
	this->wingspan = wingspan;
	company = new char[strlen(cmpny) + 1];
	strcpy(company, cmpny);
}

Plane::~Plane(void)
{
	delete[] company;
}

void Plane::print(ostream& out)
{
	Vehicle::print(out);
	out << "wingspan: " << wingspan << " feet" << endl;
	out << "company:  " << company << endl;
}

void Plane::printSpeed(ostream& out)
{
	out << speedHdr << 20 * wingspan / nEngines << " mph" << endl;
}
