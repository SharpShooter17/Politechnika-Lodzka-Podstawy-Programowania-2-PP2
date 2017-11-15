#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Dla podanej przez u¿ytkownika liczby ca³kowitej, wyœwietl jej reprezentacjê w postaci:
•	1 liczby 32 bitowej
•	2 liczb 16 bitowych
•	4 liczb 8 bitowych
•	8 liczb 4 bitowych
•	16 liczb 2 bitowych
•	32 liczb jednobitowych
PodpowiedŸ: stosuj unie, struktury i pola bitowe.*/

union liczba_t
{
	int liczba;
	short word;
	unsigned char c;
	struct {
		unsigned char b8 : 1;
		unsigned char b7 : 1;
		unsigned char b6 : 1;
		unsigned char b5 : 1;
		unsigned char b4 : 1;
		unsigned char b3 : 1;
		unsigned char b2 : 1;
		unsigned char b1 : 1;
	} bajt;
};

int main()
{
	liczba_t x;

	printf("Podaj liczbe: ");
	scanf("%d", &x.liczba);
	printf("Liczba 4 bajtowa %d\n", x.liczba);
	printf("Dwie liczby 2 bajtowe: %d, %d\n", x.word, *(&x.word + 1));
	printf("Cztery liczby jedno bajtowe: %d, %d, %d, %d\n", x.c, *(&x.c + 1), *(&x.c + 2), *(&x.c + 3));
	
	printf("Osiem liczb 4 bitowych: ");

	for (int i = 0; i < 4; ++i)
	{
		int suma = 0;
		suma += pow(2, 3) * (&x.bajt + i)->b1;
		suma += pow(2, 2) * (&x.bajt + i)->b2;
		suma += pow(2, 1) * (&x.bajt + i)->b3;
		suma += pow(2, 0) * (&x.bajt + i)->b4;

		printf("%d, ", suma);

		suma = 0;

		suma += pow(2, 3) * (&x.bajt + i)->b5;
		suma += pow(2, 2) * (&x.bajt + i)->b6;
		suma += pow(2, 1) * (&x.bajt + i)->b7;
		suma += pow(2, 0) * (&x.bajt + i)->b8;
		
		printf("%d, ", suma);
	}
	
	printf("\nSzesnascie liczb dwu bitowych: ");

	for (int i = 0; i < 4; ++i)
	{
		int suma = 0;
		suma += pow(2, 1) * (&x.bajt + i)->b1;
		suma += pow(2, 0) * (&x.bajt + i)->b2;

		printf("%d, ", suma);
		suma = 0;

		suma += pow(2, 1) * (&x.bajt + i)->b3;
		suma += pow(2, 0) * (&x.bajt + i)->b4;

		printf("%d, ", suma);
		suma = 0;

		suma += pow(2, 1) * (&x.bajt + i)->b5;
		suma += pow(2, 0) * (&x.bajt + i)->b6;

		printf("%d, ", suma);
		suma = 0;

		suma += pow(2, 1) * (&x.bajt + i)->b7;
		suma += pow(2, 0) * (&x.bajt + i)->b8;

		printf("%d, ", suma);
	}

	printf("\nTrzydziesci dwie liczby 1 bitowe: ");
	for (int i = 0; i < 4; ++i)
	{
		printf("%d, %d, %d, %d, %d, %d, %d, %d, ", 
			(&x.bajt + i)->b1, (&x.bajt + i)->b2, (&x.bajt + i)->b3, (&x.bajt + i)->b4, 
			(&x.bajt + i)->b5, (&x.bajt + i)->b6, (&x.bajt + i)->b7, (&x.bajt + i)->b8);
	}
	
	printf("\n");

	system("pause");
	return 0;
}