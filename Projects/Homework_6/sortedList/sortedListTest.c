#include <stdbool.h>
#include <stdlib.h>
#include "../list/listTest.h"
#include "sortedList.h"
#include "sortedLustTest.h"

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
    int* array = NULL;
    int size;
    bool result = getValues(NULL, &array, &size) != 1;
    result = result || getValues(list, &array, &size);
    result = result || size != 4 || array == NULL;
    result = result || array[0] != 1 || array[1] != 2 || array[2] != 4 || array[3] != 5;
    free(array);
    return result;
}

bool isDeleteSortedListBehavesIncorrect(SortedList* list)
{
    bool result = deleteSortedList(NULL) != 1;
    return result || deleteSortedList(list) != 0;
}

bool isSortedListBeahavesIncorrect()
{
    bool result = isListBehavesIncorrect();
    SortedList* sortedList = NULL;
    result = result || isCreateSortedListBehavesIncorrect(&sortedList);
    result = result || isAddElementBehavesIncorrect(sortedList);
    result = result || isRemoveElementBehavesIncorrect(sortedList);
    result = result || isGetValuesBehavesIncorrect(sortedList);
    return result || isDeleteSortedListBehavesIncorrect(sortedList);
}