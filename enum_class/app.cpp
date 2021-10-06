#include <iostream>
#include "car.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	Car		buick{Car::Brand::Buick, Car::EngineType::Diesel,	 8, 3400000};
	Car		tesla{Car::Brand::Tesla, Car::EngineType::Electric, -1, 8555058};
	Car		volvo{Car::Brand::Volvo, Car::EngineType::Gasoline,  5, 4545950};

	cout << buick << endl;
	cout << tesla << endl;
	cout << volvo << endl;

	return 0;
}
