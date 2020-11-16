#pragma once

typedef struct List List;

//Создаёт новый стек 
List* createNewList(void);

//Удаляет лист, принимает указатель на указатель
int deleteList(List** list);

//Добавляет элемент
int addElement(List* list, char* inputItem);

//Удаляет элемент
int deleteElement(List* list);

//Записывает количество элементов
int getQuantity(int* quantity, List* list);