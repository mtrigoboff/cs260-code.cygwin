#include <cstring>
#include <iostream>
#include <iomanip>
#include "hashtable.h"

using namespace std;

static const int	TABLE_SIZE{7};

HashTable::HashTable() :
	hashArray{new List[TABLE_SIZE]},
	hashArraySize{TABLE_SIZE},
	nPairs{0}
{
}

HashTable::~HashTable()
{
	delete[] hashArray; 
}

bool HashTable::get(const char* const key, int* valuePtr) const
{
	return find(key, valuePtr);
}

void HashTable::put(const char* const key, int value, int* prevValue)
{
	int*	valuePtr{getValuePtr(key)};

	if (prevValue)
		*prevValue = *valuePtr;
	*valuePtr = value;
}

bool HashTable::find(const char* const key, int* valuePtr) const
{
	int		index{hashKey(key) % hashArraySize};
	List&	slotList{hashArray[index]};
	int*	listNodeValuePtr;

	if (slotList.find(key, &listNodeValuePtr)) {
		if (valuePtr)
			*valuePtr = *listNodeValuePtr;
		return true;
		}
	else
		return false;
}

bool HashTable::remove(char* key)
{
	int		index{hashKey(key) % hashArraySize};
	List&	slotList{hashArray[index]};

	if (slotList.remove(key)) {
		nPairs--;
		return true;
		}
	else
		return false;
}

int HashTable::getNPairs(void) const
{
	return nPairs;
}

int& HashTable::operator[](char* key)
{
	return *getValuePtr(key);
}

ostream& operator<<(ostream& out, const HashTable& ht)
{
	out << "HashTable contents: " << ht.nPairs << " pairs" << endl;
	out << "----------------------------------------------------------------------------" << endl;
	for (int i = 0; i < ht.hashArraySize; i++)
		out << setw(2) << i << ": " << ht.hashArray[i] << endl;
	out << "----------------------------------------------------------------------------" << endl;
	return out;
}

int* HashTable::getValuePtr(const char* const key)
{
	int		index{hashKey(key) % hashArraySize};		// calculate index in the array
	int*	valuePtr;

	if (! hashArray[index].find(key, &valuePtr)) {
		valuePtr = hashArray[index].add(key, NO_VALUE);
		nPairs++;
		}
	return valuePtr;
}

int HashTable::hashKey(const char* const key)
{
	size_t	length{strlen(key)};
	int		hashValue{0};

	// Something is very wrong with this hash function -- what?
	for(size_t i = 0; i < length; i++)
		hashValue += key[i];

	return hashValue;
}







	


