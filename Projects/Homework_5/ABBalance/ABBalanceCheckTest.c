#include <stdbool.h>
#include "ABBalanceCheckTest.h"
#include "ABBalanceCheck.h"

bool AABalanceCheckTest()
{
    bool result = AABalanceCheck("()", 2) != true;
    result = result || AABalanceCheck("sf", 2) != true;
    result = result || AABalanceCheck("(gfgf)", 6) != true;
    result = result || AABalanceCheck("([)]", 4) != false;
    result = result || AABalanceCheck("{]", 2) != false;
    result = result || AABalanceCheck("[(){}[fgfgfggf{}{(dd4545)}][][dfdfd]{}{}(){}[2]]", 48) != true;
    result = result || AABalanceCheck("[(){}[{}}()}][][]{}{}(){}[]]", 28) != false;
    result = result || AABalanceCheck("(", 1) != false;
    result = result || AABalanceCheck("}", 1) != false;
    result = result || AABalanceCheck("{}(", 3) != false;
    result = result || AABalanceCheck("()]", 3) != false;
    return result;
}