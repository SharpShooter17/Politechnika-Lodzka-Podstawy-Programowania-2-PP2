#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <io.h>

#define ERROR(STR) { printf("%s", STR); return -1; }

bool file_exist(const char * file_name)
{
	return !access(file_name, 0);
}

long long file_size( FILE * file )
{
	fpos_t len;
	fseek (file, 0, SEEK_END);
	fgetpos (file, &len);
	fseek(file, 0, SEEK_SET);
	
	return len;
}

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
	printf("Podaj plik zrodlowy: ");
	char * file_name_source = read();
	if ( !file_exist(file_name_source)) ERROR("Plik zrodlowy nie istnieje!");
	
	FILE * file_s = fopen(file_name_source, "rb");
	if (file_s == NULL) 
	{
		free(file_name_source);
		ERROR("Nie mozna otworzyc pliku zrodlowego!");
	}
	
	printf("Podaj plik docelowy: ");
	char * file_name_target = read();
	if ( file_exist(file_name_target)) 
	{
		free(file_name_source);
		free(file_name_target);
		fclose(file_s);
		ERROR("Plik docelowy o podanej nazwie istnieje!");
	}
	
	FILE * file_t = fopen(file_name_target, "wb");
	if (file_s == NULL) 
	{
		free(file_name_source);
		free(file_name_target);
		fclose(file_s);
		ERROR("Nie mozna otworzyc pliku docelowego!");
	}
	
	long long size = file_size(file_s);
	
	unsigned char * buffor;
	unsigned int buffor_size;
	
	if ( size < 1024*1024 ) buffor_size = 1024*256;
	else if ( size >= 1024*1024 && size < 1024*1024*1024 ) buffor_size = 1024*1024*4;
	else if ( size >= 1024*1024*1024 ) buffor_size = 1024*1024*64;
	
	buffor = (unsigned char*)malloc(buffor_size);
	if (buffor == NULL)
	{
		fclose(file_t);
		fclose(file_s);
	
		free(file_name_target);
		free(file_name_source);
		ERROR("Brak wystarczajacej pamieci RAM");
	}
	
	long long remained = size;
	
	while (remained > 0)
	{
		int read = fread((void*)buffor, sizeof(unsigned char), buffor_size, file_s);
		int saved = fwrite((void*)buffor, sizeof(unsigned char), read, file_t);
		remained -= saved;
	}
	
	fclose(file_t);
	fclose(file_s);
	
	free(file_name_target);
	free(file_name_source);
}
