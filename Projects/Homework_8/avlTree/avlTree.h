#pragma once

#include <stdbool.h>

typedef struct SearchTree SearchTree;

// Returns empty Search Tree;
SearchTree* createSearchTree();

// Adds data to search tree
// Returns execution code:
// 0 - ok; 1 - SearchTree is NULL; 2 - memory allocation error
int addDataToSearchTree(SearchTree* tree, const char* key, const char* data);

// If tree is NULL returns false
bool isThereKeyInSearchTree(SearchTree* tree, const char* key);

// Gives stirng by key
// Returns execution code:
// 0 - ok; 1 - SearchTree or root is NULL; 2 - there is not the key; 3 - WTF I DON'T KNOW HOW YOU GOT THIS
int getDataFromSearchTree(SearchTree* tree, const char* key, char* buffer, const int size);

// Deletes data from tree
// Returns execution code:
//0 - ok; 1 - tree or root is NULL; 2 - there is not key; 3 - GOD DAMNED YOU DID IT AGAIN
int deleteDataFromSearchTree(SearchTree* tree, const char* key);

// Gives number of nodes
// Return 0 if tree is NULL or empty;
int getNumbersOfNodes(SearchTree* tree);

// Gives height of tree
// Return 0 if tree is NULL or empty;
int getHeight(SearchTree* tree);

// Delete tree
// Returns execution code:
//0 - ok; 1 - tree is NULL
int deleteSearchTree(SearchTree* tree);

