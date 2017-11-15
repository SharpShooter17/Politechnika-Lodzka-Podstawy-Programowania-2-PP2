#include <stdio.h>
#include <stdlib.h>

double add(double * begin, double * end)
{
	return (begin == end-1) ? *begin : *begin + add(begin + 1, end);
}

double sub(double * begin, double * end)
{
	return *begin - add(begin + 1, end);
}

double mul(double * begin, double * end)
{
	return (begin == end - 1) ? *begin : *begin * mul(begin + 1, end);
}

double div(double *begin, double * end)
{
	return *begin / mul(begin + 1, end);
}

int main()
{
	double tab[5] = { 1, 2, 4, 5, 6 };

	printf("suma: %f\n", add(tab, tab + 5));
	printf("odejmowanie: %f\n", sub(tab, tab + 5));
	printf("mnozenie: %f\n", mul(tab, tab + 5));
	printf("dzielenie: %f\n", div(tab, tab + 5));

	system("pause");
	return 0;
}