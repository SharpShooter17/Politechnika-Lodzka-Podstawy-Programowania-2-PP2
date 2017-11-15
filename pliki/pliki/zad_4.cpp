#include <stdio.h>
#include <stdlib.h>

void zad_4()
{
	FILE * plik = fopen("zad_1.txt", "r");

	if (plik == nullptr) return;

	while (!feof(plik))
	{
		int j;
		fscanf(plik, "%d", &j);
		printf("%d \n", j);
	}

	fclose(plik);
	system("pause");
}