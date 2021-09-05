#ifndef _PATIENT_NIL_H_
#define _PATIENT_NIL_H_

#include "temperature.h"

class PatientNIL
{
public:
	PatientNIL(char* name, double fahrenheit, int age);
	~PatientNIL(void);

	friend std::ostream& operator<<(std::ostream& out, PatientNIL& patient);

private:
	char*			name;
	Temperature		temperature;
	int				age;
};

#endif // _PATIENT_NIL_H_
