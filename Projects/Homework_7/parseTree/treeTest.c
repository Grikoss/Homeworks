#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "treeTest.h"

bool isCreateParceTreeBehavesIncorrectly(ParceTree** tree, const char* string)
{
    *tree = createParceTree(string);
    return *tree == NULL;
}

bool isGetStringFromParceTreeBehavesIncorrectly(ParceTree* tree, const char* string)
{
    char buffer[100] = { 0 };
    getStringFromParceTree(tree, buffer, 100);
    return strcmp(buffer, string) != 0;
}

bool isGetResultFromParceTreeBehavesIncorrectly(ParceTree* tree, const int result, const int executionCode)
{
    int subResult = 0;
    return getResultFromParceTree(tree, &subResult) != executionCode || subResult != result;
}

bool isParceTreeBehavesIncorrectly()
{
    ParceTree* tree = NULL;
    bool result = isCreateParceTreeBehavesIncorrectly(&tree, "(* (+ 1 1) 2)");
    result = result || isGetStringFromParceTreeBehavesIncorrectly(tree, "( * ( + 1 1 ) 2 ) ");
    result = result || isGetResultFromParceTreeBehavesIncorrectly(tree, 4, 0);
    deleteParceTree(tree);
    return result;
}