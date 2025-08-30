#ifndef OUTPUTS_H
#define OUTPUTS_H

/*
*	prints results of equation
*	\param[in] toPrint Testdata structure with equation results and inputs
*/
void printSwitch(struct Testdata);
/*!
*	stores quadratic equation
*/
struct Coefficients {
	double a, b, c;
};
/*!
*	stores data for unit testing nRoots function, 1 struct = 1 test
*/
struct Testdata {
	struct Coefficients coefficients;
	int roots;
	double x1, x2;
};
#endif