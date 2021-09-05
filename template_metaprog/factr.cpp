#include <iostream>

using namespace std;

int fact(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fact(n - 1);
}

int main(int argc, char** argv)
{
	int		n;
	int		nFact;

	if (argc < 2) {
		cout << "need one integer arg" << endl;
		return -1;
		}

	n = atoi(argv[1]);
	nFact = fact(n);
	cout << n << "! = " << nFact << endl;

	return 0;
}
