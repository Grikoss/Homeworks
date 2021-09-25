#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "listTestModule.h"
#include "file.h"

int getString(char* input, int size, FILE* file) {
	while (!feof(file)) {
		int count = 0;
		char currentCharacter = fgetc(file);
		while (currentCharacter != '\n' && currentCharacter != '\0') {
			input[count] = currentCharacter;
			++count;
			if (count >= (size - 1)) {
				input[size - 1] = '\0';
				return 0;
			}

			currentCharacter = fgetc(file);
		}

		input[count] = '\0';
		return (count > 0) ? 0 : 1;
	}

	input[0] = '\0';
	return 0;
}

int main() {
	/*runModuleTest();
	List* list = createNewList();
	FILE* fileRead = fopen("telephoneDirectory.txt", "r");
	if (fileRead != NULL) {
		char* bufferName = (char*)malloc(sizeof(char) * 100);
		if (bufferName == NULL) {
			return;
		}

		char* bufferTelephone = (char*)malloc(sizeof(char) * 100);
		if (bufferTelephone == NULL) {
			return;
		}

		while (!feof(fileRead)) {
			while (getString(bufferName, 100, fileRead) != 0);
			while (getString(bufferTelephone, 100, fileRead) != 0);
			if (bufferName[0] != '\0' && bufferTelephone[0] != '\0') {
				char* name = (char*)malloc(sizeof(char) * 100);
				if (name == NULL) {
					return;
				}

				char* telephone = (char*)malloc(sizeof(char) * 100);
				if (telephone == NULL) {
					return;
				}

				memcpy(name, bufferName, 100);
				memcpy(telephone, bufferTelephone, 100);
				if (addNewElement(list, name, telephone) == -2) {
					free(name);
					free(telephone);
					break;
				}
			}
		}

		fclose(fileRead);
		free(bufferName);
		free(bufferTelephone);
	}

	char** arrayOfString = NULL;
	while (true) {
		printf("0 - exit\n1 - add new contact\n2 - print all contacts\n3 - search by name\n4 - search by telephone\n5 - write all contacts in file\n");
		char input[1] = { 'a' };
		while (input[0] != '0' && input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5') {
			input[0] = getc(stdin);
			char c = '0';
			while ((c = getc(stdin)) != EOF && c != '\n');
		}

		int mode = atoi(input);
		if (mode == 0) {
			printf("exit");
			break;
		}

		if (mode == 1) {
			printf("Add new contact:\n");
			char* inputName = (char*)malloc(sizeof(char) * 100);
			if (inputName == NULL) {
				return;
			}

			char* inputTelephone = (char*)malloc(sizeof(char) * 100);
			if (inputTelephone == NULL) {
				return;
			}

			printf("Enter name\n");
			getString(inputName, 100, stdin);
			printf("Enter telephone\n");
			getString(inputTelephone, 100, stdin);
			if (addNewElement(list, inputName, inputTelephone) == -2) {
				free(inputName);
				free(inputTelephone);
				printf("Maximum number of entries exceeded");
			}
		}

		if (mode == 2) {
			printf("Print all contacts:\n");
			arrayOfString = getElements(list);
			int quantity = getQuantity(list);
			if (quantity == 0) {
				printf("It's empty\n");
			}
			else {
				for (int i = 0; i < (2 * quantity); ++i) {
					puts(arrayOfString[i]);
					++i;
					puts(arrayOfString[i]);
					printf("\n");
				}
			}
		}

		if (mode == 3 || mode == 4) {
			bool isSearchByName = (mode == 3) ? true : false;
			char* key = (char*)malloc(sizeof(char) * 100);
			if (key == NULL) {
				return;
			}

			printf((isSearchByName) ? "Search by name:\n" : "Search by telephone:\n");
			printf((isSearchByName) ? "Enter name\n" : "Enter telephone\n");
			getString(key, 100, stdin);
			char* search = searchElement(list, key, isSearchByName);
			if (search == NULL) {
				printf("Not found\n");
			}
			else {
				printf((isSearchByName) ? "Telephone: " : "Name: ");
				puts(search);
				printf("\n");
			}

			free(key);
		}

		if (mode == 5) {
			printf("Write all contacts in file\n");
			FILE* fileWrite = fopen("telephoneDirectory.txt", "w");
			if (fileWrite == NULL) {
				printf("Can't create file");
			}
			else {
				arrayOfString = getElements(list);
				for (int i = 0; i < (2 * getQuantity(list)); ++i) {
					fprintf(fileWrite, arrayOfString[i]);
					fprintf(fileWrite, "\n");
					++i;
					fprintf(fileWrite, arrayOfString[i]);
					fprintf(fileWrite, "\n");
					fprintf(fileWrite, "\n");
				}

				fclose(fileWrite);
			}
		}
	}

	deleteList(list);
	if (arrayOfString != NULL) {
		free(arrayOfString);
	}*/
	if (!runModuleTest()) {
		printf("List test failed");
		return 1;
		}

	if (readFromFile() == NULL) {
		return 2;
	}
}