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
        return 4;
    case '-':
        return 5;
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
        return 6;
    default:
        return 0;
    }
}

int sortStation(char* string, const int length)
{
    if (string == NULL)
    {
        return 1;
    }
    int index = 0;
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
        while (checkSign(string[i]) == 0 && i < length && string[i] != '\0')
        {
            ++i;
        }
        if (i >= length || string[i] == '\0')
        {
            break;
        }
        switch (checkSign(string[i]))
        {
        case 5: // minus
            if (i + 1 == length || checkSign(string[i+1]) != 6) // minus as sign
            {
                char sign = 'a'
                while (pop))
                {

                }
                break;
            }
            outString[index] = string[i]; // minus as part of number
            ++i;
            ++index;
        default:  // record numbers
            while (checkSign(string[i]) == 6 && i < length)
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
}