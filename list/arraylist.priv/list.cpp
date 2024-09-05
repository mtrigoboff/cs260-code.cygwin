#include <iomanip>
#include "list.h"
#include "list_priv.h"

using namespace std;

static const int	INITIAL_SIZE{4};

List::List(void) :
	listPriv{static_cast<void*>(new ListPriv())}
{
}

List::~List(void)
{
	delete static_cast<ListPriv*>(listPriv);
}

void List::addFirst(char ch)
{
	static_cast<ListPriv*>(listPriv)->addFirst(ch);
}

bool List::addBefore(char before, char ch)
{
	return static_cast<ListPriv*>(listPriv)->addBefore(before, ch);
}

void List::addLast(char ch)
{
	static_cast<ListPriv*>(listPriv)->addLast(ch);
}

bool List::find(char ch) const
{
	return static_cast<ListPriv*>(listPriv)->find(ch);
}

bool List::remove(char ch)
{
	return static_cast<ListPriv*>(listPriv)->remove(ch);
}

void List::empty()
{
	static_cast<ListPriv*>(listPriv)->empty();
}

int List::length(void) const
{
	return static_cast<ListPriv*>(listPriv)->length();
}

char& List::operator[](int index)
{
	return static_cast<ListPriv*>(listPriv)->operator[](index);
}

ostream& operator<<(ostream& out, const List& list)
{
	return operator<<(out, *static_cast<ListPriv*>(list.listPriv));
}
