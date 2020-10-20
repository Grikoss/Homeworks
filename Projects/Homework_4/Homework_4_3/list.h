#pragma once

#include <stdbool.h>

typedef char* dataType;

typedef struct List List;

/*
* Все функции возвращают код ошибки:
* 0 - успешно выполнено
* 1 - проблема с выделением/освобождением памяти
* 2 - неверные входные данные
*/

// Принимает адрес на указатель, заменяет указатель на указатель list
int createList(List** output);

// Принимает указатель и булевскую переменную, в которую возращает результат проверки
int checkEmpty(List* list, bool* isEmpty);

// Принимает адрес указателя на лист, удаляет структуру
int deleteList(List** list);

// Принимает указатель на лист, а также данные, которые нужно внести в контейнер
int addNewElement(List* list, dataType name, dataType telephone);