#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listTestModule.h"

const int sizeBookTest = 100;
const int sizeArray = 20;

bool createListTest(List* list)
{
	if (list == NULL)
	{
		return false;
	}

	return true;
}

bool addNewElementTest(List* list)
{
	char* name = calloc(sizeArray, sizeof(char));
	if (name == NULL)
	{
		return false;
	}

	strcpy(name, "Name");
	char* telephone = calloc(sizeArray, sizeof(char));
	if (telephone == NULL)
	{
		free(name);
		return false;
	}

	strcpy(telephone, "Telephone");
	if (addNewElement(list, name, telephone) != 0)
	{
		free(name);
		free(telephone);
		return false;
	}

	if (addNewElement(NULL, NULL, NULL) != 1)
	{
		free(name);
		free(telephone);
		return false;
	}

	char* nameTest = NULL;
	char* telephoneTest = NULL;
	for (int i = 0; i < (sizeBookTest - 2); ++i)
	{
		nameTest = calloc(sizeArray, sizeof(char));
		if (nameTest == NULL)
		{
			return false;
		}

		strcpy(nameTest, "NameTest");
		telephoneTest = calloc(sizeArray, sizeof(char));
		if (telephoneTest == NULL)
		{
			free(nameTest);
			return false;
		}

		strcpy(telephoneTest, "TelephoneTest");
		addNewElement(list, nameTest, telephoneTest);
	}

	/*if (nameTest == NULL || telephoneTest == NULL)
	{
		return false;
	}*/

	name = calloc(sizeArray, sizeof(char));
	if (name == NULL)
	{
		return false;
	}

	strcpy(name, "Name");
	telephone = calloc(sizeArray, sizeof(char));
	if (telephone == NULL)
	{
		free(name);
		return false;
	}

	strcpy(telephone, "Telephone");
	addNewElement(list, name, telephone);

	if (addNewElement(list, nameTest, telephoneTest) != 2)
	{
		return false;
	}

	return true;
}

bool getElementsTest(List* list, List* testList)
{
	char* name = calloc(sizeArray, sizeof(char));
	if (name == NULL)
	{
		return false;
	}

	strcpy(name, "Name");
	char* telephone = calloc(sizeArray, sizeof(char));
	if (telephone == NULL)
	{
		free(name);
		return false;
	}

	strcpy(telephone, "Telephone");
	char* nameTest = calloc(sizeArray, sizeof(char));
	if (nameTest == NULL)
	{
		free(name);
		free(telephone);
		return false;
	}

	strcpy(nameTest, "NameTest");
	char* telephoneTest = calloc(sizeArray, sizeof(char));
	if (telephoneTest == NULL)
	{
		free(name);
		free(telephone);
		free(nameTest);
		return false;
	}

	strcpy(telephoneTest, "TelephoneTest");
	char* outName = NULL;
	char* outTelephone = NULL;
	if (getElements(NULL, NULL, NULL) != 1 || getElements(testList, &outName, &outTelephone) != 1 || getElements(list, &outName, NULL) != 1
		|| getElements(list, NULL, &outTelephone) != 1)
	{
		return false;
	}

	if (getElements(list, &outName, &outTelephone) != 0)
	{
		return false;
	}

	if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0)
	{
		return false;
	}

	for (int i = 0; i < (sizeBookTest - 2); ++i)
	{
		getElements(list, &outName, &outTelephone);
		if (strcmp(outName, nameTest) != 0 || strcmp(outTelephone, telephoneTest) != 0)
		{
			return false;
		}
	}

	getElements(list, &outName, &outTelephone);

	if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0)
	{
		return false;
	}

	getElements(list, &outName, &outTelephone);

	if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0) //������ ��� ��� �������� pointer
	{
		return false;
	}

	if (resetPointer(NULL) != 1 || resetPointer(list) != 0)
	{
		return false;
	}

	getElements(list, &outName, &outTelephone);

	if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0) //��� ���� �������� pointer
	{
		return false;
	}

	free(name);
	free(telephone);
	free(nameTest);
	free(telephoneTest);
	return true;
}

bool getQuantityTest(List* list, List* testList)
{
	if (getQuantity(list) != sizeBookTest || getQuantity(NULL) != 0 || getQuantity(testList) != 0)
	{
		return false;
	}

	return true;
}

bool searchElementTest(List* list, List* testList)
{
	char* nameTest = calloc(sizeArray, sizeof(char));
	if (nameTest == NULL)
	{
		return false;
	}

	strcpy(nameTest, "NameTest");
	char* telephoneTest = calloc(sizeArray, sizeof(char));
	if (telephoneTest == NULL)
	{
		free(nameTest);
		return false;
	}
	
	strcpy(telephoneTest, "TelephoneTest");
	char trap[] = "trap";
	if (searchElement(NULL, NULL, true) != NULL || searchElement(testList, NULL, true) != NULL ||
		searchElement(testList, trap, true) != NULL)
	{
		free(nameTest);
		free(telephoneTest);
		return false;
	}

	if (strcmp(searchElement(list, nameTest, true), telephoneTest) != 0 || strcmp(searchElement(list, telephoneTest, false), nameTest) != 0)
	{
		free(nameTest);
		free(telephoneTest);
		return false;
	}

	free(nameTest);
	free(telephoneTest);
	return true;
}

bool deleteListTest(List* list, List* testList)
{
	if (deleteList(NULL) != 1 || deleteList(list) != 0 || deleteList(testList) != 0)
	{
		return false;
	}

	return true;
}

bool runListModuleTest()
{
	bool result = true;
	List* list = createNewList();
	result = result && createListTest(list);
	result = result && addNewElementTest(list);
	List* testList = createNewList();
	result = result && getElementsTest(list, testList);
	result = result && getQuantityTest(list, testList);
	result = result && searchElementTest(list, testList);
	result = result && deleteListTest(list, testList);
	return result;
}