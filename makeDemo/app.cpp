#include <stdlib.h>
#include <iostream>
#include "tempf.h"
#include "tempc.h"

using namespace std;

int main(int argc, char** argv)
{
	float	cmdLineTemp{argc > 1 ? (float) atof(argv[1]) : (float) 212};

	TempF	tempF{cmdLineTemp};
	TempC	tempC{&tempF};

	cout << "My Temperature Converter" << endl;

	cout << &tempF;
	cout << &tempC;

	return 0;
}
