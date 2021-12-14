#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "mergeSorting.h"
#include "mergeSortingTest.h"

#define SIZE 100

bool isMergeSortBehavesIncorrectly(void)
{
	List* list = createList();
	Position* position = createPosition();
	addListElement(list, position, "Ada1", "70", true);
	addListElement(list, position, "Ada5", "70", true);
	addListElement(list, position, "Ada4", "20", true);
	addListElement(list, position, "Ada6", "50", true);
	addListElement(list, position, "Ada2", "30", true);
	addListElement(list, position, "Ada3", "80", true);
	list = sortByMergeSorting(list, false);
	movePositionToHead(list, position);
	char bufferOne[SIZE] = { 0 };
	char bufferTwo[SIZE] = { 0 };
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	bool result = strcmp(bufferTwo, "20") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferTwo, "30") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferTwo, "50") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferTwo, "70") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferTwo, "70") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferTwo, "80") != 0;
	list = sortByMergeSorting(list, true);
	movePositionToHead(list, position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferOne, "Ada1") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferOne, "Ada2") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferOne, "Ada3") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferOne, "Ada4") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferOne, "Ada5") != 0;
	movePositionToNext(position);
	getValueFromListElement(position, bufferOne, SIZE, bufferTwo, SIZE);
	result = result || strcmp(bufferOne, "Ada6") != 0;
	movePositionToNext(position);
	deleteList(list);
	deletePosition(position);
	return result;
}