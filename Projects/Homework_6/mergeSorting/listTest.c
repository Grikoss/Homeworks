#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "listTest.h"

bool isCreateListBehavesIncorrectly(List** list)
{
    *list = createList();
    return *list == NULL;
}

bool isCreatePositionBehavesIncorrectly(Position** position)
{
    *position = createPosition();
    return *position == NULL;
}

bool isMovePositionToHeadBehavesIncorrectly(List* list, Position * position)
{
    bool result = 1 != movePositionToHead(NULL, position);
    result = result || 1 != movePositionToHead(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToHead(list, position);
}

bool isMovePositionToTailBehavesIncorrectly(List * list, Position * position)
{
    bool result = 1 != movePositionToTail(NULL, position);
    result = result || 1 != movePositionToTail(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToTail(list, position);
}

bool isAddListElementBehavesIncorrectly(List* list, Position* position)
{
    char stringOne[] = "oneOne";
    char stringTwo[] = "twoTwo";
    bool result = addListElement(NULL, position, stringOne, stringTwo, true) != 1 || addListElement(list, NULL, stringOne, stringTwo, true) != 1;
    result = result || addListElement(list, position, stringOne, stringTwo, true) != 0;
    movePositionToNext(position);
    result = result || addListElement(list, position, stringOne, stringTwo, true) != 3;
    movePositionToTail(list, position);
    return result || addListElement(list, position, stringOne, stringTwo, true);
}

bool isGetValueFromElementBehavesIncorrectly(List* list, Position* position)
{
    movePositionToHead(list, position);
    char bufferOne[10] = { 0 };
    char bufferTwo[10] = { 0 };
    bool result = getValueFromListElement(position, bufferOne, 10, bufferTwo, 10) != 0;
    movePositionToTail(list, position);
    char bufferThree[10] = { 0 };
    char bufferFour[10] = { 0 };
    result = result || getValueFromListElement(position, bufferThree, 10, bufferFour, 10) != 0;
    result = result || strcmp(bufferOne, bufferThree) != 0;
    result = result || strcmp(bufferTwo, bufferFour) != 0;
    movePositionToHead(list, position);
    movePositionToPrevious(position);
    return result || getValueFromListElement(position, bufferFour, 10, bufferThree, 10) != 1;
}

bool isMovePositionToNextOrPreviousBehavesIncorrectly(List* list, Position* position)
{
    movePositionToHead(list, position);
    bool result = movePositionToNext(position) != 0;
    result = result || movePositionToPrevious(position) != 0;
    result = result || movePositionToNext(NULL) != 1 || movePositionToPrevious(NULL) != 1;
    movePositionToHead(list, position);
    result = result || movePositionToPrevious(position) != 0;
    return result || movePositionToNext(position) != 1 || movePositionToPrevious(position) != 1;
}

bool isFunctionisPositionNullBehavesIncorrectly(List* list, Position* position)
{
    bool result = !isPositionNull(position);
    result = result || !isPositionNull(NULL);
    movePositionToHead(list, position);
    return result || isPositionNull(position);
}

bool isRemoveListElementBehavesIncorrectly(List* list, Position* position)
{
    movePositionToHead(list, position);
    bool result = removeListElement(list, position, false) != 0;
    result = result || !isPositionNull(position);
    movePositionToHead(list, position);
    result = result || removeListElement(list, position, true) != 0;
    result = result || !isPositionNull(position);
    return result || removeListElement(NULL, position, true) != 1 || removeListElement(list, NULL, true) != 1;
}

bool isDeleteListBehavesIncorrectly(List* list)
{
    return deleteList(NULL) != 1 || deleteList(list) != 0;
}

bool isListBehavesIncorrectly(void)
{
    List* list = NULL;
    bool result = isCreateListBehavesIncorrectly(&list);
    Position* position = NULL;
    result = result || isCreatePositionBehavesIncorrectly(&position);
    result = result || isMovePositionToHeadBehavesIncorrectly(list, position);
    result = result || isMovePositionToTailBehavesIncorrectly(list, position);
    result = result || isAddListElementBehavesIncorrectly(list, position);
    result = result || isGetValueFromElementBehavesIncorrectly(list, position);
    result = result || isMovePositionToNextOrPreviousBehavesIncorrectly(list, position);
    result = result || isFunctionisPositionNullBehavesIncorrectly(list, position);
    result = result || isRemoveListElementBehavesIncorrectly(list, position);
    deletePosition(position);
    return result || isDeleteListBehavesIncorrectly(list);
}