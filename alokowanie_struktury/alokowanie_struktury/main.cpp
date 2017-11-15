#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstdarg>

#include "f_geom.h"

extern figura_t * create(int *error, FIGURA fig, ...);
extern void pokaz_figure(figura_t * figura);



void zad_1()
{
	int error;

	figura_t * kolo = create(&error, FIGURA::odcinek, 7, 3, 5, 7);

	if (kolo == nullptr) return;

	if (error == 77)
	{
		pokaz_figure(kolo);
		free(kolo);
	}
}

void zapisz_bin(figura_t **tab, int n)
{
	FILE * file = fopen("figura.bin", "wb");
	if (file == NULL) return;

	for (int i = 0; i < n; i++)
	{
		fwrite(tab[i], sizeof(figura_t), 1, file);
	}

	fclose(file);
}

void wczytaj(const char * filename, figura_t ** buffer, int n)
{
	FILE * file = fopen(filename, "rb");

	figura_t * tmp = (figura_t*)malloc(sizeof(figura_t));

	for (int i = 0; i < 10; i++)
	{
		fread(tmp, sizeof(figura_t), 1, file);
		if (tmp->fig == FIGURA::kolo)
			buffer[i] = create(NULL, tmp->fig, tmp->R, tmp->p[0].x, tmp->p[0].y);
		else
			buffer[i] = create(NULL, tmp->fig, tmp->p[0].x, tmp->p[0].y, tmp->p[1].x, tmp->p[1].y, tmp->p[2].x, tmp->p[2].y, tmp->p[3].x, tmp->p[3].y);
	}

	free(tmp);

	fclose(file);
}

int zad_2()
{
	figura_t **tab = (figura_t**)malloc(sizeof(figura_t) * 10);
	if (tab == nullptr) return -1;

	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 3;

		switch (random)
		{
		case 0: 
			*(tab + i) = create(nullptr, FIGURA::kolo, rand() % 20, rand() % 100, rand() % 100);
			break;
		case 1:
			*(tab + i) = create(nullptr, FIGURA::odcinek, rand() % 20, rand() % 100, rand() % 100, rand()%20);
			break;
		case 2:
			*(tab + i) = create(nullptr, FIGURA::trojkat, rand() % 20, rand() % 100, rand() % 100, rand() % 20, rand() % 100, rand() % 20);
			break;
		case 3:
			*(tab + i) = create(nullptr, FIGURA::kwadrat, rand() % 20, rand() % 100, rand() % 100, rand() % 20, rand() % 100, rand() % 20, rand() % 100, rand() % 20);
			break;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		pokaz_figure(tab[i]);
	}

	zapisz_bin(tab, 10);

	for (int i = 0; i < 10; i++)
	{
		free(tab[i]);
	}
	free(tab);

	return 0;
}

void zad_2_wczytaj()
{
	figura_t **tab = (figura_t**)malloc(sizeof(figura_t) * 10);
	if (tab == nullptr) return;

	wczytaj("figura.bin", tab, 10);

	for (int i = 0; i < 10; i++)
	{
		pokaz_figure(tab[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		free(tab[i]);
	}
	free(tab);
}

int main()
{
	//zad_2();
	zad_2_wczytaj();
	
	system("pause");
	return 0;
}