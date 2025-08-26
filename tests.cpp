#include "nRoots.h"
#include "mathhelpers.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "tests.h"
#include "outputs.h"



/*!
*	reads single Testdata structure
*	\param[in] stream where the data is taken from
*	\param[out] Testdata structure with numbers or NAN if EOF
*	\returns 1 if successful, else 0
*/
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


/*!
*	performs one test of nRoots function
*	\param[in] Testdata structure containing test data, inputs, wanted outputs
*	\return 1 if no errors were found, 0 if there was an error
*/
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


/*!
*	unit test for nRoots, prints errors. SIZE max tests
*	\param[in] address - string with address to file with testdata
*/
void testNRoots(char address[]){
	printf("Testing nRoots...\n");

	FILE *file = fopen(address, "r");
	if (file == NULL){
		if ((int) strlen(address) > 100){
			perror("testNRoots encountered address issue");
			return;
		}
		char a[150];
		sprintf(a, "testNRoots encountered address issue with file '%s'", address);
		perror(a);
		return;
	}
	printf("successfully opened %s\n", address);
	const int SIZE = 30;
	struct Testdata tests[SIZE];
	int flag = 1, i = 0;
	while (i < SIZE){
		if (!readTestdata(file, &tests[i])){
			break;
		}
		printf("%d. ", i);
		flag = singularTestNRoots(&tests[i]) && flag;
		i++;
	}
	fclose(file);
	if (flag){
		printf("no issues found.\n");
	}
}