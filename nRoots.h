#ifndef N_ROOTS_H
#define N_ROOTS_H

enum roots {
	SOLUTION_UNCOMPUTABLE = -2,
	INFINITE_SOLUTIONS    = -1,
	NO_SOLUTIONS          = 0,
	ONE                   = 1,
	TWO                   = 2
};
int nRoots(double a, double b, double c, double *x1, double *x2);
void testNRoots();
int singularTestNRoots(struct testdata *data);
#endif // N_ROOTS_H