#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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
	int array[] = { 1,2,4,4,3,3,2,3,3,3,3,4,5,6,7,6,7,8,9,6,100,-23543,3445,3,4 };
	return function(array, 0, 24) == 3;
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
	printf("\n-----------------------------------------------------------------\n\n");
}

int mostCommonElemnet(int array[], int startIndex, int endIndex, bool* isSuccessful) {
	const int size = endIndex - startIndex + 1;
	if (size <= 0) {
		*isSuccessful = false;
		return 0;
	}

	int maxNumber = array[0];
	int minNumber = array[0];
	for (int i = 1; i < size; ++i) {
		if (minNumber > array[i]) {
			minNumber = array[i];
		}

		if (maxNumber < array[i]) {
			maxNumber = array[i];
		}
	}

	int quantity = maxNumber - minNumber + 1;
	int* arrayOfValues = (int*)calloc(quantity, sizeof(int));
	for (int i = 0; i < size; ++i) {
		++arrayOfValues[array[i] - minNumber];
	}

	int mostCommonElement = array[0];
	for (int i = minNumber; i <= maxNumber; ++i) {
		if (arrayOfValues[mostCommonElement - minNumber] < arrayOfValues[i - minNumber]) {
			mostCommonElement = i;
		}
	}

	*isSuccessful = true;
	free(arrayOfValues);
	return mostCommonElement;
}

void randomizeArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = randomNumber(0, 1);
	}
}

void printfArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%6d. - %d\n", i, array[i]);
	}
}

void main() {
	srand(time(NULL));
	runSystemTest(mostCommonElemnet);
	int sizeOfrandomArray = 20;
	int* randomArray = (int*)calloc(sizeOfrandomArray, sizeof(int));
	randomizeArray(randomArray, sizeOfrandomArray);
	printfArray(randomArray, sizeOfrandomArray);
	bool isSuccessful = false;
	printf("Most common element is %i\n", mostCommonElemnet(randomArray, 0, sizeOfrandomArray - 1, &isSuccessful));
	printf((isSuccessful) ? "successfully" : "isn't successfully");
	free(randomArray);
}