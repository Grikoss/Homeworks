#pragma once

#include <stdbool.h>

typedef struct SortedList SortedList;

typedef struct SLPosition SLPosition;

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

// Deletes sorted list
// Returns execution code:
// 0 - ok; 1 - sortedList is NULL;
int deleteSortedList(SortedList* list);

// Create SLPositon
SLPosition* createSLPosition();

// Move SLPosition to head of sortet list
void moveSLPositionToHead(SortedList* list, SLPosition* position);

// Move SLPosition to next
void moveSLPositionToNext(SLPosition* position);

// Check is SLPositon is poiting on NULL
bool isSLPositionIsNULL(SLPosition* position);

// Returns executionCode:
// 0 - ok; 1 - SLPOsition is NULL or pointig on NULL
int getValueFromSLPosition(SLPosition* position, int* output);

// Delete SLPosition
void deleteSLPositin(SLPosition* position);