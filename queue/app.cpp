#include <iostream>
#include "queue.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	int		size{6};
	Queue	q{size};
	char	ch;

	cout << "Queue Demonstration: queue size is " << size << endl << endl;
	cout << q << endl;

	for (int i = 0, ch = 'a'; i < size + 1; i++, ch++) {
		cout << "enqueueing " << (char) ch << endl;
		if (q.enqueue(ch))
			cout << q << endl;
		else
			cout << "could not enqueue " << (char) ch << endl << endl;
		}

	cout << &q << endl;

	for (int i = 0; i < size + 1; i++) {
		if (q.dequeue(ch)) {
			cout << "dequeued " << ch << endl;
			cout << q << endl;
			}
		else
			cout << "could not dequeue from empty queue" << endl << endl;
		}

	cout << &q << endl;

	return 0;
}
