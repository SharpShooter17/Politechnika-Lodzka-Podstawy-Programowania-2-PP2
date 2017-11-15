
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <varargs.h>


int suma(int count, ...)
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

int iloczyn(int count, ...)
{
	int iloczyn = 1;
	va_list ap;
	va_start(ap, count);
	va_arg(ap, int);

	for (int i = 0; i < count; i++)
		iloczyn *= va_arg(ap, int);

	va_end(ap);
	return iloczyn;
}

int main()
{
	int x = suma(3, 1, 1, 1);
	int y = iloczyn(3, 1, 2, 3);

	printf("%d, %d\n", x, y);

	system("pause");
	return 0;
}