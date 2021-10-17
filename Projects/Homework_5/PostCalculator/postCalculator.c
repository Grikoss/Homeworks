#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    if (stack == NULL)
    {
        return 1;
    }
    while (fscanf_s(stdin, "%*c") != 0);
    fprintf_s(stdin, "%s", string);
    while (!feof(stdin))
    {
        int value = 0;
        if (fscanf_s(stdin, "%d", &value) != 0)
        {
            push(stack, value);
        }
        char sign = 0;
        if (fscanf_s(stdin, "%c", &sign, 1) != 0 && checkSign(sign))
        {
            int valueOne = 0;
            int valueTwo = 0;
            if (pop(stack, &valueTwo) != 0 || pop(stack, &valueOne) != 0 || (sign == '/' && valueTwo == 0))
            {
                deleteStack(stack);
                while (fscanf_s(stdin, "%*c") != 0);
                return 2;
            }
            push(stack, binaryCalculator(valueOne, valueTwo, sign));
        }
    }
    int output = 0;
    if (pop(stack, result) != 0 || pop(stack, &output) == 0)
    {
        deleteStack(stack);
        return 3;
    }
    deleteStack(stack);
    return 0;
}