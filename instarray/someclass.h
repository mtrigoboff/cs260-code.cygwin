#ifndef _SOMECLASS_H_
#define _SOMECLASS_H_


class SomeClass
{
public:
	SomeClass(int a);
	SomeClass(void);				// default constructor

	#ifdef COPY_CTOR
	SomeClass(SomeClass& sc);		// copy constructor
	#endif

private:
	int		a;
};

#endif
