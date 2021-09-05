#ifndef _ARRAYBINARYSEARCH_H_
#define _ARRAYBINARYSEARCH_H_

class ArrayBinarySearch
{
public:
	static const int	MAX_SIZE{25};

	ArrayBinarySearch(int itemArraySize);
	~ArrayBinarySearch(void);

	bool find_iterative(char ch);
	bool find_recursive(char ch);

private:
	bool find_recursive(char ch, int start, int end);
	void print(char ch, int start, int half, int end);

	char*	items;		// the array of chars
	int		size;		// size of the array in bytes
};


#endif
