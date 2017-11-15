#include <fstream>
#include <vector>
#include <iostream>

float avg(float *p, unsigned n);

void zad_4()
{
	std::ifstream in("zad_4_data.txt");

	if (!in.is_open())
		return;

	std::vector<float> v;

	while (!in.eof())
	{
		float x;
		in >> x;
		v.push_back(x);
	}

	avg(&v[0], v.size());

	in.close();
}

float avg(float *p, unsigned n)
{
	float sum{ 0 };
	for (unsigned i = 0; i < n; i++)
	{
		sum += *p++;
	}
	std::cout << "Suma to: " << sum << " Srednia to: " << sum / n << std::endl;
	
	return sum / n;
}