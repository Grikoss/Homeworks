#pragma once

typedef struct Stack Stack;

// Creates stack, returns pointer to stack
Stack* createStack();

// Creates new element, adds element into stack with value and dataType, returns execution code
int push(Stack* stack, unsigned char value, unsigned char dataType);

// Puts values into value and dataType, deletes current element, changes head to next, returns execution code
int pop(Stack* stack, unsigned char* value, unsigned char* dataType);

// Delete all stack
int deleteStack(Stack* stack);