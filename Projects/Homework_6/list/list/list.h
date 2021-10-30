#pragma once

#include <stdbool.h>

typedef struct List List;

typedef struct Position Position;

// Creates empty list
// Returns NULL if creation is failed
List* createList();

// Creates empty position
// Returns NULL if creation is failed
Position* createPosition();

// Gives value from element, doesn't remove it and move pointer
// Returns execution code:
// 0 - ok; 1 - position or position's pointer is NULL;
int getValueFromListElement(Position* position, int* outputValue);

// Adds element into list
// If list is empty then creates element and moves position, head and tail on element
// Alaways moves position on added element
// Returns execution code:
// 0 - ok; 1 - list or position is NULL; 2 - adding list element into empty list is failed; 3 - position is pointing on NULL when list isn't empty;
// 4 - adding list element into tail is failed; 5 - adding list element into head is failed; 6 - failed to allocate memory;
int addListElement(List* list, Position* position, const int value, bool addAfterPosition);

// Removes element from list
// Returns execution code:
// 0 - ok; 1 - list or position is NULL; 2 - list is empty; 3 - position is pointing on NULL when list isn't empty;
// 4 - removing last list element is failde; 5 - removing list element from tail is failed; 6 - removing list element from head is failed;
int removeListElement(List* list, Position* position, bool movePositionToNext);