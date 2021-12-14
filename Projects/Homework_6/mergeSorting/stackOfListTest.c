#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "stackOfListTest.h"
#include "stackOfList.h"

bool createStackTest(Stack* stack)
{
    return stack == NULL;
}

bool pushTest(Stack* stack)
{
    return push(NULL, 0) != 1 || push(stack, NULL) != 0;
}

bool popTest(Stack* stack)
{
    List* output = NULL;
    bool result = pop(stack, &output) != 0;
    result = result || output != NULL;
    result = result || pop(NULL, &output) != 1;
    return result || pop(stack, &output) != 1;
}

bool deleteStackTest(Stack* stack)
{
    bool result = deleteStack(NULL) != 1;
    return result || deleteStack(stack) != 0;
}

bool topTest(Stack* stack)
{
    List* output = NULL;
    bool result = top(stack, &output) != 0;
    result = result || output != NULL;
    return result = result || top(NULL, &output) != 1;
}

bool isStackBehavesIncorrectly(void)
{
    Stack* stack = createStack();
    bool result = createStackTest(stack);
    result = result || pushTest(stack);
    result = result || topTest(stack);
    result = result || popTest(stack);
    return result || deleteStackTest(stack);
}