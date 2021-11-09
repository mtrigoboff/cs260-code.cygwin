#include <iostream>
#include <iomanip>
#include <cassert>
#include "cout_colors.h"
#include "arraybinarysearch.h"

using namespace std;
using namespace cout_colors;

ArrayBinarySearch::ArrayBinarySearch(int size) :
	items{new char[size]},
	size{size}
{
	int		nItems{0};
	char	c{'B'};
	int		i{0};

	assert(size >= 0 && size <= MAX_SIZE);
	for (; nItems < size && c <= 'Z'; i++, nItems++, c += 2)
		items[i] = c;
	c = 'b';
	for (; nItems < size && c <= 'z'; i++, nItems++, c += 2)
		items[i] = c;
}

ArrayBinarySearch::~ArrayBinarySearch(void)
{
	delete[] items;
}

bool ArrayBinarySearch::find_iterative(char ch)
{
	int		start{0};
	int		end{size - 1};
	int		half;

	cout << BOLD << BLUE << "iterative:" << endl;
	while (start <= end) {
		half = start + (end - start) / 2;
		print(ch, start, half, end);
		if (items[half] == ch)
			return true;
		else if (ch < items[half])
			end = half - 1;
		else
			start = half + 1;
		}
	return false;
}

bool ArrayBinarySearch::find_recursive(char ch)
{
	cout << BOLD << BLUE << "recursive:" << endl;
	return find_recursive(ch, 0, size - 1);
}

bool ArrayBinarySearch::find_recursive(char ch, int start, int end)
{
	assert(start <= end);

	int		half{start + (end - start) / 2};
	char	halfCh{items[half]};

	print(ch, start, half, end);

	if (halfCh == ch)
		return true;
	else if (ch < halfCh )
		if (half == start)
			return false;
		else
			return find_recursive(ch, start, half - 1);
	else
		if (half == end)
			return false;
		else
			return find_recursive(ch, half + 1, end);
}

void ArrayBinarySearch::print(char ch, int start, int half, int end)
{
	for (int i{0}; i < size; i++) {
		cout << BOLD;
		if (i == start)
			if (i == half)
				if (i == end)
					cout << MAGENTA;
				else
					cout << YELLOW;
			else
				cout << GREEN;
		else if (i == end)
			cout << GREEN;
		else if (i == half)
			cout << RED;
		else if (i > start && i < end)
			cout << BLACK;
		else
			cout << RESET << BLACK;
		cout << items[i] << " ";
		}
	cout << RESET << WHITE << endl;
}
