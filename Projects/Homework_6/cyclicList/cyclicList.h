#pragma once

#include <stdbool.h>

typedef struct CyclicList CyclicList;

typedef struct Position Position;

// Creates empty list
// Returns NULL if creation is failed
CyclicList* createList();

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
// 4 - failed to allocate memory;
int addListElement(CyclicList* list, Position* position, const int value);

// Removes element from list
// Returns execution code:
// 0 - ok; 1 - list or position is NULL; 2 - list is empty; 3 - position is pointing on NULL when list isn't empty;
// 4 - removing last list element is failde;
int removeListElement(CyclicList* list, Position* position);

// Deletes position, doesn't touch list
void deletePosition(Position* position);

// Delets list
// Returns execution code:
// 0 - ok; 1 - list is NULL;
int deleteList(CyclicList* list);

// Moves position to firstElement
// Returns execution code:
// 0 - ok; 1 - list or position is NULL;
int movePositionToFirstElement(CyclicList* list, Position* position);

// Moves position to next position
// Returns execution code:
// 0 - ok; 1 - position is NULL or position is pointing on NULL;
int movePositionToNext(Position* position);

// Moves position to previous position
// Returns execution code:
// 0 - ok; 1 - position is NULL or position is pointing on NULL;
int movePositionToPrevious(Position* position);

// Returns true if position is pointing on NULL or position is NULL
bool isPositionNull(Position* position);

// Returns true if position is pointing on last element or false if position is pointing on NULL or position is NULL
bool isPositionPointOnLastElement(Position* position);