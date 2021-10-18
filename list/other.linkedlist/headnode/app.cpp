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

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	char	ch{'k'};

	cout << "List: uses head node" << endl << endl;

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
	remove('x');

	cout << endl;

	return 0;
}
