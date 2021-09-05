#include <cstdlib>
#include <ctime>

int randomArray(char*& ar, int minSize, int maxSize)
{
	bool	chSeen[26]{false};	// init all elements to false
	int		chIndex;

	// random seed
	srand(time(nullptr));

	// generate array size between minSize and maxSize
	int		size = minSize + (rand() % (maxSize - minSize + 1));

	ar = new char[size];

	// generate random capital letters
	for (int i{0}; i < size; i++) {

		// disallow duplicate characters
		do {
			chIndex = rand() % 26;
		} while (chSeen[chIndex]);
		chSeen[chIndex] = true;

		ar[i] = 'A' + chIndex;
		}

	return size;
}
