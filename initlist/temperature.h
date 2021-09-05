#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#include <ostream>

class Temperature
{
public:
	Temperature(double fahrenheit);
	Temperature(void);

	void set(double fahrenheit);

	static double celsiusToFahrenheit(double celsius);
	static double fahrenheitToCelsius(double fahrenheit);

	friend std::ostream& operator<<(std::ostream& out, Temperature& temperature);

private:
	double	fahrenheit;
	double	celsius;

	static const unsigned char		degreeChar{0xB0};
};

#endif // _TEMPERATURE_H_
