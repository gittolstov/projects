#include "mathhelpers.h"
#include "nRoots.h"
#include <math.h>
#include <stdio.h>
#define BREAK_EVERY_TEST 0//change to 1 to test the unit tests

int nRoots(double a, double b, double c, double *x1, double *x2){
	if (BREAK_EVERY_TEST)
		return 3;
	double discriminant = NAN;
	if (neighbouringZero(a)){
		if (neighbouringZero(b)){
			*x1 = *x2 = 0;
			if (neighbouringZero(c)){// x is anything
				return INFINITE_SOLUTIONS;
			}
			return NO_SOLUTIONS;
		}

		*x1 = *x2 = adequacyCheck(-c / b);
		return ONE;
	}

	discriminant = b * b - 4 * a * c;
	if (isnan(discriminant)){
		*x1 = *x2 = 0;
		return SOLUTION_UNCOMPUTABLE;
	}

	if (neighbouringZero(discriminant)){
		*x1 = *x2 = adequacyCheck(-b / (2 * a));
		return ONE;
	}

	if (discriminant < 0){
		*x1 = *x2 = 0;
		return NO_SOLUTIONS;
	}
	*x1 = adequacyCheck((-b - sqrt(discriminant)) / (2 * a));
	*x2 = adequacyCheck((-b + sqrt(discriminant)) / (2 * a));
	if (fabs(*x1) == INFINITY || fabs(*x2) == INFINITY){
		*x1 = *x2 = 0;
		return SOLUTION_UNCOMPUTABLE;
	}
	return TWO;
}