
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <varargs.h>

bool file_exist(const char * file_name)
{
	return !_access(file_name, 0);
}

void files_exist(const char *  str, ...)
{
	va_list ap;
	va_start(ap, str);
	va_arg(ap, const char *);

	while (str != nullptr)
	{
		if (file_exist(str))
		{
			printf("Plik o nazwie : %s istnieje.\n", str);
		}
		else
		{
			printf("Plik o nazwie : %s nie istnieje.\n", str);
		}
		str = va_arg(ap, const char *);
	}

	va_end(ap);
}

int main()
{
	files_exist("Source.cpp", "plik.txt", "xyz", nullptr);

	system("pause");
	return 0;
}