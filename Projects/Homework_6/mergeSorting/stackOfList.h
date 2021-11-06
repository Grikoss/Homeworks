#pragma once

#include "list.h"

typedef struct Stack Stack;

// Creates stack, returns pointer to stack
Stack* createStack();

// Creates new element, adds element into stack with value, returns execution code, return execution code:
// 0 - ok, 1 - stack is empty, 2 - memory error
int push(Stack* stack, List* value);

// Puts value into element, deletes current element, changes head to next, if stack is empty don't change value, return execution code:
// 0 - ok, 1 - stack is empty
int pop(Stack* stack, List** value);

// Delete all stack, return execution code:
// 0 - ok, 1 - stack is NULL
int deleteStack(Stack* stack);

// Puts value into element, don't delete current element, if stack is empty don't change value, return execution code:
// 0 - ok, 1 - stack is empty
int top(Stack* stack, List** value);
