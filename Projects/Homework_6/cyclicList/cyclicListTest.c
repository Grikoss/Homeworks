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

bool isMovePositionToFirstElementBehavesIncorrect(CyclicList * list, Position * position)
{
    bool result = 1 != movePositionToFirstElement(NULL, position);
    result = result || 1 != movePositionToFirstElement(list, NULL);
    return result || !isPositionNull(position) || 0 != movePositionToFirstElement(list, position);
}

bool isAddListElementBehavesIncorrect(CyclicList* list, Position* position)
{
    bool result = addListElement(NULL, NULL, 10) != 1;
    result = result || addListElement(list, position, 1) != 0;
    result = result || addListElement(list, position, 2) != 0;
    result = result || addListElement(list, position, 3) != 0;
    return result;
}

bool isGetValueFromElementBehavesIncorrect(CyclicList* list, Position* position)
{
    int value = 0;
    bool result = getValueFromListElement(NULL, &value) != 1;
    movePositionToFirstElement(list, position);
    result = result || getValueFromListElement(position, &value);
    result = result || value != 1;
    return result;
}


bool isRemoveListElementBehavesIncorrect(CyclicList* list, Position* position)
{
    bool result = removeListElement(NULL, NULL) != 1;
    result = result || removeListElement(list, position) != 0;
    result = result || removeListElement(list, position) != 0;
    result = result || removeListElement(list, position) != 0;
    result = result || removeListElement(list, position) != 2;
    return result;
}

bool isDeleteListBehavesIncorrect(CyclicList* list)
{
    return deleteList(NULL) != 1 || deleteList(list) != 0;
}

bool isListBehavesIncorrect()
{
    CyclicList* list = NULL;
    bool result = isCreateListBehavesIncorrectly(&list);
    Position* position = NULL;
    result = result || isCreatePositionBehavesIncorrect(&position);
    result = result || isAddListElementBehavesIncorrect(list, position);
    result = result || isGetValueFromElementBehavesIncorrect(list, position);
    result = result || isRemoveListElementBehavesIncorrect(list, position);
    deletePosition(position);
    return result || isDeleteListBehavesIncorrect(list);
}