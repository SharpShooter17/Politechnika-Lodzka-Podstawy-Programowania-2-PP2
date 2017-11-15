#include <iostream>

extern const char* t1;

char * change(const char * str);

void txt10()
{
	char *p = change(t1);
	std::cout << p;
	free(p);
}

char * change(const char * str)
{
	int n{ 0 };
	char * res = (char*)malloc((strlen(str)+1)*sizeof(char));
	strcpy(res, str);

	while (*(res + n) != '\0')
	{
		if (*(res + n) == ' ')
		{
			memset( &*(res+n), '_', 1);
		}
		n++;
	}

	return res;
}