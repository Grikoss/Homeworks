#pragma once

#include "list.h"

// HashTable stores lists that it uses in cases of collisions
typedef struct HashTable HashTable;

// Creates hash table
// Returns execution code:
// 0 - ok; 1 - adress of hash table is NULL; 2 - size <= 0; 3 - keyGen is NULL; 4 - memory allocation error;
int createHashTable(HashTable** hashTable, const int size, int (*keyGen)(const char* string));

// Deletes hash table
// Returns execution code:
// 0 - ok; 1 - adress of hash table is NULL or hash table is NULL;
int deleteHashTable(HashTable** hashTable);

// Adds element into hash table
// if there is such element, increases count by one;
// Returns execution code:
// 0 - ok; 1 - hash table is NULL; 2 - string is NULL;
int addElementIntoHashTable(HashTable* hashTable, const char* string);

// Gives list by index
// Returns execution code:
// 0 - ok; 1 - hash table is NULL or adress of output list is NULL; 2 - incorrect index;
int getListFromHashTable(const HashTable* hashTable, const int index, List** outputList);

// Gives fill factor
// Returns execution code:
// 0 - ok; 1 - hash table is NULL or adress of output is NULL;
int getTheFillFactor(const HashTable* hashTable, double* output);

// Gives max list length
// Returns execution code:
// 0 - ok; 1 - hash table is NULL or adress of output is NULL; 2 - incorrect indexs;
int getMaxListLength(const HashTable* hashTable, const int beginIndex, const int endIndex, int* output);

// Gives max list length
// Returns execution code:
// 0 - ok; 1 - hash table is NULL or adress of output is NULL; 2 - incorrect indexs;
int getAverageListLength(const HashTable* hashTable, const int beginIndex, const int endIndex, double* output);