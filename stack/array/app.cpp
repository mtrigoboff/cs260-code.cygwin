#include <iostream>
#include "stack.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	int		size{6};
	Stack	stk{size};
	char	ch;

	cout << "Stack Demonstration: initial stack size == " << size << endl << endl;
	cout << stk << endl;

	for (int i = 0, ch = 'a'; i < size + 1; i++, ch++) {
		cout << "push " << static_cast<char>(ch) << endl;
		if (stk.push(ch))
			cout << stk << endl;	// call operator<< with reference arg
		else
			cout << "could not push " << static_cast<char>(ch) << endl << endl;
		}

	cout << &stk << endl;			// call operator<< with pointer arg

	for (int i = 0; i < size + 1; i++) {
		if (stk.pop(ch)) {
			cout << "pop " << static_cast<char>(ch) << endl;
			cout << stk << endl;	// call operator<< with reference arg
			}
		else
			cout << "could not pop empty stack" << endl << endl;
		}

	cout << &stk << endl;			// call operator<< with pointer arg

	cout << endl;

	return 0;
}
