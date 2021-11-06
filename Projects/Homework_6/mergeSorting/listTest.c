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

bool isCreatePositionBehavesIncorrect(Position * *position)
{
    *position = createPosition();
    return *position == NULL;
}

bool isMovePositionToHeadBehavesIncorrect(List * list, Position * position)
{
    bool result = 1 != movePositionToHead(NULL, position);
    result = result || 1 != movePositionToHead(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToHead(list, position);
}

bool isMovePositionToTailBehavesIncorrect(List * list, Position * position)
{
    bool result = 1 != movePositionToTail(NULL, position);
    result = result || 1 != movePositionToTail(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToTail(list, position);
}

bool isAddListElementBehavesIncorrect(List* list, Position* position)
{
    char stringOne[] = "one";
    char stringTwo[] = "two";
    bool result = addListElement(NULL, position, stringOne, stringTwo, true) != 1 || addListElement(list, NULL, stringOne, stringTwo, true) != 1;
    result = result || addListElement(list, position, stringOne, stringTwo, true) != 0;
    movePositionToNext(position);
    result = result || addListElement(list, position, stringOne, stringTwo, true) != 3;
    movePositionToTail(list, position);
    return result || addListElement(list, position, stringOne, stringTwo, true);
}

bool isGetValueFromElementBehavesIncorrect(List* list, Position* position)
{
    movePositionToHead(list, position);
    char bufferOne[10] = { 0 };
    char bufferTwo[10] = { 0 };
    bool result = getValueFromListElement(position, bufferOne, bufferTwo) != 0;
    movePositionToTail(list, position);
    char bufferThree[10] = { 0 };
    char bufferFour[10] = { 0 };
    result = result || getValueFromListElement(position, bufferThree, bufferFour) != 0;
    result = result || strcmp(bufferOne, bufferThree) != 0;
    result = result || strcmp(bufferTwo, bufferFour) != 0;
    movePositionToHead(list, position);
    movePositionToPrevious(position);
    return result || getValueFromListElement(position, bufferFour, bufferThree) != 1;
}

bool isMovePositionToNextOrPreviousBehavesIncorrect(List* list, Position* position)
{
    movePositionToHead(list, position);
    bool result = movePositionToNext(position) != 0;
    result = result || movePositionToPrevious(position) != 0;
    result = result || movePositionToNext(NULL) != 1 || movePositionToPrevious(NULL) != 1;
    movePositionToHead(list, position);
    result = result || movePositionToPrevious(position) != 0;
    return result || movePositionToNext(position) != 1 || movePositionToPrevious(position) != 1;
}

bool isFunctionisPositionNullBehavesIncorrect(List* list, Position* position)
{
    bool result = !isPositionNull(position);
    result = result || !isPositionNull(NULL);
    movePositionToHead(list, position);
    return result || isPositionNull(position);
}

bool isRemoveListElementBehavesIncorrect(List* list, Position* position)
{
    movePositionToHead(list, position);
    bool result = removeListElement(list, position, false) != 0;
    result = result || !isPositionNull(position);
    movePositionToHead(list, position);
    result = result || removeListElement(list, position, true) != 0;
    result = result || !isPositionNull(position);
    return result || removeListElement(NULL, position, true) != 1 || removeListElement(list, NULL, true) != 1;
}

bool isDeleteListBehavesIncorrect(List* list)
{
    return deleteList(NULL) != 1 || deleteList(list) != 0;
}

bool isListBehavesIncorrect()
{
    List* list = NULL;
    bool result = isCreateListBehavesIncorrectly(&list);
    Position* position = NULL;
    result = result || isCreatePositionBehavesIncorrect(&position);
    result = result || isMovePositionToHeadBehavesIncorrect(list, position);
    result = result || isMovePositionToTailBehavesIncorrect(list, position);
    result = result || isAddListElementBehavesIncorrect(list, position);
    result = result || isGetValueFromElementBehavesIncorrect(list, position);
    result = result || isMovePositionToNextOrPreviousBehavesIncorrect(list, position);
    result = result || isFunctionisPositionNullBehavesIncorrect(list, position);
    result = result || isRemoveListElementBehavesIncorrect(list, position);
    deletePosition(position);
    return result || isDeleteListBehavesIncorrect(list);
}