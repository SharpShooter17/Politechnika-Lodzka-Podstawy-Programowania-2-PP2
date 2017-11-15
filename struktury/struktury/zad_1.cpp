#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct student_t {
	char * imie;
	char * nazwisko;
	int index;
};

void wpisz_dane(student_t *rekord);
void wyswietl_dane(const student_t *rekord);
void zwolnij_dane(student_t *rekord);

void zapisz_dane_t(const char* plik, const student_t* rekord);
void wczytaj_dane_t(const char* plik, student_t* rekord);
void zapisz_dane_b(const char* plik, const student_t* rekord);
void wczytaj_dane_b(const char* plik, student_t* rekord);

void zad_1_2()
{
	student_t std;
	/*wpisz_dane(&std);

	wyswietl_dane(&std);

	zapisz_dane_b("zad_2_b.dat", &std);
	zapisz_dane_t("zad_2_b.txt", &std);

	zwolnij_dane(&std);*/

	wczytaj_dane_t("zad_2_b.txt", &std);
	wyswietl_dane(&std);

	zwolnij_dane(&std);

	system("pause");
}

void wpisz_dane(student_t *rekord)
{
	char *buf = (char*)malloc(sizeof(char)*64);

	printf("Podaj imie studenta: ");
	scanf("%s", buf);
	rekord->imie = (char*)malloc(sizeof(char) * (strlen(buf)+1));
	strcpy(rekord->imie, buf);

	printf("Podaj nazwisko studenta: ");
	scanf("%s", buf);
	rekord->nazwisko = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
	strcpy(rekord->nazwisko, buf);

	printf("Podaj index studenta: ");
	scanf("%d", &rekord->index);

	free(buf);
}

void wyswietl_dane(const student_t *rekord)
{
	printf("imie: %s\nnazwisko: %s\nindeks: %d\n\n", rekord->imie, rekord->nazwisko, rekord->index);
}

void zwolnij_dane(student_t *rekord)
{
	free(rekord->nazwisko);
	free(rekord->imie); 
}

void zapisz_dane_t(const char* plik, const student_t* rekord)
{
	FILE * file = fopen(plik, "w");
	if (file == nullptr) return;

	fprintf(file, "%s %s %d", rekord->imie, rekord->nazwisko, rekord->index);

	fclose(file);
}

void wczytaj_dane_t(const char* plik, student_t* rekord)
{
	FILE * file = fopen(plik, "r");
	if (file == nullptr) return;

	char *buf = (char*)malloc(64 * sizeof(char));

	fscanf(file, "%s", buf);
	rekord->imie = (char*)malloc((strlen(buf) + 1)*sizeof(char));
	strcpy(rekord->imie, buf);

	fscanf(file, "%s %d", buf, &rekord->index);
	rekord->nazwisko = (char*)malloc((strlen(buf) + 1)*sizeof(char));
	strcpy(rekord->nazwisko, buf);

	free(buf);

	fclose(file);
}

void zapisz_dane_b(const char* plik, const student_t* rekord)
{
	FILE * file = fopen(plik, "wb");
	if (file == nullptr) return;

	fwrite(rekord->imie, sizeof(char), strlen(rekord->imie) + 1, file);
	fwrite(rekord->nazwisko, sizeof(char), strlen(rekord->nazwisko) + 1, file);
	fwrite(&rekord->index, sizeof(int), 1, file);

	fclose(file);
}

void wczytaj_dane_b(const char* plik, student_t* rekord)
{
	FILE * file = fopen(plik, "rb");
	if (file == nullptr) return;

	char * buf = (char*)malloc(sizeof(char) * 64);

	char c = 'a';
	int it = 0;
	while (c != '\0')
	{
		fread(&c, sizeof(char), 1, file);
		buf[it] = c;
		it++;
	}

	rekord->imie = (char*)malloc((strlen(buf) + 1)*sizeof(char));
	strcpy(rekord->imie, buf);

	c = 'a';
	it = 0;
	while (c != '\0')
	{
		fread(&c, sizeof(char), 1, file);
		buf[it] = c;
		it++;
	}

	rekord->nazwisko = (char*)malloc((strlen(buf) + 1)*sizeof(char));
	strcpy(rekord->nazwisko, buf);

	fread(&rekord->index, sizeof(int), 1, file);

	free(buf);

	fclose(file);
}