#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

int w(int power, int x, ...)
{
	va_list a;
	va_start(a, x);
	double *tab = (double*)malloc(power*sizeof(double));
	double w_x = 0.0;
	int n = power;
	int i = 0;

	for (i = 0; i < power; i++)
	{
		tab[i] = va_arg(a, double);
		w_x += tab[i] * pow(x, n--);
	}

	free(tab);
	va_end(a);
	return w_x;
}

int main()
{
	printf("Wielomian w punkcie %d ma wartosc: %d\n", 3, w(5, 3, 4.0, 1.0, 2.0, 5.0, 7.0));

	system("pause");
	return 0;
}
