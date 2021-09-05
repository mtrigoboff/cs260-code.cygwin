#include <iomanip>
#include "list.h"

using namespace std;

static const int	INITIAL_SIZE{4};

List::List(void) :
	listArray{new char[INITIAL_SIZE]},
	arraySize{INITIAL_SIZE},
	nextIndex{0}
{
}

List::~List(void)
{
	delete[] listArray;
}

void List::expandIfNeeded(void)
{
	int		newArraySize;
	char*	newArray;

	if (nextIndex >= arraySize) {
		newArraySize = arraySize + INITIAL_SIZE;
		newArray = new char[newArraySize];
		for (int i = 0; i < arraySize; i++)
			newArray[i] = listArray[i];
		delete[] listArray;
		listArray = newArray;
		arraySize = newArraySize;
		}
}

void List::addFirst(char ch)
{
	expandIfNeeded();
	for (int i{nextIndex}; i > 0; i--)
		listArray[i] = listArray[i - 1];
	listArray[0] = ch;
	nextIndex++;
}

bool List::findIndex(char ch, int& index) const
{
	for (int i{0}; i < nextIndex; i++)
		if (listArray[i] == ch) {
			index = i;
			return true;
			}
	return false;
}

bool List::addBefore(char before, char ch)
{
	int		index;
	
	if (findIndex(before, index)) {
		expandIfNeeded();
		for (int i{nextIndex - 1}; i >= index; i--)
			listArray[i + 1] = listArray[i];
		listArray[index] = ch;
		nextIndex++;
		return true;
		}
	else
		return false;
}

void List::addLast(char ch)
{
	expandIfNeeded();
	listArray[nextIndex++] = ch;
}

bool List::find(char ch) const
{
	int		index;

	return findIndex(ch, index);
}

bool List::remove(char ch)
{
	int		index;

	if (findIndex(ch, index)) {
		for (int i = index; i < nextIndex - 1; i++)
			listArray[i] = listArray[i + 1];
		nextIndex--;
		return true;
		}
	else
		return false;
}

int List::length(void) const
{
	return nextIndex;
}

char& List::operator[](int index)
{
	if (index < 0 || index >= nextIndex)
		throw "index out of bounds";

	return listArray[index];
}

ostream& operator<<(ostream& out, const List& list)
{
	bool first{true};

	out << "List: (" << setw(2) << list.length() << " elements) [";
	for (int i{0}; i < list.nextIndex; i++) {
		if (first)
			first = false;
		else
			out << ", ";
		out << list.listArray[i];
		}
	out << "]" << endl;
	return out;
}
