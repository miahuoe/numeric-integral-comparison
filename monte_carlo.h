#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

double monte_carlo_column(double, double, double (*)(double), unsigned, unsigned);

double monte_carlo_grid(double, double, double, double,
	double (*)(double), unsigned, unsigned, unsigned);

#endif
