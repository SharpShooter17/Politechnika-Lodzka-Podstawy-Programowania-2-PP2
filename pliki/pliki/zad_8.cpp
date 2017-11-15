#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void zad_8()
{
	char buffor[256];

	printf("Podaj nazwe pliku do odczytu: ");
	scanf("%s", buffor);
	
	FILE * file = fopen(buffor, "rb");

	if (file == nullptr) 
	{
		system("pause");
		return;
	}

	fpos_t fsize;

	fseek(file, 0, SEEK_END);
	fgetpos(file, &fsize);
	fseek(file, 0, SEEK_SET);
	
	unsigned char * dfile = (unsigned char*)malloc(fsize*sizeof(unsigned char));

	fread(dfile, sizeof(unsigned char), fsize, file);

	fclose(file);

	for (int i = 0; i < fsize; ++i)
	{
		printf("%c", dfile[i]);
	}

	free(dfile);

	system("pause");
}