#include <math.h>
#include "mathhelpers.h"

/*!
*	scope of double comparison
*/
#define EPSILON 1e-5

/*!
*	compares two doubles
*	\param[in] a first
*	\param[in] b second
*	\return 1 if equal, otherwize 0
*/
int doubleCompare(double a, double b){
	return (fabs(a - b) <= EPSILON);
}


/*!
*	compares double with zero
*	\param[in] n compares it with zero
*	\return if zero then 1 otherwize 0
*/
int neighbouringZero(double n){
	return (doubleCompare(n, 0));
}


/*!
*	Transforms negative zero into zero. Everything else is unchanged.
*	\param[in] root checks this
*	\return returns that
*/
double adequacyCheck(double root){
	return (neighbouringZero(root)) ? 0 : root;
}