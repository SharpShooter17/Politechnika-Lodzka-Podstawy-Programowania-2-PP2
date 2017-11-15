#include <stdio.h>

void txt4()
{
	const char* tekst = "Ala ma kota";

	const char *p = tekst;
	int i = 0;
	while (*(p + i) != ' ')
	{
		putchar(*(p + i));
		i++;
	}
}