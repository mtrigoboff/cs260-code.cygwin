#include <cstring>
#include "database.h"

using namespace std;

Database::Database()
{
}

Database::~Database()
{
}

void Database::insert(const Fire& fire)
{
    list2.add(fire);
}

Fire* const Database::find(const char* const name) const
{
	return list2.find(name);
}

bool Database::remove(const char * const name)
{
    if(list2.remove(name))
        return true;

	return false;
}

ostream& operator<<(ostream& out, const Database& database)
{
    out << database.list2; 

	return out;	
}
