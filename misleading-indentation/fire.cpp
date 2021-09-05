#include <iostream>
#include <iomanip>
#include <cstring>
#include <iomanip>
#include "fire.h"

using namespace std;

static const int	NAME_COL_WIDTH{26};

Fire::Fire(const Fire::District district, const char * const name,
		   int latDeg, int latMin, int latSec, int longDeg, int longMin, int longSec) : district(district), latitude(latDeg, latMin, latSec), longitude(longDeg, longMin, longSec) 
{
   this->name = new char[strlen(name) + 1];
   strcpy(this->name, name); 
}

Fire::Fire(const Fire::District district, const char * const name,
	Coordinate latitude, Coordinate longitude)
{
	// your code here, or in this constructor's initialization list
}

Fire::Fire()
{
	// your code here, or in this constructor's initialization list
}

Fire::Fire(const Fire& fire) : district(fire.district), latitude(fire.latitude), longitude(fire.longitude)
{
   name = new char[strlen(fire.name) + 1];
   strcpy(name, fire.name); 
}

Fire::~Fire()
{
    delete[] name;
}

bool operator<(const Fire &fire1, const Fire &fire2)
{
    
	return std::strcmp(fire1.getName(), fire2.getName()) < 0;
}

bool operator==(const Fire &fire1, const Fire &fire2)
{
	return std::strcmp(fire1.getName(), fire2.getName()) == 0;
}

void Fire::displayColumnHeadings(ostream& out)
{
    // I did not see the var before i wrote this
    out << "-----------------------   --------------   -------------\n"
           "name                      longitude        latitude\n"
           "-----------------------   --------------   -------------\n";
}



std::ostream& operator<<(std::ostream& out, Fire::District district)
{
    static const char* names[] = {"Astoria", "Columbia_City", "Dallas", "Forest_Grove", "Molalla", "Philomath", "Santiam", "Tillamook", "Toledo"
                      };

    out << names[static_cast<int>(district)];

	return out;
}

std::ostream& operator<<(std::ostream& out, Fire* fire)
{
    out << std::setw(NAME_COL_WIDTH) << std::left << fire->name << fire->longitude << fire->latitude;

    out << std::setw(0) << '\n';
    

	return out;
}
