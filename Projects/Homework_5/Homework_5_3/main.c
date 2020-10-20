#include <stdio.h>
#include <stdlib.h>
#include "postfixCalculator.h"

void main() {
	postfixCalculator("5", true);
	printf("Enter a postfix expression:\n Example: (5 5 + 10 * 10 /)\n");
	char string[100];
	if (string == NULL) {
		return;
	}

	fgets(string, sizeof(string), stdin);
	int value = postfixCalculator(string, false);
	printf("Result = %i\n", value);
	return;
}