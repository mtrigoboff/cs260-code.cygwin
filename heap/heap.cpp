#include <cstring>
#include "heap.h"

Heap::GetNextFnPtr Heap::getNextFns[]{&Heap::getNextPC, &Heap::getNextGoTo};

int Heap::maxNextVersionNameLgth;

// this needs to be in same order as GetNextVersion
char*	getNextVersionNames[]{"politically correct", "uses goto"};

int Heap::getMaxNextVersionNameLgth()
{
	return maxNextVersionNameLgth;
}

Heap::Heap(int capacity, GetNextVersion getNextVersion) :
	items{new char[capacity]},
	capacity{capacity},
	nItems{0},
	getNextVersion{getNextVersion}
{
	int		maxLgth{0};
	int		lgth;

	for (int i{0}; i < static_cast<int>(Heap::GetNextVersion::N_VERSIONS); i++) {
		lgth = strlen(getNextVersionNames[i]);
		if (lgth > maxLgth)
			maxLgth = lgth;
		}
	maxNextVersionNameLgth = maxLgth;
}

Heap::~Heap(void)
{
	delete[] items;
}

bool Heap::add(char ch)
{
	int		index;
	int		parentIndex;

	if (nItems >= capacity)							// array full
		return false;

	index = nItems++;
	items[index] = ch;								// add new item at end of array
	while (index > 0) {								// bubble item up to its proper position
		parentIndex = parent(index);
		if (items[index] > items[parentIndex]) {	// item larger than its parent?
			swap(index, parentIndex);				// swap item with its parent
			index = parentIndex;					// continue with parent
			}
		else
			break;
		}

	return true;
}

ostream& operator<<(ostream& out, Heap::GetNextVersion getNextVersion)
{
	out << getNextVersionNames[static_cast<int>(getNextVersion)];
	return out;
}

bool Heap::getNext(char& ch)
{
	// run function from getNextFns array specified by getNextVersion
	return (this->*getNextFns[static_cast<int>(getNextVersion)])(ch);
}

// "structured programming" version of getNext
bool Heap::getNextPC(char& ch)
{
	int		endIndex;
	int		index;
	int		leftIndex, rightIndex, swapIndex;

	if (nItems < 1)												// array empty
		return false;

	ch = items[0];												// return root
	items[0] = items[--nItems];									// copy last item to slot 0
	endIndex = nItems - 1;										// index of last item in array
	index = 0;													// start with root
	for (;;) {
		leftIndex = leftChild(index);
		rightIndex = rightChild(index);
		if (rightIndex <= endIndex)								// both children legal?
			// left child always comes before right child in array,
			// so if right child is legal, left child is as well
			if (items[leftIndex] > items[index] || items[rightIndex] > items[index]) {
				// at least 1 child > parent
				swapIndex = items[leftIndex] > items[rightIndex] ? leftIndex : rightIndex;
					// index of larger child
				swap(index, swapIndex);							// swap larger child with parent
				index = swapIndex;
				}
			else
				break;
		else if (leftIndex <= endIndex)							// left child legal?
			if (items[leftIndex] > items[index] ) {				// left child larger?
				swap(index, leftIndex);							// swap left child with parent
				index = leftIndex;								// continue with left child
				}
			else
				break;
		else													// left child illegal,
			break;												//    so right child is too
	}

	return true;
}

// version of getNext that uses (gasp!!!) the dreaded goto
bool Heap::getNextGoTo(char& ch)
{
	int		endIndex;
	int		index;
	int		leftIndex, rightIndex;

	if (nItems < 1)												// heap empty
		return false;

	ch = items[0];												// return root
	items[0] = items[--nItems];									// copy last item to slot 0
	endIndex = nItems - 1;										// index of last item in array
	index = 0;													// start with root
	for (;;) {
		leftIndex = leftChild(index);
		rightIndex = rightChild(index);
		if (rightIndex <= endIndex)								// both children legal?
			if (items[leftIndex] > items[rightIndex])			// left child larger than right?
				goto checkLeftLarger;
			else
				goto checkRightLarger;
		else if (leftIndex <= endIndex)							// left child legal?
			goto checkLeftLarger;
		else
			break;

	checkLeftLarger:
		if (items[leftIndex] > items[index])					// left child larger than root?
			goto swapLeft;
		else
			break;

	checkRightLarger:
		if (items[rightIndex] > items[index])					// right child larger than root?
			goto swapRight;
		else
			break;

	swapLeft:
		swap(index, leftIndex);									// swap left child with root
		index = leftIndex;										// continue with left child
		continue;

	swapRight:
		swap(index, rightIndex);								// swap right child with root
		index = rightIndex;										// continue with right child
		continue;
	}

	return true;
}

// number of items in the heap
int Heap::getNItems(void)
{
	return nItems;
}

// index of left child
int Heap::leftChild(int index)
{
	return 2 * index + 1;
}

// index of right child
int Heap::rightChild(int index)
{
	return 2 * index + 2;
}

// index of parent
int Heap::parent(int index)
{
	return (index - 1) / 2;
}

// swaps two elements of the array
void Heap::swap(int index1, int index2)
{
	char	item;

	item = items[index1];
	items[index1] = items[index2];
	items[index2] = item;
}

