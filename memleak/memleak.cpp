#pragma GCC diagnostic ignored "-Wunused-variable"

// purposely leak memory to demonstrate valgrind output

int main()
{
	char*	c{new char[100]};

	return 0;
}
