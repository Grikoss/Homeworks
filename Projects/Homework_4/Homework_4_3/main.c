#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "listTestModule.h"
#include "file.h"
#include "fileModuleTest.h"

const int sizeOfInput = 31;
const int size = 100;

void subtractStream(void)
{
    while (scanf_s("%*c") != 0);
}

char* inputString(int size)
{
    char* buffer = calloc(size, sizeof(char));
    if (buffer == NULL)
    {
        return NULL;
    }

    if (scanf_s("%s", buffer, size) > 0)
    {
        return buffer;
    }
    else
    {
        free(buffer);
        return NULL;
    }
}

void addARecord(List* list, bool* isAnyNewRecords)
{
    if (getQuantity(list) == 100)
    {
        printf("More than 100 records are not available\n");
        return;
    }
    
    printf("Enter name:\n");
    char* name = NULL;
    while (name == NULL)
    {
        name = inputString(sizeOfInput);
    }

    printf("Enter telephone:\n");
    char* telephone = NULL;
    while (telephone == NULL)
    {
        telephone = inputString(sizeOfInput);
    }

    addNewElement(list, name, telephone);
    *isAnyNewRecords = true;
    printf("Current number of phones is %d\n", getQuantity(list));
}

void printAllAvailableRecords(List* list)
{
    printf("Records:\n");
    resetPointer(list);
    if (getQuantity(list) == 0)
    {
        printf("There are no records!\n");
        return;
    }

    for (int i = 0; i < getQuantity(list); ++i)
    {
        char* outName = NULL;
        char* outTelephone = NULL;
        getElements(list, &outName, &outTelephone);
        printf("%i) Name: ", i + 1);
        fputs(outName, stdout);
        printf(" Telephone: ");
        puts(outTelephone);
    }
}

void findRecord(List* list, bool isSearchByName)
{
    isSearchByName ? printf("Enter the name: ") : printf("Enter the telephone: ");
    char* key = inputString(sizeOfInput);
    char* search = searchElement(list, key, isSearchByName);
    free(key);

    if (search == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        isSearchByName ? printf("The telephone: ") : printf("The name: ");
        puts(search);
    }
}

void saveRecords(List* list, bool* isAnyNewRecords)
{
    FILE* file = fopen("telephone.txt", "w");
    char* writeName = NULL;
    char* writeTelehone = NULL;
    for (int i = 0; i < getQuantity(list); ++i)
    {
        getElements(list, &writeName, &writeTelehone);
        writeToFile(file, writeName, ' ');
        writeToFile(file, writeTelehone, '\n');
    }

    fclose(file);
    *isAnyNewRecords = false;
    printf("Records saved succesfully\n");
}

void startReadingFromFile(List* list, FILE* file)
{
    char* inputName = readFromFile(file);
    char* inputTelephone = readFromFile(file);
    while (inputName != NULL && inputTelephone != NULL)
    {
        addNewElement(list, inputName, inputTelephone);
        inputName = readFromFile(file);
        inputTelephone = readFromFile(file);
    }

    fclose(file);
    free(inputName);
    free(inputTelephone);
}

int main(int argc, char* argv[])
{
    if (!runListModuleTest())
    {
        return 1;
    }

    if (!runFileModuleTest())
    {
        return 2;
    }
    if (argc > 1)
    {
        return 0;
    }
    FILE* file = fopen("telephone.txt", "r");
    if (file == NULL)
    {
        file = fopen("telephone.txt", "w");
        if (file == NULL)
        {
            return 3;
        }

        fclose(file);
        file = fopen("telephone.txt", "r");
    }

    List* list = createNewList();
    startReadingFromFile(list, file);

    printf("Welcome to telephone book\n");
    printf("Current number of phones is %d\n", getQuantity(list));
    printf("Max current number of phones is %i\n", size);
    printf("Available options:\n");
    printf("0 - exit\n1 - add a record (name and phone number)\n2 - print all available records\n");
    printf("3 - find a phone by name\n4 - find a name by phone\n5 - save the current data to a file\n");
    int currentMod = 10;
    scanf_s("%d", &currentMod);
    subtractStream();
    bool isAnyNewRecords = false;
    while (currentMod != 0)
    {
        while (currentMod != 1 && currentMod != 2 && currentMod != 3 && currentMod != 4 && currentMod != 5 && currentMod != 0)
        {
            if (scanf_s("%d", &currentMod) == 0)
            {
                currentMod = 10;
            }

            subtractStream();
        }

        switch (currentMod)
        {   
            case 1:
                addARecord(list, &isAnyNewRecords);
                break;
            case 2:
                printAllAvailableRecords(list);
                break;
            case 3:
            case 4:
                findRecord(list, currentMod == 3);
                break;
            case 5:
                saveRecords(list, &isAnyNewRecords);
                break;
            default:
                break;
        }

        if (currentMod != 0)
        {
            printf("Choose option:\n");
            if (scanf_s("%d", &currentMod) == 0)
            {
                currentMod = 10;
            }

            subtractStream();
        }

        if (currentMod == 0 && isAnyNewRecords)
        {
            printf("You haven't saved the latest changes. Confirm to continue(Enter 0 if yes): \n");
            if (scanf_s("%d", &currentMod) == 0)
            {
                currentMod = 10;
            }

            subtractStream();
            if (currentMod != 0)
            {
                currentMod = 10;
                printf("Choose option:\n");
            }
        }
    }
    
    deleteList(list);
    return 0;
}