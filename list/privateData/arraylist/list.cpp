#include <iomanip>
#include "list.h"

using namespace std;

static const int	INITIAL_SIZE{4};

struct PrivateData
{
	PrivateData(int arraySize, int nItems) :
		listArray{new char[INITIAL_SIZE]},
		arraySize{arraySize},
		nItems{nItems}
	{
	}

	~PrivateData()
	{
		delete[] listArray;
	}

	char*	listArray;
	int		arraySize;
	int		nItems;
};

List::List(void) :
	privateData{new PrivateData{INITIAL_SIZE, 0}}
{
}

List::~List(void)
{
	delete static_cast<PrivateData*>(privateData);
}

void List::expandIfNeeded()
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};
	int				newArraySize;
	char*			newArray;

	if (pd->nItems >= pd->arraySize) {
		newArraySize = pd->arraySize + INITIAL_SIZE;
		newArray = new char[newArraySize];
		for (int i = 0; i < pd->arraySize; i++)
			newArray[i] = pd->listArray[i];
		delete[] pd->listArray;
		pd->listArray = newArray;
		pd->arraySize = newArraySize;
		}
}

void List::addFirst(char ch)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	expandIfNeeded();
	for (int i{pd->nItems}; i > 0; i--)
		pd->listArray[i] = pd->listArray[i - 1];
	pd->listArray[0] = ch;
	pd->nItems++;
}

bool List::findIndex(const char ch, int& index) const
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	for (int i{0}; i < pd->nItems; i++)
		if (pd->listArray[i] == ch) {
			index = i;
			return true;
			}
	return false;
}

bool List::addBefore(char before, char ch)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};
	int				index;
	
	if (findIndex(before, index)) {
		expandIfNeeded();
		for (int i{pd->nItems - 1}; i >= index; i--)
			pd->listArray[i + 1] = pd->listArray[i];
		pd->listArray[index] = ch;
		pd->nItems++;
		return true;
		}
	else
		return false;
}

void List::addLast(char ch)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	expandIfNeeded();
	pd->listArray[pd->nItems++] = ch;
}

bool List::find(char ch) const
{
	int		index;

	return findIndex(ch, index);
}

bool List::remove(char ch)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};
	int				index;

	if (findIndex(ch, index)) {
		for (int i = index; i < pd->nItems - 1; i++)
			pd->listArray[i] = pd->listArray[i + 1];
		pd->nItems--;
		return true;
		}
	else
		return false;
}

void List::empty()
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};
	
	pd->nItems = 0;
}

int List::length(void) const
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	return pd->nItems;
}

char& List::operator[](int index)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	if (index < 0 || index >= pd->nItems)
		throw "index out of bounds";

	return pd->listArray[index];
}

ostream& operator<<(ostream& out, const List& list)
{
	PrivateData*	pd{static_cast<PrivateData*>(list.privateData)};
	bool			first{true};

	out << "List: (" << setw(2) << list.length() << " elements) [";
	for (int i{0}; i < pd->nItems; i++) {
		if (first)
			first = false;
		else
			out << ", ";
		out << pd->listArray[i];
		}
	out << "]" << endl;
	return out;
}
