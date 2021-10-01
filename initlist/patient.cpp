#include <cstring>
#include <iostream>
#include <iomanip>
#include "patient.h"

using namespace std;

Patient::Patient(char* name, double fahrenheit, int age) :
	name{new char[strlen(name) + 1]},
	temperature{fahrenheit},
	age{age}
{
	strcpy(this->name, name);
	cout << *this;
}

Patient::~Patient(void)
{
	delete[] name;
}
	
ostream& operator<<(ostream& out, Patient& patient)
{
	out << "Patient["
		<< "name=" << patient.name			<< ", "
		<< "temp=" << patient.temperature	<< ", "
		<< "age="  << patient.age			<< "]"
		<< endl;

	return out;
}
