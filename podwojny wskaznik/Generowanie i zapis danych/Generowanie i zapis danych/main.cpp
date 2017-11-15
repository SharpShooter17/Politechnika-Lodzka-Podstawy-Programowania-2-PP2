#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define SIZE 1000

double wyznacz_srednia(int** tablica, int N)
{
	double avg = 0.0;

	for (int i = 0; i < N; ++i)	avg += *(*(tablica + 0) + i);			//tablica[0][i]

	return avg / N;
}

void zapisz_bin(int** liczba, int N)
{
	FILE * file = fopen("zapis_bin.bin", "wb");
	if (file == nullptr) return;

	fwrite(*liczba, sizeof(int), N, file);

	fclose(file);

	free(*liczba);
	*liczba = nullptr;

	return;
}

void zapisz_txt(int** liczba, int N)
{
	FILE * file = fopen("zapis_text.txt", "w");
	if (file == nullptr) return;

	fprintf(file, "%d ", N);

	for (int i = 0; i < N; i++)
	{
		fprintf(file, "%d ", liczba[0][i]);
	}

	fclose(file);

	free(*liczba);
	*liczba = nullptr;

	return;
}

int wczytaj_bin(int **liczby)
{
	FILE * file = fopen("zapis_bin.bin", "rb");
	if (file == nullptr) return -1;

	fseek(file, 0, SEEK_END);
	
	int size = ftell(file);
	size /= sizeof(int);
	
	fseek(file, 0, SEEK_SET);

	*liczby = (int*)malloc(size * sizeof(int));
	if (*liczby == nullptr) return -2;
	fread(*liczby, sizeof(int), size, file);

	fclose(file);

	return size;
}

int main()
{
	int * tab = (int*)malloc(SIZE * sizeof(int));
	if (tab == NULL) return -1;

	for (int i = 0; i < SIZE; i++)
		tab[i] = (rand() % 200) - 100;


	printf("Srednia: %f\n", wyznacz_srednia(&tab, SIZE));

	zapisz_bin(&tab, SIZE);

	free(tab);

	system("Pause");

	return 0;
}