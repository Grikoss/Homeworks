#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

typedef char dataType;

typedef struct Element {
	dataType* name;
	dataType* telephone;
	struct Element* next;
} Element;

typedef struct List {
	struct Element* head;
	int quantity;
} List;

List* createNewList(void) {
	Element* element = calloc(1, sizeof(Element));
	if (element == NULL) {
		return NULL;
	}

	List* list = calloc(1, sizeof(List));
	if (list == NULL) {
		return NULL;
	}

	element->next = NULL;
	list->quantity = 0;
	list->head = element;
	return list;
}

bool isEnd(List* list) {
	if (list == NULL || list->head == NULL) {
		return true;
	}

	return list->head->next == NULL;
}

int deleteList(List* list) {
	if (list == NULL) {
		return 0;
	}

	while (!isEnd(list)) {
		Element* oldHead = list->head;
		list->head = list->head->next;
		free(oldHead);
	}

	free(list->head);
	free(list);
	return 0;
}

int addNewElement(List* list, char* name, char* telephone) {
	if (list == NULL || name == NULL || telephone == NULL) {
			return 0;
	}

	if (list->quantity >= 100) {
		return -1;
	}

	Element* element = malloc(sizeof(Element));
	if (element == NULL) {
		return 1;
	}

	element->name = name;
	element->telephone = telephone;
	element->next = list->head;
	list->head = element;
	++list->quantity;
	return 0;
}

dataType** getElements(List* list) {
	if (list == NULL) {
			return NULL;
	}

	int counter = 0;
	dataType** output = malloc(sizeof(dataType**) * 200);
	for (List* i = list; !isEnd(i); i->head = i->head->next) {
		output[counter] = (i->head->name);
		++counter;
		output[counter] = (i->head->telephone);
		++counter;
	}

	return output;
}

dataType* searchElement(List* list, dataType* input, bool isSearchByName) {
	if (list == NULL || input == NULL) {
		return NULL;
	}

	if (isSearchByName) {
		for (List* i = list; !isEnd(i); i->head = i->head->next) {
			if (strcmp(i->head->name, input) == 0) {
				return i->head->telephone;
			}
		}
	}
	else {
		for (List* i = list; !isEnd(i); i->head = i->head->next) {
			if (strcmp(i->head->telephone, input) == 0) {
				return i->head->name;
			}
		}
	}

	return NULL;
}