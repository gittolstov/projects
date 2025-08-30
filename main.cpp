/*
*	\brief квадратка
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "mathhelpers.h"
#include "nRoots.h"
#include "inputs.h"
#include "outputs.h"

/*!
*	Can solve a quadratic equation in stdin.
*	Required flag: -c
*	You type in numbers on different lines and get the answer to your quadratic.
*/
int main(int argc, char *argv[]){
	char test[4] = "abc";
	test[3] = 'd';
	printf("Мяу!\n");
	const char *address = "tests.txt";
	if (!handleTerminalFlags(argc, argv)){
		return 0;
	}
	double a = NAN, b = NAN, c = NAN;
	double *list[] = {&a, &b, &c};
	int i = 0;
	printf("Input a, b, c coefficients of a quadratic equation on separate lines\n1\n-4\n4\n^like this. It would mean x^2 - 4x + 4 = 0\n");
	while (i < 3){
		if (getInputNumber(list[i])){//if number is received -> TRUE
			i++;
		}
	}

	int amount_roots = 0;
	double x1 = NAN, x2 = NAN;
	amount_roots = nRoots(a, b, c, &x1, &x2);
	assert(!isnan(x1));
	assert(!isnan(x2));
	struct Testdata toPrint = {{a, b, c}, amount_roots, x1, x2};
	printSwitch(toPrint);
	printf("\nCOMMIT GITHUB\n");
	return 1;
}