#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define ASSERT( WARUNEK, ERROR ) { if ( WARUNEK != true ){ printf("Error: %s, in file: %s, in line: %d\n", ERROR, __FILE__, __LINE__); system("pause"); exit(-1); } }

bool create_file(const char * file_name)
{
	FILE * file = fopen(file_name, "w+");
	if (file == nullptr) return false;

	fclose(file);
	return true;
}

int main()
{
	char * buffer = (char*)alloca(6);
	char * buffer1 = (char*)alloca(32);
	
	for (int i = 0; i < 10; i++)
	{
		sprintf(buffer, "file%d", i);
		sprintf(buffer1, "Can not create file: %s", buffer);
		ASSERT(create_file(buffer), buffer1);
	}

	system("pause");
	return 0;
}