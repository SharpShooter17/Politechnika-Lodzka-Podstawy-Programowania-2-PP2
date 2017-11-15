#include <stdio.h>
#include <io.h>

bool file_exist(const char * file_name)
{
	return !access(file_name, 0);
}

int main()
{
	
	if (file_exist("plik1.txt"))
	{
		printf("Plik juz istnieje");
	}
	else 
	{
		FILE * file = fopen("plik1.txt", "w+");
		if ( file == NULL ) 
		{
			printf("Nie mozna utworzyc pliku!");
			return -1;
		}
		fclose(file);
		printf("Plik zostal utworzony");
	}
	
	return 0;
}