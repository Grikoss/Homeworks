#pragma once

#include <stdbool.h>

typedef char dataType;

typedef struct List List;

typedef struct Element Element;

//Создаёт лист
List* createNewList(void);

//Проверяет, является ли елемент стражем
bool isEnd(Element* element);

//Удаляет лист
int deleteList(List* list);

//Добавляет элемент
int addNewElement(List* list, char* name, char* telephone);

//Выводит массив, содержащий элементы листа
dataType** getElements(List* list);

//Поиск элемента по другому элементу
dataType* searchElement(List* list, dataType* input, bool isSearchByName);

//Количество элементов
int getQuantity(List* list);