#include <iomanip>
#include "tempf.h"
#include "tempc.h"

using namespace std;

TempF::TempF(float degrees) :
	degrees{degrees}
{
}

TempF::TempF(TempC* tempC) :
	degrees{tempC->degrees * 9.0 / 5.0 + 32.0}
{
}

ostream& operator<<(ostream& out, TempF* tempF)
{
	out << "TempF: " << fixed << setw(5) << setprecision(1) << tempF->degrees << endl;
	return out;
}
