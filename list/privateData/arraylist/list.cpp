#include <iomanip>
#include "list.h"

using namespace std;

static const int	INITIAL_SIZE{4};

struct InstanceData
{
	InstanceData(int arraySize, int nItems) :
		listArray{new char[INITIAL_SIZE]},
		arraySize{arraySize},
		nItems{nItems}
	{
	}

	~InstanceData()
	{
		delete[] listArray;
	}

	void expandIfNeeded();
	bool findIndex(const char ch, int& index) const;

	char*	listArray;
	int		arraySize;
	int		nItems;
};

void InstanceData::expandIfNeeded()
{
	int				newArraySize;
	char*			newArray;

	if (nItems >= arraySize) {
		newArraySize = arraySize + INITIAL_SIZE;
		newArray = new char[newArraySize];
		for (int i = 0; i < arraySize; i++)
			newArray[i] = listArray[i];
		delete[] listArray;
		listArray = newArray;
		arraySize = newArraySize;
		}
}

bool InstanceData::findIndex(const char ch, int& index) const
{
	for (int i{0}; i < nItems; i++)
		if (listArray[i] == ch) {
			index = i;
			return true;
			}
	return false;
}

List::List(void) :
	instanceData{new InstanceData{INITIAL_SIZE, 0}}
{
}

List::~List(void)
{
	delete static_cast<InstanceData*>(instanceData);
}

void List::addFirst(char ch)
{
	InstanceData*	pd{static_cast<InstanceData*>(this->instanceData)};

	pd->expandIfNeeded();
	for (int i{pd->nItems}; i > 0; i--)
		pd->listArray[i] = pd->listArray[i - 1];
	pd->listArray[0] = ch;
	pd->nItems++;
}

bool List::addBefore(char before, char ch)
{
	InstanceData*	pd{static_cast<InstanceData*>(this->instanceData)};
	int				index;
	
	if (pd->findIndex(before, index)) {
		pd->expandIfNeeded();
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
	InstanceData*	pd{static_cast<InstanceData*>(this->instanceData)};

	pd->expandIfNeeded();
	pd->listArray[pd->nItems++] = ch;
}

bool List::find(char ch) const
{
	InstanceData*	pd{static_cast<InstanceData*>(this->instanceData)};
	int				index;

	return pd->findIndex(ch, index);
}

bool List::remove(char ch)
{
	InstanceData*	pd{static_cast<InstanceData*>(this->instanceData)};
	int				index;

	if (pd->findIndex(ch, index)) {
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
	InstanceData*	pd{static_cast<InstanceData*>(this->instanceData)};
	
	pd->nItems = 0;
}

int List::length(void) const
{
	InstanceData*	pd{static_cast<InstanceData*>(this->instanceData)};

	return pd->nItems;
}

char& List::operator[](int index)
{
	InstanceData*	pd{static_cast<InstanceData*>(this->instanceData)};

	if (index < 0 || index >= pd->nItems)
		throw "index out of bounds";

	return pd->listArray[index];
}

ostream& operator<<(ostream& out, const List& list)
{
	InstanceData*	pd{static_cast<InstanceData*>(list.instanceData)};
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
