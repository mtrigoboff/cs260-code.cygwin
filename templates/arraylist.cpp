template <typename ITEM_TYPE>
ArrayList<ITEM_TYPE>::ArrayList(const int capacity) :
	array{new ITEM_TYPE[capacity]},
	capacity{capacity},
	next{0}
{
}

template <typename ITEM_TYPE>
ArrayList<ITEM_TYPE>::~ArrayList(void)
{
	delete[] array;
}

template <typename ITEM_TYPE>
int ArrayList<ITEM_TYPE>::size(void) const
{
	return next;
}

template <typename ITEM_TYPE>
bool ArrayList<ITEM_TYPE>::add(const ITEM_TYPE& item)
{
	if (next >= capacity)						// array full
		throw ArrayListException("array full");
	array[next++] = item;
	return true;
}

template <typename ITEM_TYPE>
ITEM_TYPE& ArrayList<ITEM_TYPE>::operator[] (const int index) const
{
	if (index >= 0 && index < next) {			// index in range?
		return array[index];					// return value
		}
	else
		throw ArrayListException("index [" + std::to_string(index) + "] out of bounds");
}
