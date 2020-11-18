#include <stdlib.h>
#include "../MyList/list.h"
#include "postfixCalculator.h"

void doABarrelRoll(char* input, int begin, int end) {
	int step = (end - begin + 1) / 2;
	for (int i = 0; i < step; ++i) {
		input[begin + i] += input[end - i];
		input[end - i] = input[begin + i] - input[end - i];
		input[begin + i] -= input[end - i];
	}
}

char* convertIntToString(int value) {
	char* tmp = NULL;
	char* buffer = (char*)malloc(sizeof(char) * 2);
	int size = 2;
	if (buffer == NULL) {
		return NULL;
	}

	int count = 0;
	if (value == 0) {
		buffer[count] = '0';
		++count;
	}

	if (value < 0) {
		buffer[count] = '-';
		++count;
	}

	while (abs(value) > 0) {
		if (count <= size - 1) {
			size *= 2;
			tmp = (char*)realloc(buffer, sizeof(char) * size);
			if (tmp == NULL) {
				free(buffer);
				return NULL;
			}
			else {
				buffer = tmp;
			}
		}

		buffer[count] = abs(value % 10) + 48;
		count++;

		value /= 10;
	}

	buffer[count] = '\0';
	if (count > 1) {
		int begin = 0;
		if (buffer[0] == '-') {
			begin = 1;
		}

		doABarrelRoll(buffer, begin, count - 1);
	}

	return buffer;
}

int determineSign(char* subString) {
	if (subString[0] == '+') {
		return 1;
	}

	if (subString[0] == '-' && subString[1] == '\0') {
		return 2;
	}

	if (subString[0] == '*') {
		return 3;
	}

	if (subString[0] == '/') {
		return 4;
	}

	return 0;
}

int perfomOperation(List* list, int sign) {
	if (getLastItem(list) == NULL) {
		return 1;
	}

	int valueOne = atoi(getLastItem(list));
	deleteElement(list);

	if (getLastItem(list) == NULL) {
		return 1;
	}
	
	int valueTwo = atoi(getLastItem(list));
	deleteElement(list);
	int result = 1;
	if (sign == 1) {
		result = valueTwo + valueOne;
	}

	if (sign == 2) {
		result = valueTwo - valueOne;
	}

	if (sign == 3) {
		result = valueTwo * valueOne;
	}

	if (sign == 4) {
		result = valueTwo / valueOne;
	}

	char* string = convertIntToString(result);
	addElement(list, string);
	return 0;
}

int postfixCalculator(int* result, char* input) {
	List* list = createNewList();
	int intputCount = 0;
	char currentCharacter = input[intputCount];
	++intputCount;
	while (currentCharacter != '\n' && currentCharacter != '\0') {
		int count = 0;
		int size = 1;
		char* tmp = NULL;
		char* buffer = (char*)malloc(sizeof(char));
		if (buffer == NULL) {
			deleteList(&list);
			return 1;
		}

		while ((currentCharacter >= '0' && currentCharacter <= '9') || currentCharacter == '+' || currentCharacter == '-' || currentCharacter == '*' || currentCharacter == '/') {
			if (count <= size - 1) {
				size *= 2;
				tmp = (char*)realloc(buffer, sizeof(char) * size);
				if (tmp == NULL) {
					free(buffer);
					deleteList(&list);
					return 1;
				}
				else {
					buffer = tmp;
				}
			}

			buffer[count] = currentCharacter;
			++count;
			currentCharacter = input[intputCount];
			++intputCount;
		}

		buffer[count] = '\0';
		if (count <= 0) {
			free(buffer);
		}
		else {
			int sign = determineSign(buffer);
			if (sign == 0) {
				addElement(list, buffer);
			}
			else {
				free(buffer);
				if (perfomOperation(list, sign) == 1) {
					deleteList(&list);
					return 1;
				}
			}
		}

		currentCharacter = input[intputCount];
		++intputCount;
	}

	int quantity = 0;
	if (getQuantity(&quantity, list), quantity != 1) {
		deleteList(&list);
		return 1;
	}

	*result = atoi(getLastItem(list));
	deleteList(&list);
	return 0;
}