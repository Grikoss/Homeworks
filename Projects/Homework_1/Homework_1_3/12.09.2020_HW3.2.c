#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool balanceOfParentheses(char parentheses[], int length) {
	int counter = 0;
	for (int i = 0; i < (length - 1); ++i) {
		if (parentheses[i] == '(') {
			++counter;
		}

		if (parentheses[i] == ')') {
			--counter;
		}

		if (counter < 0) {
			return false;
		}
	}

	if (counter != 0) {
		return false;
	}

	return true;
}

void main() {
	printf("Enter some string\n");
	char parentheses[100];
	fgets(parentheses, sizeof(parentheses), stdin);
	printf("Balance of parentheses: ");
	const bool balance = balanceOfParentheses(parentheses, strlen(parentheses));
	if (!balance) {
		printf("false");
	}
	else {
		printf("true");
	}
}