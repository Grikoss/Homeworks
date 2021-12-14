#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

typedef struct ListElement
{
    char* string;
    int count;
    struct ListElement* next;
    struct ListElement* previous;
} ListElement;

typedef struct List
{
    ListElement* head;
    ListElement* tail;
    int quantity;
} List;

typedef struct Position
{
    ListElement* currentPosition;
} Position;

List* createList(void)
{
    return calloc(1, sizeof(List));
}

Position* createPosition(void)
{
    return calloc(1, sizeof(Position));
}

int getValueFromListElement(Position* position, char* outputString, const int sizeOfOutputString, int* outputCount)
{
    if (position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    strcpy_s(outputString, sizeOfOutputString, position->currentPosition->string);
    *outputCount = position->currentPosition->count;
    return 0;
}

void addStrings(ListElement* element, const char* inputString)
{
    const int length = strlen(inputString) + 1;
    char* string = calloc(length, sizeof(char));
    if (string != NULL)
    {
        strcpy_s(string, length, inputString);
    }
    element->string = string;
}

int addListElementIntoHead(List* list, Position* position, const char* inputString)
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
    addStrings(element, inputString);
    element->next = position->currentPosition;
    position->currentPosition->previous = element;
    list->head = element;
    position->currentPosition = element;
    ++list->quantity;
    return 0;
}

int addListElementIntoTail(List* list, Position* position, const char* inputString)
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
    addStrings(element, inputString);
    element->previous = position->currentPosition;
    position->currentPosition->next = element;
    list->tail = element;
    position->currentPosition = element;
    ++list->quantity;
    return 0;
}

int addListElementIntoEmptyList(List* list, Position* position, const char* inputString)
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
    addStrings(element, inputString);
    list->head = element;
    list->tail = element;
    position->currentPosition = element;
    ++list->quantity;
    return 0;
}

int addListElement(List* list, Position* position, const char* inputString, bool addAfterPosition)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    if (list->head == NULL || list->tail == NULL)
    {
        return (addListElementIntoEmptyList(list, position, inputString) != 0) ? 2 : 0;
    }
    if (position->currentPosition == NULL)
    {
        return 3;
    }
    if (position->currentPosition->next == NULL && position->currentPosition->previous == NULL)
    {
        if (addAfterPosition)
        {
            return (addListElementIntoTail(list, position, inputString) != 0) ? 4 : 0;
        }
        return (addListElementIntoHead(list, position, inputString) != 0) ? 5 : 0;
    }
    if (position->currentPosition->next == NULL && addAfterPosition)
    {
        return (addListElementIntoTail(list, position, inputString) != 0) ? 4 : 0;
    }
    if (position->currentPosition->previous == NULL && !addAfterPosition)
    {
        return (addListElementIntoHead(list, position, inputString) != 0) ? 5 : 0;
    }
    ListElement* element = calloc(1, sizeof(ListElement));
    if (element == NULL)
    {
        return 6;
    }
    addStrings(element, inputString);
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
    ++list->quantity;
    return 0;
}

void removeStrings(ListElement* element)
{
    free(element->string);
}

int removeLastListElement(List* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    removeStrings(position->currentPosition);
    free(position->currentPosition);
    position->currentPosition = NULL;
    list->head = NULL;
    list->tail = NULL;
    --list->quantity;
    return 0;
}

int removeListElementFromHead(List* list, Position* position, bool movePositionToNext)
{
    if (list == NULL || position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    position->currentPosition->next->previous = NULL;
    list->head = position->currentPosition->next;
    removeStrings(position->currentPosition);
    free(position->currentPosition);
    position->currentPosition = movePositionToNext ? list->head : NULL;
    --list->quantity;
    return 0;
}

int removeListElementFromTail(List* list, Position* position, bool movePositionToNext)
{
    if (list == NULL || position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    position->currentPosition->previous->next = NULL;
    list->tail = position->currentPosition->previous;
    removeStrings(position->currentPosition);
    free(position->currentPosition);
    position->currentPosition = movePositionToNext ? NULL : list->tail;
    --list->quantity;
    return 0;
}

int removeListElement(List* list, Position* position, bool movePositionToNext)
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
    if (position->currentPosition->next == NULL && position->currentPosition->previous == NULL)
    {
        return (removeLastListElement(list, position) != 0) ? 4 : 0;
    }
    if (position->currentPosition->next == NULL)
    {
        return (removeListElementFromTail(list, position, movePositionToNext) != 0) ? 5 : 0;
    }
    if (position->currentPosition->previous == NULL)
    {
        return (removeListElementFromHead(list, position, movePositionToNext) != 0) ? 6 : 0;
    }
    position->currentPosition->next->previous = position->currentPosition->previous;
    position->currentPosition->previous->next = position->currentPosition->next;
    ListElement* oldCurrentPosition = position->currentPosition;
    position->currentPosition = movePositionToNext ? position->currentPosition->next : position->currentPosition->previous;
    removeStrings(oldCurrentPosition);
    free(oldCurrentPosition);
    --list->quantity;
    return 0;
}

void deletePosition(Position* position)
{
    free(position);
}

int deleteList(List* list)
{
    if (list == NULL)
    {
        return 1;
    }
    Position* position = createPosition();
    movePositionToHead(list, position);
    while (!isPositionNull(position))
    {
        removeListElement(list, position, true);
    }
    deletePosition(position);
    free(list);
    return 0;
}

int movePositionToHead(List* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    position->currentPosition = list->head;
    return 0;
}

int movePositionToTail(List* list, Position* position)
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

void setCounter(Position* position, const int counter)
{
    if (position != NULL && position->currentPosition != NULL)
    {
        position->currentPosition->count = counter;
    }
}

int getQuantity(List* list)
{
    return (list != NULL) ? list->quantity : 0;
}

bool areStringFromPositionAndInputStringEqual(Position* position, const char* string)
{
    if (position == NULL || position->currentPosition == NULL || string == NULL)
    {
        return false;
    }
    return strcmp(string, position->currentPosition->string) == 0;
}