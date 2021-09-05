#include <iostream>
#include "cout_colors.h"

using namespace std;
using namespace cout_colors;

int main()
{
	cout << "Cout Colors" << endl;

	cout << RED << "HHHHH" << endl;
	cout << BLACK << "HHHHH" << endl;
	cout << GREEN << "HHHHH" << endl;
	cout << YELLOW << "HHHHH" << endl;
	cout << BLUE << "HHHHH" << endl;
	cout << MAGENTA << "HHHHH" << endl;
	cout << CYAN << "HHHHH" << endl;
	cout << WHITE << "HHHHH" << endl;
	cout << cout_colors::RESET;			// without using namespace

	cout << endl << "Cout Bold Colors" << endl;

	cout << BOLD << RED << "HHHHH" << endl;
	cout << BOLD << BLACK << "HHHHH" << endl;
	cout << BOLD << GREEN << "HHHHH" << endl;
	cout << BOLD << YELLOW << "HHHHH" << endl;
	cout << BOLD << BLUE << "HHHHH" << endl;
	cout << BOLD << MAGENTA << "HHHHH" << endl;
	cout << BOLD << CYAN << "HHHHH" << endl;
	cout << BOLD << WHITE << "HHHHH" << endl;
	cout << RESET;

	cout << endl;
	return 0;
}
