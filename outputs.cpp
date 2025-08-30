#include <stdio.h>
#include <assert.h>
#include "nRoots.h"
#include "outputs.h"


void printSwitch(struct Testdata toPrint){
	printf("The inputed equation: (%lg)x^2 + (%lg)x + (%lg) = 0\n", toPrint.coefficients.a, toPrint.coefficients.b, toPrint.coefficients.c);//TODO SDELAT' NOVUYU FUNCTIU
	switch (toPrint.roots){
		case INFINITE_SOLUTIONS:{
			printf("has infinite solutions: x can be any number\n");
			break;
		}
		case SOLUTION_UNCOMPUTABLE:{
			printf("is too complex: solution uncomputable\n");
			break;
		}
		case ONE:{
			printf("has 1 solution (approximation): %lf\n", toPrint.x1);
			break;
		}
		case TWO:{
			printf("has 2 solutions (approximations): %lf, %lf\n", toPrint.x1, toPrint.x2);
			break;
		}
		default:{
			assert(toPrint.roots == NO_SOLUTIONS);
			printf("has no solutions. D < 0\n");
			break;
		}
	}
}