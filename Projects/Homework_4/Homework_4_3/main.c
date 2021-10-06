#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "listTestModule.h"
#include "file.h"
#include "fileModuleTest.h"

const int sizeOfInput = 31;
const int size = 100;

char* inputString(int size)
{
	char* buffer = calloc(size, sizeof(char));
	if (buffer == NULL)
	{
		return NULL;
	}

	if (scanf_s("%s", buffer, size) > 0)
	{
		return buffer;
	}
	else
	{
		free(buffer);
		return NULL;
	}
}

void addARecord(List* list, bool* isAnyNewRecords)
{
	if (getQuantity(list) == 100)
	{
		printf("More than 100 records are not available\n");
	}
	else
	{
		printf("Enter name:\n");
		char* name = NULL;
		while (name == NULL)
		{
			name = inputString(sizeOfInput);
		}

		printf("Enter telephone:\n");
		char* telephone = NULL;
		while (telephone == NULL)
		{
			telephone = inputString(sizeOfInput);
		}

		addNewElement(list, name, telephone);
		*isAnyNewRecords = true;
		printf("Current number of phones is %d\n", getQuantity(list));
	}
}

void printAllAvailableRecords(List* list)
{
	printf("Records:\n");
	resetPointer(list);
	char* outName = NULL;
	char* outTelephone = NULL;
	if (getQuantity(list) == 0)
	{
		printf("There are not records!\n");
	}
	else
	{
		for (int i = 0; i < getQuantity(list); ++i)
		{
			getElements(list, &outName, &outTelephone);
			printf("%i) Name: ", i + 1);
			fputs(outName, stdout);
			printf(" Telephone: ");
			puts(outTelephone);
		}
	}
}

void findRecord(List* list, bool isSearchByName)
{
	isSearchByName ? printf("Enter the name: ") : printf("Enter the telephone: ");
	char* key = inputString(sizeOfInput);
	char* search = searchElement(list, key, isSearchByName);
	free(key);

	if (search == NULL)
	{
		printf("Not found\n");
	}
	else
	{
		isSearchByName ? printf("The telephone: ") : printf("The name: ");
		puts(search);
	}
}

void saveRecords(List* list, bool* isAnyNewRecords)
{
	FILE* file = fopen("telephone.txt", "w");
	char* writeName = NULL;
	char* writeTelehone = NULL;
	for (int i = 0; i < getQuantity(list); ++i)
	{
		getElements(list, &writeName, &writeTelehone);
		writeToFile(file, writeName, ' ');
		writeToFile(file, writeTelehone, '\n');
	}

	fclose(file);
	*isAnyNewRecords = false;
	printf("Records saved succesful\n");
}



int main()
{
	if (!runListModuleTest())
	{
		printf("List test failed");
		return 1;
	}

	if (!runFileModuleTest())
	{
		printf("File test failed");
		return 2;
	}

	FILE* file = fopen("telephone.txt", "r");
	if (file == NULL)
	{
		file = fopen("telephone.txt", "w");
		if (file == NULL)
		{
			return 3;
		}

		fclose(file);
		file = fopen("telephone.txt", "r");
	}

	List* list = createNewList();
	char* inputName = readFromFile(file);
	char* inputTelephone = readFromFile(file);
	while (inputName != NULL && inputTelephone != NULL)
	{
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
	printf("Max current number of phones is %i\n", size);
	printf("Available options:\n");
	printf("0 - exit\n1 - add a record (name and phone number)\n2 - print all available records\n");
	printf("3 - find a phone by name\n4 - find a name by phone\n5 - save the current data to a file\n");
	char* currentMod = calloc(2, sizeof(char));
	if (currentMod == NULL)
	{
		return 1;
	}

	scanf_s("%s", currentMod, 2);
	bool isAnyNewRecords = false;
	while (currentMod[0] != '0')
	{
		while (currentMod[0] != '1' && currentMod[0] != '2' && currentMod[0] != '3' && currentMod[0] != '4' && currentMod[0] != '5' && currentMod[0] != '0')
		{
			scanf_s("%s", currentMod, 2);
		}

		if (currentMod[0] == '1')
		{
			addARecord(list, &isAnyNewRecords);
		}

		if (currentMod[0] == '2')
		{
			printAllAvailableRecords(list);
		}

		if (currentMod[0] == '3' || currentMod[0] == '4')
		{
			findRecord(list, currentMod[0] == '3');
		}

		if (currentMod[0] == '5')
		{
			saveRecords(list, &isAnyNewRecords);
		}

		printf("Choose option:\n");
		scanf_s("%s", currentMod, 2);
		if (currentMod[0] == '0' && isAnyNewRecords)
		{
			printf("You haven't saved the latest changes. Confirm to continue(Enter: y): \n");
			scanf_s("%s", currentMod, 2);
			if (currentMod[0] == 'y')
			{
				currentMod[0] = '0';
			}
			else
			{
				currentMod[0] = 'a';
				printf("Choose option:\n");
			}
		}
	}
	
	deleteList(list);
	free(currentMod);
	return 0;
}