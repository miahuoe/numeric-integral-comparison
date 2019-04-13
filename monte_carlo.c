/*
 * An implementation of Monte Carlo methods of numeric integration.
 *
 * Author: Michał Czarnecki <czarnecky@va.pl>
 * Date: 2019-04-13
 */

#include "random.h"

double monte_carlo_column(double a, double b, double (*f)(double), unsigned n, unsigned p)
{
	double S = 0.0, dx, ai, bi;
	unsigned i, j;

	dx = (b - a) / (double)n;
	ai = a;
	for (i = 0; i < n; i++) {
		bi = ai+dx;
		for (j = 0; j < p; j++) {
			S += f(random(ai, bi));
		}
		ai = bi;
	}
	S *= (b - a) / (double)(n*p);
	return S;
}

double monte_carlo_grid(double xa, double xb, double ya, double yb,
	double (*f)(double), unsigned gx, unsigned gy, unsigned s)
{
	unsigned i, j, k, hit = 0, shots = 0;
	double dx, dy, x = xa, y;

	dx = (xb - xa) / (double)gx;
	dy = (yb - ya) / (double)gy;

	for (i = 0; i < gx; i++) {
		y = ya;
		for (j = 0; j < gy; j++) {
			for (k = 0; k < s; k++) {
				hit += (random(y, y+dy) < f(random(x, x+dx)));
				shots++;
			}
			y += dy;
		}
		x += dx;
	}
	return ((double)hit / (double) shots) * (yb - ya) * (xb - xa);
}
