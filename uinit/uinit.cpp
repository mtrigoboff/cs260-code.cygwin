#pragma GCC diagnostic ignored "-Wnarrowing"

struct UInit
{
	UInit(double d) :
		f{d}
	{
	}

	float	f;
};

int main()
{
	UInit	ui{3.14};

	return 0;
}
