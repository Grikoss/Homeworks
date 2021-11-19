#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "avlTreeTest.h"
#include "avlTree.h"

#define SIZE 100

int getMinNumberOfNodesForBalanceTree(int height)
{
    if (height <= 0)
    {
        return 0;
    }
    if (height == 1)
    {
        return 1;
    }
    return getMinNumberOfNodesForBalanceTree(height - 2) + getMinNumberOfNodesForBalanceTree(height - 1) + 1;
}

bool isTreeUnbalance(SearchTree* tree)
{
    return  getNumbersOfNodes(tree) < getMinNumberOfNodesForBalanceTree(getHeight(tree));
}

bool isCreateSearchTreeBehavesIncorrectly(SearchTree** tree)
{
    *tree = createSearchTree();
    return *tree == NULL;
}

bool isAddDataToSearchTreeBehavesIncorrectly(SearchTree* tree)
{
    bool result = addDataToSearchTree(NULL, 0, NULL) != 1;
    result = result || addDataToSearchTree(tree, -1, "-1") != 0;
    result = result || isTreeUnbalance(tree);
    result = result || addDataToSearchTree(tree, 0, "0") != 0;
    result = result || isTreeUnbalance(tree);
    result = result || addDataToSearchTree(tree, 1, "1") != 0;
    result = result || isTreeUnbalance(tree);
    result = result || addDataToSearchTree(tree, 2, "10") != 0;
    result = result || isTreeUnbalance(tree);
    result = result || addDataToSearchTree(tree, 3, "3") != 0;
    result = result || isTreeUnbalance(tree);
    result = result || addDataToSearchTree(tree, 4, "4") != 0;
    result = result || isTreeUnbalance(tree);
    result = result || addDataToSearchTree(tree, 5, "5") != 0;
    result = result || isTreeUnbalance(tree);
    result = result || addDataToSearchTree(tree, 6, "6") != 0;
    result = result || isTreeUnbalance(tree);
    result = result || addDataToSearchTree(tree, 7, "7") != 0;
    result = result || isTreeUnbalance(tree);
    result = result || addDataToSearchTree(tree, 2, "2") != 0;
    result = result || isTreeUnbalance(tree);
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
    bool result = !isThereKeyInSearchTree(tree, -1);
    result = result || !isThereKeyInSearchTree(tree, 0);
    result = result || !isThereKeyInSearchTree(tree, 1);
    result = result || !isThereKeyInSearchTree(tree, 2);
    result = result || !isThereKeyInSearchTree(tree, 3);
    result = result || !isThereKeyInSearchTree(tree, 4);
    result = result || !isThereKeyInSearchTree(tree, 5);
    result = result || !isThereKeyInSearchTree(tree, 6);
    result = result || !isThereKeyInSearchTree(tree, 7);
    result = result || isThereKeyInSearchTree(NULL, 0);
    result = result || isThereKeyInSearchTree(tree, 9);
    return result;
}

bool isGetDataFromSearchTreeBehavesIncorrectly(SearchTree* tree)
{
    char buffer[SIZE] = { 0 };
    bool result = getDataFromSearchTree(NULL, 5, buffer, SIZE) != 1;
    result = result || getDataFromSearchTree(tree, -1, buffer, SIZE) != 0 || strcmp(buffer, "-1") != 0;
    result = result || getDataFromSearchTree(tree, 0, buffer, SIZE) != 0 || strcmp(buffer, "0") != 0;
    result = result || getDataFromSearchTree(tree, 1, buffer, SIZE) != 0 || strcmp(buffer, "1") != 0;
    result = result || getDataFromSearchTree(tree, 2, buffer, SIZE) != 0 || strcmp(buffer, "2") != 0;
    result = result || getDataFromSearchTree(tree, 3, buffer, SIZE) != 0 || strcmp(buffer, "3") != 0;
    result = result || getDataFromSearchTree(tree, 4, buffer, SIZE) != 0 || strcmp(buffer, "4") != 0;
    result = result || getDataFromSearchTree(tree, 5, buffer, SIZE) != 0 || strcmp(buffer, "5") != 0;
    result = result || getDataFromSearchTree(tree, 6, buffer, SIZE) != 0 || strcmp(buffer, "6") != 0;
    result = result || getDataFromSearchTree(tree, 7, buffer, SIZE) != 0 || strcmp(buffer, "7") != 0;
    result = result || getDataFromSearchTree(tree, 8, buffer, SIZE) != 2;
    return result;
}

bool isDeleteDataFromSearchTreeBehavesIncorrectly(SearchTree* tree)
{
    bool result = deleteDataFromSearchTree(NULL, 1) != 1;
    result = result || deleteDataFromSearchTree(tree, 3) != 0;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, 5) != 0;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, -1) != 0;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, 4) != 0;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, 6) != 0;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, 7) != 0;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, 1) != 0;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, 0) != 0;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, 10) != 2;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, 2) != 0;
    result = result || isTreeUnbalance(tree);
    result = result || deleteDataFromSearchTree(tree, 2) != 1;
    result = result || isTreeUnbalance(tree);
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