#pragma once

#include<stdbool.h>
#include "qsort.h"
#include<stdio.h>

void swapFunctionForArray(int array[], int numberOne, int numberTwo) {
	const int swap = array[numberOne];
	array[numberOne] = array[numberTwo];
	array[numberTwo] = swap;
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