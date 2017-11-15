#include <stdio.h>
#include <stdlib.h>

void system(int dec, int sys) {
	if (dec == 0) return;
	system(dec / sys, sys);

	if (sys <= 10) 
	{
		printf("%d", dec % sys);
	}
	else
	{
		int var = dec % sys;
		if (var > 9) {
			var = 'A' + var - 10;
			printf("%c", var);
		}
		else
			printf("%d", dec % sys);
	}
}

int main()
{
	system(255, 16);
	printf("\n");
	system("pause");
	return 0;
}