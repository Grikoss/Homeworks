#include <string.h>
#include <stdlib.h>
#include "kmp.h"

int getPositionOfFirstOccurrence(const char* substring, const char* string)
{
    if (substring == NULL || string == NULL)
    {
        return -1;
    }
    const int subLength = strlen(substring);
    const int length = strlen(string);
    if (subLength <= 0 || length <= 0)
    {
        return -2;
    }
    if (subLength > length)
    {
        return -3;
    }
    const int size = length + subLength + 2;
    char* buffer = calloc(size, sizeof(char));
    if (buffer == NULL)
    {
        return -4;
    }
    strcpy_s(buffer, size, substring);
    strcat_s(buffer, size, string);
    int* postPrefixArray = calloc(size, sizeof(int));
    if (postPrefixArray == NULL)
    {
        free(buffer);
        return -5;
    }
    for (int i = 1; i < size; ++i)
    {
        int j = postPrefixArray[i - 1];
        while (j > 0 && buffer[i] != buffer[j])
        {
            j = postPrefixArray[j - 1];
        }
        if (buffer[i] == buffer[j])
        {
            ++j;
        }
        if (i == subLength)
        {
            postPrefixArray[i] = (buffer[i] == buffer[0]) ? 1 : 0;
            if (subLength > 1)
            {
                continue;
            }
        }
        if (j == subLength)
        {
            free(buffer);
            free(postPrefixArray);
            return i - subLength;
        }
        postPrefixArray[i] = j;
    }
    free(buffer);
    free(postPrefixArray);
    return -6;
}