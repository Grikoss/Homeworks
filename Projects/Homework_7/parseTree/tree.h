#pragma once

typedef struct ParceTree ParceTree;

ParceTree* createParceTree(const char* string);

int getStringFromParceTree(ParceTree* tree, char* buffer, const int sizeOfBuffer);

int getResultFromParceTree(ParceTree* tree, int* result);

void  deleteParceTree(ParceTree* tree);