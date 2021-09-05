#ifndef _HEAP_H_
#define _HEAP_H_

// implements a "heap," as described in the textbook

#include <ostream>

using namespace std;

class Heap
{
public:
	enum class GetNextVersion {POLITICALLY_CORRECT, USES_GOTO, N_VERSIONS};

	Heap(int capacity, GetNextVersion getNextVersion);
	~Heap(void);

	bool add(char ch);							// adds a character to the heap
	bool getNext(char& ch);						// returns the "largest" character
	int getNItems(void);						// number of items in the heap

	static int getMaxNextVersionNameLgth();
	friend ostream& operator<<(ostream& out, GetNextVersion getNextVersion);

private:
	char			*items;						// the array
	int				capacity;					// capacity of the array
	int				nItems;						// how many items in the heap
	GetNextVersion	getNextVersion;				// which version of getNext to call

	// two different versions of getNext, provided for pedagogical purposes
	typedef bool (Heap::*GetNextFnPtr)(char& ch);	// pointer to function
	static GetNextFnPtr getNextFns[];				// array of pointers of the above type

	// functions of type GetNextFnPtr
	bool getNextPC(char& ch);					// politically correct
	bool getNextGoTo(char& ch);					// ignores political correctness

	// inline "macro" functions
	inline int leftChild(int index);			// index of left child
	inline int rightChild(int index);			// index of right child
	inline int parent(int index);				// index of parent
	inline void swap(int index1, int index2);	// swaps two elements of the array

	static int maxNextVersionNameLgth;
};

#endif
