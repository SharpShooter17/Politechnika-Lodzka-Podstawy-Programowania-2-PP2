#include <malloc.h>
#include <iostream>
#include <string.h>

namespace my
{
	extern int strlen(const char *str, char ending_char = '\0');
	char *strcpy(char* To, const char* From, char ending_char = '\0');
}

void turn_words( const char * str);

extern const char* t1;

void txt7()
{
	turn_words(t1);	
}

void turn_words(const char * str)
{
	int n = my::strlen(str);
	while (n >= 0)
	{
		if ((*(str + n) == ' ')||(n==0))
		{
			int i = (n==0) ? 0 : 1;
			while ((*(str + n + i) != ' ') && (*(str + n + i) != '\0'))
			{
				putchar(*(str + n + i));
				i++;
			}
			putchar(' ');
		}
		n--;
	}
}