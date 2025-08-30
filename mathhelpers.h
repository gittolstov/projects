#ifndef MATHHELPERS_H
#define MATHHELPERS_H

/*!
*	compares double with zero
*	\param[in] n compares it with zero
*	\return if zero then 1 otherwize 0
*/
int neighbouringZero(double n);
/*!
*	compares two doubles
*	\param[in] a first
*	\param[in] b second
*	\return 1 if equal, otherwize 0
*/
int doubleCompare(double a, double b);
/*!
*	Transforms negative zero into zero. Everything else is unchanged.
*	\param[in] root checks this
*	\return returns that
*/
double adequacyCheck(double root);
#endif