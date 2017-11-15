#include <stdio.h>
#include <stdlib.h>

void iter(double it)
{
	printf("%f ", it);
}

void FOR(double start, double step, double end, void (*func)(double) )
{
	int i = 0;
	while ((start + i*step) <= end)
		func(start + i++*step);
}

int main()
{
	FOR(0, 10, 40, iter);
	system("pause");
	return 0;
}