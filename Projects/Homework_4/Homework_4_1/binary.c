#pragma once

#include <stdbool.h>

#include "binary.h"

void binarySummator(bool arrayOne[], bool arrayTwo[], bool resultArray[]) {
	bool overFlow = 0;
	int subSum = 0;
	for (int i = 31; i >= 0; --i) {
		subSum = arrayOne[i] + arrayTwo[i] + overFlow;
		switch (subSum)
		{
		case 0:
			resultArray[i] = 0;
			overFlow = 0;
			break;
		case 1:
			resultArray[i] = 1;
			overFlow = 0;
			break;
		case 2:
			resultArray[i] = 0;
			overFlow = 1;
			break;
		case 3:
			resultArray[i] = 1;
			overFlow = 1;
			break;
		}
	}
}

void binaryConverterOfExtraCode(bool array[]) {
	for (int i = 0; i < 32; ++i) {
			if (array[i]) {
				array[i] = 0;
			}
			else
			{
				array[i] = 1;
			}
		}

	bool additionalArray[32] = { 0 };
	additionalArray[31] = 1;
	bool storagearray[32] = { 0 };
	binarySummator(array, additionalArray, storagearray);
	for (int i = 0; i < 32; ++i) {
		array[i] = storagearray;
	}
}

void binaryUnpacker(int value, bool array[]) {
	for (int i = 0; i < 32; ++i) {
		array[i] = value % 2;
		value /= 2;
	}

	if (value < 0) {
		binaryConverterOfExtraCode(array);
	}
}

int binaryPacker(bool array[]) {
	int value = 0;
	bool minus = false;
	if (array[0]) {
		binaryConverterOfExtraCode(array);
		minus = true;
	}

	int powerOfTwo = 2147483648;
	for (int i = 0; i < 32; ++i) {
		if (array[i]) {
			value += powerOfTwo;
		}

		powerOfTwo /= 2;
	}

	if (minus) {
		return -value;
	}

	return value;
}