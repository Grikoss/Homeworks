#include <stdbool.h>
#include "ABBalanceCheckTest.h"
#include "ABBalanceCheck.h"

bool aABalanceCheckTest()
{
    bool result = aABalanceCheck("()", 2) != true;
    result = result || aABalanceCheck("sf", 2) != true;
    result = result || aABalanceCheck("(gfgf)", 6) != true;
    result = result || aABalanceCheck("([)]", 4) != false;
    result = result || aABalanceCheck("{]", 2) != false;
    result = result || aABalanceCheck("[(){}[fgfgfggf{}{(dd4545)}][][dfdfd]{}{}(){}[2]]", 48) != true;
    result = result || aABalanceCheck("[(){}[{}}()}][][]{}{}(){}[]]", 28) != false;
    result = result || aABalanceCheck("(", 1) != false;
    result = result || aABalanceCheck("}", 1) != false;
    result = result || aABalanceCheck("{}(", 3) != false;
    result = result || aABalanceCheck("()]", 3) != false;
    result = result || aABalanceCheck("()]", 0) != true;
    result = result || aABalanceCheck("( )", 3) != true;
    return result;
}