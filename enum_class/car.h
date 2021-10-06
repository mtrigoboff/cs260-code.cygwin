#ifndef _CAR_H_
#define _CAR_H_

#include <ostream>

class Car
{
public:

	enum class Brand {
		Audi, Buick, Chevy, Nissan, Tesla, Toyota, Volvo,
		N_BRANDS
	};

	enum class EngineType {
		Diesel, Electric, Gasoline,
		N_ENGINETYPES
	};

	Car(Brand brand, EngineType engineType, int price);

	friend std::ostream& operator<<(std::ostream& out, Brand brand);
	friend std::ostream& operator<<(std::ostream& out, EngineType engineType);
	friend std::ostream& operator<<(std::ostream& out, Car& car);

private:

	Brand		brand;
	EngineType	engineType;
	int			cylinders;
};

#endif // _CAR_H_
