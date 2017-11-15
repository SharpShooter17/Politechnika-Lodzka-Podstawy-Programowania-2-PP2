#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Dana jest nastêpuj¹ca tablica:
uint8_t bmp[] = {
		0xfc, 0x00, 0x00, 0x10, 0x30,
		0xb4, 0x00, 0x00, 0x30, 0x78,
		0x30, 0x78, 0x7c, 0x7c, 0x78,
		0x30, 0xcc, 0xc0, 0x30, 0x30,
		0x30, 0xfc, 0x78, 0x30, 0x30,
		0x30, 0xc0, 0x0c, 0x34, 0x00,
		0x78, 0x78, 0xf8, 0x18, 0x30,
		0x00, 0x00, 0x00, 0x00, 0x00
		};
Jest to obraz monochromatyczny (dwukolorowy), zapisany wiersz po wierszu. Liczba wierszy wynosi 8, liczba kolumn 40. 
Zak³adaj¹c, ¿e jeden piksel (punkt obrazu) zakodowany jest na jednym bicie, liczba bajtów w wierszu wynosi 5 (40 kolumn / 8 bitów).
1.	Wyœwietl obraz w konsoli zak³adaj¹c, ze bit ustawiony to '#' a bit wyzerowany to ' '. Pamiêtaj o znaku nowej linii '\n' na koñcu wyœwietlanego wiersz. 
Co przedstawia obraz?
2.	Wygenerowany obraz zapisz do pliku tekstowe plik18a.txt w takiej formie, jak widzisz na ekranie.


*/

union uint8_t
{
	unsigned char b;
	struct 
	{
		unsigned char b8 : 1;
		unsigned char b7 : 1;
		unsigned char b6 : 1;
		unsigned char b5 : 1;
		unsigned char b4 : 1;
		unsigned char b3 : 1;
		unsigned char b2 : 1;
		unsigned char b1 : 1;
	};
};

uint8_t bmp[] = {
	0xfc, 0x00, 0x00, 0x10, 0x30,
	0xb4, 0x00, 0x00, 0x30, 0x78,
	0x30, 0x78, 0x7c, 0x7c, 0x78,
	0x30, 0xcc, 0xc0, 0x30, 0x30,
	0x30, 0xfc, 0x78, 0x30, 0x30,
	0x30, 0xc0, 0x0c, 0x34, 0x00,
	0x78, 0x78, 0xf8, 0x18, 0x30,
	0x00, 0x00, 0x00, 0x00, 0x00
};

void zapisz()
{
	FILE * file = fopen("obraz.txt", "w");
	if (file == nullptr) return;

	for (int j = 0; j < 5*8; j++)
	{
		uint8_t x = bmp[j];

		if (x.b1) fprintf(file, "#");
		else fprintf(file, " ");
		if (x.b2) fprintf(file, "#");
		else fprintf(file, " ");
		if (x.b3) fprintf(file, "#");
		else fprintf(file, " ");
		if (x.b4) fprintf(file, "#");
		else fprintf(file, " ");
		if (x.b5) fprintf(file, "#");
		else fprintf(file, " ");
		if (x.b6) fprintf(file, "#");
		else fprintf(file, " ");
		if (x.b7) fprintf(file, "#");
		else fprintf(file, " ");
		if (x.b8) fprintf(file, "#");
		else fprintf(file, " ");

		if ( (j != 0) && (((j+1) % 5) == 0)) fprintf(file, "\n");
	}

	fclose(file);
}

int main()
{
	for (int j = 0; j < 5*8; j++)
	{
		uint8_t x = bmp[j];

		if (x.b1) printf("#");
		else printf(" ");
		if (x.b2) printf("#");
		else printf(" ");
		if (x.b3) printf("#");
		else printf(" ");
		if (x.b4) printf("#");
		else printf(" ");
		if (x.b5) printf("#");
		else printf(" ");
		if (x.b6) printf("#");
		else printf(" ");
		if (x.b7) printf("#");
		else printf(" ");
		if (x.b8) printf("#");
		else printf(" ");

		if ( (j != 0) && (((j+1) % 5) == 0)) printf("\n");
	}
	printf("\n");

	zapisz();

	system("pause");
	return 0;
}
