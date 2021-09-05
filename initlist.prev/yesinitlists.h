#ifndef _YESINITLISTS_H_
#define _YESINITLISTS_H_

#include <iostream>
#include "sequence.h"

// A class whose instances contain an embedded instance of Sequence.
// The constructor for this class uses initializer lists.

class YesInitLists
{
public:
	YesInitLists(int first, int value, int last);
	~YesInitLists(void);

private:
	int			first;
	Sequence	sequence;
	int			last;

	friend std::ostream& operator<<(std::ostream& out,
									YesInitLists& yes);
};


#endif
