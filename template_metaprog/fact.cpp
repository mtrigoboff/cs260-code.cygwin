#include <iostream>
#include <iomanip>

using namespace std;

template <int N>
struct FACT 
{
	static const int value = N * FACT<N - 1>::value;
};

template <>
struct FACT<0> 
{
	static const int value{1};
};

void print(int n, int nFact)
{
	cout << n << "! = " << setw(3) << right << nFact << endl;
}

int main()
{
	int		fact5{FACT<5>::value};
	int		fact4{FACT<4>::value};
	int		fact3{FACT<3>::value};
	int		fact2{FACT<2>::value};
	int		fact1{FACT<1>::value};
	int		fact0{FACT<0>::value};

	print(5, fact5);
	print(4, fact4);
	print(3, fact3);
	print(2, fact2);
	print(1, fact1);
	print(0, fact0);

	return 0;
}
