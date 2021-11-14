#include <stdbool.h>
#include <stdlib.h>
#include "../list/listTest.h"
#include "sortedList.h"
#include "sortedListTest.h"

bool isCreateSortedListBehavesIncorrect(SortedList** sortedList)
{
    *sortedList = createSortedList();
    return *sortedList == NULL;
}

bool isAddElementBehavesIncorrect(SortedList* list)
{
    bool result = addElement(NULL, 10) != 1;
    result = result || addElement(list, 5) != 0;
    result = result || addElement(list, 2) != 0;
    result = result || addElement(list, 3) != 0;
    result = result || addElement(list, 1) != 0;
    return result || addElement(list, 4) != 0;
}

bool isRemoveElementBehavesIncorrect(SortedList* list)
{
    bool result = removeElement(NULL, 10) != 2;
    result = result || removeElement(list, 10) != 1;
    return result || removeElement(list, 3) != 0;
}

bool isGetValuesBehavesIncorrect(SortedList* list)
{
    SLPosition* position = createSLPosition();
    moveSLPositionToHead(list, position);
    int value = 0;
    bool result = getValueFromSLPosition(NULL, &value) != 1;
    result = result || getValueFromSLPosition(position, &value) != 0;
    result = result || value != 1;
    moveSLPositionToNext(position);
    result = result || getValueFromSLPosition(position, &value) != 0;
    result = result || value != 2;
    moveSLPositionToNext(position);
    result = result || getValueFromSLPosition(position, &value) != 0;
    result = result || value != 3;
    moveSLPositionToNext(position);
    result = result || getValueFromSLPosition(position, &value) != 0;
    result = result || value != 4;
    moveSLPositionToNext(position);
    result = result || getValueFromSLPosition(position, &value) != 0;
    result = result || value != 5;
    moveSLPositionToNext(position);
    result = result || !isSLPositionIsNULL(position);
    deleteSLPositin(position);
    return result;
}

bool isDeleteSortedListBehavesIncorrect(SortedList* list)
{
    bool result = deleteSortedList(NULL) != 1;
    return result || deleteSortedList(list) != 0;
}

bool isSortedListBeahavesIncorrect()
{
    bool result = isListBehavesIncorrectly();
    SortedList* sortedList = NULL;
    result = result || isCreateSortedListBehavesIncorrect(&sortedList);
    result = result || isAddElementBehavesIncorrect(sortedList);
    result = result || isGetValuesBehavesIncorrect(sortedList);
    result = result || isRemoveElementBehavesIncorrect(sortedList);
    return result || isDeleteSortedListBehavesIncorrect(sortedList);
}