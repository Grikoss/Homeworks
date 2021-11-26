#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "sortedList.h"
#include "sortedListTest.h"

void addElementM(SortedList* list)
{
    printf("Enter number:\n");
    int value = 0;
    while (scanf_s("%d", &value) == 0)
    {
        while (scanf_s("%*[^\n]%*c") != 0);
    }
    while (scanf_s("%*c") != 0);
    addElement(list, value);
    printf("Element has been added\n");
}

void removeElementM(SortedList* list)
{
    printf("Enter number:\n");
    int value = 0;
    while (scanf_s("%d", &value) == 0)
    {
        while (scanf_s("%*[^\n]%*c") != 0);
    }
    while (scanf_s("%*c") != 0);
    if (removeElement(list, value) != 0)
    {
        printf("There is no such element\n");
        return;
    }
    printf("Element has been removed\n");
}

void printValues(SortedList* list)
{
    SortedLIstPosition* position = createSLPosition();
    moveSLPositionToHead(list, position);
    printf("Elements:\n");
    while (!isEnd(position))
    {
        int value = 0;
        getValueFromSLPosition(position, &value);
        printf("%d\n", value);
        moveSLPositionToNext(position);
    }
    deleteSLPositin(position);
}

int main()
{
    if (isSortedListBehavesIncorrectly())
    {
        return 1;
    }
    int value = 10;
    SortedList* list = createSortedList();
    while (value != 0)
    {
        printf("Choose mode:\n0 - exit; 1 - add element; 2 - remove element; 3 - print values\n");\
        scanf_s("%d", &value);
        while (scanf_s("%*[^\n]%*c") != 0);
        switch (value)
        {
        case 0:
            break;
        case 1:
            addElementM(list);
            break;
        case 2:
            removeElementM(list);
            break;
        case 3:
            printValues(list);
        default:
            break;
        }
    }
    deleteSortedList(list);
    return 0;
}