#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

char * read( FILE * file )
{
	char * res;
	char c = fgetc(file);
	unsigned short len = 1;

	res = (char*)malloc(sizeof(char));
	if (res == NULL) return NULL;
	res[len - 1] = c;

	do
	{
		c = fgetc(file);
		char *tmp = (char*)realloc(res, ++len * sizeof(char));
		if (tmp == NULL) { --len; }
		res = tmp;
		res[len - 1] = c;
	} while (c != '\n' && c != ' ' && c != '\t' && c != '\r' && c != EOF);

	res[len - 1] = '\0';
	return res;
}

bool validate(const char * text)
{
	for (int i = 0; i < strlen(text); i++)
		if (text[i] > '9' || text[i] < '0') 
			return false;

	return true;
}

int main()
{
	FILE * file = fopen("plik.txt", "r");
	if (file == nullptr) return -1;

	const char * c = nullptr;

	do
	{
		c = read(file);
		if (validate(c))
			printf("%s\n", c);
	}while (*c != EOF);

	fclose(file);

	system("pause");
	return 0;
}
/*tekst liczba chyba nie 2u to nie liczba da3sa 3 dadaad33dd3d33 3215 op 1 2 3 5 888 99 9 66 amazonka 18 1 6523
kanibal
2
op
l
9
2
p
l
0
l*/