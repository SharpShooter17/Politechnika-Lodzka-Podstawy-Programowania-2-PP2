/*1.	Utwórz strukturê kontakt_t zawierajac¹ pola typu imie, nazwisko, nr_telefonu, rok_urodzenia. Zaproponuj typy danych w tej strukturze. Utwórz dwie zmienne tej struktury i wype³nij je dowolnymi danymi.
2.	Utworz strukturê data_t, zawieraja¹c¹ dzien, miesiac i rok. Zast¹p rok_urodzenia w strukturze kontakt_t polem data_t o nazwie data_urodzenia. Nowe struktury uzupe³nij danymi.
3.	Napisz program wyœwietlaj¹cy zawartoœæ struktury kontakt_t na ekranie w formie:
Imiê: Jan
Nazwisko: Kowalski
Data urodzenia: 26 wrzesieñ 1980
4.	Nazwê miesi¹ca w dacie urodzenia wyœwietl, wykorzystuj¹c tablicê wskaŸników na napisy (nazwy miesi¹ca).
5.	Rozbuduj kontakt_t pole typu wyliczeniowego plec_t. Zaproponuj nazwy oraz odpowiadaj¹ce im wartoœci numeryczne.  
Uzupe³nij zawartoœci tych pól dowolnymi danymi. Wyœwietlaj¹c informacjê o p³ci, wykorzystaj operator potrójny (a?b:c)

*/

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
	char * imie;
	char * nazwisko;
	data_t urodziny;
	int telefon;
	plec_t plec;
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

void wyswietl(kontakt_t * p)
{
	printf("Imie: %s\nNazwisko: %s\nData urodzenia: %d %s %d\nNumer telefonu: %d\nPlec: %s\n",
		p->imie, p->nazwisko, p->urodziny.dzien, miesiace[p->urodziny.miesiac - 1], 
		p->urodziny.rok, p->telefon, p->plec == K ? "Kobieta" : "Mezczyzna");
}

int main()
{
	kontakt_t Basia;
	kontakt_t Tomek;

	wypelnij(&Basia, "Basia", "Morawska", 123123123, 23, 3, 2010, K);
	wypelnij(&Tomek, "Tomek", "Kowalski", 890890890, 26, 4, 1990, M);
	
	wyswietl(&Basia);
	wyswietl(&Tomek);

	wyczysc(&Tomek);
	wyczysc(&Basia);

	system("pause");
}