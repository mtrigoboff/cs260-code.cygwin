#include <iostream>
#include <iomanip>
#include "temperature.h"

using namespace std;

Temperature::Temperature(double fahrenheit) :
	fahrenheit{fahrenheit},
	celsius{fahrenheitToCelsius(fahrenheit)}
{
	cout << "Temperature constructor("
		 << fixed << setprecision(1)
		 << fahrenheit << degreeChar << " F"
		 << ")" << endl;
}

Temperature::Temperature(void) :
	// initialize to impossible values
	fahrenheit{-1000.0},
	celsius{-1000.0}
{
	cout << "Temperature default constructor" << endl;
}

void Temperature::set(double fahrenheit)
{
	this->fahrenheit = fahrenheit;
	celsius = fahrenheitToCelsius(fahrenheit);
	cout << "Temperature::set("
		 << fixed << setprecision(1) << fahrenheit
		 << Temperature::degreeChar << " F"
		 << ")" << endl;
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
	out << "Temperature[";
	if (temperature.fahrenheit == -1000.0 && temperature.celsius == -1000.0)
		out << "--default--";
	else
		out << fixed << setprecision(1)
			<< temperature.fahrenheit << Temperature::degreeChar << " F, "
			<< temperature.celsius << Temperature::degreeChar << " C";
	out << "]";

	return out;
}
