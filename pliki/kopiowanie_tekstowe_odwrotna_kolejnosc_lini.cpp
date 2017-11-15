#include <stdio.h>
#include <malloc.h>

long long file_size(FILE * file)
{
	fpos_t len;
	fseek(file, 0, SEEK_END);
	fgetpos(file, &len);
	fseek(file, 0, SEEK_SET);

	return len;
}

char * read_line(FILE * file)
{
	char * res;
	char c = fgetc(file);
	unsigned short len = 1;

	res = (char*)malloc(sizeof(char));
	if (res == NULL) return NULL;
	res[len - 1] = c;

	while (c != '\n' && c != EOF)
	{
		c = fgetc(file);
		char *tmp = (char*)realloc(res, ++len * sizeof(char));
		if (tmp == NULL) { free(res);  return NULL; }
		res = tmp;
		res[len - 1] = c;
	}

	char *tmp = (char*)realloc(res, ++len * sizeof(char));
	if (tmp == NULL) { free(res);  return NULL; }
	res = tmp;
	res[len - 1] = '\0';

	return res;
}

int main()
{
	FILE * fsource = fopen("source.txt", "r");
	if (fsource == NULL) return -1;

	FILE * ftarget = fopen("target.txt", "w");
	if (ftarget == NULL)
	{
		fclose(fsource);
		return -2;
	}

	long long size = file_size(fsource);

	char ** plik = (char**)malloc(sizeof(char*));

	char * c = read_line(fsource);

	int it = 0;

	while (*c != 'ÿ')
	{
		if (c == NULL)
		{
			fclose(ftarget);
			fclose(fsource);
		}
		plik[it++] = c;

		char ** tmp = (char**)realloc(plik, (it+1) * sizeof(char*));
		if (tmp == NULL)
		{
			for (int i = 0; i < it - 1; i++)
			{
				free(plik[i]);
			}
			free(plik);
			if (c != NULL) free(c);
			fclose(ftarget);
			fclose(fsource);
			return -1;
		}
		plik = tmp;

		c = read_line(fsource);
	}

	for (int i = it - 1; i >= 0; --i)
	{
		fprintf(ftarget, "%s", plik[i]);
	}

	for (int i = 0; i < it - 1; i++)
	{
		free(plik[i]);
	}
	free(plik);

	if (c != NULL) free(c);

	fclose(ftarget);
	fclose(fsource);

	return 0;
}
