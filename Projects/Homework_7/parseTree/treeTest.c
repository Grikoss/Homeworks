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

bool isDeleteParceTreeBehavesIncorrectly(ParceTree* tree)
{
    return deleteParceTree(tree) != 0;
}

bool checkOnNull()
{
    int buffer = 0;
    return deleteParceTree(NULL) != 1 || getResultFromParceTree(NULL, &buffer) != 2 || getStringFromParceTree(NULL, NULL, 0) != 1;
}

bool isParceTreeBehavesIncorrectly()
{
    ParceTree* tree = NULL;
    bool result = isCreateParceTreeBehavesIncorrectly(&tree, "(* (+ 1 1) 2)");
    result = result || isGetStringFromParceTreeBehavesIncorrectly(tree, "( * ( + 1 1 ) 2 ) ");
    result = result || isGetResultFromParceTreeBehavesIncorrectly(tree, 4, 0);
    result = result || isDeleteParceTreeBehavesIncorrectly(tree);
    result = result || isCreateParceTreeBehavesIncorrectly(&tree, "- -50 -50");
    result = result || isGetStringFromParceTreeBehavesIncorrectly(tree, "( - -50 -50 ) ");
    result = result || isGetResultFromParceTreeBehavesIncorrectly(tree, 0, 0);
    result = result || isDeleteParceTreeBehavesIncorrectly(tree);
    result = result || isCreateParceTreeBehavesIncorrectly(&tree, "(* (+ 100 100) 2)");
    result = result || isGetStringFromParceTreeBehavesIncorrectly(tree, "( * ( + 100 100 ) 2 ) ");
    result = result || isGetResultFromParceTreeBehavesIncorrectly(tree, 400, 0);
    result = result || isDeleteParceTreeBehavesIncorrectly(tree);
    result = result || isCreateParceTreeBehavesIncorrectly(&tree, "(/ (+ 100 100) 0)");
    result = result || isGetStringFromParceTreeBehavesIncorrectly(tree, "( / ( + 100 100 ) 0 ) ");
    result = result || isGetResultFromParceTreeBehavesIncorrectly(tree, 0, 1);
    result = result || isDeleteParceTreeBehavesIncorrectly(tree);
    result = result || isCreateParceTreeBehavesIncorrectly(&tree, "(+ (/ 100 0) 0)");
    result = result || isGetStringFromParceTreeBehavesIncorrectly(tree, "( + ( / 100 0 ) 0 ) ");
    result = result || isGetResultFromParceTreeBehavesIncorrectly(tree, 0, 1);
    result = result || isDeleteParceTreeBehavesIncorrectly(tree);
    result = result || checkOnNull();
    return result;
}