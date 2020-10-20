#include "listTestModule.h"
#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char* dataType;

void errorCodesAreIncorrect() {
	printf("Error codes are incorrect");
	exit(0);
}

void runListTest() {
	List* list = NULL;
	int array[3] = { 0 };
	++array[createList(&list)];
	bool isEmpty = true;
	++array[checkEmpty(list, &isEmpty)];
	if (2 != checkEmpty(NULL, &isEmpty)) {
		errorCodesAreIncorrect();
	}

	dataType testObjectOne = "A";
	dataType testObjectTwo = "A";
	++array[addNewElement(list, testObjectOne, testObjectTwo)];
	if (2 != addNewElement(NULL, testObjectOne, testObjectTwo) || 2 != addNewElement(list, NULL, testObjectTwo) || 2 != addNewElement(list, testObjectOne, NULL)) {
		errorCodesAreIncorrect();
	}

	++array[deleteList(&list)];
	list = NULL;
	if (2 != deleteList(&list)) {
		errorCodesAreIncorrect();
	}

	if (array[1] || array[2]) {
		for (int i = 0; i < 3; ++i) {
			printf("Number of error codes %i = %i\n", i, array[i]);
		}
	}
}