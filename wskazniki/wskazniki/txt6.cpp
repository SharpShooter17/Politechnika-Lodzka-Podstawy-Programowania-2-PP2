#include <iostream>

namespace my
{
	char *strcat(char* strTo, const char* strFrom, char ending_char = '\0');
	char *strcpy(char* To, const char* From, char ending_char = '\0');
	int strlen(const char *str, char ending_char = '\0');
}

void txt6()
{
	const char * t = "some text";
	char x[9 + 1 + 10];
	my::strcpy(x, t);
	std::cout << x << " dl: " << my::strlen(x) << std::endl;
	std::cout << "strcat: " << my::strcat(x, t); 
	std::cout << " dl: " << my::strlen(x);;
}

namespace my
{
	char *strcat(char* strTo, const char* strFrom, char ending_char)
	{
		int i{ 0 };
		int len = my::strlen(strTo);

		do
		{
			*(strTo + len + i) = *(strFrom + i);
			i++;
		} while (*(strFrom + i - 1) != ending_char);

		return strTo;
	}

	int strlen(const char *str, char ending_char)
	{
		int n{ 0 };
		while (*(str + n) != ending_char) n++;
		return n;
	}

	char * strcpy(char * To, const char * From, char ending_char)
	{
		int i = 0;
		do
		{
			*(To + i) = *(From + i);
			++i;
		} while ( *(From + i - 1) != ending_char );

		return To;
	}
}