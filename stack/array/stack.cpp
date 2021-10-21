#include "stack.h"

// stack fills up from last slot of array 'downwards' towards slot 0.
// When constructed, stack is empty, with 'top' pointing just past
// the end of the array.
Stack::Stack(int size) :
	size{size},
	top{size},
	stackArray{new char[size]}
{
}

Stack::~Stack(void)
{
	delete[] stackArray;
}

bool Stack::push(char ch)
{
	if (isFull())
		return false;
	else {
		stackArray[--top] = ch;
		return true;
		}
}

bool Stack::pop(char& ch)
{
	if (isEmpty())
		return false;
	else {
		ch = stackArray[top++];
		return true;
		}
}

bool Stack::isEmpty(void)
{
	return top == size;
}

bool Stack::isFull(void)
{
	return top == 0;
}

// does not use Iterator, needs to be friend of Stack
ostream& operator<<(ostream& out, Stack& stack)
{
	out << "Stack& [";
	if (stack.isEmpty())
		out << "empty";
	else
		for (int i = stack.top; i < stack.size; i++)
			out << stack.stackArray[i] << (i < stack.size - 1 ? ", " : "");
	out << ']' << endl;
	return out;
}

// uses Iterator, does not need to be friend of Stack
ostream& operator<<(ostream& out, Stack *stack)
{
	auto	iterator = stack->getIterator();
	bool	first{true};
	char	ch;

	out << "Stack* <";
	while (iterator->getNext(ch))
		out << (first ? first = false, "" : ", ") << ch;
	if (first)
		out << "empty";
	out << '>' << endl;
	delete iterator;
	return out;
}

Stack::Iterator::Iterator(Stack& stack) :
	stack{stack},
	next{stack.top}
{
}

bool Stack::Iterator::getNext(char& ch)
{
	if (next < stack.size) {
		ch = stack.stackArray[next++];
		return true;
		}
	else
		return false;
}
