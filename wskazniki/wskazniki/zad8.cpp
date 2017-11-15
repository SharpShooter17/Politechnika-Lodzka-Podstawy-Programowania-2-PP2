#include <fstream>
#include <iostream>
#include <Windows.h>

void zad_8()
{
	int histogram[11]{ 0 };

	std::ifstream in("zad_8_data.txt");

	if (!in.is_open())
		return;

	while (!in.eof())
	{
		float i;
		in >> i;
		histogram[(int)i]++;
	}

	int max = histogram[0];

	for (int i = 1; i < 11; i++)
		max = (max < histogram[i]) ? histogram[i] : max;

	for (int i = 0; i < 11; i++)
	{
		COORD x;
		x.X = i * 7;
		x.Y = max + 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), x);
		std::cout << i;

		for (int j = 0; j < histogram[i];++j)
		{
			COORD c;
			c.X = i*7;
			c.Y = max - j;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
			std::cout << (char)219;
		}
	}

}
