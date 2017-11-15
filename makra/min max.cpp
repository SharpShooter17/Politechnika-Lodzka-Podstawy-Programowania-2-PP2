#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define MIN3(a, b, c) ( MIN((a), (b)) < (c) ? MIN((a), (b)) : (c) )
#define MIN4(a, b, c, d) ( MIN3((a), (b), (c)) < (d) ? MIN3((a), (b), (c)) : (d) )
#define MIN5(a, b, c, d, e) ( MIN4((a), (b), (c), (d)) < (e) ? MIN4((a), (b), (c), (d)) : (e) )
#define MIN6(a, b, c, d, e, f) ( MIN5((a), (b), (c), (d), (e)) < (f) ? MIN5((a), (b), (c), (d), (e)) : (f) )

#define MAX(a, b) ( (a) > (b) ? (a) : (b) )
#define MAX3(a, b, c) ( MAX((a), (b)) > (c) ? MAX((a), (b)) : (c) )
#define MAX4(a, b, c, d) ( MAX3((a), (b), (c)) > (d) ? MAX3((a), (b), (c)) : (d) )
#define MAX5(a, b, c, d, e) ( MAX4((a), (b), (c), (d)) > (e) ? MAX4((a), (b), (c), (d)) : (e) )
#define MAX6(a, b, c, d, e, f) ( MAX5((a), (b), (c), (d), (e)) > (f) ? MAX5((a), (b), (c), (d), (e)) : (f) )

int main() 
{
	int a = 5, b = 8, c = 2;
	int x = MAX3(a, b, c);
	printf("%d\n", x);
	system("PAUSE");
	return 0;
}