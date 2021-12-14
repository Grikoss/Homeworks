#include "hashFunction.h"

int getKey(const char* string)
{
    int index = 0;
    int result = 0;
    int prime = 401;
    while (string[index] != '\0')
    {
        result = (result + string[index]) * prime;
        ++index;
    }
    return result;
}