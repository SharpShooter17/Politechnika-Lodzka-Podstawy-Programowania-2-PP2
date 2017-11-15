#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <varargs.h>


void func(int dummy, ...)
{
	va_list ap;
	va_start(ap, dummy);
	va_arg(ap, int);

	for (int i = 0; i < 3; i++)
		printf("%d\n", va_arg(ap, int));

	va_end(ap);
}

int main()
{
	func(1, 2, 3, 4);
	func(1);

	system("pause");
	return 0;
}