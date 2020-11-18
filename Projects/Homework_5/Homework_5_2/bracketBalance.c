#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../MyList/list.h"

bool verification(char charOne, char charTwo) {
	if (charOne == '{') {
		return (charTwo == '}') ? true : false;
	}

	if (charOne == '[') {
		return (charTwo == ']') ? true : false;
	}

	if (charOne == '(') {
		return (charTwo == ')') ? true : false;
	}

	return false;
}

bool checkBracketBalance(char* input) {
	List* list = createNewList();
	int intputCount = 0;
	char currentCharacter = input[intputCount];
	++intputCount;
	while (currentCharacter != '\n' && currentCharacter != '\0') {
		if (currentCharacter == '{' || currentCharacter == '[' || currentCharacter == '(') {
			char* buffer = (char*)malloc(sizeof(char) * 2);
			if (buffer == NULL) {
				deleteList(&list);
				return false;
			}

			buffer[0] = currentCharacter;
			buffer[1] = '\0';
			addElement(list, buffer);
		}

		if (currentCharacter == '}' || currentCharacter == ']' || currentCharacter == ')') {
			if (getLastItem(list) == NULL) {
				deleteList(&list);
				return false;
			}

			if (!verification(getLastItem(list)[0], currentCharacter)) {
				deleteList(&list);
				return false;
			}
			else {
				deleteElement(list);
			}
		}

		currentCharacter = input[intputCount];
		++intputCount;
	}

	int quantity = 1;
	getQuantity(&quantity, list);
	deleteList(&list);
	return (quantity == 0) ? true : false;
}