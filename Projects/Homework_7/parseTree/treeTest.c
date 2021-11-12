#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "treeTest.h"

bool isCreateParceTreeBehavesIncorrecty(ParceTree** tree, const char* string)
{
    *tree = createParceTree(string);
    return *tree == NULL;
}

bool isGetStringFromParceTreeBehavesIncorrect(ParceTree* tree, const char* string)
{
    char buffer[100] = { 0 };
    getStringFromParceTree(tree, buffer, 100);
    return strcmp(buffer, string) != 0;
}

bool isParceTreeBehavesIncorrectly()
{
    ParceTree* tree = NULL;
    bool result = isCreateParceTreeBehavesIncorrecty(&tree, "(* (+ 1 1) 2)");
    result = result || isGetStringFromParceTreeBehavesIncorrect(tree, "( * ( + 1 1 ) 2 ) ");
    return result;
}