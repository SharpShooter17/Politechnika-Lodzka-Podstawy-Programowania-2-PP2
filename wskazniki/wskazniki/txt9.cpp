#include <malloc.h>
#include <iostream>

void combine(char * t, const char * t1, const char *t2, const char *t3);

void txt9()
{
	char buff[100];
	memset(buff, '\0', 100);

	combine(buff, "raz", "dwa", "trzy");
	std::cout << buff;
}

void combine(char * t, const char * t1, const char *t2, const char *t3)
{
	strcat(t, t1);
	strcat(t, " ");
	strcat(t, t2);
	strcat(t, " ");
	strcat(t, t3);
	strcat(t, "\0");
}
