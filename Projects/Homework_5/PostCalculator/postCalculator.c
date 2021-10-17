#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "postCalculator.h"
#include "../stack/stack.h"

// True if sign correct
bool checkSign(char sign)
{
    return sign == '+' || sign == '-' || sign == '*' || sign == '/';
}

// Return result (valueOne 'sign' valueTwo)
int binaryCalculator(int valueOne, int valueTwo, char sign)
{
    switch (sign)
    {
    case '+':
        return valueOne + valueTwo;
    case '-':
        return valueOne - valueTwo;
    case '*':
        return valueOne * valueTwo;
    case '/':
        return valueOne / valueTwo;
    default:
        return 0;
    }
}

int postCalculator(const char* string, const int length, int* result)
{
    Stack* stack = createStack();
    for (int i = 0; i < length; ++i)
    {
        while (i < length && (string[i] == ' ' || string[i] == '\n' || string[i] == '\0'))
        {
            ++i;
        }
        if (i >= length || string[i] == '\0')
        {
            break;
        }
        char* buffer = calloc(length, sizeof(char));
        if (buffer == NULL)
        {
            deleteStack(stack);
            return 1;
        }
        int index = 0;
        while (i < length && string[i] != ' ' && string[i] != '\n' && string[i] != '\0')
        {
            buffer[index] = string[i];
            ++i;
            ++index;
        }
        if (checkSign(buffer[0]) && index <= 1)
        {
            int valueOne = 0;
            int valueTwo = 0;
            if (pop(stack, &valueTwo) != 0 || pop(stack, &valueOne) != 0 || (buffer[0] == '/' && valueTwo == 0))
            {
                free(buffer);
                deleteStack(stack);
                return 2;
            }
            push(stack, binaryCalculator(valueOne, valueTwo, buffer[0]));
            free(buffer);
        }
        else
        {
            push(stack, atoi(buffer));
            free(buffer);
        }
    }

    int executionCode = 0;
    if (pop(stack, result) != 0 || pop(stack, result) == 0)
    {
        executionCode = 3;
    }

    deleteStack(stack);
    return executionCode;
}