#include <stdio.h>
#include <stdlib.h>
#include "../stack/stackTest.h"
#include "sortStationTest.h"
#include "sortStation.h"

#define SIZE 100

int main()
{
    if (stackTest())
    {
        return 1;
    }
    if (isSortStationTestBehavesIncorrectly())
    {
        return 2;
    }
    char string[SIZE] = { '\0' };
    printf("Enter string:\n");
    scanf_s("%[^\n]", string, SIZE);
    char* output = NULL;
    int executionCode = sortStation(string, &output);
    switch (executionCode)
    {
    case 0:
        printf_s("%s\n", output);
        free(output);
        break;
    case 4:
        printf("Opening parenthesis is missing\n");
        break;
    case 5:
        printf("Closing parenthesis is missing\n");
        break;
    default:
        printf("Memory error\n");
        break;
    }
    return 0;
}