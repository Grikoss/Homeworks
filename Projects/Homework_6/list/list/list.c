#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct ListElement
{
    int value;
    struct ListElement* next;
    struct ListElement* previous;
} ListElement;

typedef struct List
{
    ListElement* head;
    ListElement* tail;
} List;

typedef struct Position
{
    ListElement* currentPosition;
} Position;

List* createList()
{
    return calloc(1, sizeof(List));
}

Position* createPosition()
{
    return calloc(1, sizeof(Position));
}

int addListElementIntoHead(List* list, Position* position, const int value)
{
    if (list == NULL || position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    ListElement* element = calloc(1, sizeof(ListElement));
    if (element == NULL)
    {
        return 2;
    }
    element->value = value;
    element->next = position->currentPosition;
    position->currentPosition->previous = element;
    list->head = element;
    position->currentPosition = element;
    return 0;
}

int addListElementIntoTail(List* list, Position* position, const int value)
{
    if (list == NULL || position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    ListElement* element = calloc(1, sizeof(ListElement));
    if (element == NULL)
    {
        return 2;
    }
    element->value = value;
    element->previous = position->currentPosition;
    position->currentPosition->next = element;
    list->tail = element;
    position->currentPosition = element;
    return 0;
}

int addListElementIntoEmptyList(List* list, Position* position, const int value)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    ListElement* element = calloc(1, sizeof(ListElement));
    if (element == NULL)
    {
        return 2;
    }
    element->value = value;
    list->head = element;
    list->tail = element;
    position->currentPosition = element;
    return 0;
}

int addListElement(List* list, Position* position, const int value, bool addAfterPosition)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    if (list->head == NULL && list->tail == NULL)
    {
        return (addListElementIntoEmptyList(list, position, value) != 0) ? 2 : 0;
    }
    if (position->currentPosition == NULL)
    {
        return 3;
    }
    if (position->currentPosition->next == NULL && position->currentPosition->previous == NULL)
    {
        if (addAfterPosition)
        {
            return (addListElementIntoTail(list, position, value) != 0) ? 4 : 0;
        }
            return (addListElementIntoHead(list, position, value) != 0) ? 5 : 0;
    }
    if (position->currentPosition->next == NULL && addAfterPosition)
    {
        return (addListElementIntoTail(list, position, value) != 0) ? 4 : 0;
    }
    if (position->currentPosition->previous == NULL && !addAfterPosition)
    {
        return (addListElementIntoHead(list, position, value) != 0) ? 5 : 0;
    }
    ListElement* element = calloc(1, sizeof(ListElement));
    if (element == NULL)
    {
        return 6;
    }
    element->value = value;
    if (addAfterPosition)
    {
        element->next = position->currentPosition->next;
        element->previous = position->currentPosition;
        position->currentPosition->next->previous = element;
        position->currentPosition->next = element;
    }
    else
    {
        element->previous = position->currentPosition->previous;
        element->next = position->currentPosition;
        position->currentPosition->previous->next = element;
        position->currentPosition->previous = element;
    }
    position->currentPosition = element;
    return 0;
}