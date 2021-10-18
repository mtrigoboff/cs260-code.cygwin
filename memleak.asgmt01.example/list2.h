// Make NO CHANGES to the public section of the List2 class.
// You can add whatever you like to the private section of List2.

// defines a doubly-threaded linked list

#ifndef _LIST2_H_
#define _LIST2_H_

#include <iostream>
#include "fire.h"
#include <cstring>

class List2
{
public:
	List2(void);		// constructor
	~List2(void);		// destructor

	// Insert a fire into the list.
	void add(const Fire& fire);

	// Return a const pointer to the fire instance it finds in
	// the list, or nullptr if it didn't find a fire with that name.
	Fire* const find(const char * const name) const;

	// Remove the fire with the specified name. Returns true if it
	// found and removed the fire, false if it did not find the fire.
	bool remove(const char* const name);

	// Return how many fires are currently in the list.
	int	getLength(void) const;

	// Print the contents of the list, first one thread and then the other.
	friend std::ostream& operator<<(std::ostream& out, const List2& list2);

private:

	struct Node
	{
		Node(const Fire& fire);			// constructor
		Fire fire;						// an actual instance of Fire, ...
										// ... NOT a pointer to an instance
		Node *nextByName;				// next node by name
		Node *nextByDistrict;			// next node by district
	};

	Node*	headByName;
	Node*	headByDistrict;
	int		length;
};

#endif	// _LIST2_H_
