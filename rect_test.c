#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "rect.h"
#include "integrals.h"

extern integral I[];
extern int I_len;

int main()
{
	int i, e;
	unsigned n;
	FILE *f;
	char fname[100];

	for (i = 0; i < I_len; i++) {
		snprintf(fname, sizeof(fname), "rect_test_f_%d.csv", i);
		f = fopen(fname, "w");
		if (!f) {
			e = errno;
			fprintf(stderr, "%s: error: %s\n", fname, strerror(e));
			continue;
		}
		printf("%s\n", fname);
		fprintf(f, "n,left,middle,right\n");
		for (n = 1; n <= 100; n++) {
			fprintf(f, "%u,%f,%f,%f\n",
				n,
				rect_left(I[i].a, I[i].b, I[i].f, n),
				rect_middle(I[i].a, I[i].b, I[i].f, n),
				rect_right(I[i].a, I[i].b, I[i].f, n)
			);
		}
		fclose(f);
	}

	return 0;
}
