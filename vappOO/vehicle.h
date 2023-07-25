#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <ostream>

class Vehicle
{
	private:
		char			name[20];

	protected:
		static char*	speedHdr;

		int				nEngines;

		Vehicle(char* name, int nEngines);

	public:
		virtual ~Vehicle(void);
		virtual void print(std::ostream& out);
		virtual void printSpeed(std::ostream& out) = 0;
};

#endif // _VEHICLE_H_
