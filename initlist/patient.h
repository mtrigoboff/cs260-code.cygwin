#ifndef _PATIENT_H_
#define _PATIENT_H_

#include <ostream>
#include "temperature.h"

class Patient
{
public:
	Patient(char* name, double fahrenheit, int age);
	~Patient(void);

	friend std::ostream& operator<<(std::ostream& out, Patient& patient);

private:
	char*			name;
	Temperature		temperature;
	int				age;
};

#endif // _PATIENT_H_
