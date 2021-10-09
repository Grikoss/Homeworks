#pragma once

#include <stdbool.h>

typedef struct List List;

// Creates a sheet
List* createNewList(void);

// Deletes a sheet
int deleteList(List* list);

// Adds an element
int addNewElement(List* list, char* name, char* telephone);

// Returns the number and phone number, then goes to the next element, if the next element does not exist,
// returns to the beginning of the sheet
int getElements(List* list, char** name, char** telephone);

// Searching for an element by another element
char* searchElement(List* list, char* input, bool isSearchByName);

// Number of elements
int getQuantity(List* list);

// Reset the pointer to the beginning(getElements)
int resetPointer(List* list);