#include <stdbool.h>
#include "ABBalanceCheckTest.h"
#include "ABBalanceCheck.h"

bool aABalanceCheckTest()
{
    bool result = !aABalanceCheck("()", 2);
    result = result || !aABalanceCheck("sf", 2);
    result = result || !aABalanceCheck("(gfgf)", 6);
    result = result || aABalanceCheck("([)]", 4);
    result = result || aABalanceCheck("{]", 2);
    result = result || !aABalanceCheck("[(){}[fgfgfggf{}{(dd4545)}][][dfdfd]{}{}(){}[2]]", 48);
    result = result || aABalanceCheck("[(){}[{}}()}][][]{}{}(){}[]]", 28);
    result = result || aABalanceCheck("(", 1);
    result = result || aABalanceCheck("}", 1);
    result = result || aABalanceCheck("{}(", 3);
    result = result || aABalanceCheck("()]", 3);
    result = result || !aABalanceCheck("()]", 0);
    result = result || !aABalanceCheck("( )", 3);
    return result;
}