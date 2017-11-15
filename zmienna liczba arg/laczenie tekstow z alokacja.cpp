#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

char *link(int N, ...)
{
	va_list ap;
	va_start(ap, N);

	const char * temp = va_arg(ap, char*);
	unsigned int size = strlen(temp) + 1;
	char * res = (char*)malloc(sizeof(char)*size);
	if (res == nullptr) return nullptr;
	strcpy(res, temp);

	for (int i = 1; i < N; i++)
	{
		temp = va_arg(ap, const char*);
		size += strlen(temp);
		char * tmp = (char*)realloc(res, size*sizeof(char));
		if (tmp == nullptr) return nullptr;
		res = tmp;
		strcat(res, temp);
	}

	va_end(ap);
	return res;
}

int main()
{
	char *text;
	text = link(7, "Ala ", "ma ", "kota ", "a ", "kot ", "ma ", "Ale.");
	printf("%s\n", text);
	free(text);
	system("pause");
	return 0;
}
