#ifndef N_ROOTS_H
#define N_ROOTS_H

enum roots {
	SOLUTION_UNCOMPUTABLE = -2,
	INFINITE_SOLUTIONS    = -1,
	NO_SOLUTIONS          = 0,
	ONE                   = 1,
	TWO                   = 2
};
/*!
*	solves quadratic equation, writes answers into pointers, returns root amount
*	\param[in] a coefficient а of a square polynomial
*	\param[in] b coefficient b of a square polynomial
*	\param[in] c coefficient c of a square polynomial
*	\param[out] x1 pointer for lesser root
*	\param[out] x2 pointer for larger root
*	\return int -2 through 2, amount of roots. -2: didn't compute; -1: infinite roots
*/
int nRoots(double a, double b, double c, double *x1, double *x2);
#endif // N_ROOTS_H