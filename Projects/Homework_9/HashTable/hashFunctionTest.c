#include <stdbool.h>
#include "hashFunction.h"
#include "hashFunctionTest.h"

bool isHashFunctionBehavesIncorrectly(void)
{
    char stringOne[] = "arbuser";
    char stringTwo[] = "abuser";
    return getKey(stringOne) != getKey(stringOne) || getKey(stringOne) == getKey(stringTwo);
}