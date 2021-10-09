#pragma once

#include <stdbool.h>

typedef struct List List;

typedef struct Element Element;

//Создаёт лист
List* createNewList(void);

//Удаляет лист
int deleteList(List* list);

//Добавляет элемент
int addNewElement(List* list, char* name, char* telephone);

//Возвращает номер и телефон, после чего переходит к след.элементу, если след.елемента не существует,
//возвращается к началу листа
int getElements(List* list, char** name, char** telephone);

//Поиск элемента по другому элементу
char* searchElement(List* list, char* input, bool isSearchByName);

//Количество элементов
int getQuantity(List* list);

//сброс указателя на начало(getElements)
int resetPointer(List* list);