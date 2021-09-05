#include <iomanip>
#include "tempc.h"
#include "tempf.h"

using namespace std;

TempC::TempC(float degrees) :
	degrees{degrees}
{
}

TempC::TempC(TempF* tempF) :
	degrees{(tempF->degrees - 32.0) * 5.0 / 9.0}
{
}

ostream& operator<<(ostream& out, TempC* tempC)
{
	out << "TempC: " << fixed << setw(5) << setprecision(1) << tempC->degrees << endl;
	return out;
}
