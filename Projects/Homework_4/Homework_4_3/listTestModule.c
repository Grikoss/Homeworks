#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listTestModule.h"

void runModuleTest() {
	List* list = createNewList();
	if (list == NULL) {
		printf("createNewList test failed\n");
	}

	char name[] = "Name";
	char telephone[] = "Telephone";
	if (0 != addNewElement(list, name, telephone) || 0 != addNewElement(NULL, NULL, NULL)) {
		printf("addNewElement test failed\n");
	}

	if (isEnd(list) || !isEnd(NULL)) {
		printf("isEnd test failed\n");
	}

	char* stringOne = NULL;
	char* stringTwo = NULL;
	if (getElements(NULL, &stringOne, &stringTwo) != 0) {
		printf("getElement test failed\n");
	}
	else {
		if (getElements(list, &stringOne, &stringTwo) != 0) {
			printf("getElement test failed\n");
		}
	}

	if (searchElement(list, stringTwo, false) != NULL) {
		printf("searchElement test failed\n");
	}
	else {
		if (searchElement(list, name, true) == NULL) {
			printf("searchElement test failed\n");
		}
	}

	if (0 != deleteList(list) || 0 != deleteList(NULL)) {
		printf("deleteList test failed\n");
	}

}