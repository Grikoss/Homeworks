#include <stdbool.h>
#include "postCalculator.h"
#include "postCalculatorTest.h"

bool isPostCalculateTestFalse()
{
    int output = 0;
    bool result = postCalculate("5\n5 +", &output) != 0 || output != 10;
    result = result || postCalculate("10 0 /", &output) != 2 || output != 10;
    result = result || postCalculate("          ", &output) != 4 || output != 10;
    result = result || postCalculate("25 25 + +", &output) != 3 || output != 10;
    result = result || postCalculate("-", &output) != 3 || output != 10;
    result = result || postCalculate("9 6 - 1 2 + *              ", &output) != 0 || output != 9;
    result = result || postCalculate("            -500 200 + 3 / -1 *", &output) != 0 || output != 100;
    result = result || postCalculate("fdffd fdfdf *", &output) != 0 || output != 0;
    result = result || postCalculate("10 25 25 +", &output) != 5 || output != 10;
    result = result || postCalculate("55555555", &output) != 0 || output != 55555555;
    return result;
}