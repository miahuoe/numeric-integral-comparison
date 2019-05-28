#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "rect.h"
#include "trapez.h"
#include "integrals.h"

extern integral I[];
extern int I_len;

_Bool close_enough(int n, double values[n], double ref, double precision)
{
	int i;

	for (i = 0; i < n; i++) {
		if (fabs(values[i] - ref) > precision) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i, e;
	unsigned n;
	FILE *f;
	char fname[100];
	double values[4];
	int nvalues = sizeof(values)/sizeof(values[0]);
	double precision = 0.025;

	for (i = 0; i < I_len; i++) {
		snprintf(fname, sizeof(fname), "rect_test_f_%d.csv", i);
		f = fopen(fname, "w");
		if (!f) {
			e = errno;
			fprintf(stderr, "%s: error: %s\n", fname, strerror(e));
			continue;
		}
		printf("%s\n", fname);
		fprintf(f, "n,true,left,middle,right,trapez\n");
		for (n = 1; n <= 100; n++) {

			values[0] = rect_left(I[i].a, I[i].b, I[i].f, n);
			values[1] = rect_middle(I[i].a, I[i].b, I[i].f, n);
			values[2] = rect_right(I[i].a, I[i].b, I[i].f, n);
			values[3] = trapezoid(I[i].a, I[i].b, I[i].f, n);

			fprintf(f, "%u,%f,%f,%f,%f,%f\n",
				n, I[i].y,
				values[0], values[1],
				values[2], values[3]
			);

			if (close_enough(nvalues, values, I[i].y, precision)) {
				break;
			}
		}
		fclose(f);
	}
	return 0;
}
