#include <iostream>

extern const char* t1;

void count(const char *p, int * const small, int * const big, int * const white);

void txt3()
{
	int small, big, white;
	count(t1, &small, &big, &white);

	std::cout << "Male znaki: " << small << " duze znaki: " << big << " spacje: " << white;
}

void count(const char *p, int * const small, int * const big, int * const white)
{
	*small = *big = *white = 0;

	int i = 0;
	while (*(p + i) != '\0')
	{
		char c = *(p + i);

		if ((c <= 'Z') && (c >= 'A'))
		{
			*big+=1;
		}
		else if ((c <= 'z') && (c >= 'a'))
		{
			*small+=1;
		}
		else if (c == ' ')
		{
			*white+=1;
		}

		i++;
	}

}