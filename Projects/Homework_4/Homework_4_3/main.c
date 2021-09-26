#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "listTestModule.h"
#include "file.h"
#include "fileModuleTest.h"

const int sizeOfInput = 31;

void cleanConsole() {
	while (getchar() != '\n');
}

char* inputString(int size) {
	char cursor = 'a';
	while ((cursor = getchar()) == ' ');
	if (cursor == '\n') {
		return NULL;
	}

	char* buffer = calloc(size, sizeof(char));
	if (buffer == NULL) {
		return NULL;
	}

	int counter = 0;
	while (cursor != ' ' && cursor != '\n' && counter < (size - 1)) {
		buffer[counter] = cursor;
		cursor = getchar();
		++counter;
	}

	buffer[counter] = '\0';
	if (cursor != '\n') {
		cleanConsole();
	}

	return buffer;
}


int main() {
	if (!runListModuleTest()) {
		printf("List test failed");
		return 1;
	}

	if (!runFileModuleTest()) {
		printf("File test failed");
		return 2;
	}

	FILE* file = fopen("telephone.txt", "r");
	if (file == NULL) {
		file = fopen("telephone.txt", "w");
		if (file == NULL) {
			return 3;
		}

		fclose(file);
		file = fopen("telephone.txt", "r");
	}

	List* list = createNewList();
	char* inputName = readFromFile(file);
	char* inputTelephone = readFromFile(file);
	while (inputName != NULL && inputTelephone != NULL) {
		addNewElement(list, inputName, inputTelephone);
		inputName = readFromFile(file);
		inputTelephone = readFromFile(file);
	}

	fclose(file);
	if (inputName != NULL){
		free(inputName);
	}

	printf("Welcome to telephone book\n");
	printf("Current number of phones is %d\n", getQuantity(list));
	printf("Max current number of phones is 100\n");
	printf("Available options:\n");
	printf("0 - exit\n1 - add a record (name and phone number)\n2 - print all available records\n");
	printf("3 - find a phone by name\n4 - find a name by phone\n5 - save the current data to a file\n");
	char currentMod = 'a';
	currentMod = getchar();
	cleanConsole();
	bool isAnyNewRecords = false;
	while (currentMod != '0') {
		while (currentMod != '1' && currentMod != '2' && currentMod != '3' && currentMod != '4' && currentMod != '5' && currentMod != '0') {
			currentMod = getchar();
			cleanConsole();
		}

		if (currentMod == '1') {
			if (getQuantity(list) == 100) {
				printf("More than 100 records are not available\n");
			}
			else {
				printf("Enter name:\n");
				char* name = NULL;
				while (name == NULL) {
					name = inputString(sizeOfInput);
				}

				printf("Enter telephone:\n");
				char* telephone = NULL;
				while (telephone == NULL) {
					telephone = inputString(sizeOfInput);
				}

				addNewElement(list, name, telephone);
				isAnyNewRecords = true;
			}
		}

		if (currentMod == '2') {
			printf("Records:\n");
			resetPointer(list);
			char* outName = NULL;
			char* outTelephone = NULL;
			for (int i = 0; i < getQuantity(list); ++i) {
				getElements(list, &outName, &outTelephone);
				printf("%i) Name: ", i + 1);
				fputs(outName, stdout);
				printf(" Telephone: ");
				puts(outTelephone);
			}
		}

		if (currentMod == '3' || currentMod == '4') {
			currentMod == '3' ? printf("Enter the name: ") : printf("Enter the telephone: ");
			char* key = inputString(sizeOfInput);
			char* search = searchElement(list, key, currentMod == '3');
			free(key);

			if (search == NULL) {
				printf("Not found\n");
			}
			else {
				currentMod == '3' ? printf("The telephone: ") : printf("The name: ");
				puts(search);
			}
		}

		if (currentMod == '5') {
			file = fopen("telephone.txt", "w");
			char* writeName = NULL;
			char* writeTelehone = NULL;
			for (int i = 0; i < getQuantity(list); ++i) {
				getElements(list, &writeName, &writeTelehone);
				writeToFile(file, writeName, ' ');
				writeToFile(file, writeTelehone, '\n');
			}

			fclose(file);
			isAnyNewRecords = false;
			printf("Records saved succesful\n");
		}

		printf("Choose option:\n");
		currentMod = getchar();
		cleanConsole();
		if (currentMod == '0' && isAnyNewRecords) {
			printf("You haven't saved the latest changes. Confirm to continue(yes): \n");
			currentMod = getchar();
			cleanConsole();
			if (currentMod == 'y') {
				currentMod = '0';
			}
			else {
				printf("Choose option:\n");
				currentMod = getchar();
				cleanConsole();
			}
		}
	}
	
	deleteList(list);
	return 0;
}