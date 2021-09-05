#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <ostream>
#include "list.h"

class HashTable
{
public:
	static const int	NO_VALUE{-1};

	HashTable();
	~HashTable();

	void insert(char* key, int value, int* prevValue = nullptr);
	bool remove(char* key);
	bool find(char* key, int* value = nullptr) const;
	int getNPairs(void) const;

	int& operator[](char* key);

	friend std::ostream& operator<<(std::ostream& out, const HashTable& ht);

private:
	List*	table;
	int		tableSize;
	int		nPairs;

	int* getValuePtr(char* key);
	int hashIndex(char* key) const;
};

#endif
