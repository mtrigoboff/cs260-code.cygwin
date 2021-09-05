#include "stack.h"

void Stack::push(char ch)
{
	list.addFirst(ch);
}

bool Stack::pop(char& ch)
{
	return list.removeFirst(ch);
}

bool Stack::isEmpty(void)
{
	return list.length() == 0;
}

ostream& operator<<(ostream& out, Stack& stack)
{
	out << "<Stack& " << stack.list << '>' << endl;
	return out;
}

ostream& operator<<(ostream& out, Stack* stack)
{
	out << "<Stack* " << &stack->list << '>' << endl;
	return out;
}
