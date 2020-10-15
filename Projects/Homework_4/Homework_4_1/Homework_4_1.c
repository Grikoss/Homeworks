#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binary.h"
#define SIZEOFINT 32

void printfBoolArray(bool array[]) {
	for (int i = SIZEOFINT - 1; i >= 0; --i) {
		printf(array[i] ? "1" : "0");
	}

	printf("\n");
}

bool isTestFailed(int valueOne, int valueTwo) {
	bool binaryValueOne[SIZEOFINT] = { 0 };
	bool binaryValueTwo[SIZEOFINT] = { 0 };
	binaryUnpacker(valueOne, binaryValueOne);
	binaryUnpacker(valueTwo, binaryValueTwo);
	bool binaryResult[SIZEOFINT] = { 0 };
	binarySummator(binaryValueOne, binaryValueTwo, binaryResult);
	if (valueOne + valueTwo != binaryPacker(binaryResult)) {
		printf("Test failed\n");
		return true;
	}

	return false;
}

void systemTest(void) {
	bool check = false;
	check += isTestFailed(5, 10);
	check += isTestFailed(-5, -26);
	check += isTestFailed(10, -18);
	check += isTestFailed(2147483648, 2147483648);
	check += isTestFailed(-214748364, -214748364);
	check += isTestFailed(-214748364, 2147483648);
	if (check) {
		abort();
	}
}

void main() {
	systemTest();
	setlocale(LC_ALL, "Russian");
	int valueOne = 0;
	int valueTwo = 0;
	printf("¬ведите целое число\n");
	while (scanf("%i", &valueOne) == 0);
	printf("¬ведите другое целое число\n");
	while (scanf("%i", &valueTwo) == 0);
	printf("\n");
	bool binaryValueOne[SIZEOFINT] = { 0 };
	bool binaryValueTwo[SIZEOFINT] = { 0 };
	binaryUnpacker(valueOne, binaryValueOne);
	binaryUnpacker(valueTwo, binaryValueTwo);
	printf("%i - ", valueOne);
	printfBoolArray(binaryValueOne);
	printf("%i - ", valueTwo);
	printfBoolArray(binaryValueTwo);
	bool binaryResult[SIZEOFINT] = { 0 };
	binarySummator(binaryValueOne, binaryValueTwo, binaryResult);
	const int sum = binaryPacker(binaryResult);
	printf("\n");
	printf("Sum = %i - ", sum);
	printfBoolArray(binaryResult);
}