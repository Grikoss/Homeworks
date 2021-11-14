#include <stdbool.h>
#include <stdlib.h>
#include "../list/list.h"
#include "sortedList.h"

typedef struct SortedList
{
    List* list;
} SortedList;

typedef struct SLPosition
{
    Position* position;
} SLPosition;

SLPosition* createSLPosition()
{
    SLPosition* position = calloc(1, sizeof(SLPosition));
    if (position != NULL)
    {
        position->position = createPosition();
    }
    return position;
}

void moveSLPositionToHead(SortedList* list, SLPosition* position)
{
    if (list != NULL && position != NULL)
    {
        movePositionToHead(list->list, position->position);
    }
}

void moveSLPositionToNext(SLPosition* position)
{
    if (position != NULL)
    {
        movePositionToNext(position->position);
    }
}

bool isSLPositionIsNULL(SLPosition* position)
{
    return position == NULL || isPositionNull(position->position);
}

int getValueFromSLPosition(SLPosition* position, int* output)
{
    if (position == NULL)
    {
        return 1;
    }
    return getValueFromListElement(position->position, output);
}

void deleteSLPositin(SLPosition* position)
{
    if (position != NULL)
    {
        deletePosition(position->position);
    }
    free(position);
}

SortedList* createSortedList()
{
    SortedList* list = calloc(1, sizeof(SortedList));
    if (list == NULL)
    {
        return NULL;
    }
    list->list = createList();
    return list;
}

int removeElement(SortedList* sortedList, const int inputValue)
{
    if (sortedList == NULL)
    {
        return 2;
    }
    Position* position = createPosition();
    movePositionToHead(sortedList->list, position);
    while (true)
    {
        int value = 0;
        getValueFromListElement(position, &value);
        if (value == inputValue)
        {
            removeListElement(sortedList->list, position, true);
            deletePosition(position);
            return 0;
        }
        if (value > inputValue || isPositionNull(position))
        {
            break;
        }
        movePositionToNext(position);
    }
    deletePosition(position);
    return 1;
}

int addElement(SortedList* sortedList, const int inputValue)
{
    if (sortedList == NULL)
    {
        return 1;
    }
    Position* position = createPosition();
    movePositionToHead(sortedList->list, position);
    int value = 0;
    getValueFromListElement(position, &value);
    if (inputValue < value)
    {
        addListElement(sortedList->list, position, inputValue, false);
        deletePosition(position);
        return 0;
    }
    movePositionToHead(sortedList->list, position);
    while (!isPositionNull(position))
    {
        getValueFromListElement(position, &value);
        if (inputValue < value)
        {
            addListElement(sortedList->list, position, inputValue, false);
            deletePosition(position);
            return 0;
        }
        movePositionToNext(position);
    }
    movePositionToTail(sortedList->list, position);
    addListElement(sortedList->list, position, inputValue, true);
    deletePosition(position);
    return 0;
}

int deleteSortedList(SortedList* list)
{
    if (list == NULL)
    {
        return 1;
    }
    deleteList(list->list);
    free(list);
    return 0;
}