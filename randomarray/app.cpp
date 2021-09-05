#include <iostream>

using namespace std;

int randomArray(char*& ar, int minSize, int maxSize);

int main()
{
	char*	ar;
	int		size{randomArray(ar, 8, 15)};
	bool	first{true};

	cout << size << " items: ";
	for (int i{0}; i < size; i++) {
		if (first)
			first = false;
		else
			cout << ", ";
		cout << ar[i];
		}
	cout << endl;

	delete[] ar;
	return 0;
}
