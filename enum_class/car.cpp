#include <iomanip>
#include "car.h"

using namespace std;

Car::Car(Brand brand, EngineType engineType, int cylinders, int price) :
	brand{brand},
	engineType{engineType},
	cylinders{cylinders},
	price{price}
{
}

ostream& operator<<(ostream& out, Car& car)
{
	out << "brand:       "	<< car.brand		<< endl
		<< "engine type: "	<< car.engineType	<< endl;

	out << "cylinders:   ";
	if (car.cylinders == -1)
		out << "n/a";
	else
		out << car.cylinders;
	out << endl;

	out << "price:       $"
		<< car.price / 100 << '.'
		<< setw(2) << setfill('0') << car.price % 100
		<< endl;

	return out;
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
