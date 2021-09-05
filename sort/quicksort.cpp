#include <iostream>
#include "cout_colors.h"

using namespace std;
using namespace cout_colors;

void swap(int& x, int& y);
void printArray(int theArray[]);

static int	arraySize;

static void printRegions(int theArray[],
						 int first, int last,			// array segment specifiers
						 int index1, int index2,		// items being swapped if != -1
						 int firstUnknown, int lastS1,	// region specifiers
						 int itemIndex)					// item being considered
{
	for (int i{0}; i < arraySize; i++) {

		// make item being considered bold
		if (i == itemIndex || (index1 != -1 && index1 == index2 && i == index1))
			cout << BOLD;
		else
			cout << RESET;

		// color
		if (i == index1 || i == index2)					// being swapped
			cout << BOLD << YELLOW;
		else if (i == first)							// pivot
			cout << RED;
		else if (i > first && i <= lastS1)				// < pivot
			cout << GREEN;
		else if (i > lastS1 && i <= firstUnknown)		// > pivot
			cout << MAGENTA;
		else if (i > firstUnknown && i <= last)			// not yet sorted
			cout << BOLD << BLACK;
		else											// not yet partitioned
			cout << BLACK;

		cout << theArray[i] << " ";
		}
	cout << endl;
}

static void printPivotSwap(int theArray[], int first, int last, int pivot)
{
	for (int i{0}; i <= last; i++) {

		// color
		if (i == first || i == pivot)		// being swapped
			cout << BOLD << YELLOW;
		else if (i < first || i > last)		// outside of array segment
			cout << BLACK;
		else								// rest of array segment
			cout << BOLD << BLACK;

		cout << theArray[i] << " ";
		}
	cout << endl;
}

// this is a heuristic that MIGHT choose a better pivot than
// what's currently in theArray[first] 
static void choosePivot(int theArray[], int first, int last)
{
	int		middle{first + (last - first) / 2};
	int		pivot;

	// place the middle value of theArray[first], theArray[middle], theArray[last]
	// into theArray[first] 

	if ((theArray[first] < theArray[middle] && theArray[middle] < theArray[last]) ||
		(theArray[first] > theArray[middle] && theArray[middle] > theArray[last]))
		  pivot = middle;
	else if ((theArray[first] < theArray[last] && theArray[last] < theArray[middle]) ||
			 (theArray[first] > theArray[last] && theArray[last] > theArray[middle]))
		  pivot = last;
	else // the middle value was already in theArray[first] 
		  pivot = first;
	swap(theArray[first], theArray[pivot]);
	printPivotSwap(theArray, first, last, pivot);
}

static int partition(int theArray[], int first, int last)
{
	choosePivot(theArray, first, last);		// place pivot in theArray[first]
	int pivot{theArray[first]};

	// initially, everything but pivot is in unknown
	int lastS1{first};				// index of last item in S1
	int firstUnknown{first + 1};	// index of first item in unknown

	// move one item at a time until unknown region is empty
	for (; firstUnknown <= last; ++firstUnknown) {

		// move item from unknown to proper region
		if (theArray[firstUnknown] < pivot) {	// item from unknown belongs in S1
			++lastS1;
			swap(theArray[firstUnknown], theArray[lastS1]);
			printRegions(theArray, first, last, firstUnknown, lastS1, firstUnknown, lastS1, -1);
			}
		else
			printRegions(theArray, first, last, -1, -1, firstUnknown, lastS1, firstUnknown);
			

		// else item from unknown belongs in S2, is already there
	}

	// place pivot in proper position and mark its location
	swap(theArray[first], theArray[lastS1]);
	printRegions(theArray, first, last, first, lastS1, firstUnknown - 1, lastS1, -1);
	printArray(theArray);
	return lastS1;
}

// recursive "private" function
static void quicksort(int theArray[], int first, int last)
{
	int pivotIndex;

	if (first < last) {
		pivotIndex = partition(theArray, first, last);

		// sort regions S1 and S2
		quicksort(theArray, first, pivotIndex - 1);
		quicksort(theArray, pivotIndex + 1, last);
		}
}

// non-recursive "public" function
void quicksort(int theArray[], int arraySizeArg)
{
	arraySize = arraySizeArg;
	cout << CYAN << "QuickSort" << endl;
	printArray(theArray);
	quicksort(theArray, 0, arraySize - 1);
	cout << endl;
}
