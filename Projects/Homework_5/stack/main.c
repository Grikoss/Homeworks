#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "stackTest.h"

int main()
{
    if (stackTest())
    {
        return 1;
    }
    Stack* stack = createStack();
    push(stack, '+', 43);
    char bookva;
    int zifra;
    pop(stack, &zifra, &bookva);
    deleteStack(stack);
    printf("%c  %d", zifra, bookva);
    return 0;
}