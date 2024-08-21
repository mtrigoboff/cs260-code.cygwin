#include <iostream>
#include <iomanip>
#include <string>
#include "arraylist.h"

using namespace std;

extern void templates2(void);

static const int MARGIN = 26;

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	ArrayList	chArray;
	
	chArray.add('a');
	chArray.add('b');
	chArray.add('c');

	cout << setw(MARGIN) << left << "normal for loop: ";
	for (int i = 0; i < chArray.size(); i++)
		cout << chArray[i] << ' ';
	cout << endl;

	cout << setw(MARGIN) << left << "explicit iterator calls: ";
	for (ArrayList::iterator it{chArray.begin()}; it != chArray.end(); it++)
		cout << *it << ' ';
	cout << endl;

	cout << setw(MARGIN) << left << "using auto keyword: ";
	for (auto it{chArray.begin()}; it != chArray.end(); it++)
		cout << *it << ' ';
	cout << endl;

	// ch variable is a reference to avoid making unecessary copies
	cout << setw(MARGIN) << left << "using for-each loop: ";
	for (auto& ch : chArray)
		cout << ch << ' ';
	cout << endl << endl;
	
	try {
		chArray.add('d');
		}
	catch (ArrayList::ArrayListException e) {
		cout << e << endl;
		}

	try {
		cout << chArray[100];
		}
	catch (ArrayList::ArrayListException e) {
		cout << e << endl;
		}

	cout << endl;
	return 0;
}
