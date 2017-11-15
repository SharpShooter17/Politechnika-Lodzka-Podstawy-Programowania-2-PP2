#include <iostream>

//http://tjaworski.iis.p.lodz.pl/

extern void zad_1();
extern void zad_2();
extern void zad_3();
extern void zad_4();
extern void zad_5();
extern void zad_6();
extern void zad_7();
extern void zad_8();

extern void dump(unsigned char *w, int size);
extern int T[20];

//teksty napisy..
const char* t1 = "Ala Ma Kota a kot Ma AlE";

extern void txt1();
extern void txt2();
extern void txt3();
extern void txt4();
extern void txt5();
extern void txt6();
extern void txt7();
extern void txt8();
extern void txt9(); 
extern void txt10();

int main()
{
	txt3(); 

	//dump((unsigned char*)T, 84);

	std::cin.get();
	std::cin.get();

	return 0;
}

