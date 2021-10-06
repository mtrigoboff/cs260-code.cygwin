#include "car.h"

using namespace std;

Car::Car(Brand brand, EngineType engineType, int cylinders) :
	brand{brand}, engineType{engineType}, cylinders{cylinders}
{
}

ostream& operator<<(ostream& out, Car::Brand brand)
{
	char* str;

	switch (brand) {
		case Car::Brand::Buick:
			str = "Buick";
			break;
		case Car::Brand::Tesla:
			str = "Tesla";
			break;
		case Car::Brand::Volvo:
			str = "Volvo";
			break;
		default:
			str = "unknown brand";
			break;
		}

	out << str;

	return out;
}

ostream& operator<<(ostream& out, Car::EngineType engineType)
{
	char* str;

	switch (engineType) {
		case Car::EngineType::Diesel:
			str = "Diesel";
			break;
		case Car::EngineType::Electric:
			str = "Electric";
			break;
		case Car::EngineType::Gasoline:
			str = "Gasoline";
			break;
		default:
			str = "unknown engine type";
			break;
		}

	out << str;

	return out;
}

ostream& operator<<(ostream& out, Car& car)
{
	out << "brand:       "	<< car.brand		<< endl
		<< "engine type: "	<< car.engineType	<< endl
		<< "# cylinders: ";

	if (car.cylinders == -1)
		out << "n/a";
	else
		out << car.cylinders;

	out << endl;

	return out;
}
