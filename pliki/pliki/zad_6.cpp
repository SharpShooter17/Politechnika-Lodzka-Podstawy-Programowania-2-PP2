#include <stdio.h>
#include <stdlib.h>

void zad_6()
{
	FILE * plik = fopen("zad_6.dat", "wb");

	if (plik == nullptr) return;

	float t[100];

	for (int i = 0; i < 100; i++)
	{
		t[i] = (rand() % 200) - 100;
	}

	fwrite(t, sizeof(float), 100, plik);

	fclose(plik);
}