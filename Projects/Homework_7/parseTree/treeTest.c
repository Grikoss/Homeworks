#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "treeTest.h"

bool isCreateParseTreeBehavesIncorrectly(ParseTree** tree, const char* string)
{
    *tree = createParseTree(string);
    return *tree == NULL;
}

bool isGetStringFromParseTreeBehavesIncorrectly(ParseTree* tree, const char* string)
{
    char buffer[100] = { 0 };
    getStringFromParseTree(tree, buffer, 100);
    return strcmp(buffer, string) != 0;
}

bool isGetResultFromParseTreeBehavesIncorrectly(ParseTree* tree, const int result, const int executionCode)
{
    int subResult = 0;
    return getResultFromParseTree(tree, &subResult) != executionCode || subResult != result;
}

bool isDeleteParseTreeBehavesIncorrectly(ParseTree* tree)
{
    return deleteParseTree(tree) != 0;
}

bool checkOnNull()
{
    int buffer = 0;
    return deleteParseTree(NULL) != 1 || getResultFromParseTree(NULL, &buffer) != 2 || getStringFromParseTree(NULL, NULL, 0) != 1;
}

bool isParseTreeBehavesIncorrectly()
{
    ParseTree* tree = NULL;
    bool result = isCreateParseTreeBehavesIncorrectly(&tree, "(* (+ 1 1) 2)");
    result = result || isGetStringFromParseTreeBehavesIncorrectly(tree, "( * ( + 1 1 ) 2 ) ");
    result = result || isGetResultFromParseTreeBehavesIncorrectly(tree, 4, 0);
    result = result || isDeleteParseTreeBehavesIncorrectly(tree);
    result = result || isCreateParseTreeBehavesIncorrectly(&tree, "- -50 -50");
    result = result || isGetStringFromParseTreeBehavesIncorrectly(tree, "( - -50 -50 ) ");
    result = result || isGetResultFromParseTreeBehavesIncorrectly(tree, 0, 0);
    result = result || isDeleteParseTreeBehavesIncorrectly(tree);
    result = result || isCreateParseTreeBehavesIncorrectly(&tree, "(* (+ 100 100) 2)");
    result = result || isGetStringFromParseTreeBehavesIncorrectly(tree, "( * ( + 100 100 ) 2 ) ");
    result = result || isGetResultFromParseTreeBehavesIncorrectly(tree, 400, 0);
    result = result || isDeleteParseTreeBehavesIncorrectly(tree);
    result = result || isCreateParseTreeBehavesIncorrectly(&tree, "(/ (+ 100 100) 0)");
    result = result || isGetStringFromParseTreeBehavesIncorrectly(tree, "( / ( + 100 100 ) 0 ) ");
    result = result || isGetResultFromParseTreeBehavesIncorrectly(tree, 0, 1);
    result = result || isDeleteParseTreeBehavesIncorrectly(tree);
    result = result || isCreateParseTreeBehavesIncorrectly(&tree, "(+ (/ 100 0) 0)");
    result = result || isGetStringFromParseTreeBehavesIncorrectly(tree, "( + ( / 100 0 ) 0 ) ");
    result = result || isGetResultFromParseTreeBehavesIncorrectly(tree, 0, 1);
    result = result || isDeleteParseTreeBehavesIncorrectly(tree);
    result = result || checkOnNull();
    return result;
}