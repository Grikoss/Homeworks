#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "searchTree.h"

typedef struct Node
{
    int key;
    char* data;
    struct Node* leftSon;
    struct Node* rigthSon;
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
    else
    {
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
                if (node->rigthSon == NULL)
                {
                    node->rigthSon = newNode;
                    return 0;
                }
                else
                {
                    node = node->rigthSon;
                }
            }
        }
    }
}