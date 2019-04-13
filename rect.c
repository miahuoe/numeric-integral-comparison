/*
 * An implementation of rectangular methods of numeric integration.
 * Includes: left edge, middle, right edge.
 *
 * Author: Michał Czarnecki <czarnecky@va.pl>
 * Date: 2019-04-13
 */

#include "rect.h"

double rect_left(double a, double b, double (*f)(double), unsigned n)
{
	double S = 0.0, x, dx;

	dx = (b - a) / (double)n;
	x = a;
	while (n--) {
		S += f(x) * dx;
		x += dx;
	}
	return S;
}

double rect_middle(double a, double b, double (*f)(double), unsigned n)
{
	double S = 0.0, x, dx;

	dx = (b - a) / (double)n;
	x = a + dx * 0.5;
	while (n--) {
		S += f(x) * dx;
		x += dx;
	}
	return S;
}

double rect_right(double a, double b, double (*f)(double), unsigned n)
{
	double S = 0.0, x, dx;

	dx = (b - a) / (double)n;
	x = a + dx;
	while (n--) {
		S += f(x) * dx;
		x += dx;
	}
	return S;
}
