#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

struct polynomial_t {
	unsigned int power;
	double * x;
};

polynomial_t * create_polynomial(int power, ...)
{
	polynomial_t * res = (polynomial_t*)malloc(sizeof(polynomial_t));
	if (res == nullptr) return nullptr;

	res->x = (double*)malloc(sizeof(double)*(power+1));
	if (res->x == nullptr) {
		free(res);
		return nullptr;
	}

	res->power = power;

	va_list ap;
	va_start(ap, power);

	for (int i = 0; i < (power + 1); i++) {
		double x = va_arg(ap, double);
		res->x[i] = x;
	}

	va_end(ap);
	return res;
}

double poly_calc(polynomial_t *poly, double x)
{
	double res = 0;
	for (int i = 0; i < (poly->power + 1); i++)
		res += ( poly->x[i] * pow(x, poly->power-i) );
	
	return res;
}

void free_polynomial(polynomial_t * poly)
{
	free(poly->x);
	free(poly);
}

int main()
{
	polynomial_t * poly = create_polynomial(2, 2.0, 0.0, 1.0);
	printf("%f\n", poly_calc(poly, 5));
	free_polynomial(poly);

	system("pause");
	return 0;
}
