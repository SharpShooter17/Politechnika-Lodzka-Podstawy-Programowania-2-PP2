#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdarg.h>
#include <Windows.h>

#define DEFAULT_COLOR FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN
#define RED_COLOR FOREGROUND_RED
#define BLUE_COLOR FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN
#define GREEN_COLOR FOREGROUND_GREEN | FOREGROUND_INTENSITY

struct kontakt_t {
	char * imie;
	char * nazwisko;
	char * email;
	int rok, dzien, miesiac;	//data urodzenia
	int telefon;
};

enum {up = 72, down = 80, enter = '\r'};

void error(const char* erro);
void info(const char* info);

kontakt_t * wczytaj_baze(int * size);
void zapisz_baze(const kontakt_t *baza, const int size);
void zwolnij_pamiec(kontakt_t *& kontakty, int size);
void wyswietl_menu(const kontakt_t *rekord, bool pelen = false);
void rysuj_ramke(bool pelen = false, int x = 16, int y = 33);
void usun_rekord(kontakt_t *& baza, int *Aktualny, int *size);
void edytuj_rekord(kontakt_t & rekord);
void dodaj_rekord(kontakt_t *& baza, int *Aktualny, int *size);
void cxyPrint(WORD Color, short x, short y, const char * format, ...);

void zad_3()
{
	int Aktualny_rekord{ 0 };
	int size{ 0 };
	bool done = false;
	kontakt_t * kontakty = wczytaj_baze(&size);
	int opcja;
	bool pelen_rekord = false;

	while (!done)
	{
		if (Aktualny_rekord != -1) wyswietl_menu((kontakty + Aktualny_rekord), pelen_rekord);
		else  wyswietl_menu(nullptr, pelen_rekord);
		printf("Twoj wybor: ");
		while ((scanf("%d", &opcja) == 0)) while (getchar() != '\n');
		while (getchar() != '\n');

		system("cls");

		switch (opcja)
		{
		case 1:
			if (Aktualny_rekord == -1) break;
			if (Aktualny_rekord < (size - 1)) Aktualny_rekord++;
			else Aktualny_rekord = 0;
			break;
		case 2:
			if (Aktualny_rekord == -1) break;
			if (Aktualny_rekord == 0) Aktualny_rekord = size - 1;
			else Aktualny_rekord--;
			break;
		case 3:
			pelen_rekord = !pelen_rekord;
			break;
		case 4:
			if (Aktualny_rekord == -1)
			{ 
				info("Brak rekordow do usuniecia - baza jest pusta."); 
				break;
			}
			usun_rekord(kontakty, &Aktualny_rekord, &size);
			break;
		case 5:
			if (Aktualny_rekord == -1) break;
			edytuj_rekord( *(kontakty + Aktualny_rekord) );
			break;
		case 6:
			dodaj_rekord(kontakty, &Aktualny_rekord, &size);
			break;
		case -1:
			done = true;
			break;
		case 0:
			zapisz_baze(kontakty, size);
			done = true;
			break;
		default:
			error("Brak komendy.");
			break;
		}
	}
	zwolnij_pamiec(kontakty, size);
}

bool isdotdash(const char c)
{
	switch (c)
	{
	case '.':
	case '-':
		return true;
	}
	return false;
}

bool email_valid(const char * address)
{
  int count = 0;
  const char *c, *domain;
  static char *rfc822_specials = "()<>@,;:\\\"[]";

  c = address;

  if ( ! isalpha ( *c ))
    return false;

  for ( c = address + 1;  *c && *c != '@';  c++ ) 
  {
    if ( isdotdash ( *c ))
    {
      if ( isdotdash ( *( c - 1 )))
		  return false;
    }

    else if ( ! isalnum ( *c ))
      return false;
  }

  if ( *c != '@' )
    return 0;

  if (!isalnum(*(c - 1)))
	  return false;
  
  if (!*(domain = ++c)) return 0;
  do 
  {
    if (*c == '.') 
    {
		if (c == domain || *(c - 1) == '.') return false;
      count++;
    }
    if (*c <= ' ' || *c >= 127) return 0;
	if (strchr(rfc822_specials, *c)) return false;
  } while (*++c);

  return (count >= 1);
}

bool day_valid(int day)
{
	if (day < 31 && day > 0) return true;
	else return false;
}

bool month_valid(int month)
{
	if (month <= 12 && 0 < month) return true;
	return false;
}

bool year_valid(int year)
{
	return (1900 < year && 2100 > year);
}

bool telephon_valid(int tele)
{
	return (tele < 999999999 && tele > 100000000);
}

int edytuj_txt(short x, short y, char *& tekst)
{
	char *res = (char*)malloc((strlen(tekst)+1)*sizeof(char));
	
	strcpy(res, tekst);

	int key = 0;

	while (key != '\r') {

		int len = strlen(res);
		if (len >= 27) info("Maksymalna dlugosc tekstu to 27 znakow");

		if (key != 0 && key != '\b' && len < 28 ) {
			len += 2;
			res = (char*)realloc(res, sizeof(char)*len);
			memset(res + len - 1, '\0', 1);
			memset(res + len - 2, key, 1);
		}
		else if (key == '\b' && strlen(res)) {
			printf("\b \b");
			res = (char*)realloc(res, sizeof(char)*len);
			memset(res + len - 1, '\0', 1);
		}
		cxyPrint(GREEN_COLOR, x, y, "%28s", res);
		
		key = _getch();

		if (key == 224)
		{
			key = _getch();
			if ((key == down) || (key == up)) break;
		}
	}

	cxyPrint(DEFAULT_COLOR, x, y, "%28s", res);

	free(tekst);
	tekst = res;

	if (key == up) return up;
	else if (key == enter) return enter;
	else return down;
}

void edytuj_rekord(kontakt_t & rekord)
{	
	system("cls");
	info("Aby poruszac sie w menu edycji uzywaj strzalek.");
	wyswietl_menu(&rekord, true);

	char key = 'x';
	int w_edycji = 1;

	while (key != enter)
	{
		switch (w_edycji)
		{
		case 1:
			key = edytuj_txt(10, 5, rekord.imie);
			break;
		case 2:
			key = edytuj_txt(10, 7, rekord.nazwisko);
			break;
		case 3:
		{
			bool ok = true;
			do
			{
				key = edytuj_txt(10, 9, rekord.email);
				ok = email_valid(rekord.email);
				if (!ok) error("Nie poprawny email! Popraw aby przejsc dalej.");
			} while (!ok);
			break;
		}
		case 4:
		{
			char *p = (char*)malloc(sizeof(char) * 3);
			strcpy(p, _itoa(rekord.dzien, p, 10));

			bool ok = true;
			do
			{
				key = edytuj_txt(10, 11, p);
				ok = day_valid(atoi(p));
				if (!ok) error("Wpisales niepoprawny dzien miesiaca! Popraw aby przejsc dalej.");
			} while (!ok);
			rekord.dzien = atoi(p);
			free(p);
			break;
		}
		case 5:
		{
			char *p = (char*)malloc(sizeof(char) * 3);
			strcpy(p, _itoa(rekord.miesiac, p, 10));

			bool ok = true;
			do
			{
				key = edytuj_txt(10, 11, p);
				ok = month_valid(atoi(p));
				if (!ok) error("Wpisales niepoprawny miesiac! Popraw aby przejsc dalej.");
			} while (!ok);
			rekord.miesiac = atoi(p);
			free(p);
			break;
		}
		case 6:
		{
			char *p = (char*)malloc(sizeof(char) * 5);
			strcpy(p, _itoa(rekord.rok, p, 10));

			bool ok = true;
			do
			{
				key = edytuj_txt(10, 11, p);
				ok = year_valid(atoi(p));
				if (!ok) error("Wpisales niepoprawny rok! Popraw aby przejsc dalej.");
			} while (!ok);
			rekord.rok = atoi(p);
			free(p);
			break;
		}
		case 7:
		{
			char *p = (char*)malloc(sizeof(char) * 10);
			strcpy(p, _itoa(rekord.telefon, p, 10));

			bool ok = true;
			do
			{
				key = edytuj_txt(10, 13, p);
				if (strlen(p) < 10) ok = telephon_valid(atoi(p));
				else ok = false;
				if (!ok) error("Wpisales niepoprawny numer telefonu! Popraw aby przejsc dalej.");
			} while (!ok);
			rekord.telefon = atoi(p);
			free(p);
			break;
		}
		default:
			break;
		}
		switch (key)
		{
		case down:
			if (w_edycji < 7) w_edycji++;
			else key = enter;
			break;
		case up:
			if (w_edycji > 1) w_edycji--;
			break;
		case enter:
			break;
		default:
			break;
		}
	}

	system("cls");
}

void zeruj_rekord(kontakt_t & rekord)
{
	rekord.imie = (char*)malloc(sizeof(char)*(strlen("imie") + 1));
	strcpy(rekord.imie, "imie");

	rekord.nazwisko = (char*)malloc(sizeof(char)*(strlen("nazwisko") + 1));
	strcpy(rekord.nazwisko, "nazwisko");

	rekord.email = (char*)malloc(sizeof(char)*(strlen("email") + 1));
	strcpy(rekord.email, "email");

	rekord.dzien = 0;
	rekord.miesiac = 0;
	rekord.rok = 0;
	rekord.telefon = 0;
}

void dodaj_rekord(kontakt_t *& baza, int * Aktualny, int * size)
{
	(*size)++;
	if ((*size) != 1) baza = (kontakt_t*)realloc(baza, (*size) * (sizeof(kontakt_t)));
	else baza = (kontakt_t*)malloc(sizeof(kontakt_t));

	*Aktualny = (*size) - 1;

	zeruj_rekord(baza[*Aktualny]);
		
	edytuj_rekord(baza[*Aktualny]);
}

void cxyPrint(WORD Color, short x, short y, const char * format, ...)
{
	static HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buffer[256];
	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);

	SetConsoleCursorPosition(hwnd, COORD{ x,y });
	SetConsoleTextAttribute(hwnd, Color);
	printf("%s", buffer);
	SetConsoleTextAttribute(hwnd , DEFAULT_COLOR);
}

kontakt_t * wczytaj_baze(int * size)
{
	FILE * file = fopen("kontakty.txt", "r");
	if (file == nullptr)
	{
		error("Nie moge znalezc pliku z baza kontaktow!");
		return nullptr;
	}

	char * buf = (char*)malloc(sizeof(char) * 64);
	if (buf == nullptr)
	{
		error("Nie moge zaalokowac wystarczajacej pamieci na tablice pomocnicza przy wczytywaniu bazy danych!");
		return nullptr;
	}

	bool new_contact = false;
	*size = 0;
	kontakt_t * tab = nullptr;

	while (!feof(file))
	{
		fscanf(file, "%s", buf);

		if (!strcmp(buf, "#new_record")) 
		{
			(*size)+=1;
			if ((*size) != 1) tab = (kontakt_t*)realloc(tab, sizeof(kontakt_t) * *size);
			else tab = (kontakt_t*)malloc(sizeof(kontakt_t));
			
			if (tab == nullptr)
			{
				error("Nie udalo sie zaalokowac wystarczajaco duzo pamieci podczas wczytywania danych z bazy kontaktow.");
				free(buf);
				return nullptr;
			} else
			{
				zeruj_rekord(tab[*size - 1]);
				new_contact = true;
				continue;
			}
		}

		if (new_contact)
		{
			if (!strcmp(buf, "#name"))
			{
				fscanf(file, "%s", buf);
				tab[*size - 1].imie = (char*)realloc(tab[*size - 1].imie, sizeof(char)*(strlen(buf)+1));
				strcpy(tab[*size - 1].imie, buf);
			}
			else if (!strcmp(buf, "#surname"))
			{
				fscanf(file, "%s", buf);
				tab[*size - 1].nazwisko = (char*)realloc(tab[*size - 1].nazwisko, sizeof(char)*(strlen(buf) + 1));
				strcpy(tab[*size - 1].nazwisko, buf);
			}
			else if (!strcmp(buf, "#email"))
			{
				fscanf(file, "%s", buf);
				tab[*size - 1].email = (char*)realloc(tab[*size - 1].email, sizeof(char)*(strlen(buf) + 1));
				strcpy(tab[*size - 1].email, buf);
			}
			else if (!strcmp(buf, "#birthday"))
			{
				fscanf(file, "%d %d %d", &tab[*size - 1].dzien, &tab[*size - 1].miesiac, &tab[*size - 1].rok);
			}
			else if (!strcmp(buf, "#telephone"))
			{
				fscanf(file, "%d", &tab[*size - 1].telefon);
			}
			else if (!strcmp(buf, "#end_record")) new_contact = false;
			else while (fgetc(file) != '\n');//eat line
		}
	}

	free(buf);
	info("Baza zostala zaladowana.");
	return tab;
}

void zapisz_baze(const kontakt_t * baza, const int size)
{
	FILE * file = fopen("kontakty.txt", "w");
	if (file == nullptr)
	{
		error("Nie moge zapisac bazy danych do pliku!");
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		fprintf(file, "#new_record\n#name\n%s\n#surname\n%s\n#email\n%s\n#birthday\n%d %d %d\n#telephone\n%d\n#end_record\n",
			baza[i].imie, baza[i].nazwisko, baza[i].email, baza[i].dzien, baza[i].miesiac, baza[i].rok, baza[i].telefon);
	}

	fclose(file);

	info("Baza zostala zapisana do pliku");
}

void wyswietl_menu(const kontakt_t *rekord, bool pelen)
{
	if (pelen) rysuj_ramke(true, 22);
	else rysuj_ramke(false);

	short x = 10, y = 2;

	cxyPrint(DEFAULT_COLOR, x, y++, "Twoje menu:");
	y++;
	if (rekord != nullptr)
	{
		cxyPrint(DEFAULT_COLOR, x, y++, "Imie:");
		if (rekord->imie != nullptr) cxyPrint(DEFAULT_COLOR, x, y, "%28s", rekord->imie);
		y++;
		
		cxyPrint(DEFAULT_COLOR, x, y++, "Nazwisko:");
		if (rekord->nazwisko != nullptr) cxyPrint(DEFAULT_COLOR, x, y, "%28s", rekord->nazwisko);
		y++;

		if (pelen)
		{
			cxyPrint(DEFAULT_COLOR, x, y++, "Email:");
			if (rekord->email != nullptr) cxyPrint(DEFAULT_COLOR, x, y++, "%28s", rekord->email);
			else y++;

			cxyPrint(DEFAULT_COLOR, x, y++, "Data urodzenia:");
			cxyPrint(DEFAULT_COLOR, x, y++, "%20.2d-%.2d-%.4d", rekord->dzien, rekord->miesiac, rekord->rok);
			cxyPrint(DEFAULT_COLOR, x, y++, "Numer telefonu:");
			cxyPrint(DEFAULT_COLOR, x, y++, "%28d", rekord->telefon);
		}
	}

	y++;
	cxyPrint(DEFAULT_COLOR, x, y++, "[1] Nastepny rekord");
	cxyPrint(DEFAULT_COLOR, x, y++, "[2] Poprzedni rekord");
	if(!pelen) cxyPrint(DEFAULT_COLOR, x, y++, "[3] Wyswietl caly rekord");
	else cxyPrint(DEFAULT_COLOR, x, y++, "[3] Wyswietl skrocony rekord");
	cxyPrint(DEFAULT_COLOR, x, y++, "[4] Usun rekord");
	cxyPrint(DEFAULT_COLOR, x, y++, "[5] Edytuj rekord");
	cxyPrint(DEFAULT_COLOR, x, y++, "[6] Dodaj rekord");
	cxyPrint(DEFAULT_COLOR, x, y++, "[0] Zapisz i wyjdz");
	cxyPrint(DEFAULT_COLOR, x, y++, "[-1] Wyjdz BEZ ZAPISYWANIA");
	y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ x,y });
}

void usun_rekord(kontakt_t *& baza, int *Aktualny, int *size)
{
	if ((*size) == 0)
	{	
		return;
	}

	free((baza + (*Aktualny))->email);
	free((baza + (*Aktualny))->nazwisko);
	free((baza + (*Aktualny))->imie);

	if (*Aktualny == ((*size) - 1))
	{
		(*size)--;
		(*Aktualny)--;
		if ((*size) == 0)
		{
			free(baza);
			baza = nullptr;
			*Aktualny = -1;
			return;
		}

		(baza) = (kontakt_t*)realloc(baza, sizeof(kontakt_t)*(*size));
		return;
	}

	if ((*size) > 1) 
	{
		*(baza + *Aktualny) = *(baza + (*size) - 1);
		(*size)--;
		(baza) = (kontakt_t*)realloc((baza), sizeof(kontakt_t)*(*size));
	}
	else
	{
		free(baza);
		(baza) = nullptr;
		(*size) = 0;
		(*Aktualny) = 0;
	}
}

void zwolnij_pamiec(kontakt_t *& kontakty, int size)
{
	if (size <= 0) {
		info("Brak pamieci do zwolnienia - baza jest pusta.");
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		free((kontakty + i)->email);
		free((kontakty + i)->nazwisko);
		free((kontakty + i)->imie);
	}

	free(kontakty);
}

void error(const char* erro)
{
	cxyPrint(RED_COLOR, 0, 0, "ERROR: %s", erro);
}

void info(const char * info)
{
	cxyPrint(BLUE_COLOR, 0, 0, "INFO: %s", info);
}

void rysuj_ramke(bool pelen, int x, int y)
{
	printf("\n\t%c", 201);								/*gora*/
	for (int i = 0; i < (y - 2); ++i) printf("%c", 205);
	printf("%c\n", 187);

	printf("\t%c", 186);
	for (int i = 0; i < (y - 2); ++i) printf("%c", ' ');//pusta linia
	printf("%c\n", 186);

	printf("\t%c", 204);
	for (int i = 0; i < (y - 2); ++i) printf("%c", 205);//pelna linia w srodku
	printf("%c\n", 185);

	for (int i = 0; i < (pelen ? 10 : 4); ++i)
	{
		printf("\t%c", 186);
		for (int i = 0; i < (y - 2); ++i) printf("%c", ' '); // pusto
		printf("%c\n", 186);
	}

	printf("\t%c", 204);
	for (int i = 0; i < (y - 2); ++i) printf("%c", 205); //pelna linia w srodku
	printf("%c\n", 185);

	for (int i = 0; i < (pelen ? x - 10 - 4 : x - 4 - 4); ++i)
	{
		printf("\t%c", 186);
		for (int i = 0; i < (y - 2); ++i) printf("%c", ' '); // pusto
		printf("%c\n", 186);
	}

	printf("\t%c", 200);
	for (int i = 0; i < (y - 2); ++i) printf("%c", 205); //dol
	printf("%c\n", 188);
}