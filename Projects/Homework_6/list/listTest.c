#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "listTest.h"

bool isCreateListBehavesIncorrect(List** list)
{
    *list = createList();
    return *list == NULL;
}

bool isCreatePositionBehavesIncorrect(Position** position)
{
    *position = createPosition();
    return *position == NULL;
}

bool isMovePositionToHeadBehavesIncorrect(List* list, Position* position)
{
    bool result = 1 != movePositionToHead(NULL, position);
    result = result || 1 != movePositionToHead(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToHead(list, position);
}

bool isMovePositionToTailBehavesIncorrect(List* list, Position* position)
{
    bool result = 1 != movePositionToTail(NULL, position);
    result = result || 1 != movePositionToTail(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToTail(list, position);
}


bool isAddListElementBehavesIncorrect(List* list, Position* position)
{
    bool result = addListElement(NULL, position, 0, true) != 1 || addListElement(list, NULL, 0, true) != 1;
    result = result || addListElement(list, position, 1, true) != 0;
    movePositionToNext(position);
    result = result || addListElement(list, position, 2, true) != 3;
    movePositionToHead(list, position);
    int value = 0;
    getValueFromListElement(position, &value);
    movePositionToTail(list, position);
    int valueTwo = 0;
    getValueFromListElement(position, &valueTwo);
    result = result || value != valueTwo;
    result = result || addListElement(list, position, 2, true) != 0;
    movePositionToHead(list, position);
    getValueFromListElement(position, &value);
    movePositionToTail(list, position);
    getValueFromListElement(position, &valueTwo);
    result = result || value != 1 || valueTwo != 2;
    removeListElement(list, position, false);
    result = result || addListElement(list, position, 2, false) != 0;
    movePositionToHead(list, position);
    getValueFromListElement(position, &value);
    movePositionToTail(list, position);
    getValueFromListElement(position, &valueTwo);
    result = result || value != 2 || valueTwo != 1;
    movePositionToHead(list, position);
    result = result || addListElement(list, position, 4, false) != 0;
    result = result || addListElement(list, position, 3, true) != 0;
    movePositionToTail(list, position);
    result = result || addListElement(list, position, 4, true) != 0;
    result = result || addListElement(list, position, 3, false) != 0;
    movePositionToHead(list, position);
    getValueFromListElement(position, &value);
    result = result || value != 4;
    movePositionToNext(position);
    getValueFromListElement(position, &value);
    result = result || value != 3;
    movePositionToNext(position);
    getValueFromListElement(position, &value);
    result = result || value != 2;
    movePositionToNext(position);
    getValueFromListElement(position, &value);
    result = result || value != 1;
    movePositionToNext(position);
    getValueFromListElement(position, &value);
    result = result || value != 3;
    movePositionToNext(position);
    getValueFromListElement(position, &value);
    return result || value != 4;
}

bool isGetValueFromElementBehavesIncorrect(List* list, Position* position)
{
    int value = 0;
    bool result = getValueFromListElement(position, &value) != 0 || value != 4;
    result = result || getValueFromListElement(NULL, &value) != 1;
    movePositionToHead(list, position);
    movePositionToPrevious(position);
    return result || getValueFromListElement(position, &value) != 1;
}

bool isListBehavesIncorrect()
{
    List* list = NULL;
    bool result = isCreateListBehavesIncorrect(&list);
    Position* position = NULL;
    result = result || isCreatePositionBehavesIncorrect(&position);
    result = result || isMovePositionToHeadBehavesIncorrect(list, position);
    result = result || isMovePositionToTailBehavesIncorrect(list, position);
    result = result || isAddListElementBehavesIncorrect(list, position);
    result = result || isGetValueFromElementBehavesIncorrect(list, position);
    return result;
}