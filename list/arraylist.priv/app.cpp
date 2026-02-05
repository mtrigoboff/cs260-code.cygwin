#include "list.h"

using namespace std;

static List		list;

static bool addBefore(char before, char ch)
{
	bool	added{list.addBefore(before, ch)};

	if (added)
		cout << "added ";
	else		
		cout << "didn't add ";
	cout << ch << " before " << before << endl;

	return added;
}

static bool find(char ch)
{
	bool	found{list.find(ch)};

	if (found)
		cout << "found ";
	else
		cout << "didn't find ";
	cout << ch << endl;

	return found;
}

static bool remove(char ch)
{
	bool	removed{list.remove(ch)};

	if (removed)
		cout << "removed ";
	else
		cout << "didn't remove ";
	cout << ch << endl;

	return removed;
}

static void getIndex(int index)
{
	try {
		char ch{list[index]};
		cout << "list[" << index << "] == " << ch;
		}
	catch (const char* e) {
		cout << "list[" << index << "]: " << e;
		}
	cout << endl;
}

static void setIndex(int index, char ch)
{
	try {
		list[index] = ch;
		cout << "list[" << index << "] = " << ch;
		}
	catch (const char* e) {
		cout << "list[" << index << "]: " << e;
		}
	cout << endl;
}

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	char	ch{'k'};

	cout << "List: no head node" << endl << endl;

	getIndex(2);
	cout << endl;

	for (int i = 0; i < 5; i++)
		list.addFirst(ch--);
	cout << list << endl;

	for (int i = 0; i < 5; i++)
		list.addFirst(ch--);
	cout << list << endl;
	
	addBefore('b', 'A');
	cout << list << endl;

	addBefore('k', 'Z');
	cout << list << endl;
	
	addBefore('x', 'X');
	cout << list << endl;

	find('f');
	remove('f');
	cout << list << endl;

	find('A');
	remove('A');
	cout << list << endl;

	find('k');
	remove('k');
	cout << list << endl;

	find('x');
	cout << endl;

	cout << "adding x at end of list" << endl;
	list.addLast('x');
	cout << list << endl;

	find('x');
	remove('x');
	cout << list << endl;

	cout << "-- operator[] overload --" << endl;
	cout << list;
	getIndex(2);
	getIndex(-3);
	getIndex(22);
	setIndex(2, 'x');
	cout << list;
	cout << "emptying list" << endl;
	list.empty();
	cout << list;
	getIndex(2);
	cout << endl;

	return 0;
}
