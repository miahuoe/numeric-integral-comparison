#include "integrals.h"

integral I[] = {
	[0] = { 1.0, 5.0, f_0, 164.0 },
	[1] = { 0.0, M_PI, f_1, 2.0 },
};

int I_len = sizeof(I)/sizeof(I[0]);

double f_0(double x)
{
	return x*x*x + 2;
}

double f_1(double x)
{
	return sin(x);
}
