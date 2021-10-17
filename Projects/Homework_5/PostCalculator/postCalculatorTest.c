#include <stdbool.h>
#include "postCalculator.h"
#include "postCalculatorTest.h"

bool postCalculatorTest()
{
    int output = 0;
    bool result = postCalculator("5\n5 +", 5, &output) != 0 || output != 10;
    return result;
}