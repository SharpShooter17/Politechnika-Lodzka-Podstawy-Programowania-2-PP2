#include <stdio.h>
#include <stdlib.h>

double wyznacz_srednia(int** tablica, int N);
void zapisz_bin(int** liczba, int N); 
void zapisz_txt(int** liczba, int N);

int main()
{
	int * liczby = (int*)malloc(sizeof(int) * 1000);
	if (liczby == nullptr) return -1;

	for (int i = 0; i < 1000; i++)
	{
		liczby[i] = (rand() % 200) - 100;
	}

	system("pause");
	return 0;
}

double wyznacz_srednia(int ** tablica, int N)
{
	double srednia = 0;

	for (int i = 0; i < N; ++i)
	{
		srednia += *tablica[i];
	}

	return srednia/N;
}

void zapisz_bin(int ** liczba, int N)
{
}

void zapisz_txt(int ** liczba, int N)
{
}
