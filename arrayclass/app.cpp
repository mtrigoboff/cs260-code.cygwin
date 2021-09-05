#include <iostream>
#include "array.h"

using namespace std;

int main(void)
{
	Array	a(10);
	char	ch;

	// demonstrate array bounds checking
	try {
		// initialize array
		ch = 'a';
		for (int i = 0; i < 10; i++)
			a[i] = ch++;

		cout << a << endl;

		// demonstrate use of operator[] for both get and set
		ch = a[4];
		a[4] = ch + 1;
		ch = a[4];
		cout << a << endl << endl;

		ch = a[20];

	} catch (Array::IndexOutOfBounds *e) {
		cout << e << endl;
		delete e;
	}

	cout << endl;
	return 0;
}
