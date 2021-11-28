#include <stdbool.h>
#include <stdlib.h>
#include "hashTable.h"
#include "hashTableTest.h"

int keyGen(const char* string)
{
    return string[0];
}

bool isCreateHashTableBehavesIncorrectly(void)
{
    bool result = createHashTable(NULL, 1, keyGen) == 0;
    HashTable* hashTable = NULL;
    result = result || createHashTable(&hashTable, 0, keyGen) == 0;
    result = result || createHashTable(&hashTable, 1, NULL) == 0;
    result = result || createHashTable(&hashTable, 1, keyGen) != 0;
    deleteHashTable(&hashTable);
    return result;
}

bool isDeleteHashTableBehavesIncorrectly(void)
{
    HashTable* hashTable = NULL;
    createHashTable(&hashTable, 1, keyGen);
    bool result = deleteHashTable(NULL) == 0;
    result = result || deleteHashTable(&hashTable) != 0;
    result = result || hashTable != NULL;
    return result;
}

bool isHashTableBehavesIncorrectly(void)
{
    bool result = isCreateHashTableBehavesIncorrectly();
    result = result || isDeleteHashTableBehavesIncorrectly();
    return result;
}
