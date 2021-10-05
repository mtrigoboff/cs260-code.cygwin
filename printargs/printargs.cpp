#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
	if (strchr(argv[0], '/'))			// running in gdb, so turn off cout
		std::cout.setstate(std::ios_base::badbit);

	if (! strstr(argv[0], "pa")) {
		// argv[0] does not contain "pa", so running in compiled file
		
		// print detailed output
		cout << "there are " << argc << " args" << endl;
		for (int i = 0; i < argc; i++)
			cout << i << ": \"" << argv[i] << "\"" << endl;
		}

	else {
		// argv[0] contains "pa", running from directory link
		
		// print short output
		bool	first = true;

		for (int i = 0; i < argc; i++) {
			if (first)
				first = false;
			else
				cout << ", ";
			cout << argv[i];
			}
		cout << endl;
		}
		
	return 0;
}
