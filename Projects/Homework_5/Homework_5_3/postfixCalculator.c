#include "postfixCalculator.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Cell {
	int item; 
	struct Cell* next;
} Cell;

typedef struct Pointer {
	struct Cell* head;
	int quantity;
} Pointer;

Pointer* createNewStruct(void) {
	Cell* cell = malloc(sizeof(Cell));
	if (cell == NULL) {
		return NULL;
	}

	Pointer* pointer = malloc(sizeof(Pointer));
	if (pointer == NULL) {
		return NULL;
	}

	cell->item = 0;
	cell->next = NULL;
	pointer->quantity = 0;
	pointer->head = cell;
	return pointer;
}

bool isEnd(Pointer* pointer) {
	return pointer->head->next == NULL;
}

void deleteStruct(Pointer* pointer) {
	while (!isEnd(pointer)) {
		Cell* oldHead = pointer->head;
		pointer->head = pointer->head->next;
		free(oldHead);
	}

	free(pointer->head);
	free(pointer);
}

void addNewItem(Pointer* pointer, char* inputItem) {
	Cell* cell = malloc(sizeof(Cell));
	if (cell == NULL) {
		return;
	}
	
	cell->item = atoi(inputItem);
	cell->next = pointer->head;
	pointer->head = cell;
	++pointer->quantity;
}

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

void perfomOperation(Pointer* pointer, int sign) {
	if (pointer->head->next == NULL) {
		printf("Invalid input");
		exit(0);
	}

	if (pointer->head->next->next == NULL) {
		printf("Invalid input");
		exit(0);
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
}

int postfixCalculator(char* string) {
	Pointer* pointer = createNewStruct();
	char* subString = strtok(string, " ");
	while (subString != NULL) {
		int sign = determineSign(subString);
		if (sign == 0) {
			addNewItem(pointer, subString);
		}
		else {
			perfomOperation(pointer, sign);
		}

		subString = strtok(NULL, " ");
	}

	if (pointer->quantity != 1) {
		printf("Invalid input");
		exit(0);
	}

	int result = pointer->head->item;
	deleteStruct(pointer);
	return result;
}