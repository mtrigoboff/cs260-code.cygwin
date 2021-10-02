#ifndef _STRING_SHALLOW_H_
#define _STRING_SHALLOW_H_

class StringShallow
{
public:
	StringShallow(char *str = nullptr);	// default constructor if called with no args 
	// no copy constructor declared, so we get the default copy constructor,
	// which does shallow copy
	~StringShallow(void);
	// no operator= overload declared, so we get the default operator= overload,
	// which does shallow copy

private:
	static int	nextID;

	char	*str;
	int		id;
};

#endif
