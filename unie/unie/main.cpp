#include <stdio.h>
#include <stdlib.h>

//Zadanie 1 i 2

union zad1
{
	int i;
	unsigned short b;
	unsigned char c;
	unsigned int i1;
};

void zad_1()
{
	zad1 x;
	x.i = 1;

	printf("bajty: \n");

	for (int i = 0; i < sizeof(zad1); ++i)
	{
		printf("0x%x\n", *(&x.c + i));
	}

	printf("slowa: \n");

	for (int i = 0; i < sizeof(zad1) / sizeof(short); ++i)
	{
		printf("0x%x\n", *(&x.b + i));
	}

	printf("DWORD: %x\n", x.i);
	system("pause");
}

union zad3
{
	unsigned char x;

	struct
	{
		unsigned char x1 : 1;
		unsigned char x2 : 1;
		unsigned char x3 : 1;
		unsigned char x4 : 1;
		unsigned char x5 : 1;
		unsigned char x6 : 1;
		unsigned char x7 : 1;
		unsigned char x8 : 1;
	};
};

void zad_3()
{
	zad3 x;
	x.x = 0;
	printf("Podaj znak: ");

	scanf("%c", &x.x);

	printf("Wartosc znaku w kodzie ASCII: %d\n", x.x);
	printf("Podany znak wyrazony w bitach: ");

	printf("%d", x.x8);
	printf("%d", x.x7);
	printf("%d", x.x6);
	printf("%d", x.x5);
	printf("%d", x.x4);
	printf("%d", x.x3);
	printf("%d", x.x2);
	printf("%d", x.x1);

	printf("\n");
	system("pause");
}

union zad4
{
	unsigned int i;
	unsigned short s;
	unsigned char c;

	struct
	{
		unsigned char x1 : 1;
		unsigned char x2 : 1;
		unsigned char x3 : 1;
		unsigned char x4 : 1;
		unsigned char x5 : 1;
		unsigned char x6 : 1;
		unsigned char x7 : 1;
		unsigned char x8 : 1;
	};
};

void wyswietl_bit(unsigned char bajt)
{
	zad4 x{ bajt };

	printf("%d", x.x8);
	printf("%d", x.x7);
	printf("%d", x.x6);
	printf("%d", x.x5);
	printf("%d", x.x4);
	printf("%d", x.x3);
	printf("%d", x.x2);
	printf("%d", x.x1);
}

void zad_4()
{
	zad4 x;

	printf("Podaj liczbe:");
	scanf("%ud", &x.i);

	printf("unsigned int: %u\n", x.i);

	printf("bajty: \n");

	for (int i = sizeof(zad4) - 1; i >= 0 ; --i)
	{
		printf("0x%x\n", *(&x.c + i));
	}

	printf("slowa: \n");

	for (int i = sizeof(zad4) / sizeof(short) - 1; i >= 0 ; --i)
	{
		printf("0x%x\n", *(&x.s + i));
	}

	printf("32 bity: \n");

	for (int i = sizeof(zad4) - 1; i >= 0; --i)
	{
		wyswietl_bit((unsigned char)*(&x.c + i));
	}

	printf("\n4x 8 bit:\n");

	for (int i = sizeof(zad4) - 1; i >= 0; --i)
	{
		wyswietl_bit((unsigned char)*(&x.c + i));
		printf("\n");
	}

	printf("\n");
	system("pause");

}

int liczba_jedynek(unsigned char bajt)
{
	zad4 x{ bajt };

	int ret = 0;

	if(x.x1) ret++;
	if (x.x2) ret++;
	if (x.x3) ret++;
	if (x.x4) ret++;
	if (x.x5) ret++;
	if (x.x6) ret++;
	if (x.x7) ret++;
	if (x.x8) ret++;

	return ret;
}

void zad_5()
{
	zad4 x;

	printf("Podaj liczbe: ");
	scanf("%ud", &x.i);

	int jedynek = 0;

	for (int i = 0; i < sizeof(unsigned int); ++i)
	{
		jedynek += liczba_jedynek((unsigned char)*(&x.c + i));
	}

	if ((jedynek % 2) == 0) printf("Bit parzystosci to 0 - liczba posiada parzysta liczbe jedynek.");
	else printf("Bit parzystosci to 1 - liczba nie posiada parzystej liczby jedynek.");

	printf("\n");
	system("pause");
}

int main()
{
	zad_1();
	return 0;
}