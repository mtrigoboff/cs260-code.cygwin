#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "hashtable.h"

using namespace std;

static const int	TABLE_SIZE{7};

HashTable::HashTable() :
	table{new List[TABLE_SIZE]},
	tableSize{TABLE_SIZE},
	nPairs{0}
{
}

HashTable::~HashTable()
{
	delete[] table; 
}

void HashTable::insert(char* key, int value, int* prevValue)
{
	int*	valuePtr{getValuePtr(key)};

	if (prevValue)
		*prevValue = *valuePtr;
	*valuePtr = value;
}

int& HashTable::operator[](char* key)
{
	return *getValuePtr(key);
}

int* HashTable::getValuePtr(char* key)
{
	int		index{hashIndex(key)};		// calculate index in the array
	int		listPosn;
	int*	valuePtr;

	listPosn = table[index].find(key, &valuePtr);
	if (listPosn == -1) {
		valuePtr = table[index].add(key, NO_VALUE);
		nPairs++;
		}
	return valuePtr;
}

bool HashTable::remove(char* key)
{
	int		index{hashIndex(key)};
	List&	slotList{table[index]};
	int*	value;
	int		listPosn{slotList.find(key, &value)};

	if (listPosn == -1) {
		return false;
		}
	else {
		slotList.remove(listPosn);
		nPairs--;
		return true;
		}
}

bool HashTable::find(char* key, int* value) const
{
	int*	listNodeValuePtr;
	int		findPosn;

	//calculate the retrieval position (the index into the array)
	int		index{hashIndex(key)};
	List&	slotList{table[index]};

	findPosn = slotList.find(key, &listNodeValuePtr);
	if (value)
		*value = *listNodeValuePtr;
	return findPosn != -1;
}

int HashTable::getNPairs(void) const
{
	return nPairs;
}

ostream& operator<<(ostream& out, const HashTable& ht)
{
	out << "HashTable contents: " << ht.nPairs << " pairs" << endl;
	out << "----------------------------------------------------------------------------" << endl;
	for (int i = 0; i < ht.tableSize; i++)
		out << setw(2) << i << ": " << ht.table[i] << endl;
	out << "----------------------------------------------------------------------------" << endl;
	return out;
}

int HashTable::hashIndex(char* key) const
{
	size_t	length{strlen(key)};
	int		hashValue{0};

	// Something is very wrong with this hash function -- what?
	for(size_t i = 0; i < length; i++)
		hashValue += key[i];

	// Is it a good idea to do the % operation here?
	return hashValue % tableSize;
}







	


