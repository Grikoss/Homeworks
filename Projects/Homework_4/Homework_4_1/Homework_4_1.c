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

void main() {
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
}