#include <stdio.h>
#include <stdlib.h>
#include "marshallingYard.h"

void runTestModule(void) {
	char string[] = "(1 + 1 ) * 2 - 4+5+4 + 3 *() 10";
	char* output = marshallingYard(string);
	if (output == NULL) {
		printf("Test on standart input failed\n");
	}
	else {
		free(output);
	}

	char wrongStringOne[] = "((1 + 1) * 2 - 4 + 5 + 4 + 3 * 10";
	output = marshallingYard(wrongStringOne);
	if (output != NULL) {
		printf("Test one on invalid input failed\n");
		free(output);
	}

	char wrongStringTwo[] = "(1 + 1) * 2 - 4 + 5 + 4 + 3 * 10)";
	output = marshallingYard(wrongStringTwo);
	if (output != NULL) {
		printf("Test two on invalid input failed\n");
		free(output);
	}

	char wrongStringThree[] = "(1 + 1) * 2 - 4 + 5 + 4 + 3 * 10 -";
	output = marshallingYard(wrongStringThree);
	if (output != NULL) {
		free(output);
	}
	else {
		printf("Test three on invalid input failed\n");
	}

	char wrongStringFour[] = "(1 + 1) * 2 - 4 + 5 5+ 4 + 3 * 10 -";
	output = marshallingYard(wrongStringFour);
	if (output != NULL) {
		free(output);
	}
	else {
		printf("Test four on invalid input failed\n");
	}
}