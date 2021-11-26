#pragma once

#include <stdbool.h>

typedef struct SortedList SortedList;

typedef struct SortedLIstPosition SortedLIstPosition;

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
SortedLIstPosition* createSLPosition();

// Move SortedLIstPosition to head of sortet list
void moveSLPositionToHead(SortedList* list, SortedLIstPosition* position);

// Move SortedLIstPosition to next
void moveSLPositionToNext(SortedLIstPosition* position);

// Check is SLPositon is poiting on NULL
bool isEnd(SortedLIstPosition* position);

// Returns executionCode:
// 0 - ok; 1 - SLPOsition is NULL or pointig on NULL
int getValueFromSLPosition(SortedLIstPosition* position, int* output);

// Delete SortedLIstPosition
void deleteSLPositin(SortedLIstPosition* position);