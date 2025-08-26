#include "inputs.h"

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*!
*	Used to get double numbers from input (terminal)
*	\param[out] n tries to write one double number from stdin into it
*	\return if no adequate number was received from stdin returns 0, otherwise 1
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
*	finds first .txt argument
*	\param[in] argc amount of args
*	\param[in] argv args
*	\param[in] limit - max len str
*	\param[out] str here be .txt
*/
int getTerminalAddressText(int argc, char *argv[], int limit, char str[]){
	for (int i = 0; i < argc; i++){
		if (strstr(argv[i], ".txt") != NULL){
			if ((int) strlen(argv[i]) >= limit){
				printf("file name too big: %s\n", argv[i]);
				return 0;
			}
			strcpy(str, argv[i]);
			return 1;
		}
	}
	return 0;
}