#include <iostream>

int size_of_table(int *p);

void zad_7()
{
	int t[] = { 16909060, 84281096, 151653132, -1 };

	std::cout << "rozmiar tablicy to: " << size_of_table(t);
}

int size_of_table(int *p)
{
	int n{ 0 };
	while (*(p + n) != -1) n++;
	return n;
}