// make NO CHANGES to this file

#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <iostream>

class Coordinate
{
public:
	Coordinate(int degrees, int minutes, int secondsTenths);
	Coordinate(void);		// default constructor
	~Coordinate(void);		// destructor

	int getDegrees()		{ return degrees; }
	int getMinutes()		{ return minutes; }
	int getSecondsTenths()	{ return secondsTenths; }

	// print a coordinate
	friend std::ostream& operator<<(std::ostream& out, Coordinate& coord);

private:
	static const unsigned char		degreeChar{0xB0};	// Linux

	int		degrees;
	int		minutes;
	int		secondsTenths;
};

#endif // _COORDINATE_H_
