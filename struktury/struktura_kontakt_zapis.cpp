#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char miesiace[12][12] = { {"Styczen"},
						{"Luty"}, 
						{"Marzec"},
						{"Kwiecien"},
						{"Maj"},
						{"Czerwiec"},
						{"Lipiec"},
						{"Sierpien"},
						{"Wrzesien"},
						{"Pazdziernik"},
						{"Listopad"},
						{"Grudzien"} };

struct data_t
{
	int dzien, miesiac, rok;
};

enum plec_t { K = 'K', M = 'M' };

struct kontakt_t {
	data_t urodziny;
	int telefon;
	plec_t plec;
	char * imie;
	char * nazwisko;
};

void wypelnij(kontakt_t * p, const char* imie, const char* nazwisko, int tel, int dzien, int miesiac, int rok, plec_t plec)
{
	p->imie = (char*)malloc(sizeof(char)*(strlen(imie) + 1));
	p->nazwisko = (char*)malloc(sizeof(char)*(strlen(nazwisko) + 1));
	strcpy(p->imie, imie);
	strcpy(p->nazwisko, nazwisko);
	p->urodziny.dzien = dzien;
	p->urodziny.miesiac = miesiac;
	p->urodziny.rok = rok;
	p->telefon = tel;
	p->plec = plec;
	return;
}

void wyczysc(kontakt_t * p)
{
	free(p->nazwisko);
	free(p->imie);
}

void zapisz_txt(kontakt_t * p)
{
	FILE * file = fopen("kontakt_text.txt", "w");
	if (file == nullptr) return;

	fprintf(file, "%s %s %d %d %d %d %d\n", p->imie, p->nazwisko, p->urodziny.dzien, p->urodziny.miesiac, p->urodziny.rok, p->telefon, p->plec);
	fclose(file);
}

void zapisz_bin(kontakt_t * p)
{
	FILE * file = fopen("kontakt_bin.bin", "wb");
	if (file == nullptr) return;
	
	fwrite(p, sizeof(int), 5, file);
	fprintf(file, "%s %s ", p->imie, p->nazwisko);

	fclose(file);
}

int main()
{
	kontakt_t Tomek;

	wypelnij(&Tomek, "Tomek", "Kowalski", 890890890, 26, 4, 1990, M);
	
	zapisz_txt(&Tomek);
	zapisz_bin(&Tomek);

	wyczysc(&Tomek);

	system("pause");
}