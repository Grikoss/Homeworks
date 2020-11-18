#include <stdio.h>
#include <stdlib.h>
#include "bracketBalance.h"
#include "testModule.h"

void main() {
	runTestModule();
	printf("Enter a expression: ");
	char string[100];
	fgets(string, sizeof(string), stdin);
	printf((checkBracketBalance(string)) ? "It's okey\n" : "It's not okey\n");
}