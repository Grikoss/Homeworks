#include <stdlib.h>
#include <string.h>

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

Node* createNode(int* inputValue)
{
    Node* node = calloc(1, sizeof(Node));
    if (node != NULL)
    {
        node->value = *inputValue;
    }
    return node;
}

Node* fillTree(Node* node, const char* string, int* index)
{
    int value = 0;
    switch (readString(string, index, &value))
    {
    case 1:
        return NULL;
    case 2:
    case 3:
    default:
        break;
    }
}