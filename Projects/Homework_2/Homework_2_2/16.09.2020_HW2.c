#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void clearLine(FILE* fp) {
	int c = 0;
	while ((c = getchar()) != EOF && c != '\n');
}

bool isTestFailed(float function(float, int), float base, int power, float result) {
	if (function(base, power) != result) {
		printf("Failed\n");
		printf("base = %f\n", base);
		printf("power = %i\n", power);
		printf("result = %f\n", result);
		printf("output = %f\n\n", function(base, power));
		return true;
	}

	return false;
}

bool areTestsFailed(float function(float, int)) {
	bool test = false;
	test = test || isTestFailed(function, -5, 0, 1);
	test = test || isTestFailed(function, 2, 4, 16);
	test = test || isTestFailed(function, 5, 2, 25);
	test = test || isTestFailed(function, 7, 3, 343);
	test = test || isTestFailed(function, -5, 3, -125);
	test = test || isTestFailed(function, 2, -2, 0.25);
	test = test || isTestFailed(function, 10, -3, 0.001);
	test = test || isTestFailed(function, -10, 3, -1000);
	test = test || isTestFailed(function, -5, 2, 25);
	test = test || isTestFailed(function, -50000, 2001, -INFINITY);
	test = test || isTestFailed(function, 50000, 2000, INFINITY);
	test = test || isTestFailed(function, 50000, -2000, 0);
	test = test || isTestFailed(function, 0, 20, 0);
	test = test || isTestFailed(function, 0, 0, 0);
	test = test || isTestFailed(function, 0.25, 2, 0.0625);
	test = test || isTestFailed(function, 0.25, -2, 16);
	test = test || isTestFailed(function, 2, 5, 32);
	test = test || isTestFailed(function, 2, 6, 64);
	test = test || isTestFailed(function, 2, 7, 128);
	return test;
}

float exponentiationForLineTime(float base, int power) {
	if (base != 0 && power == 0) {
		return 1;
	}

	if (power == 1) {
		return base;
	}

	if (power == -1) {
		return 1 / base;
	}

	float result = base;
	if (abs(power) > 1) {
		for (int i = 1; i < abs(power); ++i) {
			result *= base;
		}

		if (power < 0) {
			result = 1 / result;
		}

		return result;
	}
	
	return 0;
}

float exponentiationForLogarithmTime(float base, int power) {
	if (base != 0 && power == 0) {
		return 1;
	}
	
	if (power == 1) {
		return base;
	}

	if (power == -1) {
		return 1 / base;
	}

	if (abs(power) > 1) {
		float result = 1;
		float subResult = base;
		int subPower = abs(power);
		while (subPower > 0) {
			if ((subPower & 1) == 1) {
				result *= subResult;
			}

			subResult *= subResult;
			subPower >>= 1;
		}

		if (power < 0) {
			result = 1 / result;
		}

		return result;
	}

	return 0;
}

void outputFunction(float base, int power, float num) {
	if (num == 0 || num == INFINITY || num == -INFINITY) {
		printf("Invalid input\n");
		return;
	}

	printf("%f to the power of %i equals %f\n", base, power, num);
}

void main() {
	bool stop = false;
	if (areTestsFailed(exponentiationForLineTime)) {
		printf("exponentiationForLineTime\n\n");
		stop = true;
	}

	if (areTestsFailed(exponentiationForLogarithmTime)) {
		printf("exponentiationForLogarithmTime\n\n");
		stop = true;
	}

	if (stop) {
		return;
	}

	printf("What algorithm should I use?\n\n");
	printf("'F' - exponentiationForLineTime\n\n");
	printf("'S' - exponentiationForLogarithmTime\n\n");
	char answer = 'W';
	scanf("%c", &answer);
	while (answer != 'F' && answer != 'S') {
		clearLine(stdin);
		printf("Invalid input. Try again\n");
		scanf("%c", &answer);
	}

	printf("\nEnter base != 0\n");
	float base = 0;
	scanf("%f", &base);
	printf("Enter integer power\n");
	int power = 0;
	scanf("%i", &power);
	printf("\n");
	if (answer == 'F') {
		outputFunction(base, power, exponentiationForLineTime(base, power));
		return;
	}

	if (answer == 'S') {
		outputFunction(base, power, exponentiationForLogarithmTime(base, power));
		return;
	}
}