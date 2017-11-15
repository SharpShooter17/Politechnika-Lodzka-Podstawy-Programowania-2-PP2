#include <stdio.h>
#include <stdlib.h>

void zad_5()
{
	FILE * file = fopen("zadania_pliki_DATA3.txt", "r");
	if (file == nullptr) return;

	int num, count = 0, sum = 0;
	double avg;
	fscanf(file, "%d", &num);

	for (int i = 0; i < num; ++i)
	{
		int x = 0;
		fscanf(file, "%d", &x);
		sum += x;
		count++;
	}

	avg = (double)sum / (double)count;

	printf("liczba wczytanych: %d suma: %d, srednia: %f", count, sum, avg);

	system("pause");
}