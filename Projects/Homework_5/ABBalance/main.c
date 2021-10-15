#include "../stack/stackTest.h"
#include "ABBalanceCheckTest.h"
#include "ABBalanceCheck.h"

int main()
{
    if (stackTest())
    {
        return 1;
    }

    if (AABalanceCheckTest())
    {
        return 2;
    }

    return 0;
}