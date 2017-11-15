#include <iostream>
#include <string>

int T[20] = { 64, 65, 67, 68, 69, 11, 12, 15 ,15 ,15, 97 ,512, 8,1,1,2,1, 9, 8, 9 };

void dump(unsigned char *w, int size)
{
	std::string str;
	for (int i = 0; i < size; ++i)
	{
		if ((i % 16) == 0)
		{
			if (i != 0)
				std::cout << "\t|" << str << "|" << std::endl;

			std::cout << std::dec << i << ":\t";
			str = "";
		}

		str += *w;
		printf("%.2x ", *w++);
	}

	std::cin.get();
	std::cin.get();
}