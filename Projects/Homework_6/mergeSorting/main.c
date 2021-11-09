#include "listTest.h"
#include "stackOfListTest.h"
#include "list.h"
#include "mergeSorting.h"

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
	List* list = createList();
	Position* position = createPosition();
	addListElement(list, position, "Adad", "7777", true);
	addListElement(list, position, "Adad1", "7777", true);
	addListElement(list, position, "Smit", "2222", true);
	addListElement(list, position, "Ada1", "5777", true);
	addListElement(list, position, "Ada2", "37777", true);
	addListElement(list, position, "Ada3", "87777", true);
	list = sortByMergeSorting(list, false);
	deleteList(list);
	deletePosition(position);
	return 0;
}