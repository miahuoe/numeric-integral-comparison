#ifndef INTEGRALS_H
#define INTEGRALS_H

#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif

#include <math.h>

/*
 * Definite integral: from, to, function, and true result
 */
typedef struct {
	double a;
	double b;
	double (*f)(double);
	double y;
} integral;

#define f_n(N) double f_ ## N (double);

f_n(0)
f_n(1)
f_n(2)
f_n(3)

#undef f_n

#endif
