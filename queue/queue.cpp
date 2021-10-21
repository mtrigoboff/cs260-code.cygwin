#include "queue.h"

Queue::Queue(int size) :
	size{size},
	queueArray{new char[size]},
	last{-1}						// queue is empty when 'last' index points before start of array
{
}

Queue::~Queue(void)
{
	delete[] queueArray;
}

bool Queue::enqueue(char ch)
{
	if (isFull())
		return false;
	else {
		queueArray[++last] = ch;
		return true;
		}
}

bool Queue::dequeue(char& ch)
{
	if (isEmpty())
		return false;
	else {
		ch = queueArray[0];
		for (int i = 1; i <= last; i++)				// slide rest of array down by one
			queueArray[i - 1] = queueArray[i];
		last--;
		return true;
		}
}

bool Queue::isEmpty(void)
{
	return last == -1;
}

bool Queue::isFull(void)
{
	return last == size - 1;
}

ostream& operator<<(ostream& out, Queue& queue)
{
	out << "Queue& [";
	if (queue.isEmpty())
		out << "empty";
	else
		for (int i = 0; i <= queue.last; i++)
			out << queue.queueArray[i] << (i < queue.last ? ", " : "");
	out << ']' << endl;
	return out;
}

ostream& operator<<(ostream& out, Queue* queue)
{
	auto	iterator{queue->getIterator()};
	bool	first{true};
	char	ch;

	out << "Queue* <";
	while (iterator->getNext(ch))
		out << (first ? first = false, "" : ", ") << ch;
	if (first)
		out << "empty";
	out << '>' << endl;
	delete iterator;
	return out;
}

bool Queue::Iterator::getNext(char& ch)
{
	if (next <= queue.last) {
		ch = queue.queueArray[next++];
		return true;
		}
	else
		return false;
}

Queue::Iterator::Iterator(Queue& queue) :
	queue{queue},
	next{0}
{
}
