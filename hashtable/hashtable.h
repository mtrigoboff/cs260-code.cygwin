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

	bool get(const char* const key, int* valuePtr) const;
	void put(const char* const key, int value, int* prevValue = nullptr);
	bool find(const char* const key, int* value = nullptr) const;
	bool remove(char* key);
	int getNPairs(void) const;

	int& operator[](char* key);

	friend std::ostream& operator<<(std::ostream& out, const HashTable& ht);

private:
	int* getValuePtr(const char* const key);
	static int hashKey(const char* const key);

	List*	hashArray;
	int		hashArraySize;
	int		nPairs;
};

#endif
