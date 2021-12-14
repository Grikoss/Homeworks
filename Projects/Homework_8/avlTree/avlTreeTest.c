#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "avlTreeTest.h"
#include "avlTree.h"

#define SIZE 100

int getMinNumberOfNodesForBalancedTree(int height)
{
    if (height <= 0)
    {
        return 0;
    }
    if (height == 1)
    {
        return 1;
    }
    return getMinNumberOfNodesForBalancedTree(height - 2) + getMinNumberOfNodesForBalancedTree(height - 1) + 1;
}

bool isTreeUnbalanced(SearchTree* tree)
{
    return getNumbersOfNodes(tree) < getMinNumberOfNodesForBalancedTree(getHeight(tree));
}

bool isCreateSearchTreeBehavesIncorrectly(SearchTree** tree)
{
    *tree = createSearchTree();
    return *tree == NULL;
}

bool isAddDataToSearchTreeBehavesIncorrectly(SearchTree* tree)
{
    bool result = addDataToSearchTree(NULL, 0, NULL) != 1;
    result = result || addDataToSearchTree(tree, "a", "-1") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || addDataToSearchTree(tree, "b", "0") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || addDataToSearchTree(tree, "c", "1") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || addDataToSearchTree(tree, "d", "10") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || addDataToSearchTree(tree, "e", "3") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || addDataToSearchTree(tree, "f", "4") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || addDataToSearchTree(tree, "g", "5") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || addDataToSearchTree(tree, "h", "6") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || addDataToSearchTree(tree, "i", "7") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || addDataToSearchTree(tree, "d", "2") != 0;
    result = result || isTreeUnbalanced(tree);
    return result;
}

bool isGetNumbersOfNodesBehavesIncorrectly(SearchTree* tree)
{
    bool result = getNumbersOfNodes(tree) != 9;
    result = result || getNumbersOfNodes(NULL) != 0;
    return result;
}

bool isFunctionThereKeyInSearchTreeBehavesIncorrectly(SearchTree* tree)
{
    bool result = !isThereKeyInSearchTree(tree, "a");
    result = result || !isThereKeyInSearchTree(tree, "b");
    result = result || !isThereKeyInSearchTree(tree, "c");
    result = result || !isThereKeyInSearchTree(tree, "d");
    result = result || !isThereKeyInSearchTree(tree, "e");
    result = result || !isThereKeyInSearchTree(tree, "f");
    result = result || !isThereKeyInSearchTree(tree, "g");
    result = result || !isThereKeyInSearchTree(tree, "h");
    result = result || !isThereKeyInSearchTree(tree, "i");
    result = result || isThereKeyInSearchTree(NULL, 0);
    result = result || isThereKeyInSearchTree(tree, "l");
    return result;
}

bool isGetDataFromSearchTreeBehavesIncorrectly(SearchTree* tree)
{
    char buffer[SIZE] = { 0 };
    bool result = getDataFromSearchTree(NULL, "g", buffer, SIZE) != 1;
    result = result || getDataFromSearchTree(tree, "a", buffer, SIZE) != 0 || strcmp(buffer, "-1") != 0;
    result = result || getDataFromSearchTree(tree, "b", buffer, SIZE) != 0 || strcmp(buffer, "0") != 0;
    result = result || getDataFromSearchTree(tree, "c", buffer, SIZE) != 0 || strcmp(buffer, "1") != 0;
    result = result || getDataFromSearchTree(tree, "d", buffer, SIZE) != 0 || strcmp(buffer, "2") != 0;
    result = result || getDataFromSearchTree(tree, "e", buffer, SIZE) != 0 || strcmp(buffer, "3") != 0;
    result = result || getDataFromSearchTree(tree, "f", buffer, SIZE) != 0 || strcmp(buffer, "4") != 0;
    result = result || getDataFromSearchTree(tree, "g", buffer, SIZE) != 0 || strcmp(buffer, "5") != 0;
    result = result || getDataFromSearchTree(tree, "h", buffer, SIZE) != 0 || strcmp(buffer, "6") != 0;
    result = result || getDataFromSearchTree(tree, "i", buffer, SIZE) != 0 || strcmp(buffer, "7") != 0;
    result = result || getDataFromSearchTree(tree, "l", buffer, SIZE) != 2;
    return result;
}

bool isDeleteDataFromSearchTreeBehavesIncorrectly(SearchTree* tree)
{
    bool result = deleteDataFromSearchTree(NULL, "c") != 1;
    result = result || deleteDataFromSearchTree(tree, "e") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "g") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "a") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "f") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "h") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "i") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "c") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "b") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "l") != 2;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "d") != 0;
    result = result || isTreeUnbalanced(tree);
    result = result || deleteDataFromSearchTree(tree, "d") != 1;
    result = result || isTreeUnbalanced(tree);
    return result;
}

bool isDeleteSeatchTreeBehavesIncorrectly(SearchTree* tree)
{
    bool result = deleteSearchTree(NULL) != 1;
    result = result || deleteSearchTree(tree) != 0;
    return result;
}

bool isSearchTreeBehavesIncorrectly()
{
    SearchTree* tree = NULL;
    bool result = isCreateSearchTreeBehavesIncorrectly(&tree);
    result = result || isAddDataToSearchTreeBehavesIncorrectly(tree);
    result = result || isGetNumbersOfNodesBehavesIncorrectly(tree);
    result = result || isFunctionThereKeyInSearchTreeBehavesIncorrectly(tree);
    result = result || isGetDataFromSearchTreeBehavesIncorrectly(tree);
    result = result || isDeleteDataFromSearchTreeBehavesIncorrectly(tree);
    result = result || isDeleteSeatchTreeBehavesIncorrectly(tree);
    return result;
}