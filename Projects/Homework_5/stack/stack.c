#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct Element
{
    int value;
    struct Element* next;
} Element;

typedef struct Stack
{
    Element* head;
} Stack;

Stack* createStack()
{
    return calloc(1, sizeof(Stack));
}

int push(Stack* stack, const int value)
{
    if (stack == NULL)
    {
        return 1;
    }
    Element* element = calloc(1, sizeof(Element));
    if (element == NULL)
    {
        return 2;
    }
    element->value = value;
    element->next = stack->head;
    stack->head = element;
    return 0;
}

bool isEmpty(Stack* stack)
{
    return stack == NULL ? true : stack->head == NULL;
}

int pop(Stack* stack, int* value)
{
    if (isEmpty(stack))
    {
        return 1;
    }
    *value = stack->head->value;
    Element* oldElement = stack->head;
    stack->head = stack->head->next;
    free(oldElement);
    return 0;
}

int deleteStack(Stack* stack)
{
    if (stack == NULL)
    {
        return 1;
    }

    while (!isEmpty(stack))
    {
        Element* oldHead = stack->head;
        stack->head = stack->head->next;
        free(oldHead);
    }
    free(stack);
    return 0;
}