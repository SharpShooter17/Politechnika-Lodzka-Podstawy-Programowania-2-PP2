#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <varargs.h>


int suma_int(int count, ...)
{
	int suma = 0;
	va_list ap;
	va_start(ap, count);
	va_arg(ap, int);

	for (int i = 0; i < count; i++)
		suma += va_arg(ap, int);

	va_end(ap);
	return suma;
}

float suma_float(int count, ...)
{
	double suma = 0.0;
	va_list ap;
	va_start(ap, count);
	va_arg(ap, int);

	for (int i = 0; i < count; i++)
		suma += va_arg(ap, double);

	va_end(ap);
	return (float)suma;
}

double suma_double(int count, ...)
{
	double suma = 0.0;
	va_list ap;
	va_start(ap, count);
	va_arg(ap, int);

	for (int i = 0; i < count; i++)
		suma += va_arg(ap, double);

	va_end(ap);
	return suma;
}

int main()
{
	int x = suma_int(3, 1, 1, 1);
	float y = suma_float(3, 1.0f, 2.0f, 1.0f);
	double z = suma_double(3, 1.0, 2.0, 7.0);

	printf("%d, %f, %f\n", x, y, z);

	system("pause");
	return 0;
}