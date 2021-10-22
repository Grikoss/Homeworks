#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../stack/stack.h"
#include "sortStation.h"

int checkSign(const char sign)
{
    switch (sign)
    {
    case '(':
        return 1;
    case ')':
        return 2;
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 4;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 5;
    default:
        return 0;
    }
}

int watchStack(Stack* stack, int* sign)
{
    int number = 0;
    if (pop(stack, &number) == 0)
    {
        push(stack, number);
        *sign = number;
        return 0;
    }
    return 1;
}

int sortStation(char* string)
{
    if (string == NULL)
    {
        return 1;
    }
    int index = 0;
    const int length = strlen(string);
    char* outString = calloc(length, sizeof(char));
    if (outString == NULL)
    {
        return 2;
    }
    Stack* stack = createStack();
    if (stack == NULL)
    {
        free(outString);
        return 3;
    }
    for (int i = 0; i < length; i)
    {
        while (checkSign(string[i]) == 0 && i < length)
        {
            ++i;
        }
        if (i >= length)
        {
            break;
        }
        switch (checkSign(string[i]))
        {
        case 1:
            push(stack, string[i]);
            ++i;
            break;
        case 2:
        {
            int sign = 0;
            while (watchStack(stack, &sign) == 0 && checkSign(sign) != 1)
            {
                pop(stack, &sign);
                outString[index] = sign;
                ++index;
                outString[index] = ' ';
                ++index;
            }
            if (watchStack(stack, &sign) == 1)
            {
                free(outString);
                deleteStack(stack);
                return 4;
            }
            pop(stack, &sign);
            break;
        }
        case 3: // division and multiplication
        case 4: // minus and plus
            if (i + 1 == length || string[i] != '-' || checkSign(string[i + 1]) != 5) // as sign
            {
                int sign = 0;
                while (watchStack(stack, &sign) == 0 && (checkSign(string[i]) == 3 ? checkSign(sign) == 3 : (checkSign(sign) == 4 || checkSign(sign) == 3)))
                {
                    pop(stack, &sign);
                    outString[index] = sign;
                    ++index;
                    outString[index] = ' ';
                    ++index;
                }
                push(stack, string[i]);
                ++i;
                break;
            }
            outString[index] = string[i]; // minus as part of number
            ++i;
            ++index;
        default:  // record numbers
            while (checkSign(string[i]) == 5 && i < length)
            {
                outString[index] = string[i];
                ++i;
                ++index;
            }
            outString[index] = ' ';
            ++index;
            break;
        }
    }
    int sign = 0;
    while (pop(stack, &sign) == 0)
    {
        if (checkSign(sign) == 1)
        {
            free(outString);
            deleteStack(stack);
            return 4;
        }
        outString[index] = sign;
        ++index;
        outString[index] = ' ';
        ++index;
    }
    strcpy_s(string, length, outString);
    free(outString);
    deleteStack(stack);
    return 0;
}