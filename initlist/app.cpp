#include <iostream>
#include "patient.h"
#include "patient_nil.h"
#include "temperature.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	cout << "--- temperatures ---" << endl << endl;

	Temperature		freeze{32.0};
	Temperature		absoluteZero{-459.67};

	double boil{Temperature::celsiusToFahrenheit(100.0)};
	cout << "boil: " << boil << endl;

	cout << endl;

	cout << "--- using initialization lists ---" << endl << endl;
	Patient			p1{"Ivan", 98.6, 37};
	cout << endl;
	Patient			p2{"Ivana", 104.2, 23};
	cout << endl;

	cout << "--- not using initialization lists ---" << endl << endl;
	PatientNIL		pn1{"Norman", 98.6, 68};
	cout << endl;
	PatientNIL		pn2{"Norma", 104.2, 62};
	cout << endl;

	return 0;
}
