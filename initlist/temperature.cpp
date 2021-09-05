#include <iostream>
#include <iomanip>
#include "temperature.h"

using namespace std;

Temperature::Temperature(double fahrenheit) :
	fahrenheit{fahrenheit},
	celsius{fahrenheitToCelsius(fahrenheit)}
{
	cout << "Temperature ctor(" << *this << ")" << endl;
}

Temperature::Temperature(void) :
	// initialize to impossible values
	fahrenheit{-1000.0},
	celsius{-1000.0}
{
	cout << "Temperature default ctor(" << *this << ")" << endl;
}

void Temperature::set(double fahrenheit)
{
	this->fahrenheit = fahrenheit;
	celsius = fahrenheitToCelsius(fahrenheit);
	cout << "Temperature::set(" << *this << ")" << endl;
}

double Temperature::celsiusToFahrenheit(double celsius)
{
	return 9.0 * celsius / 5.0 + 32.0;
}

double Temperature::fahrenheitToCelsius(double fahrenheit)
{
	return (fahrenheit - 32.0) * 5.0 / 9.0;
}

ostream& operator<<(ostream& out, Temperature& temperature)
{
	out << fixed << setprecision(2) << "["
		<< temperature.fahrenheit << Temperature::degreeChar << ", "
		<< temperature.celsius << Temperature::degreeChar << "]";

	return out;
}
