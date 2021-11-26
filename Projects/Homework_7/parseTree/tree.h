#pragma once

typedef struct ParseTree ParseTree;

// Create Parce Tree from string
// Returns pointer on tree or null if a memory allocation error has occurred
ParseTree* createParceTree(const char* string);

// Puts Parce Tree into string
// Returns execution code:
// 0 - ok; 1 - tree or root or buffer is NULL
int getStringFromParceTree(ParseTree* tree, char* buffer, const int sizeOfBuffer);

// Gives result of Parce Tree
// Returns execution code:
// 0 - ok; 1 - division by zero; 2 - tree or root is NULL
int getResultFromParceTree(ParseTree* tree, int* result);

// Delete Parce Tree
// Returns execution code:
// 0 - ok; 1 - tree or root is NULL
int  deleteParceTree(ParseTree* tree);