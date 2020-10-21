#pragma once

#include <stdbool.h>

typedef char dataType;

typedef struct List List;

void switchTestMod();

List* createNewList(void);

bool isEnd(List* list);

int deleteList(List* list);

int addNewElement(List* list, char* name, char* telephone);

int getElement(List* list, dataType** name, dataType** telephone);

dataType* searchElement(List* list, dataType* input, bool isSearchByName);