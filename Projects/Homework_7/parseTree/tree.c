#include <stdlib.h>
#include <string.h>
#include "tree.h"

int getNumber(const char* string, int* index)
{
    char* buffer = calloc(strlen(string) + 1, sizeof(char));
    if (buffer == NULL)
    {
        return 0;
    }
    int subIndex = 0;
    if (string[*index] == '-')
    {
        buffer[subIndex] = string[*index];
        ++* index;
        ++subIndex;
    }
    while (string[*index] != '\0' && string[*index] <= 57 && string[*index] >= 48)
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
            if (string[*index] != '-' || string[*index + 1] > 57 || string[*index + 1] < 48)
            {
                *outputValue = string[*index];
                ++* index;
                return 1;
            }
        default:
            if ((string[*index] <= 57 && string[*index] >= 48 ) || string[*index] == '-')
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

typedef struct Node
{
    int value;
    struct Node* leftSon;
    struct Node* rigthSon;
} Node;

typedef struct ParceTree
{
    Node* root;
} ParceTree;

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

ParceTree* createParceTree(const char* string)
{
    ParceTree* tree = calloc(1, sizeof(ParceTree));
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
    while (*index < sizeOfBuffer - 1 && value != 0)
    {
        if (value < 0)
        {
            buffer[*index] = '-';
            ++*index;
            value = abs(value);
            continue;
        }
        if (value <= 9 && value >= 1)
        {
            buffer[*index] = value + 48;
            ++*index;
            value = 0;
            continue;
        }
        buffer[*index] = value % 10 + 48;
        ++*index;
        value /= 10;
    }
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
    if (*index < sizeOfBuffer - 1)
    {
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
            ++*index;
            printSpace(index, buffer, sizeOfBuffer);
            getStringFromParceTreeRecursive(node->leftSon, index, buffer, sizeOfBuffer);
            getStringFromParceTreeRecursive(node->rigthSon, index, buffer, sizeOfBuffer);
            printCloseBracket(index, buffer, sizeOfBuffer);
            printSpace(index, buffer, sizeOfBuffer);
        }
    }
}

int getStringFromParceTree(ParceTree* tree, char* buffer, const int sizeOfBuffer)
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