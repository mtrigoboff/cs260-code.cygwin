// now we can use operator[] on lefthand side too, but it doesn't do anything

#include <iostream>
#include <iomanip>
#include "filearray.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	FileArray	fileArray{"fa.bin"};
	char		ch;

	if (! fileArray.getStatus()) {
		cout << "couldn't open file" << endl;
		return -1;
		}

	cout << "file array 2" << endl << endl;

	// set values in file, demonstrate 'random access'
	for (int i = 5, ch = 'f'; i >= 1; i -= 2, ch -= 2)
		fileArray.setValue(i, ch);
	for (int i = 0, ch = 'a'; i <= 6; i += 2, ch += 2)
		fileArray.setValue(i, ch);

	cout << "print contents of file array" << endl;
	cout << "with for loop:  " << fileArray << endl;
	cout << "using eof:      " << &fileArray << endl << endl;

	// get item past end of the file
	ch = fileArray[1000];
	cout << "item 1000 contains 0x" << hex << setw(2) << setfill('0') << (int) ch << endl << endl;

	// demonstrate getting and setting item 6
	ch = fileArray[6];
	cout << "item 6 contains " << ch << endl;
	fileArray.setValue(6, '!');
	cout << "item 6 set to   !" << endl;
	ch = fileArray[6];
	cout << "item 6 contains " << ch << endl;
	cout << fileArray << endl << endl;;

	// this didn't compile in filearray1. Now it compiles, but it doesn't do anything!
	cout << "attempting to set item 0 to '@'" << endl;
	fileArray[0] = '@';
	cout << fileArray << endl << endl;

	// last use is a set (not a get), to test whether
	// the value will be written into the file
	fileArray.setValue(1, '$');
	cout << "item 1 set to   $ (at end)" << endl << endl;

	return 0;
}
