#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <varargs.h>
#include <string.h>


void concat(char * buffer, int size, int count,...)
{
	va_list ap;
	va_start(ap, count);
	va_arg(ap, int);

	buffer[0] = '\0';
	
	int len = 0;
	int i;
	for (i = 0; i < count; i++)
	{
		const char * p = va_arg(ap, const char *);
		int lenght = strlen(p);
		if ( (lenght + len) > (size - 1))
		{
			if ((size - 4 - len) > 0)
				strncat(buffer, p, size - 4 - len);
			buffer[size - 4] = '.';
			buffer[size - 3] = '.';
			buffer[size - 2] = '.';
			break;
		}
		else
		{
			len += lenght;
			strcat(buffer, p);
		}
	}

	buffer[size - 1] = '\0';
	va_end(ap);
}

int main()
{
	char buffer[10];
	concat(buffer, sizeof(buffer), 3, "Ala", "ma", "kota");
	printf("%s\n", buffer);
	concat(buffer, sizeof(buffer), 5, "Ala", " ", "ma", " ", "kota");
	printf("%s\n", buffer);
	concat(buffer, sizeof(buffer), 4, "Wlazl", "KotekNaPlotek", " i", " mruga");
	printf("%s\n", buffer);
	system("pause");
	return 0;
}