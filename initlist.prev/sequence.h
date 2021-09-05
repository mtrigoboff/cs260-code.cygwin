#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include <iostream>

// class that stores a sequence of 3 integers

class Sequence
{
public:
	Sequence(void);				// default constructor
	Sequence(int value);
	~Sequence(void);
	void setValue(int value);

private:
	int		before;		// one less than value
	int		value;
	int		after;		// one greater than value

	friend std::ostream& operator<<(std::ostream& out, Sequence& seq);
};

#endif
