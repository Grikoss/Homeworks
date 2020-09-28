#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void clearLine(FILE* fileStream) {
	int c = 0;
	while ((c = getchar()) != EOF && c != '\n');
}

int randomNumber(int minNumber, int maxNumber) {
	return rand() % (maxNumber + 1 - minNumber) + minNumber;
}

void swapFunctionForArray(int array[], int numberOne, int numberTwo) {
	const int swap = array[numberOne];
	array[numberOne] = array[numberTwo];
	array[numberTwo] = swap;
}

bool minusTenSizeTest(int sortFunction(int[], int)) {
	const int size = -10;
	int* array = (int*)calloc(size, sizeof(int));
	bool check = true;
	if (sortFunction(array, size) != -1 || sortFunction(array, size) != -1) {
		check = false;
	}

	free(array);
	return check;
}

bool zeroSizeTest(int sortFunction(int[], int)) {
	const int size = 0;
	int* array = (int*)calloc(size, sizeof(int));
	bool check = true;
	if (sortFunction(array, size) != -1 || sortFunction(array, size) != -1) {
		check = false;
	}

	free(array);
	return check;
}

bool oneSizeTest(int sortFunction(int[], int)) {
	const int size = 1;
	int* array = (int*)calloc(size, sizeof(int));
	bool check = true;
	if (sortFunction(array, size) < 0 || sortFunction(array, size) < 0) {
		check = false;
	}

	free(array);
	return check;
}

bool randomArrayTest(int sortFunction(int[], int), int size) {
	if (size <= 0 || size > 200000) {
		printf("Invalid array size\n");
		return false;
	}

	int* randomOrderedArrayOfInt = (int*)calloc(size, sizeof(int));
	int firstElement = randomNumber(-size * 10, size * 10);
	int point = randomNumber(0, size - 1);
	for (int i = 0; i < point; ++i) {
		randomOrderedArrayOfInt[i] = randomNumber(-size * 10, firstElement - 1);
	}

	randomOrderedArrayOfInt[point] = firstElement;
	for (int i = point + 1; i < size; ++i) {
		randomOrderedArrayOfInt[i] = randomNumber(firstElement, size * 10);
	}

	int* randomArrayOfInt = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		randomArrayOfInt[i] = randomOrderedArrayOfInt[i];
	}

	swapFunctionForArray(randomArrayOfInt, 0, point);
	for (int i = 0; i < size; ++i) {
		int firstRandomNumber = randomNumber(1, size - 2);
		int secondRandomNumber = randomNumber(1, size - 2);
		swapFunctionForArray(randomArrayOfInt, firstRandomNumber, secondRandomNumber);
	}

	sortFunction(randomArrayOfInt, size);
	printf("\nComparing element = %i\n\n", firstElement);
	printf("Its ordinal number = %i\n\n", point);
	for (int i = 0; i < point; ++i) {
		printf("Element, that smaller comparing element - %6i: %7i\tOutput - %6i: %7i\n", i, randomOrderedArrayOfInt[i], i, randomArrayOfInt[i]);
	}

	printf("\nComparing element - %6i: %7i\tOutput - %6i: %7i\n\n", point, randomOrderedArrayOfInt[point], point, randomArrayOfInt[point]);
	for (int i = point + 1; i < size; ++i) {
		printf("Element that bigger or equal comparing element - %6i: %7i\tOutput - %6i: %7i\n", i, randomOrderedArrayOfInt[i], i, randomArrayOfInt[i]);
	}

	bool check = true;
	for (int i = 0; i < point; ++i) {
		if (randomArrayOfInt[i] >= firstElement) {
			check = false;
		}
	}

	for (int i = point; i < size; ++i) {
		if (randomArrayOfInt[i] < firstElement) {
			check = false;
		}
	}
	
	free(randomOrderedArrayOfInt);
	free(randomArrayOfInt);
	return check;
}

double timeTest(int sortFunction(int[], int)) {
	const int size = 100000;
	int* randomArrayOfInt = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		randomArrayOfInt[i] = randomNumber(-size * 10, size * 10);
	}

	time_t time = clock();
	sortFunction(randomArrayOfInt, size);
	time = clock() - time;
	free(randomArrayOfInt);
	return ((double)time) / CLOCKS_PER_SEC;
}

bool identicalArrayTest(int sortFunction(int[], int)) {
	const int size = 10;
	int* array = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		array[i] = 5;
	}

	sortFunction(array, size);
	bool check = true;
	for (int i = 0; i < size; ++i) {
		if (array[i] != 5) {
			check = false;
		}
	}

	free(array);
	return check;
}

void runSystemTest(int sortFunction(int[], int)) {
	printf("Test on invalid size = -10\n");
	printf((minusTenSizeTest(sortFunction)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("Test on invalid size = 0\n");
	printf((zeroSizeTest(sortFunction)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("Test on invalid size = 1\n");
	printf((oneSizeTest(sortFunction)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("Test random array of one element\n");
	printf((randomArrayTest(sortFunction, 1)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("Test random array\n");
	printf((randomArrayTest(sortFunction, 11)) ? "----complete-----\n" : "-----failed-----\n");
	printf("Time test: %lf\n", timeTest(sortFunction));
	printf("Test on an array of identical elements\n");
	printf((identicalArrayTest(sortFunction)) ? "------complete-----\n" : "-----failed----\n");
	printf("\n--------------------------------------------------------------------\n\n");
}

int sortFunction(int array[], int size) {
	if (size <= 0) {
		return -1;
	}

	int firstElement = array[0];
	int numberOfSmallerValues = 0;
	for (int i = 1; i < size; ++i) {
		if (array[i] < firstElement) {
			++numberOfSmallerValues;
		}
	}

	swapFunctionForArray(array, 0, numberOfSmallerValues);
	int downCounter = size - 1;
	for (int i = 0; i < numberOfSmallerValues; ++i) {
		if (array[i] >= firstElement) {
			while (array[downCounter] >= firstElement) {
				--downCounter;
			}

			swapFunctionForArray(array, i, downCounter);
			--downCounter;
		}
	}

	return 1;
}

void main() {
	srand(time(NULL));
	printf("Test sorting function\n");
	runSystemTest(sortFunction);
}