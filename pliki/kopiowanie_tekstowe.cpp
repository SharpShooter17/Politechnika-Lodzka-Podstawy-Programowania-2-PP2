#include <stdio.h>

int main()
{
    FILE * fsource = fopen("source.txt", "r");
    if (fsource == NULL) return -1;

    FILE * ftarget = fopen("target.txt", "w");
    if(ftarget == NULL)
    {
        fclose(fsource);
        return -2;
    }

    int c = getc( fsource );
    while( c != EOF )
    {
        fprintf(ftarget, "%c", c);
        c = getc( fsource );
    }

    fclose(ftarget);
    fclose(fsource);

    return 0;
}
