#include <iostream>
#include "hashtable.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	HashTable	hashTable;
	int			value;

	// insert hashTable
	hashTable["Alpha"] =	1;
	hashTable["Bravo"] =	2;
	hashTable["Charlie"] =	3;
	hashTable["Delta"] =	4;
	cout << hashTable << endl;

	hashTable["Echo"] =		5;
	hashTable["Foxtrot"] =	6;
	hashTable["Golf"] =		7;
	cout << hashTable << endl;

	// test right side use operator[]
	value = hashTable["Bravo"];
	cout << "value for Bravo is: " << value << endl;
	hashTable["Bravo"] =	22;
	value = hashTable["Bravo"];
	cout << "value for Bravo is: " << value << endl;
	value = hashTable["Zulu"];
	cout << "value for Zulu is: " << value << endl << endl;
	cout << hashTable << endl;

	if (hashTable.find("Charlie"))
		cout << "found Charlie" << endl;
	if (hashTable.find("Charlie", &value))
		cout << "found Charlie's value: " << value << endl;
	cout << endl;

	hashTable.remove("Charlie");
	hashTable.remove("Echo");
	cout << hashTable << endl;

	hashTable.insert("Delta", 44, &value);
	cout << "Delta previous value: " << value << endl;
	hashTable.insert("Golf",  77, &value);
	cout << "Golf  previous value: " << value << endl << endl;
	cout << hashTable << endl;

	return 0;
}
