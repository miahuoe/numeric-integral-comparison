#include <stdio.h>
#include "monte_carlo.h"
#include "rect.h"

typedef struct {
	double a;
	double b;
	double (*f)(double);
	double y;
} int_test;

double f(double x)
{
	return x*x*x + 2;
}

int_test t[] = {
	{ 1.0, 5.0, f, 164.0 },
};

int main()
{
	for (size_t i = 0; i < sizeof(t)/sizeof(t[0]); i++) {
		printf("%.2f\n\t%.2f, %.2f, %.2f, %.2f\n",
			t[i].y,
			monte_carlo_column(t[i].a, t[i].b, t[i].f, 10, 4),
			monte_carlo_grid(t[i].a, t[i].b, t[i].f(t[i].a), t[i].f(t[i].b), f, 6, 6, 2),
			rect_left(t[i].a, t[i].b, t[i].f, 10),
			rect_right(t[i].a, t[i].b, t[i].f, 10)
		);
	}

	return 0;
}
