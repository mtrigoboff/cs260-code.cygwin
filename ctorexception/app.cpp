#include <iostream>

using namespace std;

class ThrowException
{
public:
	ThrowException(int x)
		try : // handle exceptions for entire initialization list
			data{x > 1 ? throw 5, -1 : 0}
	// body of constructor
	{
		cout << "constructor called" << endl;
	}
	// catch phrase for initialization list
	catch (int ex)
	{
		// right here we could do any cleanup that was necessary
		// (none is necessary for this particular class)
		cout << "constructor caught and rethrew " << ex << endl;
		throw ex;						// rethrow exception
	}

	~ThrowException(void) noexcept(false)
	{
		cout << "destructor called" << endl;
	}

private:
	int		data;
};

static void fn()
{
	throw 3;
}

int main(int argc, char** argv)
{
	ThrowException	*te{nullptr};

	try {
		te = new ThrowException(argc);

		fn();
	} catch(int ex) {
		cout << "main caught " << ex << endl;
	}

	cout << "deleting te(" << hex << te << ")" << endl;
	delete te;
	return 0;
}
