#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../stack/stack.h"
#include "sortStation.h"

int checkSign(const char sign)
{
    if ('0' <= sign && sign <= '9')
    {
        return 5;
    }
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
    default:
        return 0;
    }
}

void writeCharacter(char* string, char sign, int* index)
{
    string[*index] = sign;
    ++*index;
    string[*index] = ' ';
    ++*index;
}

void writeSign(Stack* stack, char* outString, char inputSing, int* index, int priority)
{
    int sign = 0;
    if (priority == 0)
    {
        while (top(stack, &sign) == 0 && checkSign(sign) == 3)
        {
            pop(stack, &sign);
            writeCharacter(outString, sign, index);
        }
    }
    else
    {
        while (top(stack, &sign) == 0 && (checkSign(sign) == 4 || checkSign(sign) == 3))
        {
            pop(stack, &sign);
            writeCharacter(outString, sign, index);
        }
    }
    push(stack, inputSing);
}

int sortStation(const char* string, char** output)
{
    if (string == NULL)
    {
        return 1;
    }
    int index = 0;
    const int length = strlen(string);
    char* outString = calloc(length * 2 + 1, sizeof(char));
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
            while (top(stack, &sign) == 0 && checkSign(sign) != 1)
            {
                pop(stack, &sign);
                writeCharacter(outString, sign, &index);
            }
            if (top(stack, &sign) == 1)
            {
                free(outString);
                deleteStack(stack);
                return 4;
            }
            pop(stack, &sign);
            ++i;
            break;
        }
        case 3: // division and multiplication
            writeSign(stack, outString, string[i], &index, 0);
            ++i;
            break;
        case 4: // minus and plus
            if (i + 1 == length || string[i] != '-' || checkSign(string[i + 1]) != 5) // as sign
            {
                writeSign(stack, outString, string[i], &index, 1);
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
            return 5;
        }
        writeCharacter(outString, sign, &index);
    }
    outString[index] = '\0';
    deleteStack(stack);
    *output = outString;
    return 0;
}