#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void zad1()
{
	float *ptr = (float*)malloc(sizeof(float) * 100);
	if (ptr == nullptr)
		return;

	for (int i = 0; i < 100; i++)
	{
		ptr[i] = (rand() % 10000)/100.0f;
	}

	for (int i = 0; i < 100; i++)
	{
		printf("%f\n", ptr[i]);
	}

	free(ptr);
}

void zad2()
{
	char *GB = (char*)malloc(1 * 1024 * 1024 * 1024);
	if (GB == nullptr)
		return;
	
	printf("Udalo zaalokowac siê 1gb pamieci! ");
	system("pause");
	free(GB);
}

void zad3()
{
	char *blok = (char*)malloc(1024);
	if (blok == nullptr) return;

	unsigned int n = 1;

	while (true)
	{
		char *tmp = (char*)realloc(blok, n * 1024 * sizeof(char));
		if (tmp == nullptr) 
		{ 
			printf("Nie udalo zaalokowac sie pamieci.\nPamiec zaalokowana to: %dkB. ", 1024 * n);
			free(blok);
			return;
		}
		blok = tmp;
		n++;
	}

	free(blok);
	return;
}

void zad4()
{
	double *pi = (double*)malloc(sizeof(double));
	*pi = 22.0/7.0;
	printf("PI: %f adres: 0x%x ", *pi, &*pi);
	free(pi);
}

//5
float* alokuj_f(int N)
{
	return (float*)malloc(N*sizeof(float));
}


void wyswietl(const int * ptr, int N)
{
	if (ptr == nullptr) return;

	for (int i = 0; i < N; ++i)
	{
		printf("%d, ", ptr[i]);
	}
}

int* kopia(const int* ptr, int N)
{
	int * ret = (int*)malloc(sizeof(int)*N);
	if (ret == nullptr)
		return nullptr;

	memcpy(ret, ptr, N*sizeof(int));

	return ret;
}

void zad6()
{
	int tab[] = { 1,2,3,4,5,6,7,8,9,0 };
	wyswietl(tab, 10);
	int *ptr = kopia(tab, 10);
	wyswietl(ptr, 10);
	free(ptr);
}

struct student_t {
	char *imie;
	char *nazwisko;
	char *album;
};

student_t* wypelnij(void)
{
	student_t * ret = (student_t*)malloc(sizeof(student_t));
	if (ret == nullptr) return nullptr;

	char *buffor = (char*)malloc(256);
	if (buffor == nullptr)
	{
		printf("Nie udalo zaalokowac sie pamieci dla bufora.");
		return nullptr;
	}

	printf("Podaj imie studenta: ");
	scanf("%s", buffor);
	ret->imie = (char*)malloc(sizeof(char) * (1 + strlen(buffor)));
	if (ret->imie == nullptr)
	{
		printf("Nie udalo zaalokowac sie pamieci napisu.");
		return nullptr;
	}
	strcpy(ret->imie, buffor);

	printf("Podaj nazwisko studenta: ");
	scanf("%s", buffor);
	ret->nazwisko = (char*)malloc(sizeof(char) * (1 + strlen(buffor)));
	if (ret->nazwisko == nullptr)
	{
		printf("Nie udalo zaalokowac sie pamieci napisu.");
		return nullptr;
	}
	strcpy(ret->nazwisko, buffor);

	printf("Podaj album studenta: ");
	scanf("%s", buffor);
	ret->album = (char*)malloc(sizeof(char) * (1 + strlen(buffor)));
	if (ret->album == nullptr)
	{
		printf("Nie udalo zaalokowac sie pamieci napisu.");
		return nullptr;
	}
	strcpy(ret->album, buffor);

	free(buffor);

	return ret;
}

void wyswietl_studenta(const student_t * ss)
{
	printf("Imie: %s\nNazwisko: %s\nAlbum: %s\n", ss->imie, ss->nazwisko, ss->album);
}

void oblej_studenta(student_t *ss)
{
	free(ss->album);
	free(ss->nazwisko);
	free(ss->imie);
	free(ss);
}

void zad_7()
{
	student_t * ss = wypelnij();
	wyswietl_studenta(ss);
	oblej_studenta(ss);
}

int main()
{
	zad3();
	system("pause");
}