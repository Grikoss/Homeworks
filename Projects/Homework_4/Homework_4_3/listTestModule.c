#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listTestModule.h"

typedef char datatype;

void runModuleTest() {
	List* list = createNewList();
	if (list == NULL) {
		printf("createNewList test failed\n");
	}

	char name[] = "Name";
	char telephone[] = "Telephone";
	if (0 != addNewElement(list, name, telephone) || -1 != addNewElement(NULL, NULL, NULL)) {
		printf("addNewElement test failed\n");
	}

	if (!isEnd(NULL)) {
		printf("isEnd test failed\n");
	}

	if (getElements(NULL) != NULL) {
		printf("getElements test failed\n");
	}
	else {
		datatype** testArray = getElements(list);
		if (testArray == NULL) {
			printf("getElements test failed\n");
		}

		free(testArray);
	}

	if (searchElement(list, NULL, false) != NULL) {
		printf("searchElement test failed\n");
	}
	else {
		if (searchElement(list, name, true) == NULL) {
			printf("searchElement test failed\n");
		}
	}

	if (getQuantity(NULL) != 0 || getQuantity(list) != 1) {
		printf("getQuantity test failed\n");
	}

	if (0 != deleteList(list) || 0 != deleteList(NULL)) {
		printf("deleteList test failed\n");
	}
}