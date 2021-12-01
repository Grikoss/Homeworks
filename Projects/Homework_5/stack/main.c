#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "stackTest.h"

int main(int argc, char* argv[])
{
    if (stackTest())
    {
        return 1;
    }
    return 0;
}