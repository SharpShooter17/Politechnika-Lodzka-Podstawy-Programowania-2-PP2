#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define _USE_MATH_DEFINES
#include <math.h>

struct zesp_t
{
	double i, r;
};

zesp_t* lz(double rzeczywista, double urojona);
void ustaw(zesp_t* liczba, double rzeczywista, double urojona);
void wyswietl(zesp_t* liczba);
void dodaj(zesp_t* a, zesp_t* b, zesp_t* wynik);
void odejmij(zesp_t* a, zesp_t* b, zesp_t* wynik);
void pomnoz(zesp_t* a, zesp_t* b, zesp_t* wynik);
double modul(zesp_t* liczba);
double argument(zesp_t* liczba);

int main()
{
	zesp_t * x = lz(2, 4);
	zesp_t * y = lz(1, 2);
	zesp_t * z = (zesp_t*)malloc(sizeof(zesp_t));
	
	printf("Dodawanie:\n");
	wyswietl(x);
	printf(" + ");
	wyswietl(y);
	printf(" = ");
	dodaj(x, y, z);
	wyswietl(z);

	printf("\nOdejmowanie:\n");
	wyswietl(x);
	printf(" - ");
	wyswietl(y);
	printf(" = ");
	odejmij(x, y, z);
	wyswietl(z);

	printf("\nMnozenie:\n(");
	wyswietl(x);
	printf(") * (");
	wyswietl(y);
	printf(") = ");
	pomnoz(x, y, z);
	wyswietl(z);

	printf("\nModul: %f\n", modul(x));

	printf("Argument: %f\n", argument(x));

	system("pause");

	return 0;
}

zesp_t * lz(double rzeczywista, double urojona)
{
	zesp_t * res = (zesp_t*)malloc(sizeof(zesp_t));
	if (res == nullptr) return nullptr;

	res->i = urojona;
	res->r = rzeczywista;

	return res;
}

void ustaw(zesp_t * liczba, double rzeczywista, double urojona)
{
	liczba->r = rzeczywista;
	liczba->i = urojona;
}

void wyswietl(zesp_t * liczba)
{
	printf("%f + %fi", liczba->r, liczba->i);
}

void dodaj(zesp_t * a, zesp_t * b, zesp_t * wynik)
{
	wynik->i = a->i + b->i;
	wynik->r = a->r + b->r;
}

void odejmij(zesp_t * a, zesp_t * b, zesp_t * wynik)
{
	wynik->i = a->i - b->i;
	wynik->r = a->r - b->r;
}

void pomnoz(zesp_t * a, zesp_t * b, zesp_t * wynik)
{
	wynik->r = a->r*b->r - a->i*b->i;
	wynik->i = a->r*b->i + a->i*b->r;
}

double modul(zesp_t * liczba)
{
	return sqrt(pow(liczba->r, 2) + pow(liczba->i, 2));
}

double argument(zesp_t * liczba)
{
	return acos(liczba->r / modul(liczba)) * 180.0/ M_PI;
}
