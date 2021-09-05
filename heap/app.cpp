#include <iostream>
#include <iomanip>
#include <cstring>
#include "heap.h"

using namespace std;

void printPriorityOrder(Heap& heap)
{
	char	ch;

	while (heap.getNext(ch))
		cout << ch << " ";
	cout << endl;
}

static void run(Heap::GetNextVersion getNextVersion)
{
	Heap	heap{15, getNextVersion};
	char*	items{"CBEFGDAZRWXNTJH"};
	int		nItems{(int) strlen(items)};

	// add a set of items to the heap
	for (int i{0}; i < nItems; i++)
		heap.add(items[i]);

	// print out the contents of the heap in "priority" order,
	// by removing one item at a time until the heap is empty
	cout << setw(heap.getMaxNextVersionNameLgth()) << getNextVersion << ": ";
	printPriorityOrder(heap);
	cout << endl;
}

int main(int argc, char **argv)
{
	if (argc > 1)               // turn off cout
		std::cout.setstate(std::ios_base::badbit);

	run(Heap::GetNextVersion::POLITICALLY_CORRECT);
	run(Heap::GetNextVersion::USES_GOTO);

	return 0;
}
