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

static void addLast(char ch)
{
	list.addLast(ch);

	cout << "added " << ch << " as new last item" << endl;
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

	char	ch{'f'};

	cout << "list: implemented as array" << endl << endl;

	for (int i = 0; i < 5; i++)
		list.addFirst(ch--);
	cout << list << endl;

	addLast('G');
	cout << list << endl;

	addBefore('b', 'A');
	cout << list << endl;

	addBefore('c', 'C');
	cout << list << endl;

	addBefore('x', 'X');
	cout << list << endl;

	find('f');
	remove('f');
	cout << list << endl;

	find('A');
	remove('A');
	cout << list << endl;

	find('G');
	remove('G');
	cout << list << endl;

	find('x');
	remove('x');
	cout << endl;

	cout << "changing item [1] to 'X'" << endl;
	list[1] = 'X';
	cout << list << endl;

	cout << "retrieving item [1]" << endl;
	ch = list[1];
	cout << "   value is: " << ch << endl << endl;

	// for convenient gdb demo
	list[2] = 'Y';
	ch = list[2];

	// illegal index
	try {
		cout << "retrieving item [1000]" << endl;
		ch = list[1000];
		cout << "   value is: " << ch << endl << endl;
		}
	catch (char const * err) {
		cout << "   const error exception: " << err << endl;
		}
	catch (char* err) {
		cout << "   error exception: " << err << endl;
		}
	catch (...) {
		cout << "ellipsis!" << endl;
		}
	cout << endl;
	
	return 0;
}
