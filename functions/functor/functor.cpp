#include <iostream>

using namespace std;

class Counter
{
public:
	Counter() : count{0} {}
	int operator()() { return ++count; }

private:
	int		count;
};

class GreaterThan
{
public:
	GreaterThan(int value) : val{value} {}
	bool operator()(int n) { return n > val; }
	int value() { return val; }

private:
	int		val;
};

void run_ct(Counter& ct)
{
	cout << "run_ct: " << ct() << endl;
}

void run_gt(GreaterThan& gt, int n)
{
	cout << "run_gt: " << n << (gt(n) ? " >  " : " <= ") << gt.value() << endl;
}

int main(int argc, char** argv)
{
	if (argc > 2)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	int		val;

	cout << "Functors!" << endl << endl;

	if (argc < 2) {
		cout << "need one integer arg" << endl << endl;
		return -1;
		}
	val = atoi(argv[1]);

	GreaterThan		gt{val};
	Counter			ct;

	for (int i = 0; i < 5; i++)
		run_ct(ct);
	cout << endl;

	for (int i = 0; i < 5; i++)
		run_gt(gt, i);
	cout << endl;

	return 0;
}
