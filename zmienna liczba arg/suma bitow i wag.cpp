#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

long long suma_bitow(int N, ...)
{
	va_list ap;
	va_start(ap, N);

	long long res = 0;
	N--;
	for ( ; N >= 0; N--)
	{
		res += (va_arg(ap, int) * pow(2, N));
	}

	va_end(ap);
	return res;
}

int main()
{	
	printf("%lld\n", suma_bitow(32, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0));
	system("pause");
	return 0;
}
