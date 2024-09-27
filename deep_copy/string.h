#ifndef _STRING_DEEP_H_
#define _STRING_DEEP_H_

// On cslinux.pcc.edu, the symbol was _STRING_H_, and it worked just fine.
// But in Cygwin, the <cstring> include apparently uses _STRING_H_, so this
// header got skipped and compiling string.cpp produced "String undeclared"
// errors. The fix was to make a different name for the symbol.

class String
{
public:
	String(const char* str = nullptr);	// default constructor if called with no args 
	String(const String& src);			// copy constructor
	~String(void);
	String& operator=(const String& src);

private:
	static int	nextID;

	void	copy(const String& src, bool deletePrevStr);
	char*	str;
	int		id;
};

#endif
