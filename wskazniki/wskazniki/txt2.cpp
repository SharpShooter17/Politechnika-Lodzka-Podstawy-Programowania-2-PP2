#include <iostream>

extern const char* t1;

unsigned int str_len(const char*p);

void txt2()
{
	std::cout << "Dl tekstu to: " << str_len(t1);
}

unsigned int str_len(const char*p)
{
	int n{ 0 };
	while (*(p + n) != '\0') n++;
	return n;
}