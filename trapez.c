/*
 * An implementation of trapezoid method of numeric integration.
 *
 * Author: Michał Czarnecki <czarnecky@va.pl>
 * Date: 2019-04-13
 */

#include "trapez.h"

double trapezoid(double a, double b, double (*f)(double), unsigned n)
{
	double S = 0.0, x, dx, fa, fb;

	dx = (b - a) / (double)n;
	x = a;
	fa = f(x);
	while (n--) {
		x += dx;
		fb =  f(x);
		S += 0.5 * (fa + fb) * dx;
		fa = fb;
	}
	return S;
}
