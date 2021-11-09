#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "stackOfList.h"
#include "mergeSorting.h"

#define SIZE_OF_BUFFER 100



List* merge(List* firtsList, List* secondList, bool isSortingByName)
{
    Position* firstPosition = createPosition();
    Position* secondPosition = createPosition();
    Position* position = createPosition();
    List* list = createList();
    movePositionToHead(firtsList, firstPosition);
    movePositionToHead(secondList, secondPosition);
    while (!isPositionNull(firstPosition) || !isPositionNull(secondPosition))
    {
        char firstName[SIZE_OF_BUFFER] = { 0 };
        char secondName[SIZE_OF_BUFFER] = { 0 };
        char firstTelephone[SIZE_OF_BUFFER] = { 0 };
        char secondTelephone[SIZE_OF_BUFFER] = { 0 };
        getValueFromListElement(firstPosition, firstName, SIZE_OF_BUFFER, firstTelephone, SIZE_OF_BUFFER);
        getValueFromListElement(secondPosition, secondName, SIZE_OF_BUFFER, secondTelephone, SIZE_OF_BUFFER);
        int difference = isSortingByName ? strcmp(firstName, secondName) : strcmp(firstTelephone, secondTelephone);
        if (difference >= 0 && !isPositionNull(secondPosition))
        {
            addListElement(list, position, secondName, secondTelephone, true);
            movePositionToNext(secondPosition);
        }
        else
        {
            addListElement(list, position, firstName, firstTelephone, true);
            movePositionToNext(firstPosition);
        }
    }
    deleteList(firtsList);
    deletePosition(firstPosition);
    deleteList(secondList);
    deletePosition(secondPosition);
    deletePosition(position);
    return list;
}

List* sortByMergeSorting(List* list, bool isSortingByName)
{
    Stack* stack = createStack();
    Position* position = createPosition();
    movePositionToHead(list, position);
    while (!isPositionNull(position))
    {
        char bufferOne[SIZE_OF_BUFFER] = { 0 };
        char bufferTwo[SIZE_OF_BUFFER] = { 0 };
        getValueFromListElement(position, bufferOne, SIZE_OF_BUFFER, bufferTwo, SIZE_OF_BUFFER);
        List* subList = createList();
        addListElement(subList, position, bufferOne, bufferTwo, true);
        movePositionToHead(list, position);
        removeListElement(list, position, true);
        push(stack, subList);
    }
    deleteList(list);
    while (true)
    {
        Stack* newStack = createStack();
        int count = 0;
        while (true)
        {
            List* firstList = NULL;
            pop(stack, &firstList);
            if (firstList == NULL)
            {
                break;
            }
            List* secondList = NULL;
            pop(stack, &secondList);
            if (secondList == NULL)
            {
                ++count;
                push(newStack, firstList);
                break;
            }
            ++count;
            push(newStack, merge(firstList, secondList, isSortingByName));
        }
        deleteStack(stack);
        if (count == 1)
        {
            List* outList = NULL;
            pop(newStack, &outList);
            deleteStack(newStack);
            deletePosition(position);
            return outList;
        }
        stack = newStack;
    }
}