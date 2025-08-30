#include "inputs.h"

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "tests.h"


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

	if (isinf(*n)){
		printf("number is too large! try again\n");
		return 0;
	}

	printf("number accepted: (%lg)\n", *n);
	return 1;
}



int handleTerminalFlags(int argc, char *argv[]){
	int flag = 0;
	for (int i = 1; i < argc; i++){
		if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--test") == 0){
			i += 1;
			char str[] = "tests.txt";
			char *replacer = str;
			if (i == argc){
				testNRoots(replacer);
				break;
			}
			if (strstr(argv[i], ".txt") != NULL){
				replacer = argv[i];
				testNRoots(replacer);
			}
		} else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0){
			printf("Quadratic equation solver welcomes you! Here is list of commands:\n"
				   "-t [filename].txt | --test [filename].txt  performs unit tests. filename is optional.\n"
				   "--help  list all commands\n"
				   "-c calculate quadratic equation");
		} else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--calculate") == 0){
			flag = 1;
		}
	}
	return flag;
}