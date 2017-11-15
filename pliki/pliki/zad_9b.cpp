#include <stdio.h>
#include <stdlib.h>

void zad_9b()
{
	FILE *file = fopen("zad_9a.txt", "r");
	if (file == nullptr) return;

	int count{ 0 };
	char c;

	while(!feof(file))
	{
		c = fgetc(file);
		if (c == '\n')
			count++;
		printf("%c", c);
	}

	printf("\nliczba tekstow to: %d ", count);

	fclose(file);

	system("pause");
}
