// make NO CHANGES to this file

#ifndef _FIRE_H_
#define _FIRE_H_

#include <ostream>
#include "coordinate.h"

class Fire
{
public:
	enum class District {Astoria, Columbia_City, Dallas, Forest_Grove,
						 Molalla, Philomath, Santiam, Tillamook, Toledo,
						 N_DISTRICTS};

	Fire(const District district, const char * const name,
		 int latDeg, int latMin, int latSec, int longDeg, int longMin, int longSec);
	Fire(const District district, const char * const name,
		Coordinate latitude, Coordinate longitude);
	Fire(void);					// default constructor
	Fire(const Fire& fire);		// copy constructor
	virtual ~Fire(void);

	// nothing needed in the .cpp file for these functions - complete implementation is provided
	District			getDistrict() const		{ return district; }
	const char * const	getName() const			{ return name; };
	Coordinate			getLatitude() const		{ return latitude; };
	Coordinate			getLongitude() const	{ return longitude; };

	// comparison operators
	friend bool operator<(const Fire& fire1, const Fire& fire2);
	friend bool operator==(const Fire& fire1, const Fire& fire2);

	// print column headings for lists of fires
	static void displayColumnHeadings(std::ostream& out);

	// printing
	friend std::ostream& operator<<(std::ostream& out, Fire* fire);
	friend std::ostream& operator<<(std::ostream& out, Fire::District district);

private:
	District	district;
	char*		name;
	Coordinate	latitude;
	Coordinate	longitude;
};

#endif // _FIRE_H_
