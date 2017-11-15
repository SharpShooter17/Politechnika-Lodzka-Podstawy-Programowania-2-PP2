#include <stdio.h>

extern const char* t1;

void txt1()
{
	
	const char * p = t1;

	while (*p != '\0') 
	{
		putchar(*p);
		p++;
	}
}