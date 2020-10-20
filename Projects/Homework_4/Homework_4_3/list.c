#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef char* dataType;

typedef struct Element {
	dataType name;
	dataType telephone;
	struct Element* next;
} Element;

typedef struct List {
	Element* head;
} List;

int createList(List** output) {
	List* list = malloc(sizeof(List));
	if (list == NULL) {
		return 1;
	}

	*output = list;
	return 0;
}

int checkEmpty(List* list, bool* isEmpty ) {
	*isEmpty = true;
	if (list == NULL) {
		return 2;
	}	

	*isEmpty = (list->head == NULL) ? true : false;
	return 0;
}

int deleteList(List** list) {
	if (*list == NULL) {
		return 2;
	}

	bool isEmpty = true;
	for (List* i = *list; isEmpty = checkEmpty(i, &isEmpty); i->head = i->head->next) {
		free(i->head);
	}

	if ((*list)->head != NULL) {
		return 1;
	}

	free(*list);
	return (*list == NULL) ? 0 : 1;
}

int addNewElement(List* list, dataType name, dataType telephone) {
	if (name == NULL || telephone == NULL || list == NULL) {
		return 2;
	}

	Element* element = malloc(sizeof(Element));
	if (element == NULL) {
		return 1;
	}
	
	element->name = name;
	element->telephone = telephone;
	element->next = list->head;
	list->head = element;
	return 0;
}