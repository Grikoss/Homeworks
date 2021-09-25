#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "file.h"

const int sizeBuffer = 31;

char* readFromFile() {
	FILE* file = fopen("telephone.txt", "r");
	if (file == NULL) {
		FILE* file = fopen("telephone.txt", "w");
		if (file == NULL) {
			return NULL;
		}

		fclose(file);
		file = fopen("telephone.txt", "r");
		if (file == NULL) {
			return NULL;
		}
	}

	if (file == NULL) {
		return NULL;
	}

	if (feof(file)) {
		fclose(file);
		return NULL;
	}

	char cursor = 'a';
	while ((cursor = fgetc(file)) == ' ' || cursor == '\n');
	if (cursor == EOF || cursor == '\0') {
		fclose(file);
		return NULL;

	}

	char* buffer = calloc(sizeBuffer, sizeof(char));
	if (buffer == NULL) {
		return NULL;
	}

	int counter = 0;
	while (cursor != ' ' && cursor !='\n' && cursor != EOF && cursor != '\0' && counter < (sizeBuffer - 1)) {
		buffer[counter] = cursor;
		cursor = fgetc(file);
		++counter;
		if (counter == (sizeBuffer -1)) {
			buffer[sizeBuffer - 1] = '\0';
		}
	}

	return buffer;
}