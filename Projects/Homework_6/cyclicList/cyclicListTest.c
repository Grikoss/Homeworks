#include <stdbool.h>
#include <stdlib.h>
#include "cyclicList.h"
#include "cyclicListTest.h"

bool isCreateListBehavesIncorrectly(CyclicList** list)
{
    *list = createList();
    return *list == NULL;
}

bool isCreatePositionBehavesIncorrect(Position * *position)
{
    *position = createPosition();
    return *position == NULL;
}

bool isMovePositionToHeadBehavesIncorrect(CyclicList * list, Position * position)
{
    bool result = 1 != movePositionToHead(NULL, position);
    result = result || 1 != movePositionToHead(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToHead(list, position);
}

bool isMovePositionToTailBehavesIncorrect(CyclicList * list, Position * position)
{
    bool result = 1 != movePositionToTail(NULL, position);
    result = result || 1 != movePositionToTail(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToTail(list, position);
}

bool isAddListElementBehavesIncorrect(CyclicList* list, Position* position)
{
    bool result = addListElement(NULL, position, 0, true) != 1 || addListElement(list, NULL, 0, true) != 1;
    result = result || addListElement(list, position, 1, true) != 0;
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

bool isGetValueFromElementBehavesIncorrect(CyclicList* list, Position* position)
{
    int value = 0;
    bool result = getValueFromListElement(position, &value) != 0 || value != 4;
    return result || getValueFromListElement(NULL, &value) != 1;
}

bool isMovePositionToNextOrPreviousBehavesIncorrect(CyclicList* list, Position* position)
{
    movePositionToHead(list, position);
    bool result = movePositionToNext(position) != 0;
    result = result || movePositionToPrevious(position) != 0;
    result = result || movePositionToNext(NULL) != 1 || movePositionToPrevious(NULL) != 1;
    movePositionToHead(list, position);
    result = result || movePositionToPrevious(position) != 0;
    return result || movePositionToNext(position) != 0 || movePositionToPrevious(position) != 0;
}

bool isFunctionisPositionNullBehavesIncorrect(CyclicList* list, Position* position)
{
    bool result = isPositionNull(position);
    result = result || !isPositionNull(NULL);
    movePositionToHead(list, position);
    return result || isPositionNull(position);
}

bool isRemoveListElementBehavesIncorrect(CyclicList* list, Position* position)
{
    movePositionToHead(list, position);
    bool result = removeListElement(list, position, false) != 0;
    result = result || isPositionNull(position);
    movePositionToHead(list, position);
    result = result || removeListElement(list, position, true) != 0;
    result = result || isPositionNull(position);
    movePositionToTail(list, position);
    result = result || removeListElement(list, position, true) != 0;
    result = result || isPositionNull(position);
    movePositionToTail(list, position);
    result = result || removeListElement(list, position, false) != 0;
    result = result || isPositionNull(position);
    result = result || removeListElement(list, position, false) != 0;
    movePositionToHead(list, position);
    result = result || removeListElement(list, position, true) != 0;
    result = result || !isPositionNull(position);
    result = result || removeListElement(list, position, true) != 2;
    return result || removeListElement(NULL, position, true) != 1 || removeListElement(list, NULL, true) != 1;
}

bool isDeleteListBehavesIncorrect(CyclicList* list)
{
    return deleteList(NULL) != 1 || deleteList(list) != 0;
}

bool isCyclicListIsNotOkey(CyclicList* list, Position* position)
{
    movePositionToHead(list, position);
    addListElement(list, position, 10, false);
    movePositionToTail(list, position);
    addListElement(list, position, 15, true);
    movePositionToHead(list, position);
    movePositionToPrevious(position);
    int value = 0;
    getValueFromListElement(position, &value);
    return 15 != value;
}

bool isPositionPointOnLastElementBehavesIncorrectly(CyclicList* list, Position* position)
{
    removeListElement(list, position, true);
    bool result = !isPositionPointOnLastElement(position) || isPositionPointOnLastElement(NULL);
    removeListElement(list, position, true);
    return result || isPositionPointOnLastElement(position);
}

bool isListBehavesIncorrect()
{
    CyclicList* list = NULL;
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
    result = result || isCyclicListIsNotOkey(list, position);
    result = result || isPositionPointOnLastElementBehavesIncorrectly(list, position);
    deletePosition(position);
    return result || isDeleteListBehavesIncorrect(list);
}