#include <stdlib.h>
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
        return 5;
    }
    newHashTable->size = size;
    newHashTable->keyGen = keyGen;
    newHashTable->array = array;
    *hashTable = newHashTable;
    return 0;
}

int deleteHashTable(HashTable** hashTable)
{
    if (hashTable == NULL)
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
