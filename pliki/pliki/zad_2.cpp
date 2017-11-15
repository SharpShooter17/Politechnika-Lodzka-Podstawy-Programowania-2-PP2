#include <stdio.h>

void zad_2()
{
	FILE* plik = fopen("zad_2.txt", "w");

	if (plik == nullptr) return;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			fprintf(plik, "%.2d ", i * 10 + j);
		}
		fprintf(plik, "\n");
	}
}