#include <stdio.h>
#include <stdlib.h>
#include "testModule.h"
#include "marshallingYard.h"

void main() {
	runTestModule();
	printf("Enter a infix expression: ");
	char string[100];
	int result = 0;
	fgets(string, sizeof(string), stdin);
	char* output = marshallingYard(string);
	if (output == NULL) {
		printf("Invalid input\n");
	}
	else {
		printf("Result: ");
		puts(output);
		free(output);
	}
}