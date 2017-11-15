#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char to_upper(char ch)
{
	int x = 'a' - 'A';
	if (ch >= 'a' && ch <= 'z')
		return ch - x;
	else
		return ch;
}

char to_down(char ch)
{
	int x = 'a' - 'A';
	if (ch < 'a' && ch >= 'A' && ch <= 'z')
		return ch + x;
	else
		return ch;
}

char space_to_dash(char ch)
{
	if (ch == ' ')
		return '-';
	else
		return ch;
}

void change(char * text, char(*func)(char))
{
	for (int i = 0; i < strlen(text); i++)
	{
		text[i] = func(text[i]);
	}
}

int main()
{
	char buffer[10] = "Troche to";

	change(buffer, space_to_dash);

	printf("%s\n", buffer);

	system("pause");
	return 0;
}
