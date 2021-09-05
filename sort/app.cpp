#include <cstring>
#include <iostream>
#include "cout_colors.h"

using namespace std;

void bubblesort(int theArray[], int n);
void insertionsort(int theArray[], int n);
void mergesort(int theArray[], int arraySize);
void quicksort(int theArray[], int arraySize);
void selectionsort(int theArray[], int n);
void shellsort(int theArray[], int n);

typedef void(*SortFnPtr)(int theArray[], int n);

typedef struct {
	char		arg;
	char*		fnName;
	SortFnPtr	fnPtr;
	}
SortFnSpec;

SortFnSpec sortFns[] = {
			{'b', "bubblesort",		bubblesort},
			{'i', "insertionsort",	insertionsort},
			{'m', "mergesort",		mergesort},
			{'q', "quicksort",		quicksort},
			{'s', "selectionsort",	selectionsort},
			{'h', "shellsort",		shellsort}
			};

const int	N_SORT_FNS{sizeof(sortFns) / sizeof(SortFnSpec)};

const int	initValues[] = {6, 4, 1, 8, 3, 9, 7, 0, 2, 5};
const int	N_VALUES{sizeof(initValues) / sizeof(int)};
int			values[N_VALUES];

static void initArray(int values[], const int initValues[])
{
	for (int i = 0; i < N_VALUES; i++)
		values[i] = initValues[i];
}

void printArray(int theArray[])
{
	cout << cout_colors::RESET << cout_colors::CYAN;
	for (int i{0}; i <= N_VALUES - 1; i++)
		cout << theArray[i] << " ";
	cout << endl;
}

void swap(int& x, int& y)
{
	int		temp;

	temp = x;
	x = y;
	y = temp;
}

int main(int argc, char** argv)
{
	if (argc == 1) {
		cout << "need arg specifying which sort to run" << endl;
		for (int i{0}; i < N_SORT_FNS; i++)
			cout << "   " << sortFns[i].arg << ": " << sortFns[i].fnName << endl;
		return 0;
		}

	if (argc > 2)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);
	
	char	sortFnArg{argv[1][0]};

	initArray(values, initValues);
	for (int i{0}; i < N_SORT_FNS; i++)
		if (sortFns[i].arg == sortFnArg) {
			(*sortFns[i].fnPtr)(values, N_VALUES);
			goto done;
			}
	
	cout << "bad sort arg" << endl;
	return -1;

done:
	cout << cout_colors::RESET;
	return 0;
}
