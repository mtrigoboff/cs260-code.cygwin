#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <ostream>

using namespace std;

static const int	SIZE{5};

class Queue
{
public:
	Queue(int size);
	~Queue(void);
	bool enqueue(char ch);
	bool dequeue(char& ch);
	bool isEmpty(void);
	bool isFull(void);

	class Iterator
	{
	public:
		bool getNext(char& ch);
	
	private:
		Iterator(Queue& queue);
			// constructor is private so that you can only get an instance
			// of Iterator by calling getIterator(), defined below

		Queue&	queue;
		int		next;

		friend class Queue;
	};

	friend ostream& operator<<(ostream& out, Queue& queue);

	Iterator *getIterator(void) { return new Iterator(*this); }

private:
	int		size;
	char	*queueArray;
	int		last;
};

ostream& operator<<(ostream& out, Queue *queue);

#endif
