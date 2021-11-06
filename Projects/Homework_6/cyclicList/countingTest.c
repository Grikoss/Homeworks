#include <stdbool.h>
#include "countingTest.h"
#include "counting.h"

bool isGetNumberofTheLastRemainingBehavesIncorrectly()
{
    bool result = 5 != getNumberofTheLastRemaining(5, 0);
    result = result || 5 != getNumberofTheLastRemaining(5, 1);
    result = result || 0 != getNumberofTheLastRemaining(0, 5);
    return result || 1 != getNumberofTheLastRemaining(9, 3);
}