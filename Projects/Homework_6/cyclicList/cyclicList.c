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
    CyclicListElement* firstElement;
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
    list->firstElement = element;
    position->currentPosition = element;
    return 0;
}

int addListElement(CyclicList* list, Position* position, const int value)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    if (list->firstElement == NULL)
    {
        return addListElementIntoEmptyList(list, position, value);
    }
    if (position->currentPosition == NULL)
    {
        return 3;
    }
    CyclicListElement* element = calloc(1, sizeof(CyclicListElement));
    if (element == NULL)
    {
        return 4;
    }
    element->value = value;
    element->next = position->currentPosition->next;
    element->previous = position->currentPosition;
    position->currentPosition->next->previous = element;
    position->currentPosition->next = element;
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
    list->firstElement = NULL;
    return 0;
}


int removeListElement(CyclicList* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    if (list->firstElement == NULL)
    {
        return 2;
    }
    if (position->currentPosition == NULL)
    {
        return 3;
    }
    if (isPositionPointOnLastElement(position))
    {
        return removeLastListElement(list, position);
    }
    if (position->currentPosition == list->firstElement)
    {
        list->firstElement = position->currentPosition->next;
    }
    position->currentPosition->next->previous = position->currentPosition->previous;
    position->currentPosition->previous->next = position->currentPosition->next;
    CyclicListElement* oldCurrentPosition = position->currentPosition;
    position->currentPosition = position->currentPosition->next;
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
    movePositionToFirstElement(list, position);
    while (!isPositionNull(position))
    {
        removeListElement(list, position);
    }
    free(list);
    deletePosition(position);
    return 0;
}

int movePositionToFirstElement(CyclicList* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    position->currentPosition = list->firstElement;
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