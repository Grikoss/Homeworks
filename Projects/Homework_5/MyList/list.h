#pragma once

typedef struct List List;

List* createNewList(void);

int deleteList(List** list);

int addElement(List* list, char* inputItem);

int deleteElement(List* list);

int getQuantity(int* quantity, List* list);