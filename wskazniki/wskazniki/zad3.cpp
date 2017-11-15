#include <cmath>
#include <iostream>

void zad_3()
{
	double t[999];

	for (int i = 0; i < 999; i++)
	{
		t[i] = std::rand();
	}

	double suma{ 0 }, srednia{ 0 };

	double *wsk = t;

	for (int i = 0; i < 999; ++i)
	{
		suma += *wsk++;
	}

	srednia = suma / 999;
}