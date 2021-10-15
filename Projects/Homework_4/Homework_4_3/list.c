#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

const int sizeBook = 100;

typedef struct Element
{
    const char* name;
    const char* telephone;
    struct Element* next;
} Element;

typedef struct List
{
    Element* head;
    Element* pointer;
    int quantity;
} List;

List* createNewList(void)
{
    Element* element = calloc(1, sizeof(Element));
    if (element == NULL)
    {
        return NULL;
    }

    List* list = calloc(1, sizeof(List));
    if (list == NULL)
    {
        free(element);
        return NULL;
    }

    list->head = element;
    return list;
}

bool isEnd(Element* element)
{
    if (element == NULL)
    {
        return true;
    }

    return element->next == NULL;
}

void deleteList(List* list)
{
    while (!isEnd(list->head))
    {
        Element* oldHead = list->head;
        list->head = list->head->next;
        free(oldHead->name);
        free(oldHead->telephone);
        free(oldHead);
    }

    free(list->head);
    free(list);
}

int addNewElement(List* list, char* name, char* telephone)
{
    if (list == NULL || name == NULL || telephone == NULL)
    {
        return 1;
    }

    if (list->quantity >= sizeBook)
    {
        return 2;
    }

    Element* element = malloc(sizeof(Element));
    if (element == NULL)
    {
        return 3;
    }

    element->name = name;
    element->telephone = telephone;
    element->next = list->head;
    list->head = element;
    ++list->quantity;
    return 0;
}

int getElements(List* list, char** name, char** telephone)
{
    if (list == NULL || list->head == NULL || list->quantity == 0 || name == NULL || telephone == NULL)
    {
        return 1;
    }

    if (list->pointer == NULL || list->pointer->next == NULL)
    {
        resetPointer(list);        
    }
    
    *name = list->pointer->name;
    *telephone = list->pointer->telephone;
    list->pointer = list->pointer->next;
    return 0;
}

char* searchElement(List* list, char* input, bool isSearchByName)
{
    if (list == NULL || input == NULL || list->head == NULL || list->quantity == 0)
    {
        return NULL;
    }

    for (Element* i = list->head; !isEnd(i); i = i->next)
    {
        if (isSearchByName)
        {
            if (strcmp(i->name, input) == 0)
            {
                return i->telephone;
            }
        }
        else
        {
            if (strcmp(i->telephone, input) == 0)
            {
                return i->name;
            }
        }
    }

    return NULL;
}

int getQuantity(List* list)
{
    if (list == NULL)
    {
        return 0;
    }

    return list->quantity;
}

int resetPointer(List* list)
{
    if (list == NULL)
    {
        return 1;
    }

    list->pointer = list->head;
    return 0;
}