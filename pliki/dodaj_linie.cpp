#include <stdio.h>
#include <malloc.h>

char * read()
{
	char * res;
	char c = getchar();
	unsigned short len = 1;

	res = (char*)malloc(sizeof(char));
	if (res == NULL) return NULL;
	res[len-1] = c;

	do
	{
		c = getchar();
		char *tmp = (char*)realloc(res, ++len * sizeof(char));
		if (tmp == NULL) { putchar('\b'); --len; }
		res = tmp;
		res[len-1] = c;
	} while (c != '\n');

	res[len-1] = '\0';
	return res;
}

int main()
{
    printf("Podaj linie tekstu:\n");
    char * tekst = read();
    if (tekst == NULL) return -1;

    FILE * file = fopen("plik5.txt", "a");
    if (file == NULL) { free(tekst); return -2;}

    fprintf(file, "%s\n", tekst);
    fclose(file);

    return 0;
}
