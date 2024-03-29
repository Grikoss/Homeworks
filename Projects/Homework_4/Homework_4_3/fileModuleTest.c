#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "file.h"
#include "fileModuleTest.h"

const int sizeOfArray = 10;

bool writeToFileTest(FILE* file)
{
    char name[] = "name";
    char telephone[] = "telephone";
    if (writeToFile(NULL, name, ' ') != 1 || writeToFile(file, NULL, ' ') != 1)
    {
        fclose(file);
        return false;
    }

    writeToFile(file, name, ' ');
    writeToFile(file, telephone, '\n');
    return true;
}

bool readFromFileTest(FILE* file)
{
    if (readFromFile(NULL) != NULL)
    {
        return false;
    }

    char name[] = "name";
    char telephone[] = "telephone";
    char* outName = readFromFile(file);
    if (outName == NULL)
    {
        return false;
    }

    char* outTelephone = readFromFile(file);
    if (outTelephone == NULL)
    {
        free(outName);
        return false;
    }

    if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0)
    {
        free(outName);
        free(outTelephone);
        return false;
    }

    free(outName);
    free(outTelephone);

    return readFromFile(file) == NULL;
}

bool runFileModuleTest()
{
    FILE* file = fopen("telephoneTest.txt", "w");
    bool result = writeToFileTest(file);
    fclose(file);
    file = fopen("telephoneTest.txt", "r");
    result = result && readFromFileTest(file);
    fclose(file);
    remove("telephoneTest.txt");
    return result;
}