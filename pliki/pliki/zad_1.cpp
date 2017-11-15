#include <stdio.h>

void zad_1()
{
	FILE * plik = fopen("zad_1.txt", "w");

	if (plik == nullptr) return;

	for (int i = 0; i < 100; ++i)
	{
		fprintf(plik, "%d\n", i);
	}

	fclose(plik);
}