#include "listTest.h"
#include "hashFunctionTest.h"
#include "hashTableTest.h"

int main(void)
{
    if (isListBehavesIncorrectly())
    {
        return 1;
    }
    if (isHashFunctionBehavesIncorrectly())
    {
        return 2;
    }
    if (isHashTableBehavesIncorrectly())
    {
        return 3;
    }
    return 0;
}