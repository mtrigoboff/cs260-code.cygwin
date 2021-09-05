#ifndef _STR_H_
#define _STR_H_

#include <iostream>

class Str
{
	public:
		Str(char* str);
		~Str();

	private:
		static int	nextID;
		
		char	*chars;

	friend std::ostream& operator<<(std::ostream& out, Str* str);
};

#endif // _STR_H_
