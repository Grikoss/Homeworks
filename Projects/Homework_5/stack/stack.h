#pragma once

typedef struct Stack Stack;

// Creates stack, returns pointer to stack
Stack* createStack();

// Creates new element, adds element into stack with value, returns execution code
int push(Stack* stack, const int value);

// Puts value into element, deletes current element, changes head to next, returns execution code
int pop(Stack* stack, int* value);

// Delete all stack
int deleteStack(Stack* stack);