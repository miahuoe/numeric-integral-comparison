#ifndef INTEGRALS_H
#define INTEGRALS_H

/*
 * Definite integral: from, to, function, and true result
 */
typedef struct {
	double a;
	double b;
	double (*f)(double);
	double y;
} integral;

double f_0(double);

#endif
