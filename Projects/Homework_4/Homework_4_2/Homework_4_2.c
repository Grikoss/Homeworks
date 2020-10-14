#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "qsort.h"
#include "Reading.h"

int randomNumber(int minNumber, int maxNumber) {
	return rand() % (maxNumber + 1 - minNumber) + minNumber;
}

bool InvalidArraySizeTest(int function(int[], int, int, bool*)) {
	int array[5] = { 0 };
	bool isSuccessful = true;
	function(array, 5, 4, &isSuccessful);
	return !isSuccessful;
}

bool ArraySizeOneTest(int function(int[], int, int, bool*)) {
	int array[5] = { 0 };
	bool isSuccessful = false;
	function(array, 4, 4, &isSuccessful);
	return isSuccessful;
}

bool identicalArrayTest(int function(int[], int, int)) {
	int array[25] = { 0 };
	return function(array, 0, 24) == 0;
}

bool orderedArrayTest(int function(int[], int, int, bool*)) {
	int array[25] = { 0 };
	for (int i = 0; i < 25; ++i) {
		array[i] = i;
	}

	bool isSuccessful = false;
	function(array, 0, 24, &isSuccessful);
	return isSuccessful;
}

bool workingValuesTest(int function(int[], int, int)) {
	int array[] = { 1, 2, 4, 4, 3, 3, 2, 3, 3, 3, 3, 4, 5, 6, 7, 6, 7, 8 ,9 ,6 , 100, -23543, 3445, 3, 4 };
	return function(array, 0, 24) == 3;
}

bool workingValuesTestTwo(int function(int[], int, int)) {
	int array[] = { 1, 2, 2, 3, 3, 3 };
	return function(array, 0, 5) == 3;
}

void runSystemTest(int function()) {
	printf("InvalidArraySizeTest\n");
	printf((InvalidArraySizeTest(function)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("ArraySizeOneTest\n");
	printf((ArraySizeOneTest(function)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("identicalArrayTest\n");
	printf((identicalArrayTest(function)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("orderedArrayTest\n");
	printf((orderedArrayTest(function)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("workingValuesTest\n");
	printf((workingValuesTest(function)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("workingValuesTest two\n");
	printf((workingValuesTestTwo(function)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("\n-----------------------------------------------------------------\n\n");
}

int mostCommonElement(int array[], int startIndex, int endIndex, bool* isSuccessful) {
	const int size = endIndex - startIndex + 1;
	if (size <= 0) {
		*isSuccessful = false;
		return 0;
	}

	quickSort(array, startIndex, endIndex);
	int counter = 1;
	int counterMax = 0;
	int mostCommonElement = 0;
	int i = startIndex + 1;
	while (i <= endIndex) {
		if (array[i - 1] == array[i]) {
			++counter;
		}

		if (counter > counterMax) {
			mostCommonElement = array[i - 1];
			counterMax = counter;
		}

		if (array[i - 1] != array[i]) {
			counter = 1;
		}

		++i;
	}

	*isSuccessful = true;
	return mostCommonElement;
}

void randomizeArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = randomNumber(0, 2);
	}
}

void printfArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%6d. - %d\n", i, array[i]);
	}
}

void main() {
	srand(time(NULL));
	runSystemTest(mostCommonElement);
	int sizeOfRandomArray = 6;
	int* randomArray = (int*)calloc(sizeOfRandomArray, sizeof(int));
	randomizeArray(randomArray, sizeOfRandomArray);
	printfArray(randomArray, sizeOfRandomArray);
	bool isSuccessful = false;
	printf("Most common element is %i\n", mostCommonElement(randomArray, 0, sizeOfRandomArray - 1, &isSuccessful));
	free(randomArray);
	printf("\nRead array:\n");
	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
		printf("File not found!");
		return;
	}

	int* array = NULL;
	int size = readFromFile(file, array);
	fclose(file);
}