#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "file.h"

const int sizeBuffer = 31;

char* readFromFile(FILE* file) {
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
	while (cursor != ' ' && cursor !='\n' && cursor != EOF && cursor != '\0') {
		buffer[counter] = cursor;
		cursor = fgetc(file);
		++counter;
		if (counter == (sizeBuffer -1)) {
			while (cursor != ' ' && cursor != '\n' && cursor != EOF && cursor != '\0') {
				cursor = fgetc(file);
			}
		}
	}

	buffer[counter] = '\0';
	return buffer;
}

int writeToFile(FILE* file, char* input, char literal) {
	if (file == NULL || input == NULL) {
		return 1;
	}

	fprintf(file, input);
	literal == '\n' ? fprintf(file, "\n") : 0;
	literal == ' ' ? fprintf(file, " ") : 0;

	return 0;
}