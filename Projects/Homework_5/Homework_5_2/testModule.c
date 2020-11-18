#include <stdio.h>
#include "bracketBalance.h"

void runTestModule(void) {
	char stringOne[] = "(){}[]({[]})";
	char stringTwo[] = "f g s d";
	char wrongStringOne[] = ")(){}[]({[]})";
	char wrongStringTwo[] = "(){}[]({[]})(";
	char wrongStringThree[] = "(){}[]({[]})({)}";

	if (!checkBracketBalance(stringOne)) {
		printf("Test stringOne failed\n");
	}

	if (!checkBracketBalance(stringTwo)) {
		printf("Test stringTwo failed\n");
	}

	if (checkBracketBalance(wrongStringOne)) {
		printf("Test wrongStringOne failed\n");
	}

	if (checkBracketBalance(wrongStringTwo)) {
		printf("Test wrongStringTwo failed\n");
	}

	if (checkBracketBalance(wrongStringThree)) {
		printf("Test wrongStringThree failed\n");
	}
}