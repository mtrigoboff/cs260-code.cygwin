#include "list.h"

using namespace std;

static const int	INITIAL_SIZE{5};

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
	listArray[nextIndex++] = ch;
}

bool List::getFirst(char& ch)
{
	if (nextIndex >= 1) {
		ch = listArray[nextIndex - 1];
		return true;
		}
	else
		return false;
}

bool List::findIndex(char ch, int& index)
{
	for (int i = 0; i < nextIndex; i++)
		if (listArray[i] == ch) {
			index = i + 1;
			return true;
			}
	return false;
}

bool List::addBefore(char before, char ch)
{
	int		index;
	
	expandIfNeeded();
	if(findIndex(before, index)) {
		for (int i = nextIndex; i >= index; i--)
			listArray[i] = listArray[i - 1];
		listArray[index] = ch;
		nextIndex++;
		return true;
		}
	else
		return false;
}

bool List::find(char ch)
{
	int		index;

	return findIndex(ch, index);
}

bool List::remove(char ch)
{
	int		index;

	for (index = 0; index < nextIndex; index++)
		if (listArray[index] == ch)
			goto found;
	return false;

found:
	for (int i = index; i < nextIndex - 1; i++)
		listArray[i] = listArray[i + 1];
	nextIndex--;
	return true;
}

bool List::removeFirst(char& ch)
{
	if (nextIndex > 0) {
		ch = listArray[--nextIndex];
		return true;
		}
	else
		return false;
}

int List::length(void)
{
	return nextIndex;
}

ostream& operator<<(ostream& out, List& list)
{
	bool first{true};

	out << "{List& (" << list.length() << ") [";
	for (int i = list.nextIndex - 1; i >= 0; i--) {
		if (first)
			first = false;
		else
			out << ", ";
		out << list.listArray[i];
		}
	out << "]}";
	return out;
}

ostream& operator<<(ostream& out, List* list)
{
	auto	iter{list->getIterator()};
	char	ch;
	bool	first{true};

	out << "{List* (" << list->length() << ") [";
	while (iter->getNext(ch)) {
		if (first)
			first = false;
		else
			out << ", ";
		out << ch;
		}
	out << "]}";

	delete iter;
	return out;
}

List::Iterator::Iterator(List& list) :
	list{list},
	next(list.nextIndex - 1)
{
}

bool List::Iterator::getNext(char& ch)
{
	if (next >= 0) {
		ch = list.listArray[next--]; 
		return true;
		}
	else
		return false;
}
