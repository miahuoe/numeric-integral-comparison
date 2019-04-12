#include "rect.h"

double rect_left(double a, double b, double (*f)(double), unsigned n)
{
	double S = 0.0, dx, x;
	unsigned i;

	dx = (b - a) / (double)n;
	x = a;

	for (i = 0; i < n; i++) {
		S += f(x) * dx;
		x += dx;
	}
	return S;
}

double rect_right(double a, double b, double (*f)(double), unsigned n)
{
	double S = 0.0, dx, x;
	unsigned i;

	dx = (b - a) / (double)n;
	x = a+dx;

	for (i = 0; i < n; i++) {
		S += f(x) * dx;
		x += dx;
	}
	return S;
}
