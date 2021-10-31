#pragma once

typedef struct SortedList SortedList;

// Returns sortedList or null if creation unsuccessful
SortedList* createSortedList();

// Removes element that equal inputElement
// Returns execution code:
// 0 - ok; 1 - there is no such element; 2 - sortedList is NULL;
int removeElement(SortedList* sortedList, const int inputValue);

// Adds element, saves sorting
// Returns execution code:
// 0 - ok; 1 - sortedList is NULL;
int addElement(SortedList* sortedList, const int inputValue);

// Gives outArray and his size if execution code is 0;
// Gives memery managment
// Returns execution code:
// 0 - ok; 1 - sortedList is NULL; 2 - memory allocation error;
int getValues(SortedList* sortedList, int** outArray, int* outSize);

// Deletes sorted list
// Returns execution code:
// 0 - ok; 1 - sortedList is NULL;
int deleteSortedList(SortedList* list);