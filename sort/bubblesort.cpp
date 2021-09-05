#include <iostream>
#include "cout_colors.h"

using namespace std;
using namespace cout_colors;

void swap(int& x, int& y);
void printArray(int theArray[]);

static int arraySize;

void printNoSwap(int theArray[], int itemIndex, int endIndex)
{
	for (int i{0}; i < arraySize; i++) {
		if (i == itemIndex || i == itemIndex + 1)
			cout << BOLD << MAGENTA;
		else if (i <= endIndex)
			cout << RESET << GREEN;
		else
			cout << BOLD << BLACK;
		cout << theArray[i] << " ";
		}
	cout << endl;
}

void printSwap(int theArray[], int index1, int index2, int endIndex)
{
	for (int i{0}; i < arraySize; i++) {
		if (i == index1 || i == index2)
			cout << BOLD << YELLOW;
		else if (i <= endIndex)
			cout << RESET << GREEN;
		else
			cout << BOLD << BLACK;
		cout << theArray[i] << " ";
		}
	cout << endl;
}

void bubblesort(int theArray[], int arraySizeArg)
{
	bool sorted{false};

	arraySize = arraySizeArg;
	cout << "BubbleSort" << endl;
	printArray(theArray);
	for (int pass{1}; pass < arraySize && ! sorted; ++pass) {
		sorted = true;
		for (int index{0}; index < arraySize - pass; ++index) {
			int nextIndex{index + 1};
			if (theArray[index] > theArray[nextIndex]) {
				swap(theArray[index], theArray[nextIndex]);
				printSwap(theArray, index, nextIndex, arraySize - pass);
				sorted = false;
				}
			else
				printNoSwap(theArray, index, arraySize - pass);
			}
		}
	printArray(theArray);
	cout << endl;
}
