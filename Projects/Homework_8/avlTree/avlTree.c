#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "avlTree.h"

typedef enum Direction
{
    right,
    left
} Direction;

typedef struct Node
{
    char* key;
    int balance;
    char* data;
    struct Node* leftSon;
    struct Node* rightSon;
} Node;

typedef struct SearchTree
{
    Node* root;
} SearchTree;

int getHeightRecursive(Node* node)
{
    if (node->leftSon == NULL && node->rightSon == NULL)
    {
        return 1;
    }
    int heightLeft = 0;
    int heightRight = 0;
    if (node->leftSon != NULL)
    {
        heightLeft = getHeightRecursive(node->leftSon) + 1;
    }
    if (node->rightSon != NULL)
    {
        heightRight = getHeightRecursive(node->rightSon) + 1;
    }
    return heightLeft > heightRight ? heightLeft : heightRight;
}

int getHeight(SearchTree* tree)
{
    if (tree == NULL || tree->root == NULL)
    {
        return 0;
    }
    return getHeightRecursive(tree->root);
}

char* createString(const char* data)
{
    const int length = strlen(data) + 1;
    char* string = calloc(length, sizeof(char));
    if (string != NULL)
    {
        strcpy_s(string, length, data);
    }
    return string;
}

Node* createNode(const char* key, const char* data)
{
    Node* node = calloc(1, sizeof(Node));
    if (node != NULL)
    {
        node->key = createString(key);
        node->data = createString(data);
    }
    return node;
}

SearchTree* createSearchTree()
{
    return calloc(1, sizeof(SearchTree));
}

void swapData(Node* nodeOne, Node* nodeTwo)
{
    char* buffer = nodeOne->data;
    nodeOne->data = nodeTwo->data;
    nodeTwo->data = buffer;
}

void deleteNode(Node* node)
{
    free(node->key);
    free(node->data);
    free(node);
}

int calculateBalance(Node* node)
{
    int leftHeight = 0;
    int rightHeight = 0;
    if (node->leftSon != NULL)
    {
        leftHeight = getHeightRecursive(node->leftSon);
    }
    if (node->rightSon != NULL)
    {
        rightHeight = getHeightRecursive(node->rightSon);
    }
    return rightHeight - leftHeight;
}

Node* smallLeftRotation(Node* node)
{
    Node* rightNode = node->rightSon;
    node->rightSon = node->rightSon->leftSon;
    rightNode->leftSon = node;
    node->balance = calculateBalance(node);
    rightNode->balance = calculateBalance(rightNode);
    return rightNode;
}

Node* smallRightRotation(Node* node)
{
    Node* leftNode = node->leftSon;
    node->leftSon = node->leftSon->rightSon;
    leftNode->rightSon = node;
    node->balance = calculateBalance(node);
    leftNode->balance = calculateBalance(leftNode);
    return leftNode;
}

Node* bigLeftRotation(Node* node)
{
    Node* rightNode = node->rightSon;
    Node* rightLeftNode = node->rightSon->leftSon;
    node->rightSon = node->rightSon->leftSon->leftSon;
    rightNode->leftSon = rightNode->leftSon->rightSon;
    rightLeftNode->leftSon = node;
    rightLeftNode->rightSon = node->rightSon;
    node->balance = calculateBalance(node);
    rightNode->balance = calculateBalance(rightNode);
    rightLeftNode->balance = calculateBalance(rightLeftNode);
    return rightLeftNode;
}

Node* bigRightRotation(Node* node)
{
    Node* leftNode = node->leftSon;
    Node* leftRightNode = node->leftSon->rightSon;
    node->leftSon = node->leftSon->rightSon->rightSon;
    leftNode->rightSon = leftNode->rightSon->leftSon;
    leftRightNode->rightSon = node;
    leftRightNode->leftSon = leftNode;
    node->balance = calculateBalance(node);
    leftNode->balance = calculateBalance(leftNode);
    leftRightNode->balance = calculateBalance(leftRightNode);
    return leftRightNode;
}

Node* rebalanceRecursive(Node* node, const char* key)
{
    if (strcmp(key, node->key) < 0)
    {
       node->leftSon = rebalanceRecursive(node->leftSon, key);
    }
    if (strcmp(key, node->key) > 0)
    {
       node->rightSon = rebalanceRecursive(node->rightSon, key);
    }
    node->balance = calculateBalance(node);
    if (node->balance == 2)
    {
        return node->rightSon->balance >= 0 ? smallLeftRotation(node) : bigLeftRotation(node);
    }
    if (node->balance == -2)
    {
        return node->leftSon->balance <= 0 ? smallRightRotation(node) : bigRightRotation(node);
    }
    return node;
}

int addDataToSearchTree(SearchTree* tree, const char* key, const char* data)
{
    if (tree == NULL)
    {
        return 1;
    }
    Node* newNode = createNode(key, data);
    if (newNode == NULL)
    {
        return 2;
    }
    if (tree->root == NULL)
    {
        tree->root = newNode;
        return 0;
    }
    Node* node = tree->root;
    while (true)
    {
        if (strcmp(newNode->key, node->key) == 0)
        {
            swapData(newNode, node);
            deleteNode(newNode);
            return 0;
        }
        if (strcmp(newNode->key, node->key) < 0)
        {
            if (node->leftSon == NULL)
            {
                node->leftSon = newNode;
                tree->root = rebalanceRecursive(tree->root, newNode->key);
                return 0;
            }
            node = node->leftSon;
        }
        else
        {
            if (node->rightSon == NULL)
            {
                node->rightSon = newNode;
                tree->root = rebalanceRecursive(tree->root, newNode->key);
                return 0;
            }
            node = node->rightSon;
        }
    }
}

Node* searchNodeParentByKey(SearchTree* tree, const char* key)
{
    if (strcmp(tree->root->key, key) == 0)
    {
        return tree->root;
    }
    Node* node = tree->root;
    while (node != NULL)
    {
        if (node->leftSon != NULL)
        {
            if (strcmp(node->leftSon->key, key) == 0)
            {
                break;
            }
        }
        if (node->rightSon != NULL)
        {
            if (strcmp(node->rightSon->key, key) == 0)
            {
                break;
            }
        }
        if (strcmp(key, node->key) < 0)
        {
            node = node->leftSon;
        }
        else
        {
            node = node->rightSon;
        }
    }
    return node;
}

bool isThereKeyInSearchTree(SearchTree* tree, const char* key)
{
    if (tree == NULL || tree->root == NULL)
    {
        return false;
    }
    return searchNodeParentByKey(tree, key) != NULL;
}

int getDataFromSearchTree(SearchTree* tree, const char* key, char* buffer, const int size)
{
    if (tree == NULL || tree->root == NULL)
    {
        return 1;
    }
    Node* node = searchNodeParentByKey(tree, key);
    if (node == NULL)
    {
        return 2;
    }
    if (strcmp(node->key, key) == 0)
    {
        strcpy_s(buffer, size, node->data);
        return 0;
    }
    if (node->leftSon != NULL && strcmp(node->leftSon->key, key) == 0)
    {
        strcpy_s(buffer, size, node->leftSon->data);
        return 0;
    }
    if (node->rightSon != NULL && strcmp(node->rightSon->key, key) == 0)
    {
        strcpy_s(buffer, size, node->rightSon->data);
        return 0;
    }
    return 3;
}

Node* rigthmost(Node* node)
{
    while (node->rightSon->rightSon != NULL)
    {
        node = node->rightSon;
    }
    return node;
}

void deleteNodeInTree(SearchTree* tree, Node* parent, Node* node, Direction direction)
{
    if (node->leftSon == NULL && node->rightSon == NULL)
    {
        deleteNode(node);
        if (parent == NULL)
        {
            tree->root = NULL;
        }
        else
        {
            if (direction == left)
            {
                parent->leftSon = NULL;
            }
            else
            {
                parent->rightSon = NULL;
            }
            tree->root = rebalanceRecursive(tree->root, parent->key);
        }
        return;
    }
    if (node->leftSon == NULL && node->rightSon != NULL)
    {
        if (parent == NULL)
        {
            tree->root = node->rightSon;
            deleteNode(node);
            return;
        }
        if (direction == left)
        {
            parent->leftSon = node->rightSon;
        }
        else
        {
            parent->rightSon = node->rightSon;
        }
        deleteNode(node);
        tree->root = rebalanceRecursive(tree->root, parent->key);
        return;
    }
    if (node->leftSon != NULL && node->rightSon == NULL)
    {
        if (parent == NULL)
        {
            tree->root = node->leftSon;
            deleteNode(node);
            return;
        }
        if (direction == left)
        {
            parent->leftSon = node->leftSon;
        }
        else
        {
            parent->rightSon = node->leftSon;
        }
        deleteNode(node);
        tree->root = rebalanceRecursive(tree->root, parent->key);
        return;
    }
    if (node->leftSon != NULL && node->rightSon != NULL)
    {
        Node* newNode = NULL;
        char* key = NULL;
        char* data = NULL;
        if (node->leftSon->rightSon == NULL)
        {
            newNode = node;
            key = createString(newNode->leftSon->key);
            data = createString(newNode->leftSon->data);
            deleteNodeInTree(tree, newNode, newNode->leftSon, left);
        }
        else
        {
            newNode = rigthmost(node->leftSon);
            key = createString(newNode->rightSon->key);
            data = createString(newNode->rightSon->data);
            deleteNodeInTree(tree, newNode, newNode->rightSon, right);
        }
        free(node->key);
        node->key = key;
        free(node->data);
        node->data = data;
    }
}

int deleteDataFromSearchTree(SearchTree* tree, const char* key)
{
    if (tree == NULL || tree->root == NULL)
    {
        return 1;
    }
    Node* node = searchNodeParentByKey(tree, key);
    if (node == NULL)
    {
        return 2;
    }
    if (strcmp(node->key, key) == 0)
    {
        deleteNodeInTree(tree, NULL, node, left);
        return 0;
    }
    if (node->leftSon != NULL && strcmp(node->leftSon->key, key) == 0)
    {
        deleteNodeInTree(tree, node, node->leftSon, left);
        return 0;
    }
    if (node->rightSon != NULL && strcmp(node->rightSon->key, key) == 0)
    {
        deleteNodeInTree(tree, node, node->rightSon, right);
        return 0;
    }
    return 3;
}

void deleteSearchThreeRecursive(Node* node)
{
    if (node->leftSon != NULL)
    {
        deleteSearchThreeRecursive(node->leftSon);
    }
    if (node->rightSon != NULL)
    {
        deleteSearchThreeRecursive(node->rightSon);
    }
    free(node->data);
    free(node->key);
    free(node);
}

int getNumberOfNodesRecursive(Node* node)
{
    int leftValue = 0;
    int rightValue = 0;
    if (node->leftSon != NULL)
    {
        leftValue = getNumberOfNodesRecursive(node->leftSon);
    }
    if (node->rightSon != NULL)
    {
        rightValue = getNumberOfNodesRecursive(node->rightSon);
    }
    return leftValue + rightValue + 1;
}

int getNumbersOfNodes(SearchTree* tree)
{
    if (tree == NULL || tree->root == NULL)
    {
        return 0;
    }
    return getNumberOfNodesRecursive(tree->root);
}

int deleteSearchTree(SearchTree* tree)
{
    if (tree == NULL)
    {
        return 1;
    }
    if (tree->root != NULL)
    {
        deleteSearchThreeRecursive(tree->root);
    }
    free(tree);
    return 0;
}