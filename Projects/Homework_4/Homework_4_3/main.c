#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "listTestModule.h"

void main() {
	runModuleTest();
	List* list = createNewList();
	addNewElement(list, "Grisha", "782324324324");
	addNewElement(list, "Grisha1", "7823243224324");
	char** arrayOfString = getElements(list);
	puts(arrayOfString[0]);
	puts(arrayOfString[1]);
	puts(arrayOfString[2]);
	puts(arrayOfString[3]);
	deleteList(list);
}