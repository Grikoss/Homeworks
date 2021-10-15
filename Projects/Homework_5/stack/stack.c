#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct Element
{
    unsigned char value;
    unsigned char dataType; // to interpret data
    struct Element* next;
}Element;

typedef struct Stack
{
    Element* head;
}Stack;

Stack* createStack()
{
    Stack* stack = calloc(1, sizeof(Stack));
    return stack;
}

int push(Stack* stack, unsigned char value, unsigned char dataType)
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
    element->dataType = dataType;
    element->next = stack->head;
    stack->head = element;
}

bool isEnd(Stack* stack)
{
    return stack->head == NULL;
}

int pop(Stack* stack, unsigned char* value, unsigned char* dataType)
{
    if (stack == NULL)
    {
        return 1;
    }
    if (isEnd(stack))
    {
        return 2;
    }
    *value = stack->head->value;
    *dataType = stack->head->dataType;
    Element* oldElement = stack->head;
    stack->head = stack->head->next;
    free(oldElement);
    return 0;
}