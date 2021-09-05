#ifndef _TRIANGULARARRAY_H_
#define _TRIANGULARARRAY_H_

class TriangularArray
{
public:
	TriangularArray(int size, bool initialValue);
	~TriangularArray();

	bool& item(int i, int j);

private:
	int		size;
	int		capacity;
	bool	*items;

	static int sum0toN(int n);
};

#endif	// _TRIANGULARARRAY_H_
