#pragma once

#include <stdbool.h>

typedef struct SearchTree SearchTree;

SearchTree* createSearchTree();

int addDataToSearchTree(SearchTree* tree, const int key, const char* data);

bool isThereKeyInSearchTree(SearchTree* tree, const int key);

int getDataFromSearchTree(SearchTree* tree, const int key, char* buffer, const int size);

int deleteDataFromSearchTree(SearchTree* tree, const int key);

int deleteSearchTree(SearchTree* tree);