#include <stdio.h>
#include <stdlib.h>
#include "postfixCalculator.h"
#include "testModule.h"

void main() {
	runTestModule();
	printf("Enter a postfix expression:\n Example: (5 5 + 10 * 10 /)\n");
	char string[100];
	int result = 0;
	fgets(string, sizeof(string), stdin);
	if (postfixCalculator(&result, string) == 0) {
		printf("Result = %i\n", result);
	}
	else {
		printf("Invalid input\n");
	}
}