// make NO CHANGES to this file

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <ostream>
#include "list2.h"

class Database
{
public:
	Database(void);				// constructor
	virtual ~Database(void);	// destructor

	// Insert a fire into the database.
	void insert(const Fire& fire);

	// Return a const pointer to the fire instance it finds in the
	// database, or nullptr if it didn't find a fire with that name.
	// Because the pointer is declared const, there is no danger
	// that find's caller will be able to use the returned pointer
	// to change the internal instance of Fire.
	Fire* const find(const char* const name) const;

	// Remove the fire with the specified name. Returns true if it
	// found and removed the fire, false if it did not find the fire.
	bool remove(const char * const name);

	// Print the contents of the database.
	friend std::ostream& operator<<(std::ostream& out, const Database& database);

private:
	List2	list2;
};

#endif // _DATABASE_H_
