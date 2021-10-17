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
    return push(NULL, 0) != 1 || push(stack, '+') != 0;
}

bool popTest(Stack* stack)
{
    int output = 1;
    bool result = pop(stack, &output) != 0;
    result = result || output != '+';
    result = result || pop(NULL, &output) != 1;
    return result || pop(stack, &output) != 1;
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