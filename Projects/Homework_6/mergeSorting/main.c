#include <stdio.h>
#include "listTest.h"
#include "stackOfListTest.h"
#include "list.h"
#include "mergeSortingTest.h"
#include "mergeSorting.h"

#define SIZE 100

int main(void)
{
	if (isListBehavesIncorrect())
	{
		return 1;
	}
	if (isStackBehavesIncorrectly())
	{
		return 2;
	}
	if (isMergeSortBehavesIncorrectly())
	{
		return 3;
	}
	FILE* file = NULL;
	fopen_s(&file, "input.txt", "r");
	if (file == NULL)
	{
		return 4;
	}
	List* list = createList();
	Position* position = createPosition();
	char bufferOne[SIZE] = { 0 };
	char bufferTwo[SIZE] = { 0 };
	while (!feof(file))
	{
		fscanf_s(file, "%s", bufferOne, SIZE);
		fscanf_s(file, "%s", bufferTwo, SIZE);
		addListElement(list, position, bufferOne, bufferTwo, true);
	}
	fclose(file);
	printf_s("Sort by name(1) or by phone(2)?\n");
	int mode = 0;
	while (mode != 1 && mode != 2)
	{
		scanf_s("%d", &mode);
		while (scanf_s("%*c") != 0);
	}
	list = sortByMergeSorting(list, mode == 1);
	movePositionToHead(list, position);
	while (!isPositionNull(position))
	{
		getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
		printf_s("%s - %s\n", bufferOne, bufferTwo);
		movePositionToNext(position);
	}
	deletePosition(position);
	deleteList(list);
	return 0;
}