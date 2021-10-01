#ifndef _STRING_SHALLOW_H_
#define _STRING_SHALLOW_H_

class StringShallow
{
public:
	StringShallow(char *str = nullptr);	// default constructor if called with no args 
	~StringShallow(void);

private:
	static int	nextID;

	char	*str;
	int		id;
};

#endif
