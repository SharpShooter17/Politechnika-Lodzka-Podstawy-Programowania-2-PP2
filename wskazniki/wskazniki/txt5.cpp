#include <string.h>
#include <stdio.h>

extern const char* t1;

void txt5()
{
	int n = strlen(t1);

	while (n-- != 0)
	{
		putchar(*(t1 + n));
	}
}