#include "postfixCalculator.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int determineSign(char* subString) {
	if (strcmp(subString, "+") == 0 || strcmp(subString, "+\n") == 0) {
		return 1;
	}

	if (strcmp(subString, "-") == 0 || strcmp(subString, "-\n") == 0) {
		return 2;
	}

	if (strcmp(subString, "*") == 0 || strcmp(subString, "*\n") == 0) {
		return 3;
	}

	if (strcmp(subString, "/") == 0 || strcmp(subString, "/\n") == 0) {
		return 4;
	}

	return 0;
}

int perfomOperation(Pointer* pointer, int sign) {
	if (pointer->head->next == NULL) {
		return 1;
	}

	if (pointer->head->next->next == NULL) {
		return 1;
	}

	int valueOne = pointer->head->item;
	int valueTwo = pointer->head->next->item;

	if (sign == 1) {
		pointer->head->next->item = valueTwo + valueOne;
	}

	if (sign == 2) {
		pointer->head->next->item = valueTwo - valueOne;
	}

	if (sign == 3) {
		pointer->head->next->item = valueTwo * valueOne;
	}

	if (sign == 4) {
		pointer->head->next->item = valueTwo / valueOne;
	}

	Cell* oldHead = pointer->head;
	pointer->head = pointer->head->next;
	--pointer->quantity;
	free(oldHead);
	return 0;
}

int postfixCalculator(int* result, char* string) {
	Pointer* pointer = createNewStruct();
	char* subString = strtok(string, " ");
	while (subString != NULL) {
		int sign = determineSign(subString);
		if (sign == 0) {
			addNewItem(pointer, subString);
		}
		else {
			if (perfomOperation(pointer, sign) == 1) {
				return 1;
			}
		}

		subString = strtok(NULL, " ");
	}

	if (pointer->quantity != 1) {
		return 1;
	}

	*result = pointer->head->item;
	deleteStruct(&pointer);
	return 0;
}