#include <stdio.h>
#include "random.h"

double monte_carlo_a(double a, double b, double (*f)(double), unsigned n, unsigned p)
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

double monte_carlo_b(double xa, double xb, double ya, double yb,
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

double monte_carlo_c(double xa, double xb, double ya, double yb,
	double (*f)(double), unsigned shots)
{
	unsigned hit = 0, s = shots;

	while (s--) {
		if (random(ya, yb) < f(random(xa, xb))) {
			hit++;
		}
	}
	return ((double)hit / (double) shots) * (yb - ya) * (xb - xa);
}

double f(double x)
{
	return x*x*x + 2;
}

int main()
{
	double ia = monte_carlo_a(1.0, 5.0, f, 10, 4);
	double ib = monte_carlo_b(1.0, 5.0, f(1.0), f(5.0), f, 6, 6, 2);
	double ic = monte_carlo_c(1.0, 5.0, f(1.0), f(5.0), f, 100);
	printf("%.2f, %.2f, %.2f\n", ia, ib, ic);
	return 0;
}
