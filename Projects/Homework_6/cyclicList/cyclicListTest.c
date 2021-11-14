#include <stdbool.h>
#include <stdlib.h>
#include "cyclicList.h"
#include "cyclicListTest.h"

bool isCreateListBehavesIncorrectly(CyclicList** list)
{
    *list = createList();
    return *list == NULL;
}

bool isCreatePositionBehavesIncorrectly(Position * *position)
{
    *position = createPosition();
    return *position == NULL;
}

bool isMovePositionToFirstElementBehavesIncorrectly(CyclicList * list, Position * position)
{
    bool result = 1 != movePositionToFirstElement(NULL, position);
    result = result || 1 != movePositionToFirstElement(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToFirstElement(list, position);
}

bool isAddListElementBehavesIncorrectly(CyclicList* list, Position* position)
{
    bool result = addListElement(NULL, NULL, 10) != 1;
    result = result || addListElement(list, position, 1) != 0;
    result = result || addListElement(list, position, 2) != 0;
    result = result || addListElement(list, position, 3) != 0;
    return result;
}

bool isGetValueFromElementBehavesIncorrectly(CyclicList* list, Position* position)
{
    int value = 0;
    bool result = getValueFromListElement(NULL, &value) != 1;
    movePositionToFirstElement(list, position);
    result = result || getValueFromListElement(position, &value);
    result = result || value != 1;
    return result;
}


bool isRemoveListElementBehavesIncorrectly(CyclicList* list, Position* position)
{
    bool result = removeListElement(NULL, NULL) != 1;
    result = result || removeListElement(list, position) != 0;
    result = result || removeListElement(list, position) != 0;
    result = result || removeListElement(list, position) != 0;
    result = result || removeListElement(list, position) != 2;
    return result;
}

bool isDeleteListBehavesIncorrectly(CyclicList* list)
{
    return deleteList(NULL) != 1 || deleteList(list) != 0;
}

bool isListBehavesIncorrectly()
{
    CyclicList* list = NULL;
    bool result = isCreateListBehavesIncorrectly(&list);
    Position* position = NULL;
    result = result || isCreatePositionBehavesIncorrectly(&position);
    result = result || isAddListElementBehavesIncorrectly(list, position);
    result = result || isGetValueFromElementBehavesIncorrectly(list, position);
    result = result || isRemoveListElementBehavesIncorrectly(list, position);
    deletePosition(position);
    return result || isDeleteListBehavesIncorrectly(list);
}