/**
 * Program po³owi zadany przedzia³ w celu szukania pierwiastków podanej funkcji
 **/

#include <iostream>
#include <vector>
#include <cmath>

const double epsilon = 0.00001;

double liczFx(std::vector<int> wielomian, double x)
{
	double wynik = 0.0;

	for (int i = 0; i < wielomian.size(); i++)
	{
		wynik += wielomian[i] * pow(x, wielomian.size() - 1 - i);
	}

	return wynik;
}

double polowienie(double a, double b, std::vector<int> wielomian)
{
	while (fabs(b - a) > epsilon)
	{
		if (liczFx(wielomian, a) == 0.0)
		{
			return a;
		}
		else if (liczFx(wielomian, b) == 0.0)
		{
			return b;
		}

		double srodek = (b + a) / 2.0;

		if (liczFx(wielomian, srodek) == 0.0)
		{
			return srodek;
		}

		double fa = liczFx(wielomian, a);
		double fs = liczFx(wielomian, srodek);

		if ( fa * fs < epsilon)
		{
			b = srodek;
		}
		else
		{
			a = srodek;
		}
	}

	return (b + a) / 2.0;
}

int main()
{
	std::vector<int> wielomian;
	int stopien_rownania;
	std::cout << "Podaj stopien rownania: ";
	std::cin >> stopien_rownania;

	for (int i = 0; i < stopien_rownania + 1; i++)
	{
		std::cout << "Podaj x" << stopien_rownania - i << " : ";
		int x;
		std::cin >> x;
		wielomian.push_back(x);
	}

	std::cout << std::endl << "Rownanie: F(x) = ";

	for (int i = 0; i < wielomian.size(); i++)
	{
		std::cout << wielomian[i] << "x^" << stopien_rownania - i << " + ";
	}

	double a, b;

	std::cout << std::endl << "Podaj przedzial [A, B]: ";
	std::cin >> a >> b;

	if (liczFx(wielomian, a) * liczFx(wielomian, b) > 0)
	{
		std::cout << "Funkcja nie spelnia zalorzen";
	}
	else
	{
		std::cout << "Wynk to: " << polowienie(a, b, wielomian);
	}

	return 0;
}