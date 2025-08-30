#include <math.h>
#include "mathhelpers.h"

/*!
*	scope of double comparison
*/
#define EPSILON 1e-5


int doubleCompare(double a, double b){
	return (fabs(a - b) <= EPSILON);
}


int neighbouringZero(double n){
	return (doubleCompare(n, 0));
}


double adequacyCheck(double root){
	return (neighbouringZero(root)) ? 0 : root;
}