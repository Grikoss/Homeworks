#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "searchTree.h"

typedef struct Node
{
    int key;
    char* data;
    struct Node* leftSon;
    struct Node* rightSon;
} Node;

typedef struct SearchTree
{
    Node* root;
} SearchTree;

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

Node* createNode(const int key, const char* data)
{
    Node* node = calloc(1, sizeof(Node));
    if (node != NULL)
    {
        node->key = key;
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
    free(node->data);
    free(node);
}

int addDataToSearchTree(SearchTree* tree, const int key, const char* data)
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
            if (newNode->key == node->key)
            {
                swapData(newNode, node);
                deleteNode(newNode);
                return 0;
            }
            if (newNode->key < node->key)
            {
                if (node->leftSon == NULL)
                {
                    node->leftSon = newNode;
                    return 0;
                }
                else
                {
                    node = node->leftSon;
                }
            }
            else
            {
                if (node->rightSon == NULL)
                {
                    node->rightSon = newNode;
                    return 0;
                }
                else
                {
                    node = node->rightSon;
                }
            }
        }
}

Node* searchNodeParentByKey(SearchTree* tree, const int key)
{
    if (tree->root->key == key)
    {
        return tree->root;
    }
    Node* node = tree->root;
    while (node != NULL)
    {
        if (node->leftSon != NULL)
        {
            if (node->leftSon->key == key)
            {
                break;
            }
        }
        if (node->rightSon != NULL)
        {
            if (node->rightSon->key == key)
            {
                break;
            }
        }
        if (key < node->key)
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

bool isThereKeyInSearchTree(SearchTree* tree, const int key)
{
    if (tree == NULL || tree->root == NULL)
    {
        return false;
    }
    return searchNodeParentByKey(tree, key) != NULL;
}

int getDataFromSearchTree(SearchTree* tree, const int key, char* buffer, const int size)
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
    if (node->key == key)
    {
        strcpy_s(buffer, size, node->data);
        return 0;
    }
    if (node->leftSon != NULL && node->leftSon->key == key)
    {
        strcpy_s(buffer, size, node->leftSon->data);
        return 0;
    }
    if (node->rightSon != NULL && node->rightSon->key == key)
    {
        strcpy_s(buffer, size, node->rightSon->data);
        return 0;
    }
    return 3;
}

Node* rightmost(Node* node)
{
    while (node->rightSon->rightSon != NULL)
    {
        node = node->rightSon;
    }
    return node;
}

void assignSonToParent(Node* parent, Node* son, bool isLeftSon)
{
    if (isLeftSon)
    {
        parent->leftSon = son;
    }
    else
    {
        parent->rightSon = son;
    }
}

void deleteNodeInTree(SearchTree* tree, Node* parent, Node* node, bool isLeftSon)
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
            assignSonToParent(parent, NULL, isLeftSon);
        }
        return;
    }
    if (node->leftSon == NULL && node->rightSon != NULL)
    {
        if (parent == NULL)
        {
            tree->root = node->rightSon;
        }
        else
        {
            assignSonToParent(parent, node->rightSon, isLeftSon);
        }
        deleteNode(node);
        return;
    }
    if (node->leftSon != NULL && node->rightSon == NULL)
    {
        if (parent == NULL)
        {
            tree->root = node->leftSon;
        }
        else
        {
            assignSonToParent(parent, node->leftSon, isLeftSon);
        }
        deleteNode(node);
        return;
    }
    if (node->leftSon != NULL && node->rightSon != NULL)
    {
        int key = 0;
        char* data = NULL;
        if (node->leftSon->rightSon == NULL)
        {
            key = node->leftSon->key;
            data = createString(node->leftSon->data);
            deleteNodeInTree(tree, node, node->leftSon, true);
        }
        else
        {
            Node* newNode = rightmost(node->leftSon);
            key = newNode->rightSon->key;
            data = createString(newNode->rightSon->data);
            deleteNodeInTree(tree, newNode, newNode->rightSon, false);
        }
        node->key = key;
        free(node->data);
        node->data = data;
    }
}

int deleteDataFromSearchTree(SearchTree* tree, const int key)
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
    if (node->key == key)
    {
        deleteNodeInTree(tree, NULL, node, true);
        return 0;
    }
    if (node->leftSon != NULL && node->leftSon->key == key)
    {
        deleteNodeInTree(tree, node, node->leftSon, true);
        return 0;
    }
    if (node->rightSon != NULL && node->rightSon->key == key)
    {
        deleteNodeInTree(tree, node, node->rightSon, false);
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
    free(node);
}

int deleteSearchTree(SearchTree* tree)
{
    if (tree == NULL )
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