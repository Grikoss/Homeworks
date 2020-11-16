#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Element {
	char* item;
	struct Element* next;
} Element;

typedef struct List {
	struct Element* head;
	int quantity;
} List;

List* createNewList(void) {
	Element* element = malloc(sizeof(Element));
	if (element == NULL) {
		return NULL;
	}

	List* list = malloc(sizeof(List));
	if (list == NULL) {
		return NULL;
	}

	element->item = NULL;
	element->next = NULL;
	list->quantity = 0;
	list->head = element;
	return list;
}

bool isEnd(Element* element) {
	return element->next == NULL;
}

int deleteList(List** list) {
	if (list == NULL) {
		return 1;
	}

	while (!isEnd((*list)->head)) {
		Element* oldHead = (*list)->head;
		(*list)->head = (*list)->head->next;
		if (oldHead->item != NULL){
			free(oldHead->item);
			}

		free(oldHead);
	}

	free((*list)->head);
	free((*list));
	return 0;
}

int addElement(List* list, char* inputItem) {
	if (list == NULL || inputItem == NULL) {
		return 1;
	}

	Element* element = malloc(sizeof(Element));
	if (element == NULL) {
		return 1;
	}

	element->item = inputItem;
	element->next = list->head;
	list->head = element;
	++list->quantity;
	return 0;
}

int deleteElement(List* list) {
	if (list == NULL) {
		return 1;
	}

	if (list->quantity <= 0) {
		return 1;
	}

	Element* oldHead = list->head;
	list->head = list->head->next;
	if (oldHead->item != NULL) {
		free(oldHead->item);
	}

	free(oldHead);
	--list->quantity;
	return 0;
}

int getQuantity(int* quantity, List* list) {
	if (list == NULL || quantity == NULL) {
		return 1;
	}

	*quantity = list->quantity;
	return 0;
}

char* getLastItem(List* list) {
	if (list == NULL || isEnd(list->head)) {
		return NULL;
	}

	if (list->head->item == NULL) {
		return NULL;
	}

	return list->head->item;
}