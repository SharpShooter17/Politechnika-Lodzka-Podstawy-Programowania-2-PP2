#include <stdio.h>
#include <stdlib.h>

void zad_5a()
{
	FILE * file = fopen("zadania_pliki_DATA1.txt", "r");
	if (file == nullptr) return;

	int num, count = 0;
	long long int sum = 0;
	long double avg;
	fscanf(file, "%d", &num);

	for (int i = 0; i < num; ++i)
	{
		long long int x = 0;
		fscanf(file, "%lld", &x);
		sum += x;
		count++;
	}

	avg = (long double)sum / (long double)count;

	printf("liczba wczytanych: %d suma: %d, srednia: %Lf", count, sum, avg);

	system("pause");
}