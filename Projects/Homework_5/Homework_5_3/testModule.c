#include <stdio.h>
#include "postfixCalculator.h"

void runTestModule(void) {
	char string[] = "-558 67655 - -10 * 10 /";
	char wrongStringOne[] = "f g s d";
	char wrongStringTwo[] = "5 +";
	char wrongStringThree[] = "5 5 / /";
	int result = 0;
	if (postfixCalculator(&result, string) != 0) {
		printf("Test on standart input failed\n");
		printf("Result = %i\n", result);
	}

	if (postfixCalculator(&result, wrongStringOne) == 0) {
		printf("Test one on invalid input failed\n");
		printf("Result = %i\n", result);
	}

	if (postfixCalculator(&result, wrongStringTwo) == 0) {
		printf("Test two on invalid input failed\n");
		printf("Result = %i\n", result);
	}

	if (postfixCalculator(&result, wrongStringThree) == 0) {
		printf("Test three on invalid input failed\n");
		printf("Result = %i\n", result);
	}
};
