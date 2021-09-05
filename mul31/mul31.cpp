int main(int argc, char** argv)
{
	unsigned int		n{5};

	for (int i{0}; i < 1000000000; i++)
		n *= 31;

	return 0;
}
