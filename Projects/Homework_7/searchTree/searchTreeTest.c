#include <stdbool.h>
#include <stdlib.h>
#include "searchTreeTest.h"
#include "searchTree.h"

bool isCreateSearchTreeBehavesIncorrectly(SearchTree** tree)
{
    *tree = createSearchTree();
    return *tree == NULL;
}

bool isAddDataToSearchTreeBehavesIncorrect(SearchTree* tree)
{
    bool result = addDataToSearchTree(NULL, 0, NULL) != 1;
    result = result || addDataToSearchTree(tree, 3, "3") != 0;
    result = result || addDataToSearchTree(tree, 5, "5") != 0;
    result = result || addDataToSearchTree(tree, 1, "1") != 0;
    result = result || addDataToSearchTree(tree, 6, "6") != 0;
    result = result || addDataToSearchTree(tree, 0, "0") != 0;
    result = result || addDataToSearchTree(tree, 4, "4") != 0;
    result = result || addDataToSearchTree(tree, 2, "10") != 0;
    result = result || addDataToSearchTree(tree, 7, "7") != 0;
    result = result || addDataToSearchTree(tree, -1, "-1") != 0;
    return result || addDataToSearchTree(tree, 2, "2") != 0;
}

bool isSearchTreeBehavesIncorrectly()
{
    SearchTree* tree = NULL;
    bool result = isCreateSearchTreeBehavesIncorrectly(&tree);
    result = result || isAddDataToSearchTreeBehavesIncorrect(tree);
    return result;
}