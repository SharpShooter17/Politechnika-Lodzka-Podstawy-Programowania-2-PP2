/*1.	Utw�rz struktur� kontakt_t zawierajac� pola typu imie, nazwisko, nr_telefonu, rok_urodzenia. Zaproponuj typy danych w tej strukturze. Utw�rz dwie zmienne tej struktury i wype�nij je dowolnymi danymi.
2.	Utworz struktur� data_t, zawieraja�c� dzien, miesiac i rok. Zast�p rok_urodzenia w strukturze kontakt_t polem data_t o nazwie data_urodzenia. Nowe struktury uzupe�nij danymi.
3.	Napisz program wy�wietlaj�cy zawarto�� struktury kontakt_t na ekranie w formie:
Imi�: Jan
Nazwisko: Kowalski
Data urodzenia: 26 wrzesie� 1980
4.	Nazw� miesi�ca w dacie urodzenia wy�wietl, wykorzystuj�c tablic� wska�nik�w na napisy (nazwy miesi�ca).
5.	Rozbuduj kontakt_t pole typu wyliczeniowego plec_t. Zaproponuj nazwy oraz odpowiadaj�ce im warto�ci numeryczne.  
Uzupe�nij zawarto�ci tych p�l dowolnymi danymi. Wy�wietlaj�c informacj� o p�ci, wykorzystaj operator potr�jny (a?b:c)

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