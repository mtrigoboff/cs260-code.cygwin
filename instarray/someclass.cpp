#include "someclass.h"

SomeClass::SomeClass(int a) :
	a{a}
{
}

SomeClass::SomeClass() :
	a{-1}
{
}

#ifdef COPY_CTOR
// copy constructor
SomeClass::SomeClass(SomeClass& sc) :
	a{sc.a}
{
}
#endif
