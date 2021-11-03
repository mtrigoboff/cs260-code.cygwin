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

	// test right side use of operator[]
	cout << "changing value for Bravo" << endl;
	value = hashTable["Bravo"];
	cout << "value for Bravo is: " << value << endl;
	hashTable["Bravo"] =	22;
	value = hashTable["Bravo"];
	cout << "value for Bravo is: " << value << endl;

	cout << endl << "getting value for nonexistent key" << endl;
	value = hashTable["Zulu"];
	cout << "value for Zulu is: " << value << endl << endl;
	cout << hashTable << endl;

	cout << "finding Charlie" << endl;
	if (hashTable.find("Charlie"))
		cout << "found Charlie" << endl;
	if (hashTable.find("Charlie", &value))
		cout << "found Charlie's value: " << value << endl;
	cout << endl;

	cout << "removing Charlie and Echo" << endl << endl;
	hashTable.remove("Charlie");
	hashTable.remove("Echo");
	cout << hashTable << endl;

	cout << "changing Delta's value" << endl;
	hashTable.put("Delta", 44, &value);
	cout << "Delta previous value: " << value << endl;
	hashTable.get("Delta", &value);
	cout << "Delta current value: " << value << endl << endl;

	cout << "changing Xray's value" << endl;
	hashTable.put("Xray",  77, &value);
	cout << "Xray  previous value: " << value << endl;
	hashTable.get("Xray", &value);
	cout << "Xray current value: " << value << endl << endl;
	cout << hashTable << endl;

	return 0;
}
