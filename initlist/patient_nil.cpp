#include <cstring>
#include <iostream>
#include <iomanip>
#include "patient_nil.h"

using namespace std;

PatientNIL::PatientNIL(char* name, double fahrenheit, int age)
{
	// these could have been done in an initialization list
	this->name = new char[strlen(name) + 1];
	this->age = age;
	
	strcpy(this->name, name);
	cout << *this;

	// this could have been done in an initialization list
	temperature.set(fahrenheit);
	cout << *this;
}

PatientNIL::~PatientNIL(void)
{
	delete[] name;
}

ostream& operator<<(ostream& out, PatientNIL& patient)
{
	out << "PatientNIL["
		<< "name=" << patient.name			<< ", "
		<< "temp=" << patient.temperature	<< ", "
		<< "age="  << patient.age			<< "]"
		<< endl;

	return out;
}
