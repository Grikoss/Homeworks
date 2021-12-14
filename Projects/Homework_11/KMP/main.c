#include <stdio.h>
#include <stdlib.h>
#include "kmp.h"
#include "kmpTest.h"

#define SIZE 100
#define SIZE_OF_FILE 10000

int main(int argc, char* argv[])
{
    if (isKMPBehavesIncorrectly())
    {
        return 1;
    }
    if (argc > 1)
    {
        return 0;
    }
    FILE* file = NULL;
    fopen_s(&file, "input.txt", "r");
    if (file == NULL)
    {
        return 1;
    };
    char* input = calloc(SIZE_OF_FILE, sizeof(char));
    int index = 0;
    while (!feof(file))
    {
        fscanf_s(file, "%c", &input[index], SIZE_OF_FILE);
        ++index;
    }
    fclose(file);
    char string[SIZE] = { 0 };
    printf_s("Enter subString:\n");
    scanf_s("%[^\n]", string, SIZE);
    const int position = getPositionOfFirstOccurrence(string, input);
    free(input);
    if (position < 0)
    {
        printf_s("There are no occurrences\n");
    }
    else
    {
        printf_s("The position of the first occurrence is %d\n", position);
    }
}