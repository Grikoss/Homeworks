#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

typedef char dataType;
bool isTestModOn = false;
void switchTestMod() {
	isTestModOn = !isTestModOn;
}

void decodeError(int code) {
	switch (code)
	{
	case(1):
		printf("Memory allocation error\n");

	case (2):
		printf("NULL ptr input error\n");

	default:
		exit(0);
	}
}

typedef struct Element {
	dataType* name;
	dataType* telephone;
	struct Element* next;
} Element;

typedef struct List {
	struct Element* head;
	struct Element* point;
	int quantity;
} List;

List* createNewList(void) {
	Element* element = calloc(1, sizeof(Element));
	if (element == NULL) {
		if (isTestModOn) {
			return NULL;
		}
		else {
			decodeError(1);
		}
	}

	List* list = calloc(1, sizeof(List));
	if (list == NULL) {
		if (isTestModOn) {
			return NULL;
		}
		else {
			decodeError(1);
		}
	}

	element->next = NULL;
	list->quantity = 0;
	list->head = element;
	list->point = list->head;
	return list;
}

bool isEnd(List* list) {
	if (list == NULL || list->head == NULL) {
		if (isTestModOn) {
			return true;
		}
		else {
			decodeError(2);
		}
	}

	return list->head->next == NULL;
}

int deleteList(List* list) {
	if (list == NULL) {
		if (isTestModOn) {
			return 2;
		}
		else {
			decodeError(2);
		}
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
		if (isTestModOn) {
			return 2;
		}
		else {
			decodeError(2);
		}
	}

	Element* element = malloc(sizeof(Element));
	if (element == NULL) {
		if (isTestModOn) {
			return 1;
		}
		else {
			decodeError(1);
		}
	}

	element->name = name;
	element->telephone = telephone;
	element->next = list->head;
	list->head = element;
	list->point = list->head;
	++list->quantity;
	return 0;
}

int getElement(List* list, dataType** name, dataType** telephone) {
	if (list == NULL) {
		if (isTestModOn) {
			return 2;
		}
		else {
			decodeError(2);
		}
	}

	if (list->point->next != NULL) {
		*name = list->point->name;
		*telephone = list->point->telephone;
		list->point = list->point->next;
		return 0;
	}

	list->point = list->head;
	return -1;
}

dataType* searchElement(List* list, dataType* input, bool isSearchByName) {
	if (list == NULL || input == NULL) {
		if (isTestModOn) {
			return NULL;
		}
		else {
			decodeError(2);
		}
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