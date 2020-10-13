#pragma once

#include <stdbool.h>

#include "binary.h"

void binarySummator(bool arrayOne[], bool arrayTwo[], bool resultArray[]) {

}

void binaryConverterOfExtraCode(bool array[]) {
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
	if (array[0]) {
		binaryConverterOfExtraCode(array);
	}
}