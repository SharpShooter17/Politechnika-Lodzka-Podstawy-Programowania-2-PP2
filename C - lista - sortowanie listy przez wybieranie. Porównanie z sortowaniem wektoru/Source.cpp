#include <stdio.h>
#include <time.h>

#include "lista.h"

#define SIZE 50000			//Liczba elementow w tablicy

void sortuj_liste_selekcje(list_t * first)
{
	int n = size(first);

	for (int i = 0; i < n-1; i++)
	{
		type max_index = i;

		list_t * it = get_element(first, i + 1);
		list_t * it_max = get_element(first, i);

		for (int j = i + 1; j < n; j++)
		{
			if (it->value > it_max->value) {
				max_index = j;
				it_max = it;
			}
			it = get_element(it, 1);
		}

		list_t * it1 = get_element(first, i);

		type tmp = it1->value;
		it1->value = it_max->value;
		it_max->value = tmp;
	}

}

void sortuje_wektor_selekcje(type * tab, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int max_index = i;

		for (int j = i + 1; j < n; j++)
		{
			if (tab[j] > tab[max_index])
				max_index = j;
		}
		type tmp = tab[max_index];
		tab[max_index] = tab[i];
		tab[i] = tmp;
	}
}

bool sorted(type * tab)
{
	for (int i = 0; i < SIZE-1; i++)
	{
		if (tab[i] < tab[i + 1]) return false;
	}
	return true;
}

int main(void)
{
	list_t * first = new_element();

	first->value = 1;

	resize(first, SIZE);

	type tab[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = rand();
	}

	clock_t start = clock();

	sortuje_wektor_selekcje(tab, SIZE);
	printf("Czas sortowania wektoru przez selekcje: %f\n", (clock() - start) / 1000.0);
	printf("Sorted: %d\n", sorted(tab));

	start = clock();
	sortuj_liste_selekcje(first);
	printf("Czas sortowania listy przez selekcje: %f\n", (clock() - start) / 1000.0);
	printf("Sorted: %d\n", sorted(first));

	remove(first);

	system("pause");
	return 0;
}