#include <stdio.h>

void getline(unsigned char * dest);

void zad_9a()
{
	FILE *file = fopen("zad_9a.txt", "w");
	if (file == nullptr) return;

	unsigned char buffor[100]{ 0 };

	while (true)
	{
		printf("Wprowadz tekst: ");
		getline(buffor);
		if (buffor[0] != '\n')
			fprintf(file, "%s", buffor);
		else break;
	}

	fclose(file);
}

void getline(unsigned char * dest)
{
	char c = 0;
	int i = 0;
	while (c != '\n')
	{
		scanf("%c", &c);
		dest[i] = c;
		i++;
	}
}