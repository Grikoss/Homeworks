#include <stdbool.h>
#include <stdlib.h>
#include "../list/list.h"
#include "sortedList.h"

typedef struct SortedList
{
    List* list;
} SortedList;

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
    while (!isPositionNull(position))
    {
        int value = 0;
        getValueFromListElement(position, &value);
        if (value == inputValue)
        {
            removeListElement(sortedList->list, position, true);
            deletePosition(position);
            return 0;
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

int getValues(SortedList* sortedList, int** outArray, int* outSize)
{
    if (sortedList == NULL)
    {
        return 1;
    }
    Position* position = createPosition();
    movePositionToHead(sortedList->list, position);
    int size = 0;
    while (!isPositionNull(position))
    {
        ++size;
        movePositionToNext(position);
    }
    int* array = calloc(size, sizeof(int));
    if (array == NULL)
    {
        deletePosition(position);
        return 2;
    }
    movePositionToHead(sortedList->list, position);
    for (int i = 0; i < size; ++i)
    {
        int value = 0;
        getValueFromListElement(position, &value);
        array[i] = value;
        movePositionToNext(position);
    }
    *outArray = array;
    *outSize = size;
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