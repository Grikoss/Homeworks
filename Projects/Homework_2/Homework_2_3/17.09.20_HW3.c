#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void clearLine(FILE* fileStream) {
	int c = 0;
	while ((c = getchar()) != EOF && c != '\n');
}

int randomNumber(minNumber, maxNumber) {
	return rand() % (maxNumber + 1 - minNumber) + minNumber;
}

void swapFunctionForArray(int array[], int numberOne, int numberTwo) {
	const int swap = array[numberOne];
	array[numberOne] = array[numberTwo];
	array[numberTwo] = swap;
}

void doABarrelRoll(int arrayOfValues[], int begin, int end) {
	int step = (end - begin + 1) / 2;
	for (int i = 0; i < step; ++i) {
		arrayOfValues[begin + i] += arrayOfValues[end - i];
		arrayOfValues[end - i] = arrayOfValues[begin + i] - arrayOfValues[end - i];
		arrayOfValues[begin + i] -= arrayOfValues[end - i];
	}
}

bool minusTenSizeTest(int sortFunction(int[], int)) {
	int size = -10;
	int* array = (int*)calloc(size, sizeof(int));
	bool check = true;
	if (sortFunction(array, size) != -1 || sortFunction(array, size) != -1) {
		check = false;
	}

	free(array);
	return check;
}

bool zeroSizeTest(int sortFunction(int[], int)) {
	int size = 0;
	int* array = (int*)calloc(size, sizeof(int));
	bool check = true;
	if (sortFunction(array, size) != -1 || sortFunction(array, size) != -1) {
		check = false;
	}

	free(array);
	return check;
}

bool oneSizeTest(int sortFunction(int[], int)) {
	int size = 1;
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
	int firstLimit = -size * 10;
	int secondLimit = firstLimit + 20;
	for (int i = 0; i <= size - 1; ++i) {
		randomOrderedArrayOfInt[i] = randomNumber(firstLimit, secondLimit);
		firstLimit = secondLimit;
		secondLimit += 20;
	}

	int* randomArrayOfInt = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		randomArrayOfInt[i] = randomOrderedArrayOfInt[i];
	}

	for (int i = 0; i < size; ++i) {
		int firstRandomNumber = randomNumber(0, size - 1);
		int secondRandomNumber = randomNumber(0, size - 1);
		swapFunctionForArray(randomArrayOfInt, firstRandomNumber, secondRandomNumber);
	}

	sortFunction(randomArrayOfInt, size);
	for (int i = 0; i < size; ++i) {
		printf("Must be: %6i. %7i Output: %6i. %7i\n", (i + 1), randomOrderedArrayOfInt[i], (i + 1), randomArrayOfInt[i]);
	}

	bool check = true;
	for (int i = 0; i < size; ++i) {
		if (randomArrayOfInt[i] != randomOrderedArrayOfInt[i]) {
			check = false;
		}
	}

	free(randomArrayOfInt);
	free(randomOrderedArrayOfInt);
	return check;
}

double timeTest(int sortFunction(int[], int)) {
	int size = 100000;
	int* randomArrayOfInt = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		randomArrayOfInt[i] = randomNumber(-size * 10, size * 10);
	}

	clock_t time = clock();
	sortFunction(randomArrayOfInt, size);
	time = clock() - time;
	free(randomArrayOfInt);
	return ((double)time) / CLOCKS_PER_SEC;;
}

bool identicalArrayTest(int sortFunction(int[], int)) {
	int size = 10;
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

bool orderedArrayTest(int sortFunction(int[], int)) {
	int size = 10;
	int* array = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		array[i] = i;
	}

	sortFunction(array, size);
	bool check = true;
	for (int i = 0; i < size; ++i) {
		if (array[i] != i) {
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
	printf("Test on an ordered array\n");
	printf((orderedArrayTest(sortFunction)) ? "-----complete-----\n" : "-----failed----\n");
	printf("\n--------------------------------------------------------------------\n\n");
}

int bubbleSorting(int array[], int size) {
	if (size <= 0) {
		return -1;
	}

	for (int i = 0; i < size - 1 ; ++i) {
		for (int j = 0; j <= size - i - 1; ++j) {
			if (array[j] < array[j + 1]) {
				swapFunctionForArray(array, j, j + 1);
			}
		}
	}

	doABarrelRoll(array, 0, size - 1);
	return 1;
}

int sortingByCounting(int array[], int size) {
	if (size <= 0) {
		return -1;
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

	int index = 0;
	for (int i = 0; i < quantity; ++i) {
		while (arrayOfValues[i] > 0) {
			array[index] = i + minNumber;
			--arrayOfValues[i];
			++index;
		}
	}

	free(arrayOfValues);
	return 1;
}

void main() {
	srand(time(NULL));
	printf("Test sorting by counting\n");
	runSystemTest(sortingByCounting);
	printf("Test bubble sort\n");
	runSystemTest(bubbleSorting);
}