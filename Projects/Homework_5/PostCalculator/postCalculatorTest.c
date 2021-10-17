#include <stdbool.h>
#include "postCalculator.h"
#include "postCalculatorTest.h"

bool postCalculatorTest()
{
    int output = 0;
    bool result = postCalculator("5\n5 +", 6, &output) != 0 || output != 10;
    result = result || postCalculator("10 10 -", 0, &output) != 3 || output != 10;
    result = result || postCalculator("10 0 /", 7, &output) != 2 || output != 10;
    result = result || postCalculator("          ", 11, &output) != 3 || output != 10;
    result = result || postCalculator("25 25 + +", 10, &output) != 2 || output != 10;
    result = result || postCalculator("-", 2, &output) != 2 || output != 10;
    result = result || postCalculator("9 6 - 1 2 + *              ", 28, &output) != 0 || output != 9;
    result = result || postCalculator("            -500 200 + 3 / -1 *", 32, &output) != 0 || output != 100;
    result = result || postCalculator("fdffd fdfdf *", 14, &output) != 0 || output != 0;
    result = result || postCalculator("10 25 25 +", 14, &output) != 3 || output != 10;
    result = result || postCalculator("55555555", 9, &output) != 0 || output != 55555555;
    return result;
}