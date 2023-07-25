#ifndef _PLANE_H_
#define _PLANE_H_

#include "vehicle.h"

class Plane : public Vehicle
{
	private:
		int		wingspan;
		char*	company;
		
	public:
		Plane(char *name, int nEngines, int wingspan, char* cmpny);
		~Plane(void);
		void print(std::ostream& out);
		void printSpeed(std::ostream& out);
};

#endif // _PLANE_H_
