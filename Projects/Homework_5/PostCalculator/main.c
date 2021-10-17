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
    if (postCalculatorTest())
    {
        return 2;
    }

    char string[SIZE] = { '\0' };
    printf("Enter string:\n");
    scanf_s("%[^\n]", string, SIZE);
    int executionCode = 0;
    int value = 0;
    executionCode = postCalculator(string, SIZE, &value);
    switch (executionCode)
    {
    case 1:
        printf("Failed to initialize memory\n");
        break;
    case 2:
        printf("Too many operators or division by zero\n");
        break;
    case 3:
        printf("Too many numbers or string is empty\n");
        break;
    default:
        printf("Result = %d\n", value);
        break;
    }
    return 0;
}