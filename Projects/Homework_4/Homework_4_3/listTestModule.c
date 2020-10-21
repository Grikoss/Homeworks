#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listTestModule.h"

void runModuleTest() {
	switchTestMod();
	List* list = createNewList();
	if (list == NULL) {
		printf("createNewList test failed\n");
	}

	char name[] = "Name";
	char telephone[] = "Telephone";
	if (0 != addNewElement(list, name, telephone) || 2 != addNewElement(NULL, NULL, NULL)) {
		printf("addNewElement test failed\n");
	}

	if (isEnd(list) || !isEnd(NULL)) {
		printf("isEnd test failed\n");
	}

	char* stringOne = NULL;
	char* stringTwo = NULL;
	if (getElement(NULL, &stringOne, &stringTwo) != 2 || getElement(list, &stringOne, &stringTwo) != 0) {
		printf("getElement test failed\n");
	}
	else {
		if (getElement(list, &stringOne, &stringTwo) != -1) {
			printf("getElement test failed\n");
		}
	}

	if (strcmp(searchElement(list, name, true), stringTwo) != 0) {
		printf("searchElement test failed\n");
	}
	else {
		if (strcmp(searchElement(list, stringTwo, false), name) != 0) {
			printf("searchElement test failed\n");
		}
	}

	if (0 != deleteList(list) || 2 != deleteList(NULL)) {
		printf("deleteList test failed\n");
	}

	switchTestMod();
}