#include <stdio.h>
#include <stdlib.h>

void zad_7()
{
	FILE * plik = fopen("zad_6.dat", "rb");

	if (plik == nullptr) return;

	float t[100];

	fread(t, sizeof(float), 100, plik);

	for (int i = 0; i < 100; i++)
	{		
		printf("%f\n", t[i]);
	}

	fclose(plik);

	system("pause");
}