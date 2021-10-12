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
    return list != NULL;
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
    return addNewElement(list, nameTest, telephoneTest) == 2;
}

bool getElementsTest(List* list, List* testList)
{
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

    if (strcmp(outName, "Name") != 0 || strcmp(outTelephone, "Telephone") != 0)
    {
        return false;
    }

    for (int i = 0; i < (sizeBookTest - 2); ++i)
    {
        getElements(list, &outName, &outTelephone);
        if (strcmp(outName, "NameTest") != 0 || strcmp(outTelephone, "TelephoneTest") != 0)
        {
            return false;
        }
    }

    getElements(list, &outName, &outTelephone);

    if (strcmp(outName, "Name") != 0 || strcmp(outTelephone, "Telephone") != 0)
    {
        return false;
    }

    getElements(list, &outName, &outTelephone);

    if (strcmp(outName, "Name") != 0 || strcmp(outTelephone, "Telephone") != 0) // The second time to check the pointer
    {
        return false;
    }

    if (resetPointer(NULL) != 1 || resetPointer(list) != 0)
    {
        return false;
    }

    getElements(list, &outName, &outTelephone);

    if (strcmp(outName, "Name") != 0 || strcmp(outTelephone, "Telephone") != 0) // Another pointer check
    {
        return false;
    }

    return true;
}

bool getQuantityTest(List* list, List* testList)
{
    return !(getQuantity(list) != sizeBookTest || getQuantity(NULL) != 0 || getQuantity(testList) != 0);
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

bool runListModuleTest()
{
    List* list = createNewList();
    bool result = createListTest(list);
    result = result && addNewElementTest(list);
    List* testList = createNewList();
    result = result && getElementsTest(list, testList);
    result = result && getQuantityTest(list, testList);
    result = result && searchElementTest(list, testList);
    deleteList(list);
    deleteList(testList);
    return result;
}