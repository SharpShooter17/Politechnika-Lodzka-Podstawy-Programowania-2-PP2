#include <stdio.h>
#include <stdlib.h>

int main() 
{
	printf("Data kompilacji: %s czas kompilacji: %s\n", __DATE__, __TIME__);
	printf("Plik: %s, linia: %d", __FILE__, __LINE__);

	system("PAUSE");
	return 0;
}