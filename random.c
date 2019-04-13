/*
 * An implementation of random function.
 * Returns a random double from given range.
 *
 * On linux it uses random bytes from auxiliary vector.
 * time() ticks every second, so if one runs programs faster,
 * then one gets the same random numbers. Seeding using auxiliary
 * vector random bytes solves this problem.
 *
 * Author: Michał Czarnecki <czarnecky@va.pl>
 * Date: 2019-04-13
 */

/*
 * TODO increase resolution. RAND_MAX is usually 2^16-1 or something like that.
 */

#include "random.h"

#ifdef __linux__

double random(double a, double b)
{
	static _Bool seeded = 0;
	unsigned long max = RAND_MAX, r, seed, i;
	double R;
	unsigned char *auxrandom;

	if (!seeded) {
		seeded = 1;
		auxrandom = (unsigned char*)getauxval(25);
		seed = 0;
		for (i = 0; i < 8; i++) {
			seed <<= 8;
			seed |= auxrandom[i];
		}
		srand(seed);
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

