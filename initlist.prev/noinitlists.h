#ifndef _NOINITLISTS_H_
#define _NOINITLISTS_H_

#include <iostream>

#include "sequence.h"

// A class whose instances contain an embedded instance of Sequence.
// The constructor for this class does not use initializer lists.

class NoInitLists
{
public:
	NoInitLists(int first, int value, int last);
	~NoInitLists(void);

private:
	int			first;
	Sequence	sequence;
	int			last;

	friend std::ostream& operator<<(std::ostream& out,
									NoInitLists& no);
};

#endif
