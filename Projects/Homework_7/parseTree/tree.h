#pragma once

typedef struct ParseTree ParseTree;

// Create Parse Tree from string
// Returns pointer on tree or null if a memory allocation error has occurred
ParseTree* createParseTree(const char* string);

// Puts Parse Tree into string
// Returns execution code:
// 0 - ok; 1 - tree or root or buffer is NULL
int getStringFromParseTree(ParseTree* tree, char* buffer, const int sizeOfBuffer);

// Gives result of Parse Tree
// Returns execution code:
// 0 - ok; 1 - division by zero; 2 - tree or root is NULL
int getResultFromParseTree(ParseTree* tree, int* result);

// Delete Parse Tree
// Returns execution code:
// 0 - ok; 1 - tree or root is NULL
int  deleteParseTree(ParseTree* tree);