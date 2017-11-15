#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char buffor[256];

	printf("Podaj nazwe pliku do odczytu: ");
	scanf("%s", buffor);

	if ( !strcmp(".txt", buffor + strlen(buffor) - 3 ) )
    {
        printf("Plik musi miec rozszerzenie: \".txt\"");
        return -1;
    }

	FILE * file = fopen(buffor, "r");

	if (file == NULL)
	{
		return -1;
	}

    int c = getc( file );
    while( c != EOF )
    {

        printf( "%c", toupper(c) );
        c = getc( file );
    }

    fclose(file);

    return 0;
}
