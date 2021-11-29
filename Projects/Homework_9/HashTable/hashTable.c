#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "hashTable.h"

typedef struct HashTable
{
    List** array;
    int (*keyGen)(const char* string);
    int count;
    int size;
} HashTable;

int createHashTable(HashTable** hashTable, const int size, int (*keyGen)(const char* string))
{
    if (hashTable == NULL)
    {
        return 1;
    }
    if (size <= 0)
    {
        return 2;
    }
    if (keyGen == NULL)
    {
        return 3;
    }
    HashTable* newHashTable = calloc(1, sizeof(HashTable));
    if (newHashTable == NULL)
    {
        return 4;
    }
    List** array = calloc(size, sizeof(List*));
    if (array == NULL)
    {
        free(newHashTable);
        return 4;
    }
    newHashTable->size = size;
    newHashTable->keyGen = keyGen;
    newHashTable->array = array;
    *hashTable = newHashTable;
    return 0;
}

int deleteHashTable(HashTable** hashTable)
{
    if (hashTable == NULL || *hashTable == NULL)
    {
        return 1;
    }
    HashTable* oldHashTalbe = *hashTable;
    for (int i = 0; i < oldHashTalbe->size; ++i)
    {
        deleteList(oldHashTalbe->array[i]);
    }
    free(oldHashTalbe->array);
    free(oldHashTalbe);
    *hashTable = NULL;
    return 0;
}

int addElementIntoHashTable(HashTable* hashTable, const char* string)
{
    if (hashTable == NULL)
    {
        return 1;
    }
    if (string == NULL)
    {
        return 2;
    }
    const int key = hashTable->keyGen(string) % hashTable->size;
    Position* position = createPosition();
    if (hashTable->array[key] == NULL)
    {
        List* list = createList();
        addListElement(list, position, string, true);
        setCounter(position, 1);
        hashTable->array[key] = list;
    }
    else
    {
        List* list = hashTable->array[key];
        movePositionToHead(list, position);
        while (!isPositionNull(position))
        {
            if (areStringFromPositionAndInputStringEqual(position, string))
            {
                char buffer[] = "buffer";
                int count = 0;
                getValueFromListElement(position, buffer, 7, &count);
                setCounter(position, count + 1);
                deletePosition(position);
                hashTable->count += 1;
                return 0;
            }
            movePositionToNext(position);
        }
        movePositionToTail(list, position);
        addListElement(list, position, string, true);
        setCounter(position, 1);
    }
    deletePosition(position);
    hashTable->count += 1;
    return 0;
}

int getListFromHashTable(const HashTable* hashTable, const int index, List** outputList)
{
    if (hashTable == NULL || outputList == NULL)
    {
        return 1;
    }
    if (index < 0 || index >= hashTable->size)
    {
        return 2;
    }
    *outputList = hashTable->array[index];
    return 0;
}

int getTheFillFactor(const HashTable* hashTable, double* output)
{
    if (hashTable == NULL || output == NULL)
    {
        return 1;
    }
    double count = hashTable->count;
    double size = hashTable->size;
    *output = count / size;
    return 0;
}

int getMaxListLength(const HashTable* hashTable, const int beginIndex, const int endIndex, int* output)
{
    if (hashTable == NULL || output == NULL)
    {
        return 1;
    }
    if (beginIndex < 0 || beginIndex >= hashTable->size || endIndex < 0 || endIndex >= hashTable->size || beginIndex > endIndex)
    {
        return 2;
    }
    int maxValue = 0;
    for (int i = beginIndex; i <= endIndex; ++i)
    {
        int value = getQuantity(hashTable->array[i]);
        maxValue = max(maxValue, value);
    }
    *output = maxValue;
    return 0;
}

int getAverageListLength(const HashTable* hashTable, const int beginIndex, const int endIndex, double* output)
{
    if (hashTable == NULL || output == NULL)
    {
        return 1;
    }
    if (beginIndex < 0 || beginIndex >= hashTable->size || endIndex < 0 || endIndex >= hashTable->size || beginIndex > endIndex)
    {
        return 2;
    }
    double average = 0;
    double count = 0;
    for (int i = beginIndex; i <= endIndex; ++i)
    {
        average += getQuantity(hashTable->array[i]);
        ++count;
    }
    *output = average / count;
    return 0;
}