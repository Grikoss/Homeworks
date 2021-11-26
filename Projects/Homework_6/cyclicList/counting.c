#include <stdlib.h>
#include "counting.h"
#include "cyclicList.h"

int getNumberofTheLastRemaining(const int numberOfStanding, const int step)
{
    CyclicList* list = createList();
    if (list == NULL)
    {
        return 0;
    }
    Position* position = createPosition();
    if (position == NULL)
    {
        return 0;
    }
    for (int i = 1; i <= numberOfStanding; ++i)
    {
        addListElement(list, position, i);
    }
    movePositionToFirstElement(list, position);
    while (!isPositionPointOnLastElement(position) && !isPositionNull(position))
    {
        for (int i = 1; i < step; ++i)
        {
            movePositionToNext(position);
        }
        removeListElement(list, position);
    }
    int value = 0;
    getValueFromListElement(position, &value);
    deleteList(list);
    deletePosition(position);
    return value;
}