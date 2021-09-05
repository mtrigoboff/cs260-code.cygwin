#ifndef _BOAT_H_
#define _BOAT_H_

#include "vehicle.h"

class Boat : public Vehicle
{
	public:
		enum class BoatType {
			SAIL, POWER
			};

		Boat(char* name, BoatType type, int nEngines, int length);
		~Boat(void);
		void print(std::ostream& out);
		void printSpeed(std::ostream& out);

	private:
		int			length;
		BoatType	type;	
};

#endif // _BOAT_H_
