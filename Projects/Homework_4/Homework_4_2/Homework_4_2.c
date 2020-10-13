#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int randomNumber(int minNumber, int maxNumber) {
	return rand() % (maxNumber + 1 - minNumber) + minNumber;
}

void swapFunctionForArray(int array[], int numberOne, int numberTwo) {
	const int swap = array[numberOne];
	array[numberOne] = array[numberTwo];
	array[numberTwo] = swap;
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

int insertionSort(int array[], int startIndex, int endIndex) {
	const int size = endIndex - startIndex + 1;
	if (size <= 0) {
		return -1;
	}

	for (int i = startIndex + 1; i <= endIndex; ++i) {
		int j = i;
		while (array[j] < array[j - 1] && j > startIndex) {
			swapFunctionForArray(array, j, j - 1);
			--j;
		}
	}

	return 1;
}

double selectionOfKeyElement(int array[], int startIndex, int endIndex, bool* isSuccessful) {
	const int size = endIndex - startIndex + 1;
	*isSuccessful = false;
	if (size < 10) {
		printf("Invalid size (selection of key element)\n");
		return -1;
	}

	const int step = size / 10;
	int index = startIndex;
	int elements[10] = { 0 };
	for (int i = 0; i < 10; ++i) {
		elements[i] = array[index];
		index += step;
	}

	double theArithmeticMean = 0;
	for (int i = 0; i < 10; ++i) {
		theArithmeticMean += elements[i];
	}

	theArithmeticMean /= 10;
	int counter = 0;
	for (int i = 0; i < 10; ++i) {
		if (theArithmeticMean == elements[i]) {
			++counter;
		}
	}

	if (counter == 10) {
		int keyElement = array[startIndex];
		for (int i = startIndex + 1; i <= endIndex; ++i) {
			if (keyElement != array[i] && array[i] > keyElement) {
				*isSuccessful = true;
				return array[i];
			}

			if (keyElement != array[i] && array[i] < keyElement) {
				*isSuccessful = true;
				return keyElement;
			}
		}
	}
	else {
		*isSuccessful = true;
		return theArithmeticMean;
	}

	return -1;
}

int quickSort(int array[], int startIndex, int endIndex) {
	const int size = endIndex - startIndex + 1;
	if (size <= 0) {
		return -1;
	}

	if (size < 10) {
		insertionSort(array, startIndex, endIndex);
		return 1;
	}

	bool isSelectionOfKeyElementSuccesful = true;
	const double keyElement = selectionOfKeyElement(array, startIndex, endIndex, &isSelectionOfKeyElementSuccesful);
	if (!isSelectionOfKeyElementSuccesful) {
		return 1;
	}

	int counterStart = startIndex;
	int counterEnd = endIndex;
	while (counterStart < counterEnd) {
		if (array[counterStart] >= keyElement) {
			while (array[counterEnd] >= keyElement) {
				--counterEnd;
			}

			if (counterStart >= counterEnd) {
				break;
			}

			swapFunctionForArray(array, counterStart, counterEnd);
		}

		++counterStart;
	}

	quickSort(array, startIndex, counterStart - 1);
	quickSort(array, counterStart, endIndex);
	return 1;
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
}