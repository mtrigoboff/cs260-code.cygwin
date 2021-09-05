#ifndef _TEMPF_H_
#define _TEMPF_H_

#include <iostream>

class TempC;	// forward declaration, can't #include "tempc.h"

class TempF
{
	public:
		TempF(float degrees);
		TempF(TempC* tempC);

	private:
		double	degrees;
	
	friend std::ostream& operator<<(std::ostream& out, TempF* tempF);

	friend class TempC;
};

#endif // _TEMPF_H_
