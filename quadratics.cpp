/*
	\file quadratics.cpp
	\brief квадратка
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>
/*!
scope of double comparison
*/
#define EPSILON 1e-5
/*!
different outputs for nRoots
*/
enum roots {SOLUTION_UNCOMPUTABLE = -2, INFINITE_SOLUTIONS = -1, NO_SOLUTIONS = 0, ONE = 1, TWO = 2};

int neighbouringZero(double n);
int nRoots(double a, double b, double c, double *x1, double *x2);
double adequacyCheck(double root);
int getInputNumber(double *n);
int doubleCompare(double a, double b);
void testNRoots();
int singularTestNRoots(struct testdata *data);

/*!
	Can solve a quadratic equation in stdin.
	You type in numbers on different lines and get the answer to your quadratic.
*/
int main(){
	#ifdef _DEBUG
	testNRoots();
	#endif
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

	printf("The inputed equation: (%lg)x^2 + (%lg)x + (%lg) = 0\n", a, b, c);
	switch (amount_roots){
		case INFINITE_SOLUTIONS:{
			printf("has infinite solutions: x can be any number\n");
			break;
		}
		case SOLUTION_UNCOMPUTABLE:{
			printf("is too complex: solution uncomputable\n");
			break;
		}
		case ONE:{
			printf("has 1 solution: %lg\n", x1);
			break;
		}
		case TWO:{
			printf("has 2 solutions: %lg, %lg\n", x1, x2);
			break;
		}
		default:{
			assert(amount_roots == NO_SOLUTIONS);
			printf("has no solutions. D < 0\n");
			break;
		}
	}
	printf("\n");
	return 1;
}


/*!
Used to get double numbers from input (terminal)
\param[out] n tries to write one double number from stdin into it
\return if no adequate number was received from stdin returns 0, otherwise 1 
*/
int getInputNumber(double *n){
	assert(n != NULL);

	char check = '\n';
	int amount = scanf("%lf%c", n, &check);

	if (check != '\n' || amount != 2){
		printf("Incorrect character \"%c\", try again\n", (check != '\n') ? check : ' ');
		check = ' ';
		while (check != '\n'){
			scanf("%c", &check);
		}
		return 0;
	}

	if (isnan(*n)){
		printf("Not a number, stop trying bozo\n");
		return 0;
	}

	if (*n == INFINITY){
		printf("number too large! try again\n");
		return 0;
	}

	printf("number accepted: (%lg)\n", *n);
	return 1;
}


/*!
Transforms negative zero into zero. Everything else is unchanged.
\param[in] root checks this
\return returns that
*/
double adequacyCheck(double root){
	return (neighbouringZero(root)) ? 0 : root;
}



/*!
solves quadratic equation, writes answers into pointers, returns root amount
\param[in] a coefficient а of a square polynomial
\param[in] b coefficient b of a square polynomial
\param[in] c coefficient c of a square polynomial
\param[out] x1 pointer for lesser root
\param[out] x2 pointer for larger root
\return int -2 through 2, amount of roots. -2: didn't compute; -1: infinite roots
*/
int nRoots(double a, double b, double c, double *x1, double *x2){
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

/*!
stores data for unit testing nRoots function, 1 struct = 1 test
*/
struct testdata {
	double a, b, c;
	int roots;
	double x1, x2;
};

/*!
unit test for nRoots, prints errors
*/
void testNRoots(){
	printf("Testing nRoots...");
	struct testdata tests[] = {
		{1, -5, 6, TWO, 2, 3},
		{1, -5, 30, NO_SOLUTIONS, 0, 0},
		{0, 0, 0, INFINITE_SOLUTIONS, 0, 0},
		{1, -3, 2, TWO, 1, 2},
		{1, -4, 4, ONE, 2, 2},
		{0, -4, 4, ONE, 1, 1},
		{0, 0, 4, NO_SOLUTIONS, 0, 0},
		{1e+307, 1e+307, 1e+307, SOLUTION_UNCOMPUTABLE, 0, 0},
		{1e+307, 1e+307, 4, SOLUTION_UNCOMPUTABLE, 0, 0},
	};

	int flag = 1;
	for (int i = 0; i < (int) (sizeof(tests) / sizeof(tests[0])); i++){
		flag = flag && singularTestNRoots(&tests[i]);
	}
	if (flag){
		printf("	no issues found.\n");
	} else {
		printf("\n");
	}
}


/*!
performs one test of nRoots function
\param[in] testdata structure containing test data, inputs, wanted outputs
\return 1 if no errors were found, 0 if there was an error
*/
int singularTestNRoots(struct testdata *data){
	int amountRoots = 0;
	double x1 = 0, x2 = 0;
	amountRoots = nRoots((*data).a, (*data).b, (*data).c, &x1, &x2);
	if (!(doubleCompare(amountRoots, (*data).roots) && doubleCompare(x1, (*data).x1) && doubleCompare(x2, (*data).x2))){
		printf(
			"FAIL: nRoots(%lg, %lg, %lg) should return %d; x1 = %lg; x2 = %lg;"
			" instead returns %d; x1 = %lg; x2 = %lg;\n",
			(*data).a,
			(*data).b,
			(*data).c,
			(*data).roots,
			(*data).x1,
			(*data).x2,
			amountRoots,
			x1,
			x2
		);
		return 0;
	}
	return 1;
}


/*!
compares double with zero
\param[in] n compares it with zero
\return if zero then 1 otherwize 0
*/
int neighbouringZero(double n){
	return (doubleCompare(n, 0));
}

/*!
compares two doubles
\param[in] a first
\param[in] b second
\return 1 if equal, otherwize 0
*/
int doubleCompare(double a, double b){
	return (fabs(a - b) <= EPSILON);
}