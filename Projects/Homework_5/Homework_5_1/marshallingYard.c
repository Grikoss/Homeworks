#include <stdlib.h>
#include "marshallingYard.h"
#include "../MyList/list.h"

int determineMod(char* subString) {
	if (subString[0] == '+') {
		return 1;
	}

	if (subString[0] == '-' && subString[1] == '\0') {
		return 1;
	}

	if (subString[0] == '*') {
		return 2;
	}

	if (subString[0] == '/') {
		return 2;
	}

	if (subString[0] == '(') {
		return 3;
	}

	if (subString[0] == ')') {
		return 4;
	}

	return 0;
}

char* putToString(char* output, char* input, int* size, int* count) {
	char* tmp = NULL;
	if (output[*count] == '\0') {
		output[*count] = ' ';
		++* count;
	}

	int inputCount = 0;
	while (input[inputCount] != '\0') {
		if (*count <= *size - 1) {
			*size *= 2;
			tmp = (char*)realloc(output, sizeof(char) * *size);
			if (tmp == NULL) {
				free(output);
				return NULL;
			}
			else {
				output = tmp;
			}
		}

		output[*count] = input[inputCount];
		++* count;
		++inputCount;
	}

	output[*count] = '\0';
	return output;
}

int customs(List* list, char* input, char** output, int* size, int* count) {
	int mod = determineMod(input);
	if (mod == 1) {
		if (getLastItem(list) == NULL) {
			addElement(list, input);
			return 0;
		}

		if (determineMod(getLastItem(list)) == 2 || determineMod(getLastItem(list)) == 1) {
			*output = putToString(*output, getLastItem(list), size, count);
			deleteElement(list);
		}

		addElement(list, input);
		return 0;
	}

	if (mod == 2) {
		if (getLastItem(list) == NULL) {
			addElement(list, input);
			return 0;
		}

		if (determineMod(getLastItem(list)) == 2) {
			*output = putToString(*output, getLastItem(list), size, count);
			deleteElement(list);
		}

		addElement(list, input);
		return 0;
	}

	if (mod == 3) {
		addElement(list, input);
		return 0;
	}

	if (mod == 4) {
		free(input);
		if (getLastItem(list) == NULL) {
			return 1;
		}

		while (determineMod(getLastItem(list)) != 3) {
			*output = putToString(*output, getLastItem(list), size, count);
			deleteElement(list);
			if (getLastItem(list) == NULL) {
				return 1;
			}
		}

		deleteElement(list);
		return 0;
	}

	return 1;
}

char* marshallingYard(char* input) {
	List* list = createNewList();
	char* output = (char*)malloc(sizeof(char));
	if (output == NULL) {
		deleteList(&list);
		return NULL;
	}

	int previousMod = 5;
	int outputCount = 0;
	int outputSize = 1;
	int intputCount = 0;
	char currentCharacter = input[intputCount];
	++intputCount;
	while (currentCharacter != '\n' && currentCharacter != '\0') {
		int count = 0;
		int size = 2;
		char* tmp = NULL;
		char* buffer = (char*)malloc(sizeof(char) * 2);
		if (buffer == NULL) {
			free(output);
			deleteList(&list);
			return NULL;
		}

		if (currentCharacter == '+' || currentCharacter == '-' || currentCharacter == '*' || currentCharacter == '/' || currentCharacter == '(' || currentCharacter == ')') {
			buffer[count] = currentCharacter;
			++count;
			currentCharacter = input[intputCount];
			++intputCount;
		}
		else {
			while ((currentCharacter >= '0' && currentCharacter <= '9')) {
				if (count <= size - 1) {
					size *= 2;
					tmp = (char*)realloc(buffer, sizeof(char) * size);
					if (tmp == NULL) {
						free(output);
						free(buffer);
						deleteList(&list);
						return NULL;
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
		}

		buffer[count] = '\0';
		if (count <= 0) {
			free(buffer);
		}
		else {
			int mod = determineMod(buffer);
			if ((mod == 0) && (previousMod == 3 || previousMod == 0)) {
				free(buffer);
				free(output);
				deleteList(&list);
				return NULL;
			}

			if ((mod == 1 || mod == 2) && (previousMod == 1 || previousMod == 2 || previousMod == 4)) {
				free(buffer);
				free(output);
				deleteList(&list);
				return NULL;
			}

			if ((mod == 3) && (previousMod == 1 || previousMod == 2)) {
				free(buffer);
				free(output);
				deleteList(&list);
				return NULL;
			}

			if ((mod == 4) && (previousMod == 0 || previousMod == 3)) {
				free(buffer);
				free(output);
				deleteList(&list);
				return NULL;
			}

			previousMod = mod;
			if (mod == 0) {
				output = putToString(output, buffer, &outputSize, &outputCount);
				free(buffer);
				if (output == NULL) {
					deleteList(&list);
					return NULL;
				}
			}
			else {
				if (customs(list, buffer, &output, &outputSize, &outputCount) == 1) {
					free(output);
					deleteList(&list);
					return NULL;
				}
			}
		}

		if (currentCharacter != '+' && currentCharacter != '-' && currentCharacter != '*' && currentCharacter != '/' && currentCharacter != '(' && currentCharacter != ')') {
			currentCharacter = input[intputCount];
			++intputCount;
		}
	}

	int quantity = 1;
	if (getQuantity(&quantity, list), quantity != 0) {
		free(output);
		deleteList(&list);
		return NULL;
	}

	deleteList(&list);
	return output;
}