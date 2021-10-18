#include <iostream>
#include <iomanip>
#include <cstring>
#include "fire.h"

using namespace std;

static const int	NAME_COL_WIDTH{26};

Fire::Fire(const Fire::District district, const char * const name,
		   int latDeg, int latMin, int latSec, int longDeg, int longMin, int longSec) :
    district{district},
    latitude{latDeg, latMin, latSec},
    longitude{longDeg, longMin, longSec},
    name{new char[strlen(name)+1] }
{
    strcpy(this->name, name);
}

Fire::Fire(const Fire::District district, const char * const name,
		   Coordinate latitude, Coordinate longitude):
           latitude{latitude},
           longitude{longitude},
           name{new char[strlen(name)+1] }
{
    strcpy(this->name, name);
}

Fire::Fire(void) :
    latitude{0,0,0},
    longitude{0,0,0}
{
    strcpy(name, "NO NAME");
}


Fire::Fire(const Fire& fire) :
    district {fire.district},
    latitude {fire.latitude},
    longitude {fire.longitude},
    name{new char[strlen(fire.getName() )+1] }
{
    strcpy(this->name,fire.getName());
}

Fire::~Fire()
{
    delete [] name;

}

bool operator<(const Fire &fire1, const Fire &fire2)
{
    if (fire1.getDistrict() == fire2.getDistrict() )
        return true;

	return false;
}

bool operator==(const Fire &fire1, const Fire &fire2)
{
    if(fire1.getDistrict() == fire2.getDistrict() )
        return true;

	return false;
}

void Fire::displayColumnHeadings(ostream& out)
{
    cout << "-----------------------   ----------------    --------------   -------------" << endl;
    cout << "name                      district            longitude        latitude     " << endl;
    cout << "-----------------------   ----------------    --------------   -------------" << endl;

}

std::ostream& operator<<(std::ostream& out, Fire::District district)
{
    char * districtName;

    switch(district)
    {
        case Fire::District::Astoria:
            districtName = "Astoria";
            break;
        case Fire::District::Columbia_City:
            districtName = "Columbia_City";
            break;
        case Fire::District::Dallas:
            districtName = "Dallas";
            break;
        case Fire::District::Forest_Grove:
            districtName = "Forest_Grove";
            break;
        case Fire::District::Molalla:
            districtName = "Molalla";
            break;
        case Fire::District::Philomath:
            districtName = "Philomath";
            break;
        case Fire::District::Santiam:
            districtName = "Santiam";
            break;
        case Fire::District::Tillamook:
            districtName = "Tillamook";
            break;
        case Fire::District::Toledo:
            districtName = "Toledo";
            break;
        default:
            districtName = "unknown district";
            break;

    }
    out << districtName;

	return out;
}

ostream& operator<<(ostream& out, Fire* fire)
{
    out << setw(26) << setfill(' ')<< left <<fire->name <<setw(20) 
    << fire->district  
    << fire->longitude << "    " 
    << fire->latitude << endl;


        

	return out;
}
