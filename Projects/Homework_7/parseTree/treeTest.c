#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"
#include "treeTest.h"

bool isCreateParceTreeBehavesIncorrecty(ParceTree** tree, const char* string)
{
    *tree = createParceTree(string);
    return *tree == NULL;
}

bool isParceTreeBehavesIncorrectly()
{
    ParceTree* tree = NULL;
    bool result = isCreateParceTreeBehavesIncorrecty(&tree, "(* (+ 1 1) 2)");
    return result;
}