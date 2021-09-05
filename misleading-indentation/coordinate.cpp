#include <iostream>
#include <iomanip>
#include "coordinate.h"
#include <iomanip>
using namespace std;

Coordinate::Coordinate(int degrees, int minutes, int secondsTenths) : degrees(degrees), minutes(minutes), secondsTenths(secondsTenths)
{
}

Coordinate::Coordinate(void)
{
	// your code here, or in this constructor's initialization list
}

Coordinate::~Coordinate(void)
{
	// your code here
}

ostream& operator<<(ostream& out, Coordinate& coord)
{
    int seconds = (coord.secondsTenths - (coord.secondsTenths % 10)) / 10;
    int tenths  =  (coord.secondsTenths % 10);

    //auto a = "º"; 
    //out << a << ' ';
    
    out << std::right << std::setw(3) << coord.degrees << Coordinate::degreeChar << ' ' << std::setw(2) << coord.minutes << "\'" << ' ' << std::setw(2) << seconds << '.' << tenths << std::left << std::setw(3) << "\""; 
	return out;
}
