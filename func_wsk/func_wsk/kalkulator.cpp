#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

enum OPERATION {ADD = '+',
				SUB = '-',
				MULT = '*', 
				DIV = '/',
};

double add(double a, double b) 
{
	return a + b;
}

double sub(double a, double b)
{
	return a - b;
}

double mul(double a, double b)
{
	return a * b;
}

double div(double a, double b)
{
	if (b == 0) return 0;
	return a / b;
}
double(*func)(double, double);

int main()
{
	int a, b;
	char op;

	scanf("%d %d %c", &a, &b, &op);

	switch ((OPERATION)op)
	{
	case ADD:
		func = add;
		break;
	case SUB:
		func = sub;
		break;
	case MULT:
		func = mul;
		break;
	case DIV:
		func = div;
		break;
	default:
		break;
	}

	printf("wynik: %f\n", func(a, b));
	system("Pause");
	return 0;
}