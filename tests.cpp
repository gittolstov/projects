#include "nRoots.h"
#include "mathhelpers.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "tests.h"
#include "outputs.h"



int readTestdata(FILE *stream, struct Testdata *toChange){
	double a = NAN, b = NAN, c = NAN;
	int roots = 0;
	double x1 = NAN, x2 = NAN;
	if (fscanf(stream, "%lg %lg %lg %d %lg %lg ", &a, &b, &c, &roots, &x1, &x2) == EOF){
		*toChange = {{a, b, c}, roots, x1, x2};
		return 0;
	}
	*toChange = {{a, b, c}, roots, x1, x2};
	return 1;
}


int singularTestNRoots(struct Testdata *data){
	int amountRoots = 0;
	double x1 = 0, x2 = 0;
	amountRoots = nRoots((*data).coefficients.a, (*data).coefficients.b, (*data).coefficients.c, &x1, &x2);
	if (!(doubleCompare(amountRoots, (*data).roots) && doubleCompare(x1, (*data).x1) && doubleCompare(x2, (*data).x2))){
		printf(
			"FAIL: nRoots(%lg, %lg, %lg) should return %d; ",
			(*data).coefficients.a,
			(*data).coefficients.b,
			(*data).coefficients.c,
			(*data).roots
		);
		switch ((*data).roots)
		{
			case 2:
				printf("x1 = %lg; x2 = %lg; instead returns %d; x1 = %lg; x2 = %lg;\n", (*data).x1, (*data).x2, amountRoots, x1, x2);
				break;
			case 1:
				printf("x1 = %lg; instead returns %d; x1 = %lg;\n", (*data).x1, amountRoots, x1);
				break;
			default:
				printf("instead returns %d;\n", amountRoots);
				break;
		}
		return 0;
	}
	printf("test successful\n");
	return 1;
}


void testNRoots(const char address[]){
	printf("Testing nRoots...\n");

	FILE *file = fopen(address, "r");
	if (file == NULL){
		fprintf(stderr, "testNRoots encountered address issue with file '%s'", address);
		perror("");
		return;
	}
	printf("successfully opened %s\n", address);
	int flag = 1, i = 0, failed = 0;
	while (1){
		struct Testdata test = {};
		if (!readTestdata(file, &test)){
			break;
		}
		printf("%d. ", i + 1);
		int currentTestResult = singularTestNRoots(&test);
		flag = currentTestResult && flag;
		failed += !currentTestResult;
		i++;
	}
	fclose(file);
	if (flag){
		printf("no issues found.\n");
	} else {
		printf("failed %d tests out of %d\n", failed, i);
	}
}