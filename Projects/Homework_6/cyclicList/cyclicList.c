#include <stdbool.h>
#include <stdlib.h>
#include "cyclicList.h"

typedef struct CyclicListElement
{
    int value;
    struct CyclicListElement* next;
    struct CyclicListElement* previous;
} CyclicListElement;

typedef struct CyclicList
{
    CyclicListElement* head;
    CyclicListElement* tail;
} CyclicList;

typedef struct Position
{
    CyclicListElement* currentPosition;
} Position;

CyclicList* createList()
{
    return calloc(1, sizeof(CyclicList));
}

Position* createPosition()
{
    return calloc(1, sizeof(Position));
}

int getValueFromListElement(Position* position, int* outputValue)
{
    if (position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    *outputValue = position->currentPosition->value;
    return 0;
}

int addListElementIntoHead(CyclicList* list, Position* position, const int value)
{
    if (list == NULL || position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    CyclicListElement* element = calloc(1, sizeof(CyclicListElement));
    if (element == NULL)
    {
        return 2;
    }
    element->value = value;
    element->next = position->currentPosition;
    element->previous = list->tail;
    list->tail->next = element;
    position->currentPosition->previous = element;
    list->head = element;
    position->currentPosition = element;
    return 0;
}

int addListElementIntoTail(CyclicList* list, Position* position, const int value)
{
    if (list == NULL || position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    CyclicListElement* element = calloc(1, sizeof(CyclicListElement));
    if (element == NULL)
    {
        return 2;
    }
    element->value = value;
    element->previous = position->currentPosition;
    element->next = list->head;
    list->head->previous = element;
    position->currentPosition->next = element;
    list->tail = element;
    position->currentPosition = element;
    return 0;
}

int addListElementIntoEmptyList(CyclicList* list, Position* position, const int value)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    CyclicListElement* element = calloc(1, sizeof(CyclicListElement));
    if (element == NULL)
    {
        return 2;
    }
    element->value = value;
    element->next = element;
    element->previous = element;
    list->head = element;
    list->tail = element;
    position->currentPosition = element;
    return 0;
}

int addListElement(CyclicList* list, Position* position, const int value, bool addAfterPosition)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    if (list->head == NULL || list->tail == NULL)
    {
        return (addListElementIntoEmptyList(list, position, value) != 0) ? 2 : 0;
    }
    if (position->currentPosition == NULL)
    {
        return 3;
    }
    if (position->currentPosition->next == position->currentPosition)
    {
        if (addAfterPosition)
        {
            return (addListElementIntoTail(list, position, value) != 0) ? 4 : 0;
        }
    return (addListElementIntoHead(list, position, value) != 0) ? 5 : 0;
    }
    if (position->currentPosition->next == list->head && addAfterPosition)
    {
        return (addListElementIntoTail(list, position, value) != 0) ? 4 : 0;
    }
    if (position->currentPosition->previous == list->tail && !addAfterPosition)
    {
        return (addListElementIntoHead(list, position, value) != 0) ? 5 : 0;
    }
    CyclicListElement* element = calloc(1, sizeof(CyclicListElement));
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

int removeLastListElement(CyclicList* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    free(position->currentPosition);
    position->currentPosition = NULL;
    list->head = NULL;
    list->tail = NULL;
    return 0;
}

int removeListElementFromHead(CyclicList* list, Position* position, bool movePositionToNext)
{
    if (list == NULL || position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    position->currentPosition->next->previous = list->tail;
    list->head = position->currentPosition->next;
    list->tail->next = list->head;
    free(position->currentPosition);
    position->currentPosition = movePositionToNext ? list->head : list->tail;
    return 0;
}

int removeListElementFromTail(CyclicList* list, Position* position, bool movePositionToNext)
{
    if (list == NULL || position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    position->currentPosition->previous->next = list->head;
    list->tail = position->currentPosition->previous;
    list->head->previous = list->tail;
    free(position->currentPosition);
    position->currentPosition = movePositionToNext ? list->head : list->tail;
    return 0;
}

int removeListElement(CyclicList* list, Position* position, bool movePositionToNext)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    if (list->head == NULL || list->tail == NULL)
    {
        return 2;
    }
    if (position->currentPosition == NULL)
    {
        return 3;
    }
    if (position->currentPosition->next == position->currentPosition)
    {
        return (removeLastListElement(list, position) != 0) ? 4 : 0;
    }
    if (position->currentPosition->next == list->head)
    {
        return (removeListElementFromTail(list, position, movePositionToNext) != 0) ? 5 : 0;
    }
    if (position->currentPosition->previous == list->tail)
    {
        return (removeListElementFromHead(list, position, movePositionToNext) != 0) ? 6 : 0;
    }
    position->currentPosition->next->previous = position->currentPosition->previous;
    position->currentPosition->previous->next = position->currentPosition->next;
    CyclicListElement* oldCurrentPosition = position->currentPosition;
    position->currentPosition = movePositionToNext ? position->currentPosition->next : position->currentPosition->previous;
    free(oldCurrentPosition);
    return 0;
}

void deletePosition(Position* position)
{
    free(position);
}

int deleteList(CyclicList* list)
{
    if (list == NULL)
    {
        return 1;
    }
    Position* position = createPosition();
    movePositionToHead(list, position);
    while (list->head != NULL)
    {
        removeListElement(list, position, true);
    }
    free(list);
    deletePosition(position);
    return 0;
}

int movePositionToHead(CyclicList* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    position->currentPosition = list->head;
    return 0;
}

int movePositionToTail(CyclicList* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    position->currentPosition = list->tail;
    return 0;
}

int movePositionToNext(Position* position)
{
    if (position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    position->currentPosition = position->currentPosition->next;
    return 0;
}

int movePositionToPrevious(Position* position)
{
    if (position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    position->currentPosition = position->currentPosition->previous;
    return 0;
}

bool isPositionNull(Position* position)
{
    return position == NULL || position->currentPosition == NULL;
}

bool isPositionPointOnLastElement(Position* position)
{
    if (position == NULL || position->currentPosition == NULL)
    {
        return false;
    }
    return position->currentPosition == position->currentPosition->next;
}