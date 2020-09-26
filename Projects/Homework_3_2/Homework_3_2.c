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

void runSortTest(int sortFunction(int[], int, int)) {
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

int selectionOfKeyElement(int array[], int startIndex, int endIndex, bool* isSuccesful) {
	const int size = endIndex - startIndex + 1;
	*isSuccesful = false;
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

	int theArithmeticMean = 0;
	for (int i = 0; i < 10; ++i) {
		theArithmeticMean += elements[i];
	}

	int counter = 0;
	for (int i = 0; i < 10; ++i) {
		if (theArithmeticMean / 10 == elements[i]) {
			++counter;
		}
	}

	if (counter == 10) {
		int keyElement = array[startIndex];
		for (int i = startIndex + 1; i <= endIndex; ++i) {
			if (keyElement != array[i]) {
				*isSuccesful = true;
				return i;
			}
		}
	}
	else {
		theArithmeticMean /= 10;
		int indexOfkeyElement = 0;
		for (int i = 1; i < 10; ++i) {
			if (abs(theArithmeticMean - elements[indexOfkeyElement]) > abs(theArithmeticMean - elements[i])) {
				indexOfkeyElement = i;
			}
		}

		*isSuccesful = true;
		return elements[indexOfkeyElement];
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
	const int keyElement = selectionOfKeyElement(array, startIndex, endIndex, &isSelectionOfKeyElementSuccesful);
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

int searchingElement(int array[], int startIndex, int endIndex, int element, bool* isSuccessful) {
	int size = endIndex - startIndex + 1;
	int keyelement = size / 2;
	if (size <= 0) {
		*isSuccessful = false;
		return -1;
	}

	if (size == 1 && element != array[startIndex]) {
		*isSuccessful = false;
		return -1;
	}

	if (array[startIndex + size / 2] == element) {
		*isSuccessful = true;
		return startIndex + size / 2;
	}

	if (array[startIndex + size / 2] > element) {
		*isSuccessful = false;
		return searchingElement(array, startIndex, startIndex + size / 2 - 1, element, isSuccessful);
	}
	
	if (array[startIndex + size / 2] < element) {
		*isSuccessful = false;
		return searchingElement(array, startIndex + size / 2 + 1, endIndex, element, isSuccessful);
	}


	*isSuccessful = false;
	return -1;
}

bool searchingElementTestOnRandomValue(int function(int[], int, int, int, bool*)) {
	int array[51] = { 0 };
	for (int i = 0; i < 51; ++i) {
		array[i] = i;
	}

	int element = randomNumber(0, 50);
	bool isSuccessful = false;
	if (function(array, 0, 50, element, &isSuccessful) == element && isSuccessful) {
		return true;
	}

	return false;
}

bool searchingElementTestOnInvalidSize(int function(int[], int, int, int, bool*)) {
	bool isSuccessful = false;
	int array[50] = { 0 };
	if (function(array, 0, -1, 10, &isSuccessful) == -1 && !isSuccessful) {
		return true;
	}

	return false;
}

bool searchingElementTestOnMissingElement(int function(int[], int, int, int, bool*)) {
	bool isSuccessful = false;
	int array[51] = { 0 };
	for (int i = 0; i < 51; ++i) {
		array[i] = i * 2;
	}

	if (function(array, 0, 50, 39, &isSuccessful) == -1 && !isSuccessful) {
		return true;
	}

	return false;
}

void runSearchingElementTest(int function(int[], int, int, int, bool*)) {
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

void main() {
	srand(time(NULL));
	runSystemTest();
	int sizeOfrandomArray = 100;
	int* randomArray = (int*)calloc(sizeOfrandomArray, sizeof(int));
	randomizeArray(randomArray, sizeOfrandomArray);

	int sizeOfRandomElements = 1;
	int* randomElements = (int*)calloc(sizeOfRandomElements, sizeof(int));
	randomizeArray(randomElements, sizeOfRandomElements);

	quickSort(randomArray, 0, sizeOfrandomArray - 1);
	bool isSuccessful = false;
	int index = 0;
	for (int i = 0; i < sizeOfRandomElements; ++i) {
		index = searchingElement(randomArray, 0, sizeOfrandomArray - 1, randomElements[i], &isSuccessful);
		printf((isSuccessful) ? "Element %i found. Its index - %i\n" : "Element %i is not found\n", randomElements[i], index);
	}

	free(randomArray);
	free(randomElements);
}