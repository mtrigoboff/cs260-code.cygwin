#ifndef _STACK_H_
#define _STACK_H_

#include <ostream>

using namespace std;

class Stack
{
public:
	Stack(int size);
	~Stack(void);
	bool push(char ch);
	bool pop(char& ch);
	bool isEmpty(void);
	bool isFull(void);
	
	class Iterator
	{
	public:
		bool getNext(char& ch);
	
	private:
		Iterator(Stack& stack);
			// constructor is private so that you can only get an instance
			// of Iterator by calling getIterator(), defined below

		Stack&	stack;
		int		next;

		friend class Stack;
	};

	friend ostream& operator<<(ostream& out, Stack& stack);

	Iterator *getIterator(void) { return new Iterator(*this); }

private:
	int		size;
	int		top;
	char*	stackArray;
};

ostream& operator<<(ostream& out, Stack *stack);

#endif
