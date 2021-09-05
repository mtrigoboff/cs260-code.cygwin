#ifndef _CAR_H_
#define _CAR_H_

#include "vehicle.h"

class Car : public Vehicle
{
	private:
		int		weight;
		
	public:
		Car(char* name, int weight);
		~Car(void);
		void print(std::ostream& out);
		void printSpeed(std::ostream& out);
};

#endif // _CAR_H_
