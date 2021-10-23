#include <stdio.h>
#include "../stack/stackTest.h"
#include "postCalculator.h"
#include "postCalculatorTest.h"

#define SIZE 100

int main()
{
    if (stackTest())
    {
        return 1;
    }
    if (isPostCalculateBehavesIncorrectly())
    {
        return 2;
    }
    char string[SIZE] = { '\0' };
    printf("Enter string:\n");
    scanf_s("%[^\n]", string, SIZE);
    int value = 0;
    int executionCode = postCalculate(string, &value);
    switch (executionCode)
    {
    case 1:
        printf("Failed to initialize memory\n");
        break;
    case 2:
        printf("Division by zero\n");
        break;
    case 3:
        printf("Too many operators\n");
        break;
    case 4:
        printf("String is empty\n");
        break;
    case 5:
        printf("Too many numbers\n");
        break;
    default:
        printf("Result = %d\n", value);
        break;
    }
    return 0;
}