#include "random.h"

#ifdef __linux__

double random(double a, double b)
{
	static _Bool seeded = 0;
	unsigned long max = RAND_MAX, r, rr[2], i;
	double R;
	unsigned char *auxrandom;

	if (!seeded) {
		seeded = 1;
		auxrandom = (unsigned char*)getauxval(25);
		rr[0] = rr[1] = 0;
		for (i = 0; i < 8; i++) {
			rr[0] <<= 8;
			rr[0] |= auxrandom[i];
			rr[1] <<= 8;
			rr[1] |= auxrandom[8+i];
		}
		srand(time(0) * rr[0] + rr[1]); // TODO
	}
	r = rand() % (max + 1);
	R = (double)r / (double)max;
	return (b - a) * R + a;
}

#else

double random(double a, double b)
{
	static _Bool seeded = 0;
	unsigned long max = RAND_MAX, r;
	double R;

	if (!seeded) {
		seeded = 1;
		srand(time(0));
	}
	r = rand() % (max + 1);
	R = (double)r / (double)max;
	return (b - a) * R + a;
}

#endif

