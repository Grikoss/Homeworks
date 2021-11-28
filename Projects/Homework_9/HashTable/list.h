#pragma once

#include <stdbool.h>

typedef struct List List;

typedef struct Position Position;

// Creates empty list
// Returns NULL if creation is failed
List* createList(void);

// Creates empty position
// Returns NULL if creation is failed
Position* createPosition(void);

// Gives value from element, doesn't remove it and move pointer
// Returns execution code:5
// 0 - ok; 1 - position or position's pointer is NULL;
int getValueFromListElement(Position* position, char* outputString, const int sizeOfOutputString, int* outputCount);

// Adds element into list
// If list is empty then creates element and moves position, head and tail on element
// Alaways moves position on added element
// Returns execution code:
// 0 - ok; 1 - list or position is NULL; 2 - adding list element into empty list is failed; 3 - position is pointing on NULL when list isn't empty;
// 4 - adding list element into tail is failed; 5 - adding list element into head is failed; 6 - failed to allocate memory;
// Copyes strings, so you can use const strings
int addListElement(List* list, Position* position, const char* inputString, bool addAfterPosition);

// Removes element from list
// Returns execution code:
// 0 - ok; 1 - list or position is NULL; 2 - list is empty; 3 - position is pointing on NULL when list isn't empty;
// 4 - removing last list element is failde; 5 - removing list element from tail is failed; 6 - removing list element from head is failed;
int removeListElement(List* list, Position* position, bool movePositionToNext);

// Deletes position, doesn't touch list
void deletePosition(Position* position);

// Delets list
// Returns execution code:
// 0 - ok; 1 - list is NULL;
int deleteList(List* list);

// Moves position to list head
// Returns execution code:
// 0 - ok; 1 - list or position is NULL;
int movePositionToHead(List* list, Position* position);

// Moves position to list tail
// Returns execution code:
// 0 - ok; 1 - list or position is NULL;
int movePositionToTail(List* list, Position* position);

// Moves position to next position
// Returns execution code:
// 0 - ok; 1 - position is NULL or position is pointing on NULL;
int movePositionToNext(Position* position);

// Moves position to previous position
// Returns execution code:
// 0 - ok; 1 - position is NULL or position is pointing on NULL;
int movePositionToPrevious(Position* position);

// Return true if position is pointing on NULL or position is NULL
bool isPositionNull(Position* position);

// Sets counter, if position is pointing on NULL or position is NULL does nothing
void setCounter(Position* position, const int counter);

// Gives quantity of elements in list, if list is NULL return 0
int getQuantity(List* list);