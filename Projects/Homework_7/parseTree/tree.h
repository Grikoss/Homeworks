#pragma once

typedef struct ParceTree ParceTree;

// Create Parce Tree from string
// Returns pointer on tree or null if a memory allocation error has occurred
ParceTree* createParceTree(const char* string);

// Puts Parce Tree into string
// Returns execution code:
// 0 - ok; 1 - tree or root or buffer is NULL
int getStringFromParceTree(ParceTree* tree, char* buffer, const int sizeOfBuffer);

// Givs result of Parce Tree
// Returns execution code:
// 0 - ok; 1 - division by zero; 2 - tree or root is NULL
int getResultFromParceTree(ParceTree* tree, int* result);

// Delete Parce Tree
// Returns execution code:
// 0 - ok; 1 - tree or root is NULL
int  deleteParceTree(ParceTree* tree);