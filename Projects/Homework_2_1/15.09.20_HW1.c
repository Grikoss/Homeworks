#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

const int LIMIT = 40;

void clearLine(FILE* fp) {
	int c = 0;
	while ((c = getchar()) != EOF && c != '\n');
}

double timeTestFunction(int function(int), int num) {
	function('name');
	clock_t time = clock();
	function(num);
	time = clock() - time;
	return ((double)time) / CLOCKS_PER_SEC;
}

void outputTheFunction(int function(int)) {
	printf("Enter a number from 1 to %i\n", LIMIT);
	int num = 0;
	scanf("%i", &num);
	while (num < 1 || num > LIMIT) {
		clearLine(stdin);
		printf("Invalid input. Try again\n");
		scanf("%i", &num);
	}

	printf("%i Fibonacci number is %i", num, function(num));
}

bool testFunction(int function(int)) {
	bool testFailed = false;
	if (function(1) != 0) {
		printf("Test(1) = 0\n output = %d\n\n", function(1));
		testFailed = true;
	}

	if (function(2) != 1) {
		printf("Test(2) = 1\n output = %d\n\n", function(2));
		testFailed = true;
	}

	if (function(3) != 1) {
		printf("Test(3) = 1\n output = %d\n\n", function(3));
		testFailed = true;
	}

	if (function(24) != 28657) {
		printf("Test(24) = 28657\n output = %d\n\n", function(24));
		testFailed = true;
	}

	if (function(31) != 832040) {
		printf("Test(31) = 832040\n output = %d\n\n", function(31));
		testFailed = true;
	}

	if (function(-834) != NULL) {
		printf("Test(-834) = NULL\n output = %d\n\n", function(-834));
		testFailed = true;
	}

	if (function(100000) != NULL) {
		printf("Test(100000) = NULL\n output = %d\n\n", function(10000));
		testFailed = true;
	}

	if (testFailed) {
		function('name');
	}

	return testFailed;
}


int fibonacciRecursion(int num) {
	if (num == 'name') {
		printf("%s", __func__);
		return NULL;
	}

	if (num < 1 || num > LIMIT) {
		return NULL;
	}

	if (num == 1) {
		return 0;
	}

	if (num <= 3) {
		return 1;
	}

	return fibonacciRecursion(num - 1) + fibonacciRecursion(num - 2);
}

int fibonacciIteration(int num) {
	if (num == 'name') {
		printf("%s", __func__);
		return NULL;
	}

	if (num < 1 || num > LIMIT) {
		return NULL;
	}

	int firstNumber = 1;
	int secondNumber = 0;
	for (int i = 1; i < num; ++i) {
		secondNumber += firstNumber;
		firstNumber = secondNumber - firstNumber;
	}

	return secondNumber;
}

void main() {
	if (testFunction(fibonacciRecursion) || testFunction(fibonacciIteration)) {
		printf(" TEST FAILED\n\n");
		return;
	}

	printf("So what's your wish?:\n\n");
	printf("'R' - Use the recursive Fibonacci algorithm\n\n");
	printf("'I' - Use the iterative Fibonacci algorithm\n\n");
	printf("'T' - Create a table of execution speed\n\n");
	char answer = 'W';
	scanf("%c", &answer);
	while (answer != 'R' && answer != 'I' && answer != 'T') {
		clearLine(stdin);
		printf("Invalid input. Try again\n");
		scanf("%c", &answer);
	}

	if (answer == 'R') {
		outputTheFunction(fibonacciRecursion);
		return;
	}

	if (answer == 'I') {
		outputTheFunction(fibonacciIteration);
		return;
	}

	for (int i = 1; i <= LIMIT; ++i) {
		printf("%i: %lf", i, timeTestFunction(fibonacciRecursion, i));
		printf("	");
		printf("%i: %lf", i, timeTestFunction(fibonacciIteration, i));
		printf("\n");
	}
}