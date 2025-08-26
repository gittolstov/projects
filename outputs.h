#ifndef OUTPUTS_H
#define OUTPUTS_H

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