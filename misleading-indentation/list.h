// make NO CHANGES to this file

#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include "fire.h"

class List
{
public:
	List(void);		// constructor
	~List(void);		// destructor

	// Insert a fire into the list, maintaining the list in
	// alphabetical order by name.
	void add(const Fire& fire);

	// Return a const pointer to the fire instance it finds in
	// the list, or nullptr if it didn't find a fire with that name.
	Fire* const find(const char * const name) const;


	// Remove the fire with the specified name. Returns true if it
	// found and removed the fire, false if it did not find the fire.
	bool remove(const char* const name);

	// Return how many fires are currently in the list.
	int	getLength(void) const;

	// Print the contents of the list.
	friend std::ostream& operator<<(std::ostream& out, const List& list);

private:

	struct Node
	{
		Node(const Fire& fire);			// constructor
		Fire fire;						// an actual instance of Fire,
										// NOT a pointer to an instance
		Node *next;						// next node in the linked list
	};

	Node*	first;
	int		length;
};

#endif	// _LIST_H_
