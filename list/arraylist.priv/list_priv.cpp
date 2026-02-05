#include <iomanip>
#include "list_priv.h"

using namespace std;

static const int	INITIAL_SIZE{4};

ListPriv::ListPriv(void) :
	listArray{new char[INITIAL_SIZE]},
	arraySize{INITIAL_SIZE},
	nItems{0}
{
}

ListPriv::~ListPriv(void)
{
	delete[] listArray;
}

void ListPriv::expandIfNeeded(void)
{
	int		newArraySize;
	char*	newArray;

	if (nItems >= arraySize) {
		newArraySize = arraySize + INITIAL_SIZE;
		newArray = new char[newArraySize];
		for (int i = 0; i < arraySize; i++)
			newArray[i] = listArray[i];
		delete[] listArray;
		listArray = newArray;
		arraySize = newArraySize;
		}
}

void ListPriv::addFirst(char ch)
{
	expandIfNeeded();
	for (int i{nItems}; i > 0; i--)
		listArray[i] = listArray[i - 1];
	listArray[0] = ch;
	nItems++;
}

bool ListPriv::findIndex(char ch, int& index) const
{
	for (int i{0}; i < nItems; i++)
		if (listArray[i] == ch) {
			index = i;
			return true;
			}
	return false;
}

bool ListPriv::addBefore(char before, char ch)
{
	int		index;
	
	if (findIndex(before, index)) {
		expandIfNeeded();
		for (int i{nItems - 1}; i >= index; i--)
			listArray[i + 1] = listArray[i];
		listArray[index] = ch;
		nItems++;
		return true;
		}
	else
		return false;
}

void ListPriv::addLast(char ch)
{
	expandIfNeeded();
	listArray[nItems++] = ch;
}

bool ListPriv::find(char ch) const
{
	int		index;

	return findIndex(ch, index);
}

bool ListPriv::remove(char ch)
{
	int		index;

	if (findIndex(ch, index)) {
		for (int i = index; i < nItems - 1; i++)
			listArray[i] = listArray[i + 1];
		nItems--;
		return true;
		}
	else
		return false;
}

void ListPriv::empty()
{
	nItems = 0;
}

int ListPriv::length(void) const
{
	return nItems;
}

char& ListPriv::operator[](int index)
{
	if (index < 0 || index >= nItems)
		throw "index out of bounds";

	return listArray[index];
}

ostream& operator<<(ostream& out, const ListPriv& list)
{
	bool	first{true};
	int		listLgth{list.length()};

	out << "List: (" << setw(2) << listLgth << " elements) [";
	for (int i{0}; i < listLgth; i++) {
		if (first)
			first = false;
		else
			out << ", ";
		out << list.listArray[i];
		}
	out << "]" << endl;
	return out;
}
