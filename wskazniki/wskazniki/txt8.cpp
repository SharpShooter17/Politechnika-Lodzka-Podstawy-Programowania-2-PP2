#include <malloc.h>
#include <iostream>

namespace my
{
	extern int strlen(const char *str, char ending_char = '\0');
}

extern const char* t1;

char * funny_copy(const char * str);

void txt8()
{
	char * p = funny_copy(t1);
	std::cout << p;
	free(p);
}

char * funny_copy(const char * str)
{
	int sub = 'a' - 'A';
	int len = my::strlen(str);

	char * res = (char*)malloc((len+1)*sizeof(char));

	for (int i = 0; i < len; i++)
	{
		char c = str[i];
		if (c <= 'Z' && c >= 'A')
			res[i] = c + sub;
		else if (c <= 'z' && c >= 'a')
			res[i] = c - sub;
		else
			res[i] = c;
	}
	res[len] = '\0';

	return res;
}