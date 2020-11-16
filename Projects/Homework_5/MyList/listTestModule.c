#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listTestModule.h"

void runListTestModule(void) {
	List* list = createNewList();
	if (list == NULL) {
		printf("createNewList test failed\n");
	}

	int quantity = 0;
	if (getQuantity(&quantity, list) != 0) {
		printf("getQuantity test failed\n");
	}
	else {
		if (getQuantity(NULL, list) != 1 || getQuantity(NULL, NULL) != 1) {
			printf("getQuantity test failed\n");
		}
	}

	char* string = (char*)malloc(sizeof(char)*100);
	if (addElement(list, string) != 0) {
		printf("addElement test failed\n");
	}
	else {
		if (addElement(NULL, NULL) != 1) {
			printf("addElement test failed\n");
		}
		else {
			if (getQuantity(&quantity, list), quantity != 1) {
				printf("addElement test failed\n");
			}
		}
	}

	if (deleteElement(NULL) != 1) {
		printf("deleteElement test failed");
	}
	else {
		if (deleteElement(list) != 0) {
			printf("deleteElement test failed");
		}
		else {
			if (getQuantity(&quantity, list), quantity != 0) {
				printf("deleteElement test failed\n");
			}
			else {
				if (deleteElement(list) != 1) {
					printf("deleteElement test failed\n");
				}
			}
		}
	}

	if (deleteList(NULL) != 1) {
		printf("deleteList test failed\n");
	}
	else {
		if (deleteList(&list) != 0) {
			printf("deleteList test failed\n");
		}
	}
}