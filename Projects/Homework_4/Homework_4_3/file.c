#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "file.h"

const int sizeBuffer = 31;

char* readFromFile(FILE* file)
{
	if (file == NULL)
	{
		return NULL;
	}

	if (feof(file))
	{
		return NULL;
	}

	char* buffer = calloc(sizeBuffer, sizeof(char));
	if (buffer == NULL)
	{
		return NULL;
	}

	if (fscanf_s(file, "%s", buffer, sizeBuffer) > 0)
	{
		return buffer;
	}
	else
	{
		free(buffer);
		return NULL;
	}
}

int writeToFile(FILE* file, char* input, char literal)
{
	if (file == NULL || input == NULL)
	{
		return 1;
	}

	fprintf(file, input);
	literal == '\n' ? fprintf(file, "\n") : 0;
	literal == ' ' ? fprintf(file, " ") : 0;

	return 0;
}