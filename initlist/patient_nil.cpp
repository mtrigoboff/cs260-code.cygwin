#include <cstring>
#include <iostream>
#include <iomanip>
#include "patient_nil.h"

using namespace std;

PatientNIL::PatientNIL(char* name, double fahrenheit, int age)
{
	this->name = new char[strlen(name) + 1];
	this->age = age;
	strcpy(this->name, name);
	cout << *this;
	temperature.set(fahrenheit);
	cout << *this;
}

PatientNIL::~PatientNIL(void)
{
	delete[] name;
}

ostream& operator<<(ostream& out, PatientNIL& patient)
{
	out << "PatientNIL("
		<< patient.name << ", "
		<< patient.temperature << ", "
		<< patient.age
		<< ")" << endl;

	return out;
}
