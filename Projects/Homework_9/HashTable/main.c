#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "hashFunction.h"
#include "hashTable.h"
#include "listTest.h"
#include "hashFunctionTest.h"
#include "hashTableTest.h"

#define SIZE_OF_BUFFER 100

int main(void)
{
    if (isListBehavesIncorrectly())
    {
        return 1;
    }
    if (isHashFunctionBehavesIncorrectly())
    {
        return 2;
    }
    if (isHashTableBehavesIncorrectly())
    {
        return 3;
    }
    int size = 0;
    printf_s("Enter size of hash table:\n");
    while (size <= 0)
    {
        if (scanf_s("%d", &size) == 0)
        {
            scanf_s("%*s");
        }
    }
    FILE* file = NULL;
    fopen_s(&file, "input.txt", "r");
    if (file == NULL)
    {
        return 4;
    }
    HashTable* hashTable = NULL;
    createHashTable(&hashTable, size, getKey);
    char buffer[SIZE_OF_BUFFER] = { 0 };
    while (fscanf_s(file, "%s", buffer, SIZE_OF_BUFFER) != -1)
    {
        addElementIntoHashTable(hashTable, buffer);
    }
    fclose(file);
    printf_s("There are:\n");
    for (int i = 0; i < size; ++i)
    {
        List* list = NULL;
        getListFromHashTable(hashTable, i, &list);
        if (list != NULL)
        {
            printf_s("%d: ", i);
            Position* positon = createPosition();
            movePositionToHead(list, positon);
            while (!isPositionNull(positon))
            {
                char string[SIZE_OF_BUFFER] = { 0 };
                int count = 0;
                getValueFromListElement(positon, string, SIZE_OF_BUFFER, &count);
                printf_s("%s - count = %d | ", string, count);
                movePositionToNext(positon);
            }
            deletePosition(positon);
            printf_s("\n");
        }
        else
        {
            printf_s("%d is NULL\n", i);
        }
    }
    double fillFactor = 0;
    getTheFillFactor(hashTable, &fillFactor);
    int maxListLength = 0;
    getMaxListLength(hashTable, 0, size - 1, &maxListLength);
    double averageListLength = 0;
    getAverageListLength(hashTable, 0, size - 1, &averageListLength);
    printf_s("Fill factor = %f\n", fillFactor);
    printf_s("Max list length = %d\n", maxListLength);
    printf_s("Average list length = %f\n", averageListLength);
    deleteHashTable(&hashTable);
    return 0;
}