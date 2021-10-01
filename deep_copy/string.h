#ifndef _STRING_H_
#define _STRING_H_

class String
{
public:
	String(char* str = nullptr);	// default constructor if called with no args 
	String(const String& src);		// copy constructor
	~String(void);
	String& operator=(String& src);

private:
	static int	nextID;

	void	copy(const String& src, bool deletePrevStr);
	char*	str;
	int		id;
};

#endif
