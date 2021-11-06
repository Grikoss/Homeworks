#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

typedef struct ListElement
{
    char* name;
    char* telephone;
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

int getValueFromListElement(Position* position, char* outputName, char* outputTelephone)
{
    if (position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    strcpy_s(outputName, sizeof(outputName), position->currentPosition->name);
    strcpy_s(outputTelephone, sizeof(outputTelephone), position->currentPosition->telephone);
    return 0;
}

void addStrings(ListElement* element, char* inputName, char* inputTelephone)
{
    char* name = calloc(strlen(inputName) + 1, sizeof(char));
    if (name != NULL)
    {
        strcpy_s(name, sizeof(name), inputName);
    }
    element->name = name;
    char* telephone = calloc(strlen(inputTelephone) + 1, sizeof(char));
    if (telephone != NULL)
    {
        strcpy_s(telephone, sizeof(telephone), inputTelephone);
    }
    element->telephone = telephone;
}

int addListElementIntoHead(List* list, Position* position, char* inputName, char* inputTelephone)
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
    addStrings(element, inputName, inputTelephone);
    element->next = position->currentPosition;
    position->currentPosition->previous = element;
    list->head = element;
    position->currentPosition = element;
    return 0;
}

int addListElementIntoTail(List* list, Position* position, char* inputName, char* inputTelephone)
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
    addStrings(element, inputName, inputTelephone);
    element->previous = position->currentPosition;
    position->currentPosition->next = element;
    list->tail = element;
    position->currentPosition = element;
    return 0;
}

int addListElementIntoEmptyList(List* list, Position* position, char* inputName, char* inputTelephone)
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
    addStrings(element, inputName, inputTelephone);
    list->head = element;
    list->tail = element;
    position->currentPosition = element;
    return 0;
}

int addListElement(List* list, Position* position, char* inputName, char* inputTelephone, bool addAfterPosition)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    if (list->head == NULL || list->tail == NULL)
    {
        return (addListElementIntoEmptyList(list, position, inputName, inputTelephone) != 0) ? 2 : 0;
    }
    if (position->currentPosition == NULL)
    {
        return 3;
    }
    if (position->currentPosition->next == NULL && position->currentPosition->previous == NULL)
    {
        if (addAfterPosition)
        {
            return (addListElementIntoTail(list, position, inputName, inputTelephone) != 0) ? 4 : 0;
        }
    return (addListElementIntoHead(list, position, inputName, inputTelephone) != 0) ? 5 : 0;
    }
    if (position->currentPosition->next == NULL && addAfterPosition)
    {
        return (addListElementIntoTail(list, position, inputName, inputTelephone) != 0) ? 4 : 0;
    }
    if (position->currentPosition->previous == NULL && !addAfterPosition)
    {
        return (addListElementIntoHead(list, position, inputName, inputTelephone) != 0) ? 5 : 0;
    }
    ListElement* element = calloc(1, sizeof(ListElement));
    if (element == NULL)
    {
        return 6;
    }
    addStrings(element, inputName, inputTelephone);
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

void removeStrings(ListElement* element)
{
    free(element->name);
    free(element->telephone);
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