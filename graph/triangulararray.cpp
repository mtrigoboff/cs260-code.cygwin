#include "triangulararray.h"
#include <cassert>

TriangularArray::TriangularArray(int size, bool initialValue) :
	size{size},
	capacity{sum0toN(size)},
	items{new bool[capacity]}
{
	for (int i{0}; i < capacity; i++)
		items[i] = initialValue;
}

bool& TriangularArray::item(int i, int j)
{
	int		index;

	assert(i >= 0 && j >= 0 && i < size && j < size);
	if (j > i) {		// switch to diagonally symmetrical array element
		int		temp{i};
		i = j;
		j = temp;
		}
	index = sum0toN(i) + j;
	assert(index >= 0 && index < capacity);
	return items[index];
}

TriangularArray::~TriangularArray()
{
	delete[] items;
}

int TriangularArray::sum0toN(int n)
{
	return n * (n + 1) / 2;
}
