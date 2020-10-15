#include <stdio.h>
#include <stdlib.h>
#include "postfixCalculator.h"

void main() {
	printf("Enter a postfix expression:\n Exemple: (5 5 + 10 * 10 /)\n");
	char string[100];
	if (string == NULL) {
		return;
	}

	fgets(string, sizeof(string), stdin);
	int value = postfixCalculator(string);
	printf("%i\n", value);
	return;
}