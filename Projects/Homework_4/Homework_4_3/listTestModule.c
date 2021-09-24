#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listTestModule.h"

bool runModuleTest() {
	List* list = createNewList();
	if (list == NULL) {
		return false;
	}


	char name[] = "Name";
	char telephone[] = "Telephone";
	if (addNewElement(NULL, NULL, NULL) != 1 || addNewElement(list, name, telephone) != 0) {
		return false;
	}

	char nameTest[] = "NameTest";
	char telephoneTest[] = "TelephoneTest";
	for (int i = 0; i < 98; ++i) {
		addNewElement(list, nameTest, telephoneTest);
	}

	addNewElement(list, name, telephone);

	if (addNewElement(list, nameTest, telephoneTest) != 2) {
		return false;
	}

	List* testList = createNewList();
	char* outName = NULL;
	char* outTelephone = NULL;
	if (getElements(NULL, NULL, NULL) != 1 || getElements(testList, &outName, &outTelephone) != 1) {
		return false;
	}

	if (getElements(list, &outName, &outTelephone) != 0) {
		return false;
	}

	if (outName != name || outTelephone != telephone) {
		return false;
	}

	getElements(list, &outName, &outTelephone);

	if (outName != nameTest || outTelephone != telephoneTest) {
		return false;
	}

	if (resetPointer(NULL) != 1 || resetPointer(list) != 0) {
		return false;
	}

	getElements(list, &outName, &outTelephone);

	if (outName != name || outTelephone != telephone) {
		return false;
	}

	if (getQuantity(list) != 100 || getQuantity(NULL) != 0 || getQuantity(testList) != 0) {
		return false;
	}

	char trap[] = "trap";
	if (searchElement(NULL, NULL, true) != NULL || searchElement(testList, NULL, true) != NULL ||
		searchElement(testList, trap, true) != NULL) {
		return false;
	}

	if (searchElement(list, nameTest, true) != telephoneTest || searchElement(list, telephoneTest, false) != nameTest) {
		return false;
	}

	if (deleteList(NULL) != 1 || deleteList(list) != 0 || deleteList(testList) != 0) {
		return false;
	}

	return true;
}