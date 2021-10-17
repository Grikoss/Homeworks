#include "../stack/stackTest.h"
#include "postCalculator.h"
#include "postCalculatorTest.h"

int main()
{
    if (stackTest())
    {
        return 1;
    }
    if (postCalculatorTest())
    {
        return 2;
    }
    return 0;
}