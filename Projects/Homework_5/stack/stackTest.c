#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
#include "stackTest.h"

bool createStackTest(Stack* stack)
{
    return stack == NULL;
}

bool pushTest(Stack* stack)
{
    return push(NULL, 'a', 'b') != 1 || push(stack, 'a', 'b') != 0;
}

bool popTest(Stack* stack)
{
    char outputOne = 'c';
    char outputTwo = 'c';
    bool result = pop(stack, &outputOne, &outputTwo) != 0;
    result = result || outputOne != 'a' || outputTwo != 'b';
    result = result || pop(NULL, &outputOne, &outputTwo) != 1;
    return result || pop(stack, &outputOne, &outputTwo) != 2;
}

bool deleteStackTest(Stack* stack)
{
    bool result = deleteStack(NULL) != 1;
    return result || deleteStack(stack) != 0;
}

bool stackTest()
{
    Stack* stack = createStack();
    bool result = createStackTest(stack);
    result = result || pushTest(stack);
    result = result || popTest(stack);
    return result || deleteStackTest(stack);
}