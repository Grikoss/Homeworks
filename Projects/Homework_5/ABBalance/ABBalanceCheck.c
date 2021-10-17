#include <stdlib.h>
#include <stdbool.h>
#include "../stack/stack.h"
#include "ABBalanceCheck.h"

bool bracketCheck(char openBracket, char closeBracket)
{
    switch (openBracket)
    {
    case '[':
        return closeBracket == ']';
    case '{':
        return closeBracket == '}';
    case '(':
        return closeBracket == ')';
    default:
        return false;
    }
}

bool aABalanceCheck(const char* string, int length)
{
    Stack* stack = createStack();
    for (int i = 0; i < length; ++i)
    {
        int bracket = 'a';
        switch (string[i])
        {
        case '[':
        case '{':
        case '(':
            push(stack, string[i]);
            break;
        case ']':
        case '}':
        case ')':
            pop(stack, &bracket);
            if (!bracketCheck(bracket, string[i]))
            {
                deleteStack(stack);
                return false;
            }
            break;
        default:
            break;
        }
    }

    int bufferOne = 1;
    bool result = pop(stack, &bufferOne) != 0;
    deleteStack(stack);
    return result;
}