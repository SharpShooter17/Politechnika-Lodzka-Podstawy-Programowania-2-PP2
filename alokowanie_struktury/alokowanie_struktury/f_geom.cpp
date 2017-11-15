#include <malloc.h>
#include <cstdarg>
#include <stdio.h>
#include "f_geom.h"


bool walidacja_punktow(int *error, punkt_t * p, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i].x < 0 || p[i].x > 100) TEST_ERROR_VALID(1);
		if (p[i].y < 0 || p[i].y > 100) TEST_ERROR_VALID(2);
	}
	return true;
}


void pokaz_punkty(punkt_t * p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Punkt: %d:\t(%d, %d)\n", i, p[i].x, p[i].y);
	}
}

figura_t * create(int *error, FIGURA fig, ...)
{
	TEST_ERROR(77);
	va_list ap;
	va_start(ap, fig);
	punkt_t p[4];
	switch (fig)
	{
	case FIGURA::kolo:
	{
		///walidacja danych.
		int r = va_arg(ap, int);
		if (r < 0) TEST_ERROR(0);
		for (int i = 0; i < 1; i++)
		{
			p[i].x = va_arg(ap, int);
			p[i].y = va_arg(ap, int);
		}

		if (!walidacja_punktow(error, p, 1)) return nullptr;

		figura_t * figura = (figura_t*)malloc(sizeof(figura_t));
		if (figura == nullptr) TEST_ERROR(100);

		figura->fig = fig;
		figura->p[0] = p[0];
		figura->R = r;

		return figura;
	}
	case FIGURA::kwadrat:
	{
		for (int i = 0; i < 4; i++)
		{
			p[i].x = va_arg(ap, int);
			p[i].y = va_arg(ap, int);
		}

		if (!walidacja_punktow(error, p, 4)) return nullptr;

		figura_t * figura = (figura_t*)malloc(sizeof(figura_t));
		if (figura == nullptr) TEST_ERROR(100);

		figura->fig = fig;
		for (int i = 0; i < 4; i++)
		{
			figura->p[i] = p[i];
		}

		return figura;
	}
	case FIGURA::trojkat:
	{
		for (int i = 0; i < 3; i++)
		{
			p[i].x = va_arg(ap, int);
			p[i].y = va_arg(ap, int);
		}

		if (!walidacja_punktow(error, p, 3)) return nullptr;

		figura_t * figura = (figura_t*)malloc(sizeof(figura_t));
		if (figura == nullptr) TEST_ERROR(100);

		figura->fig = fig;
		for (int i = 0; i < 3; i++)
		{
			figura->p[i] = p[i];
		}

		return figura;
	}
	case FIGURA::odcinek:
	{
		for (int i = 0; i < 2; i++)
		{
			p[i].x = va_arg(ap, int);
			p[i].y = va_arg(ap, int);
		}

		if (!walidacja_punktow(error, p, 2)) return nullptr;

		figura_t * figura = (figura_t*)malloc(sizeof(figura_t));
		if (figura == nullptr) TEST_ERROR(100);

		figura->fig = fig;
		for (int i = 0; i < 2; i++)
		{
			figura->p[i] = p[i];
		}

		return figura;
	}
	default:
		TEST_ERROR(9);
	}
}

void pokaz_figure(figura_t * figura)
{
	switch (figura->fig)
	{
	case FIGURA::kolo:
		printf("Kolo: R: %d\n", figura->R);
		pokaz_punkty(figura->p, 1);
		break;
	case FIGURA::kwadrat:
		printf("Kwadrat:\n");
		pokaz_punkty(figura->p, 4);
		break;
	case FIGURA::trojkat:
		printf("Trojkat:\n");
		pokaz_punkty(figura->p, 3);
		break;
	case FIGURA::odcinek:
		printf("Odcinek:\n");
		pokaz_punkty(figura->p, 2);
		break;
	}
}