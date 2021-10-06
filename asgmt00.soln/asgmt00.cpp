#include <iostream>
#include "linkedlist.h"

using namespace std;

static void add(LinkedList& list, char ch)
{
	cout << "adding " << ch << endl;
	list.add(ch);
}

static void find(LinkedList& list, char ch)
{
	if (list.find(ch))
		cout << "found ";
	else
		cout << "did not find ";
	cout << ch << endl;
}

static void del(LinkedList& list, char ch)
{
	cout << "deleting " << ch << endl;
	list.del(ch);
}

int main(int argc, char** argv)
{
	if (argc > 1)               // turn off cout
        std::cout.setstate(std::ios_base::badbit);

	LinkedList	list;

	cout << "CS260 - Assignment 0" << endl << endl;

	add(list, 'x');
	add(list, 'y');
	add(list, 'z');
	cout << list << endl;
	find(list, 'y');

	del(list, 'y');
	cout << list << endl;
	find(list, 'y');

	del(list, 'x');
	cout << list << endl;
	find(list, 'y');

	del(list, 'z');
	cout << list << endl;
	find(list, 'y');

	return 0;
}
