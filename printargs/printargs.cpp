#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
	if (strcmp(argv[0], "pa") != 0) {			// argv[0] not equal to "pa"
		
		// detailed output

		cout << "there are " << argc << " args" << endl;
		for (int i = 0; i < argc; i++)
			cout << i << ": \"" << argv[i] << "\"" << endl;
		}

	else {										// argv[0] equal to "pa"
		
		// short output
		
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
