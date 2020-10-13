#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "binary.h"

void printfBoolArray(bool array[]) {
	for (int i = 0; i < 32; ++i) {
		printf(array[i] ? "1" : "0");
	}

	printf("\n");
}

bool isTestSuccessful(int valueOne, int valueTwo) {
	bool binaryValueOne[32] = { 0 };
	bool binaryValueTwo[32] = { 0 };
	binaryUnpacker(valueOne, binaryValueOne);
	binaryUnpacker(valueTwo, binaryValueTwo);
	bool binaryResult[32] = { 0 };
	binarySummator(binaryValueOne, binaryValueTwo, binaryResult);
	return valueOne + valueTwo == binaryPacker(binaryResult);
}

void sistemTest(void) {
	if (!isTestSuccessful(5, 10)) {
		printf("Test failed\n");
	}

	if (!isTestSuccessful(-5, -26)) {
		printf("Test failed\n");
	}

	if (!isTestSuccessful(9, -18)) {
		printf("Test failed\n");
	}

	if (!isTestSuccessful(2147483648, 2147483648)) {
		printf("Test failed\n");
	}

	if (!isTestSuccessful(-214748364, -214748364)) {
		printf("Test failed\n");
	}

	if (!isTestSuccessful(-214748364, 2147483648)) {
		printf("Test failed\n");
	}
}

void main() {
	sistemTest();
	setlocale(LC_ALL, "Russian");
	int valueOne = 0;
	int valueTwo = 0;
	printf("¬ведите целое число\n");
	while (scanf("%i", &valueOne) == 0);
	printf("¬ведите другое целое число\n");
	while (scanf("%i", &valueTwo) == 0);
	printf("\n");
	bool binaryValueOne[32] = { 0 };
	bool binaryValueTwo[32] = { 0 };
	binaryUnpacker(valueOne, binaryValueOne);
	binaryUnpacker(valueTwo, binaryValueTwo);
	printf("%i - ", valueOne);
	printfBoolArray(binaryValueOne);
	printf("%i - ", valueTwo);
	printfBoolArray(binaryValueTwo);
	bool binaryResult[32] = { 0 };
	binarySummator(binaryValueOne, binaryValueTwo, binaryResult);
	int sum = binaryPacker(binaryResult);
	printf("\n");
	printf("Sum = %i - ", sum);
	printfBoolArray(binaryResult);
}