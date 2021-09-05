#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned int (*HashFn)(char* str);

unsigned int hashFn1(char* str);
unsigned int hashFn2(char* str);
unsigned int hashFn3(char* str);

HashFn hashFns[] = {hashFn1, hashFn2, hashFn3};

int main(int argc, char** argv)
{
	if (argc != 4) {
		cout << "bad args" << endl;
		return -1;
		}

	char*			str		=argv[1];
	int				hashFn	=atoi(argv[2]) - 1;
	int				nTimes	=atoi(argv[3]);
	unsigned int	hashCode;

	for (int i = 0; i < nTimes; i++)
		hashCode = (*hashFns[hashFn])(str);
	
	cout << "hashFn" << hashFn + 1 << "(\"" << str << "\")"
		 << " = 0x" << setw(8) << setfill('0') << hex << hashCode << endl
		 << dec << nTimes << " repetitions" << endl;

	return 0;
}
