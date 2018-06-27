#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstdlib>

int losuj()
{
	return std::rand();
}
int wyswietl(std::vector<double> & v) 
{
	for(int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ", ";
	}
}
int main() 
{
	//pomaga wygenerowac rozne liczby pseudolosowe - tak aby sie nie powtarzaly
	std::srand(std::time(NULL));
	//Liczba pseudolosowa
	int N = losuj() % 1000 + 1;
	//vektor - tablica  w której będzie ciag
	std::vector<double> ciag;
	
	//generowanie liczb pseudolosowych - ciagu
	for (int i = 0; i < N; i++) 
	{
		ciag.push_back(static_cast<double>(losuj())/1000.0);
	}
	std::cout << "N: " << N << std::endl;
	//funkcja pobierajaca wektor po przez referencje - 
	//nie trzeba wtedy kopiować element po elemencie(przekopiowanie w pamieci) 
	//tylko dane są pobierane z tego samego miejsca w pamieci.
	wyswietl(ciag);
	
	//znajdowanie podciagow
	std::cout << "Licze\n";	
	//wektor w wektorze - tablica dwuwymiarowa
	std::vector<int> rosnacy;
	std::vector<int> pomocny(ciag.size());
	rosnacy.push_back(0);
	int a, b;
	for (int i = 1; i < ciag.size(); i++) 
	{
		if (ciag[rosnacy[rosnacy.size()-1]] < ciag[i]) 
		{
			pomocny[i] = rosnacy[rosnacy.size()-1];
			rosnacy.push_back(i);
			continue;
		}
		
		for (a = 0, b = rosnacy.size()-1; a < b;)
		{
			int c = (a+b)/2;
			if (ciag[rosnacy[c]] < ciag[i])
			{
				a = c + 1;
			}
			else 
			{
				b = c;
			}
		}
		if (ciag[i] < ciag[rosnacy[a]])
		{
			if (a > 0)
			{
				pomocny[i] = rosnacy[a-1];
			}
			rosnacy[a] = i;
		}
	}
	for(a = rosnacy.size(), b = rosnacy[rosnacy.size()-1]; a--; b = pomocny[b])
	{
		rosnacy[a] = b;
	}
	
	std::cout << std::endl << "Najdluzszy podciag powyzszego ciagu\n";
	for (int i = 0; i < rosnacy.size(); i++)
	{
		std::cout << ciag[rosnacy[i]] << ", ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}