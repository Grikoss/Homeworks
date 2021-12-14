#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "hashTable.h"
#include "hashTableTest.h"

int keyGen(const char* string)
{
    return -string[0];
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
    result = result || deleteHashTable(&hashTable) == 0;
    return result;
}

bool isAddElementIntoHashTableBehavesIncorrectly(void)
{
    HashTable* hashTable = NULL;
    createHashTable(&hashTable, 2, keyGen);
    bool result = addElementIntoHashTable(NULL, "0") == 0;
    result = result || addElementIntoHashTable(hashTable, NULL) == 0;
    result = result || addElementIntoHashTable(hashTable, "0") != 0;
    result = result || addElementIntoHashTable(hashTable, "1") != 0;
    result = result || addElementIntoHashTable(hashTable, "2") != 0;
    result = result || addElementIntoHashTable(hashTable, "2") != 0;
    deleteHashTable(&hashTable);
    return result;
}

bool isGetListFromHashTableBehavesIncorrectly(void)
{
    HashTable* hashTable = NULL;
    createHashTable(&hashTable, 2, keyGen);
    addElementIntoHashTable(hashTable, "0");
    addElementIntoHashTable(hashTable, "1");
    addElementIntoHashTable(hashTable, "2");
    addElementIntoHashTable(hashTable, "2");
    List* listOne = NULL;
    List* listTwo = NULL;
    bool result = getListFromHashTable(NULL, 0, &listOne) == 0;
    result = result || getListFromHashTable(hashTable, -1, &listOne) == 0;
    result = result || getListFromHashTable(hashTable, 3, &listOne) == 0;
    result = result || getListFromHashTable(hashTable, 0, NULL) == 0;
    result = result || getListFromHashTable(hashTable, 0, &listOne) != 0;
    result = result || getListFromHashTable(hashTable, 1,& listTwo) != 0;
    result = result || listOne == NULL;
    result = result || listTwo == NULL;
    Position* position = createPosition();
    char buffer[2] = { 0 };
    int count = 0;
    movePositionToHead(listOne, position);
    getValueFromListElement(position, buffer, 2, &count);
    result = result || strcmp(buffer, "0") != 0;
    result = result || count != 1;
    movePositionToNext(position);
    getValueFromListElement(position, buffer, 2, &count);
    result = result || strcmp(buffer, "2") != 0;
    result = result || count != 2;
    movePositionToNext(position);
    result = result || !isPositionNull(position);
    movePositionToHead(listTwo, position);
    getValueFromListElement(position, buffer, 2, &count);
    result = result || strcmp(buffer, "1") != 0;
    result = result || count != 1;
    movePositionToNext(position);
    result = result || !isPositionNull(position);
    deletePosition(position);
    deleteHashTable(&hashTable);
    return result;
}

bool isGetTheFillFactorBehavesIncorrectly(void)
{
    HashTable* hashTable = NULL;
    createHashTable(&hashTable, 2, keyGen);
    double fillFactor = -10;
    bool result = getTheFillFactor(NULL, &fillFactor) == 0;
    result = result || getTheFillFactor(hashTable, NULL) == 0;
    result = result || getTheFillFactor(hashTable, &fillFactor) != 0;
    result = result || fillFactor != 0;
    addElementIntoHashTable(hashTable, "0");
    result = result || getTheFillFactor(hashTable, &fillFactor) != 0;
    result = result || fillFactor != 0.5;
    addElementIntoHashTable(hashTable, "1");
    result = result || getTheFillFactor(hashTable, &fillFactor) != 0;
    result = result || fillFactor != 1;
    addElementIntoHashTable(hashTable, "2");
    result = result || getTheFillFactor(hashTable, &fillFactor) != 0;
    result = result || fillFactor != 1.5;
    deleteHashTable(&hashTable);
    return result;
}

bool isGetMaxListLengthBehavesIncorrect(void)
{
    HashTable* hashTable = NULL;
    createHashTable(&hashTable, 2, keyGen);
    addElementIntoHashTable(hashTable, "0");
    addElementIntoHashTable(hashTable, "1");
    addElementIntoHashTable(hashTable, "2");
    addElementIntoHashTable(hashTable, "2");
    int maxListLength = 0;
    bool result = getMaxListLength(NULL, 0, 1, &maxListLength) == 0;
    result = result || getMaxListLength(hashTable, -1, 0, &maxListLength) == 0;
    result = result || getMaxListLength(hashTable, 0, 1, NULL) == 0;
    result = result || getMaxListLength(hashTable, 0, 1, &maxListLength) != 0;
    result = result || maxListLength != 2;
    deleteHashTable(&hashTable);
    return result;
}

bool isGetAverageListLengthBehavesIncorrect(void)
{
    HashTable* hashTable = NULL;
    createHashTable(&hashTable, 2, keyGen);
    addElementIntoHashTable(hashTable, "0");
    addElementIntoHashTable(hashTable, "1");
    addElementIntoHashTable(hashTable, "2");
    addElementIntoHashTable(hashTable, "2");
    double averageListLength = 0;
    bool result = getAverageListLength(NULL, 0, 1, &averageListLength) == 0;
    result = result || getAverageListLength(hashTable, -1, 0, &averageListLength) == 0;
    result = result || getAverageListLength(hashTable, 0, 1, NULL) == 0;
    result = result || getAverageListLength(hashTable, 0, 1, &averageListLength) != 0;
    result = result || averageListLength != 1.5;
    deleteHashTable(&hashTable);
    return result;
}

bool isHashTableBehavesIncorrectly(void)
{
    bool result = isCreateHashTableBehavesIncorrectly();
    result = result || isDeleteHashTableBehavesIncorrectly();
    result = result || isAddElementIntoHashTableBehavesIncorrectly();
    result = result || isGetListFromHashTableBehavesIncorrectly();
    result = result || isGetTheFillFactorBehavesIncorrectly();
    result = result || isGetMaxListLengthBehavesIncorrect();
    result = result || isGetAverageListLengthBehavesIncorrect();
    return result;
}
