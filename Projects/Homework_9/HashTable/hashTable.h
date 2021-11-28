#pragma once

typedef struct HashTable HashTable;

int createHashTable(HashTable** hashTable, const int size, int (*keyGen)(const char* string));

int deleteHashTable(HashTable** hashTable);

int addElementIntoHashTable(HashTable* hashTable, const char* string);

int getStringFromHashTable(const HashTable* hashTable, const int key, char* output, const int sizeOfOutput);

int getTheFillFactor(const HashTable* hashTable, int* output);

int getMaxListLength(const HashTable* hashTable, const int beginIndex, const int endIndex, int* output);

int averageListLength(const HashTable* hashTable, const int beginIndex, const int endIndex, int* output);