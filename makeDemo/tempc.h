#ifndef _TEMPC_H_
#define _TEMPC_H_

#include <iostream>

class TempF;	// forward declaration, can't #include "tempf.h"

class TempC
{
	public:
		TempC(float degrees);
		TempC(TempF* tempf);

	private:
		double	degrees;
	
	friend std::ostream& operator<<(std::ostream& out, TempC* tempC);

	friend class TempF;
};

#endif // _TEMPC_H_
