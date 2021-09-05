#ifndef _STACK_H_
#define _STACK_H_

#include <ostream>
#include "list.h"

using namespace std;

class Stack
{
public:
	void push(char ch);
	bool pop(char& ch);
	bool isEmpty(void);
	
	friend ostream& operator<<(ostream& out, Stack& stack);
	friend ostream& operator<<(ostream& out, Stack *stack);

private:
	List	list;
};

#endif
