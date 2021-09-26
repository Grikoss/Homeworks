#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "file.h"
#include "fileModuleTest.h"


bool runFileModuleTest() {
	FILE* file = fopen("telephoneTest.txt", "w");
	char name[] = "name";
	char telephone[] = "telephone";
	if (writeToFile(NULL, name, ' ') != 1 || writeToFile(file, NULL, ' ') != 1) {
		fclose(file);
		return false;
	}

	writeToFile(file, name, ' ');
	writeToFile(file, telephone, '\n');
	fclose(file);

	if (readFromFile(NULL) != NULL) {
		fclose(file);
		return false;
	}

	file = fopen("telephoneTest.txt", "r");
	char* outName = NULL;
	char* outTelephone = NULL;
	outName = readFromFile(file);
	outTelephone = readFromFile(file);
	if (strcmp(outName, name) != 0 || strcmp(outTelephone, telephone) != 0) {
		fclose(file);
		return false;
	}

	free(outName);
	free(outTelephone);
	
	if (readFromFile(file) != NULL) {
		fclose(file);
		return false;
	}

	fclose(file);
	return true;
}