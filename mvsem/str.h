#ifndef _STR_H_
#define _STR_H_

#include <iostream>

class Str
{
	public:
		Str();
		Str(char* str);
		Str(const Str& str);		// copy constructor
		Str& operator=(Str& rval);	// copy operator=
		Str(Str&& rval);			// move constructor
		Str& operator=(Str&& rhs);	// move operator=
		~Str();

	private:
		static int	nextID;
		
		char	*chars;
		int		instID;

	friend std::ostream& operator<<(std::ostream& out, Str& str);
};

#endif // _STR_H_
