#include "integrals.h"

integral I[] = {
	[0] = { 1.0, 5.0, f_0, 164.0 },
	[1] = { 0.0, M_PI, f_1, 2.0 },
	[2] = { 0.0, 1.0, f_2, 18.391 },
	[3] = { 0.0, 10.0*M_E, f_3, 23.4392 },
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

double f_2(double x)
{
	return 100.0 * sin(x * 10.0);
}

double f_3(double x)
{
	return pow(M_E, -1.0 / x);
}
