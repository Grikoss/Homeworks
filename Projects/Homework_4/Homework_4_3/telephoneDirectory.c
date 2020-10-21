#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "telephoneDirectory.h"
#include "list.h"

void readFromFile(List* list) {
	FILE* file = fopen("telephoneDirectory.txt", "r");
	if (file == NULL) {
		return;
	}

	int i = 0;
	while (!feof(file)) {
		char* bufferOne = malloc(sizeof(char) * 100);
		char* bufferTwo = malloc(sizeof(char) * 100);
		switch (i % 2)
		{
		case (0):
			if (fgets(bufferOne, sizeof(bufferOne), file) == NULL || fgets(bufferTwo, sizeof(bufferTwo), file) == NULL) {
				return;
			}

			if (addNewElement(list, bufferOne, bufferTwo) < 0) {
				printf("Exceeded the maximum size of contacts");
				return;
			}

		case(1):
			fgets(bufferOne, sizeof(bufferOne), file);
			free(bufferOne);
		}

		++i;
	}

	fclose(file);
}

List* list = NULL;
bool isFirstRun = true;
void telephoneDirectory(int mod, char* name, char* telephone) {
	if (isFirstRun) {
		List* newList = createNewList();
		readFromFile(list);
		isFirstRun = false;
		list = newList;
	}
	
	char* nameOutput = NULL;
	char* telephoneOutput = NULL;
	FILE* file = fopen("telephoneDirectory.txt", "w");
	switch (mod)
	{
	case(1):
		if (addNewElement(list, name, telephone) < 0) {
			printf("Exceeded the maximum size of contacts");
			return;
		}
	
	case(2):
		while (getElement(list, &nameOutput, &telephoneOutput) >= 0) {
			puts(nameOutput);
			puts(telephoneOutput);
			printf("\n");
		}

		return;

	case (3):
		puts(searchElement(list, name, true));
		return;

	case(4):
		puts(searchElement(list, telephone, false));
		return;

	case(5):
		if (file == NULL) {
			printf("File not found");
			return;
		}

		while (getElement(list, &nameOutput, &telephoneOutput) >= 0) {
			fwrite(nameOutput, sizeof(nameOutput), 1, file);
			fwrite(telephoneOutput, sizeof(telephoneOutput), 1, file);
			fwrite("\n", sizeof(char), 1, file);
		}

		return;

	default:
		printf("Goodbay\n");
		deleteList(list);
		exit(0);
	}

	fclose(file);
}