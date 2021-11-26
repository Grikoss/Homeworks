#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"

typedef struct Node
{
    int value;
    struct Node* leftSon;
    struct Node* rigthSon;
} Node;

typedef struct ParseTree
{
    Node* root;
} ParseTree;

int getNumber(const char* string, int* index)
{
    char* buffer = calloc(11, sizeof(char));
    if (buffer == NULL)
    {
        return 0;
    }
    int subIndex = 0;
    int minus = 1;
    if (string[*index] == '-')
    {
        buffer[subIndex] = string[*index];
        ++*index;
        ++subIndex;
        minus = 0;
    }
    while (string[*index] != '\0' && string[*index] <= '9' && string[*index] >= '0' && subIndex <= 11 - minus)
    {
        buffer[subIndex] = string[*index];
        ++* index;
        ++subIndex;
    }
    buffer[subIndex] = '\0';
    const int result = atoi(buffer);
    free(buffer);
    return result;
}

int readString(const char* string, int* index, int* outputValue)
{
    while (string[*index] != '\0')
    {
        switch (string[*index])
        {
        case '+':
        case '-':
        case '*':
        case '/':
            if (string[*index] != '-' || string[*index + 1] > '9' || string[*index + 1] < '0')
            {
                *outputValue = string[*index];
                ++* index;
                return 1;
            }
        default:
            if ((string[*index] <= '9' && string[*index] >= '0') || string[*index] == '-')
            {
                *outputValue = getNumber(string, index);
                return 2;
            }
            ++* index;
            break;
        }
    }
    return 3;
}

Node* createNode(const int inputValue)
{
    Node* node = calloc(1, sizeof(Node));
    if (node != NULL)
    {
        node->value = inputValue;
    }
    return node;
}

Node* fillTree(const char* string, int* index)
{
    int value = 0;
    const int mode = readString(string, index, &value);
    switch (mode)
    {
    case 3:
        return NULL;
    case 2:
    case 1:
    {
        Node* node = createNode(value);
        if (node == NULL)
        {
            return NULL;
        }
        if (mode == 2)
        {
            return node;
        }
        node->leftSon = fillTree(string, index);
        node->rigthSon = fillTree(string, index);
        return node;
    }
    default:
        return NULL;
    }
}

ParseTree* createParceTree(const char* string)
{
    ParseTree* tree = calloc(1, sizeof(ParseTree));
    if (tree == NULL)
    {
        return NULL;
    }
    int index = 0;
    tree->root = fillTree(string, &index);
    return tree;
}

void printNumber(int value, int* index, char* buffer, const int sizeOfBuffer)
{
    if (*index < sizeOfBuffer - 1 && value == 0)
    {
        buffer[*index] = '0';
        ++*index;
        return;
    }
    char* stringValue = calloc(11, sizeof(char));
    if (stringValue == NULL)
    {
        return;
    }
    buffer[*index] = '\0';
    sprintf_s(stringValue, 11, "%d", value);
    strcat_s(buffer, sizeOfBuffer, stringValue);
    free(stringValue);
    while (*index < sizeOfBuffer - 1 && buffer[*index] != '\0')
    {
        ++*index;
    }
    buffer[*index] = 'þ';
}

void printSpace(int* index, char* buffer, const int sizeOfBuffer)
{
    if (*index < sizeOfBuffer - 1)
    {
        buffer[*index] = ' ';
        ++*index;
    }
}

void printOpenBracket(int* index, char* buffer, const int sizeOfBuffer)
{
    if (*index < sizeOfBuffer - 1)
    {
        buffer[*index] = '(';
        ++* index;
    }
}

void printCloseBracket(int* index, char* buffer, const int sizeOfBuffer)
{
    if (*index < sizeOfBuffer - 1)
    {
        buffer[*index] = ')';
        ++* index;
    }
}

void getStringFromParceTreeRecursive(Node* node, int* index, char* buffer, const int sizeOfBuffer)
{
    if (*index >= sizeOfBuffer - 1)
    {
        return;
    }
    if (node->leftSon == NULL || node->rigthSon == NULL)
    {
        printNumber(node->value, index, buffer, sizeOfBuffer);
        printSpace(index, buffer, sizeOfBuffer);
    }
    else
    {
        printOpenBracket(index, buffer, sizeOfBuffer);
        printSpace(index, buffer, sizeOfBuffer);
        buffer[*index] = node->value;
        ++* index;
        printSpace(index, buffer, sizeOfBuffer);
        getStringFromParceTreeRecursive(node->leftSon, index, buffer, sizeOfBuffer);
        getStringFromParceTreeRecursive(node->rigthSon, index, buffer, sizeOfBuffer);
        printCloseBracket(index, buffer, sizeOfBuffer);
        printSpace(index, buffer, sizeOfBuffer);
    }
}

int getStringFromParceTree(ParseTree* tree, char* buffer, const int sizeOfBuffer)
{
    if (tree == NULL || tree->root == NULL || buffer == NULL)
    {
        return 1;
    }
    int index = 0;
    getStringFromParceTreeRecursive(tree->root, &index, buffer, sizeOfBuffer);
    buffer[index] = '\0';
    return 0;
}

int checkSign(char sign)
{
    switch (sign)
    {
    case '-':
        return 1;
    case '+':
        return 2;
    case '*':
        return 3;
    case '/':
        return 4;
    }
    return -1;
}

int getResultFromParceTreeRecursive(Node* node, int* result)
{
    if (node->leftSon == NULL || node->rigthSon == NULL)
    {
        *result = node->value;
        return 0;
    }
    int resultOne = 0;
    int resultTwo = 0;
    if (getResultFromParceTreeRecursive(node->leftSon, &resultOne) != 0 || getResultFromParceTreeRecursive(node->rigthSon, &resultTwo) != 0)
    {
        return 1;
    }
    switch (node->value)
    {
    case '-':
        *result = resultOne - resultTwo;
        return 0;
    case '+':
        *result = resultOne + resultTwo;
        return 0;
    case '*':
        *result = resultOne * resultTwo;
        return 0;
    case '/':
        if (resultTwo == 0)
        {
            return 1;
        }
        *result = resultOne / resultTwo;
        return 0;
    default:
        return 2;
    }
}

int getResultFromParceTree(ParseTree* tree, int* result)
{
    if (tree == NULL || tree->root == NULL)
    {
        return 2;
    }
    return getResultFromParceTreeRecursive(tree->root, result);
}

void deleteParceTreeRecursive(Node* node)
{
    if (node->leftSon != NULL && node->rigthSon != NULL)
    {
        deleteParceTreeRecursive(node->leftSon);
        deleteParceTreeRecursive(node->rigthSon);
    }
    free(node);
}

int  deleteParceTree(ParseTree* tree)
{
    if (tree == NULL || tree->root == NULL)
    {
        return 1;
    }
    deleteParceTreeRecursive(tree->root);
    free(tree);
    return 0;
}