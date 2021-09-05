#include <iostream>
#include <string>
#include "arraylist.h"

using namespace std;

extern void templates2(void);

// an example of a function template
template <typename TYPE>
void print(TYPE item)
{
	cout << "print: " << item << endl;
}

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	// template function
	print(38);
	print(1.414);
	print("a string");
	cout << endl;
	
	// template class

	{
	ArrayList<double>	dblArray;
	double				dVal;
	
	dblArray.add(3.14);
	dVal = dblArray[0];
	cout << dVal << endl;
	try {
		dVal = dblArray[10];
		}
	catch (ArrayList<double>::ArrayListException e) {
		cout << e << endl;
		}
	}
	
	{	
	ArrayList<int>		intArray{2};
	int					iVal;
	
	intArray.add(3);
	intArray.add(4);
	try {
		intArray.add(5);
		}
	catch (ArrayList<int>::ArrayListException e) {
		cout << e << endl;
		}
	intArray[0] = 2;
	iVal = intArray[0];
	cout << "iVal = " << iVal << endl;
	cout << "intArray contains " << intArray.size() << " elements" << endl;
	cout << endl;
	}
	
	{
	ArrayList<string>	strArray;
	string				str;
	
	strArray.add("abc");
	strArray.add("def");
	strArray.add("ghi");

	str = strArray[0];
	cout << str << endl;
	cout << endl;

	for (ArrayList<string>::iterator it = strArray.begin(); it != strArray.end(); it++)
		cout << *it << " ";
	cout << endl;

	for (auto it = strArray.begin(); it != strArray.end(); it++)
		cout << *it << " ";
	cout << endl;

	for (auto str : strArray)
		cout << str << " ";
	cout << endl;
	}
	
	cout << endl;
	return 0;
}
