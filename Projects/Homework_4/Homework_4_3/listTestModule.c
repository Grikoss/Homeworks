#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listTestModule.h"

const int sizeBookTest = 100;
const int sizeArray = 20;

bool runListModuleTest() {
	List* list = createNewList();
	if (list == NULL) {
		return false;
	}

	char* name = calloc(sizeArray, sizeof(char));
	if (name == NULL) {
		return false;
	}

	strcpy(name, "Name");
	char* telephone = calloc(sizeArray, sizeof(char));
	if (telephone == NULL) {
		return false;
	}

	strcpy(telephone, "Telephone");
	if (addNewElement(NULL, NULL, NULL) != 1 || addNewElement(list, name, telephone) != 0) {
		return false;
	}

	char* nameTest = NULL;
	char* telephoneTest = NULL;
	for (int i = 0; i < (sizeBookTest - 2); ++i) {
		nameTest = calloc(sizeArray, sizeof(char));
		if (nameTest == NULL) {
			return false;
		}

		strcpy(nameTest, "NameTest");
		telephoneTest = calloc(sizeArray, sizeof(char));
		if (telephoneTest == NULL) {
			return false;
		}

		strcpy(telephoneTest, "TelephoneTest");
		addNewElement(list, nameTest, telephoneTest);
	}

	if (nameTest == NULL || telephoneTest == NULL) {
		return false;
	}

	name = calloc(sizeArray, sizeof(char));
	if (name == NULL) {
		return false;
	}

	strcpy(name, "Name");
	telephone = calloc(sizeArray, sizeof(char));
	if (telephone == NULL) {
		return false;
	}

	strcpy(telephone, "Telephone");
	addNewElement(list, name, telephone);

	if (addNewElement(list, nameTest, telephoneTest) != 2) {
		return false;
	}

	List* testList = createNewList();
	char* outName = NULL;
	char* outTelephone = NULL;
	if (getElements(NULL, NULL, NULL) != 1 || getElements(testList, &outName, &outTelephone) != 1 || getElements(list, &outName, NULL) != 1
	|| getElements(list, NULL, &outTelephone) != 1) {
		return false;
	}

	if (getElements(list, &outName, &outTelephone) != 0) {
		return false;
	}

	if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0) {
		return false;
	}

	for (int i = 0; i < (sizeBookTest - 2); ++i) {
		getElements(list, &outName, &outTelephone);
		if (strcmp(outName, nameTest) != 0 || strcmp(outTelephone, telephoneTest) != 0) {
			return false;
		}
	}

	getElements(list, &outName, &outTelephone);

	if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0) {
		return false;
	}

	getElements(list, &outName, &outTelephone);

	if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0) { //второй раз для проверки pointer
		return false;
	}

	if (resetPointer(NULL) != 1 || resetPointer(list) != 0) {
		return false;
	}

	getElements(list, &outName, &outTelephone);

	if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0) {  //ещё одна проверка pointer
		return false;
	}

	if (getQuantity(list) != sizeBookTest || getQuantity(NULL) != 0 || getQuantity(testList) != 0) {
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