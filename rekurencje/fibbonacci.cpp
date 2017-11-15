#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

unsigned int Fibbonacci(unsigned int n)
{
	return n <= 2 ? 1 : Fibbonacci(n - 1) + Fibbonacci(n - 2);
}

unsigned int sum_to_25_fib(unsigned int n)
{
	unsigned int res = Fibbonacci(n);
	printf("%u\n", res);

	if (n == 23) {		
		return res;
	}
	else {
		return res + sum_to_25_fib(n + 1);
	}
}

int main()
{
	printf("%d\n", sum_to_25_fib(4));

	system("pause");
	return 0;
}