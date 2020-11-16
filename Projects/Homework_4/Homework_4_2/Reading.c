#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Reading.h"

typedef struct ScannedItem {
	char item[100];
	struct ScannedItem* next;
} ScannedItem;

typedef struct HeadPointer {
	ScannedItem* head;
} HeadPointer;

HeadPointer* createNewBox() {
	ScannedItem* item = malloc(sizeof(ScannedItem));
	if (item == NULL) {
		return NULL;
	}

	HeadPointer* pointer = malloc(sizeof(HeadPointer));
	if (pointer == NULL) {
		return NULL;
	}

	item->next = NULL;
	pointer->head = item;
	return pointer;
}

bool isEnd(HeadPointer* pointer) {
	return pointer->head->next == NULL;
}

void deleteBox(HeadPointer* pointer) {
	while (!isEnd(pointer)) {
		ScannedItem* oldHead = pointer->head;
		pointer->head = pointer->head->next;
		free(oldHead);
	}

	free(pointer->head);
	free(pointer);
}

int* convertCharToInt(HeadPointer* pointer, int size) {
	ScannedItem* oldHead = pointer->head;
	pointer->head = pointer->head->next;
	int* array = (int*)calloc(size, sizeof(int));
	if (array == NULL) {
		return NULL;
	}

	int index = 0;
	for (HeadPointer* i = pointer; !isEnd(i); i->head = i->head->next ) {
		array[index] = atoi(i->head->item);
		++index;
	}

	return array;
}

void addNewItem(HeadPointer* pointer) {
	ScannedItem* item = malloc(sizeof(ScannedItem));
	if (item == NULL) {
		return;
	}

	item->next = pointer->head;
	pointer->head = item;
}

int readFromFile(FILE* file, int** array) {
	HeadPointer* box = createNewBox();
	addNewItem(box);
	int size = 0;
	while (!feof(file))
	{
		const int readBytes = fscanf(file, "%s", box->head->item);
		if (readBytes < 0) { 
			break; 
		}

		addNewItem(box);
		++size;
	}

	*array = convertCharToInt(box, size);
	deleteBox(box);
	return size;
}