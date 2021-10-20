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
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	id->expandIfNeeded();
	for (int i{id->nItems}; i > 0; i--)
		id->listArray[i] = id->listArray[i - 1];
	id->listArray[0] = ch;
	id->nItems++;
}

bool List::addBefore(char before, char ch)
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};
	int				index;
	
	if (id->findIndex(before, index)) {
		id->expandIfNeeded();
		for (int i{id->nItems - 1}; i >= index; i--)
			id->listArray[i + 1] = id->listArray[i];
		id->listArray[index] = ch;
		id->nItems++;
		return true;
		}
	else
		return false;
}

void List::addLast(char ch)
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	id->expandIfNeeded();
	id->listArray[id->nItems++] = ch;
}

bool List::find(char ch) const
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};
	int				index;

	return id->findIndex(ch, index);
}

bool List::remove(char ch)
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};
	int				index;

	if (id->findIndex(ch, index)) {
		for (int i = index; i < id->nItems - 1; i++)
			id->listArray[i] = id->listArray[i + 1];
		id->nItems--;
		return true;
		}
	else
		return false;
}

void List::empty()
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};
	
	id->nItems = 0;
}

int List::length(void) const
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	return id->nItems;
}

char& List::operator[](int index)
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	if (index < 0 || index >= id->nItems)
		throw "index out of bounds";

	return id->listArray[index];
}

ostream& operator<<(ostream& out, const List& list)
{
	InstanceData*	id{static_cast<InstanceData*>(list.instanceData)};
	bool			first{true};

	out << "List: (" << setw(2) << list.length() << " elements) [";
	for (int i{0}; i < id->nItems; i++) {
		if (first)
			first = false;
		else
			out << ", ";
		out << id->listArray[i];
		}
	out << "]" << endl;
	return out;
}
