#pragma once

#include<stdio.h>
#include<stdlib.h>
#include"Reading.h"

int readFromFile(FILE* file, int array[]) {
	free(array);
	array = (int*)calloc(1, sizeof(int));
	int index = 0;
	while (!feof(file))
	{
		unsigned char* buffer = (unsigned char*)malloc(4 * sizeof(unsigned char));
		if (buffer == NULL) {
			return 0;
		}

		const int readBytes = fscanf(file, "%s", buffer);
		if (readBytes < 0) 
		{ 
			break;
		}

		array[index] = *buffer;
		++index;
		array = realloc(array, (index + 1) * sizeof(int));
		free(buffer); 
	}

	return index + 1;
}