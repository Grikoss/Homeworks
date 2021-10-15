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

bool AABalanceCheck(const char* string, int length)
{
    Stack* stack = createStack();
    for (int i = 0; i < length; ++i)
    {
        char bracket = 'a';
        int datatype = 0;
        switch (string[i])
        {
        case '[':
        case '{':
        case '(':
            push(stack, string[i], 0);
            break;
        case ']':
        case '}':
        case ')':
            pop(stack, &bracket, &datatype);
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
    int bufferTwo = 1;
    bool result = pop(stack, &bufferOne, &bufferTwo) != 0;
    deleteStack(stack);
    return result;
}