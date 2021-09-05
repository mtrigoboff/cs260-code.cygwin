#include <cstring>
#include "database.h"
#include "list.h"

using namespace std;

Database::Database()
{
    lists = new List[Fire::District::N_DISTRICTS];
}

Database::~Database()
{
    delete[] lists;
}

void Database::insert(const Fire& fire)
{
    lists[static_cast<int>(fire.getDistrict())].add(fire);
}

Fire* const Database::find(const char* const name) const
{
    Fire* found = nullptr;
    for(int i = 0; 
        (i < static_cast<int>(Fire::District::N_DISTRICTS) && !found); ++i)
    {
       found = lists[i].find(name); 
    }

	return found;
}

bool Database::remove(const char * const name)
{
    Fire* found = nullptr;
    int i;
    for(i = 0; 
        (i < static_cast<int>(Fire::District::N_DISTRICTS) && !found); ++i)
    {
       found = lists[i].find(name); 
    }
    if(found)
         lists[i - 1].remove(name);

	return found;
}

ostream& operator<<(ostream& out, const Database& database)
{
	for(int i = 0; i < static_cast<int>(Fire::District::N_DISTRICTS); ++i)
    {
        out << static_cast<Fire::District>(i)
            << '(' << database.lists[i].getLength() << "):\n";
        out << database.lists[i] << '\n';
    }
    
	return out;	
}
