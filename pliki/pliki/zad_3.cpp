#include <stdio.h>
#include <stdlib.h>

void zad_3()
{
	FILE * plik = fopen("zad_3.txt", "w");
	if (plik == nullptr) return;

	for (int i = 0; i < 145; ++i)
	{
		if (((i % 10) == 0) && i != 0)
			fprintf(plik, "\n");

		fprintf(plik, "%d ", rand() % 1000);
	}

	fclose(plik);
}