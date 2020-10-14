#pragma once

#include <stdbool.h>
#include "binary.h"
#define SIZEOFINT 32

void binarySummator(bool arrayOne[], bool arrayTwo[], bool resultArray[]) {
	bool overFlow = 0;
	int subSum = 0;
	for (int i = 0; i < SIZEOFINT; ++i) {
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

void binaryUnpacker(int value, bool array[]) {
	for (int i = 0; i < SIZEOFINT; ++i) {
		if ((value & 1) == 1) {
			array[i] = 1;
		}
		else 
		{
			array[i] = 0;
		}

		value >>= 1;
	}
}

int binaryPacker(bool array[]) {
	int value = 0;

	int powerOfTwo = 1;
	for (int i = 0; i < SIZEOFINT; ++i) {
		if (array[i]) {
			value += powerOfTwo;
		}

		powerOfTwo *= 2;
	}

	return value;
}