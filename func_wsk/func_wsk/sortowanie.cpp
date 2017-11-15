#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

bool if_smaller(const int const * x1, const int const * x2)
{
	return *x1 < *x2;
}

bool if_higher(const int const * x1, const int const * x2)
{
	return *x1 > *x2;
}

void swap(int * s1, int * s2)
{
	int t = *s1;
	*s1 = *s2;
	*s2 = t;
	return;
}

void buble_sort(int tab[], int n, bool (*cmp)(const int const*, const int const*))
{
	for (int i = 0; i<n; i++)
		for (int j = 1; j<n - i; j++)
			if( cmp(&tab[j - 1], &tab[j]))
				swap(&tab[j - 1], &tab[j]);
}

void show(int *buf, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", buf[i]);
		if (((i + 1) % 10) == 0)
			printf("\n");
	}
	printf("\n\n\n");
}

int main()
{
	int buffer[100];// = (int*)alloca(100);

	FILE * file = fopen("data.txt", "r");
	if (file == nullptr) return -1;

	for (int i = 0; i < 100; i++)
	{
		fscanf(file, "%d", &buffer[i]);
	}

	fclose(file);

	show(buffer, 100);

	buble_sort(buffer, 100, if_smaller);

	show(buffer, 100);

	system("pause");
	return 0;
}