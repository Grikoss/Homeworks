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

void doABarrelRoll(int arrayOfValues[], int begin, int end) {
	const int step = (end - begin + 1) / 2;
	for (int i = 0; i < step; ++i) {
		arrayOfValues[begin + i] += arrayOfValues[end - i];
		arrayOfValues[end - i] = arrayOfValues[begin + i] - arrayOfValues[end - i];
		arrayOfValues[begin + i] -= arrayOfValues[end - i];
	}
}

bool minusTenSizeTest(int sortFunction(int[], int, int)) {
	const int size = -10;
	int* array = (int*)calloc(size, sizeof(int));
	bool check = true;
	if (sortFunction(array, 0, size - 1) != -1 || sortFunction(array, 0, size - 1) != -1) {
		check = false;
	}

	free(array);
	return check;
}

bool zeroSizeTest(int sortFunction(int[], int, int)) {
	const int size = 0;
	int* array = (int*)calloc(size, sizeof(int));
	bool check = true;
	if (sortFunction(array, 0, size - 1) != -1 || sortFunction(array, 0, size - 1) != -1) {
		check = false;
	}

	free(array);
	return check;
}

bool oneSizeTest(int sortFunction(int[], int, int)) {
	const int size = 1;
	int* array = (int*)calloc(size, sizeof(int));
	bool check = true;
	if (sortFunction(array, 0, size - 1) < 0 || sortFunction(array, 0, size - 1) < 0) {
		check = false;
	}

	free(array);
	return check;
}

bool randomArrayTest(int sortFunction(int[], int, int), int size) {
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

	sortFunction(randomArrayOfInt, 0, size - 1);
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

bool identicalArrayTest(int sortFunction(int[], int, int)) {
	const int size = 50;
	int* array = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		array[i] = 5;
	}

	sortFunction(array, 0, size - 1);
	bool check = true;
	for (int i = 0; i < size; ++i) {
		if (array[i] != 5) {
			check = false;
		}
	}

	free(array);
	return check;
}

bool orderedArrayTest(int sortFunction(int[], int, int)) {
	const int size = 50;
	int* array = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		array[i] = i;
	}

	sortFunction(array, 0, size - 1);
	bool check = true;
	for (int i = 0; i < size; ++i) {
		if (array[i] != i) {
			check = false;
		}
	}

	free(array);
	return check;
}

void keyElementTest(int sortFunction(int[], int, int)) {
	int array[] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 };
	sortFunction(array, 0, 12);
}

void runSortTest(int sortFunction(int[], int, int)) {
	keyElementTest(sortFunction);
	printf("Test on invalid size = -10\n");
	printf((minusTenSizeTest(sortFunction)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("Test on invalid size = 0\n");
	printf((zeroSizeTest(sortFunction)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("Test on invalid size = 1\n");
	printf((oneSizeTest(sortFunction)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("Test random array of one element\n");
	printf((randomArrayTest(sortFunction, 1)) ? "-----complete-----\n" : "-----failed-----\n");
	printf("Test random array\n");
	printf((randomArrayTest(sortFunction, 29)) ? "----complete-----\n" : "-----failed-----\n");
	printf("Test on an array of identical elements\n");
	printf((identicalArrayTest(sortFunction)) ? "-----complete-----\n" : "-----failed----\n");
	printf("Test on an ordered array\n");
	printf((orderedArrayTest(sortFunction)) ? "-----complete-----\n" : "-----failed----\n");
	printf("\n--------------------------------------------------------------------\n\n");
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

	bool isSelectionOfKeyElementSuccessful = true;
	const double keyElement = selectionOfKeyElement(array, startIndex, endIndex, &isSelectionOfKeyElementSuccessful);
	if (!isSelectionOfKeyElementSuccessful) {
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

int searchingElement(int array[], int startIndex, int endIndex, int element) {
	int size = endIndex - startIndex + 1;
	while (size > 0) {
		if (array[startIndex + size / 2] == element) {
			return startIndex + size / 2;
		}

		if (array[startIndex + size / 2] > element) {
			endIndex = startIndex + size / 2 - 1;
		}
		else {
			startIndex += startIndex + size / 2 + 1;
		}
		
		size = endIndex - startIndex + 1;
	}

	return -1;
}

bool searchingElementTestOnRandomValue(int function(int[], int, int, int)) {
	int array[51] = { 0 };
	for (int i = 0; i < 51; ++i) {
		array[i] = i;
	}

	int element = randomNumber(0, 50);
	return function(array, 0, 50, element) == element;
}

bool searchingElementTestOnInvalidSize(int function(int[], int, int, int)) {
	int array[50] = { 0 };
	return function(array, 0, -1, 10) == -1;
}

bool searchingElementTestOnMissingElement(int function(int[], int, int, int)) {
	int array[51] = { 0 };
	for (int i = 0; i < 51; ++i) {
		array[i] = i * 2;
	}

	return function(array, 0, -1, 10) == -1;
}

void runSearchingElementTest(int function(int[], int, int, int)) {
	printf("Invalid size test\n");
	printf((searchingElementTestOnInvalidSize(function)) ? "-----complete-----\n" : "-----failed----\n");
	printf("Missing element test\n");
	printf((searchingElementTestOnMissingElement(function)) ? "-----complete-----\n" : "-----failed----\n");
	printf("Test on random value\n");
	printf((searchingElementTestOnRandomValue(function)) ? "-----complete-----\n" : "-----failed----\n");
	printf("\n--------------------------------------------------------------------\n\n");
}

void runSystemTest() {
	printf("Insertion sort\n");
	runSortTest(insertionSort);
	printf("qsort\n");
	runSortTest(quickSort);
	printf("Searching element\n");
	runSearchingElementTest(searchingElement);
}

void randomizeArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = randomNumber(-100, 100);
	}
}

void printfArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%6d. - %d\n", i, array[i]);
	}
}

void main() {
	srand(time(NULL));
	runSystemTest();
	int sizeOfrandomArray = 0;
	printf("Enter size of array\n");
	scanf("%d", &sizeOfrandomArray);
	int* randomArray = (int*)calloc(sizeOfrandomArray, sizeof(int));
	randomizeArray(randomArray, sizeOfrandomArray);
	quickSort(randomArray, 0, sizeOfrandomArray - 1);
	printfArray(randomArray, sizeOfrandomArray);
	int numberOfRandomElements = 0;
	printf("Enter the number of random numbers\n");
	scanf("%d", &numberOfRandomElements);
	for (int i = 0; i < numberOfRandomElements; ++i) {
		int randomElement = randomNumber(-100, 100);
		int index = 0;
		index = searchingElement(randomArray, 0, sizeOfrandomArray - 1, randomElement);
		printf((index >= 0) ? "Element %i found. Its index - %i\n" : "Element %i is not found\n", randomElement, index);
	}

	free(randomArray);
}