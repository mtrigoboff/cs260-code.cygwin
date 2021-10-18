#include <iostream>
#include <iomanip>
#include "coordinate.h"

using namespace std;

Coordinate::Coordinate(int degrees, int minutes, int secondsTenths):
                    degrees{degrees},
                    minutes{minutes},
                    secondsTenths{secondsTenths}
{}

Coordinate::Coordinate(void):
    degrees{0},
    minutes{0},
    secondsTenths{0}
{}

Coordinate::~Coordinate(void)
{}

ostream& operator<<(ostream& out, Coordinate& coord)
{
    out << coord.getDegrees () << "\370" <<" " << coord.getMinutes() << "\' " 
    << coord.getSecondsTenths() / 10 << "." << setw(2) << setfill('0') << coord.getSecondsTenths() % 10 << "\"";

	return out;
}
