#include <malloc.h>
#include <iostream>

extern void dump(unsigned char *w, int size);

void zad_6()
{
	int t[] = { 16909060, 84281096, 151653132 };
	unsigned char *wsk = (unsigned char *)t;

	for (int i = 0; i < 3 * sizeof(int); i++)
	{
		if (*wsk >= 4 && *wsk <= 7)
		{
			std::cout << std::hex << "&" << (int)wsk << ": " << (int)*wsk << std::endl;
		}

		wsk++;
	}
}