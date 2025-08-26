#include "mathhelpers.h"
#include "nRoots.h"
#include <math.h>
#include <stdio.h>
#define BREAK_EVERY_TEST 0//change to 1 to test the unit tests

/*!
*	solves quadratic equation, writes answers into pointers, returns root amount
*	\param[in] a coefficient а of a square polynomial
*	\param[in] b coefficient b of a square polynomial
*	\param[in] c coefficient c of a square polynomial
*	\param[out] x1 pointer for lesser root
*	\param[out] x2 pointer for larger root
*	\return int -2 through 2, amount of roots. -2: didn't compute; -1: infinite roots
*/
int nRoots(double a, double b, double c, double *x1, double *x2){
	double discriminant = NAN;
	if (neighbouringZero(a)){
		if (neighbouringZero(b)){
			*x1 = *x2 = 0;
			if (neighbouringZero(c)){// x is anything
				return INFINITE_SOLUTIONS + BREAK_EVERY_TEST;
			}
			return NO_SOLUTIONS + BREAK_EVERY_TEST;
		}

		*x1 = *x2 = adequacyCheck(-c / b);
		return ONE + BREAK_EVERY_TEST;
	}

	discriminant = b * b - 4 * a * c;
	if (isnan(discriminant)){
		*x1 = *x2 = 0;
		return SOLUTION_UNCOMPUTABLE + BREAK_EVERY_TEST;
	}

	if (neighbouringZero(discriminant)){
		*x1 = *x2 = adequacyCheck(-b / (2 * a));
		return ONE + BREAK_EVERY_TEST;
	}

	if (discriminant < 0){
		*x1 = *x2 = 0;
		return NO_SOLUTIONS + BREAK_EVERY_TEST;
	}
	*x1 = adequacyCheck((-b - sqrt(discriminant)) / (2 * a));
	*x2 = adequacyCheck((-b + sqrt(discriminant)) / (2 * a));
	if (fabs(*x1) == INFINITY || fabs(*x2) == INFINITY){
		*x1 = *x2 = 0;
		return SOLUTION_UNCOMPUTABLE + BREAK_EVERY_TEST;
	}
	return TWO + BREAK_EVERY_TEST;
}