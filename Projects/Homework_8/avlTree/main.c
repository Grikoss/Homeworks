#include <stdlib.h>
#include <stdio.h>
#include "avlTreeTest.h"
#include "avlTree.h"

#define SIZE 100

void printOptions(void)
{
    printf_s("Choose option:\n");
    printf_s("0 - exit\n");
    printf_s("1 - add string by key\n");
    printf_s("2 - print string by key\n");
    printf_s("3 - check is there key\n");
    printf_s("4 - delete string by key\n");
}

void scanString(char* buffer,const int size)
{
    scanf_s("%[^\n]", buffer, size);
    scanf_s("%*c");
}

int main()
{
    if (isSearchTreeBehavesIncorrectly())
    {
        return 1;
    }
    SearchTree* tree = createSearchTree();
    while (true)
    {
        int mode = 10;
        printOptions();
        while (mode > 4 || mode < 0)
        {
            scanf_s("%d", &mode);
            while (scanf_s("%*c") != 0);
        }
        if (mode == 0)
        {
            break;
        }
        char key[SIZE] = { 0 };
        char buffer[SIZE] = { 0 };
        printf_s("Enter the key:\n");
        scanString(key, SIZE);
        switch (mode)
        {
        case 1:
            printf_s("Enter string:\n");
            scanString(buffer, SIZE);
            addDataToSearchTree(tree, key, buffer);
            break;
        case 2:
        {
            const int executionCode = getDataFromSearchTree(tree, key, buffer, SIZE);
            switch (executionCode)
            {
            case 1:
                printf_s("SearchTree is empty\n");
                break;
            case 2:
                printf_s("No such key\n");
                break;
            default:
                printf_s("Data: %s\n", buffer);
                break;
            }
            break;
        }
        case 3:
            printf_s(isThereKeyInSearchTree(tree, key) ? "The key is present in the tree\n" : "No such key\n");
            break;
        case 4:
        {
            const int executionCode = deleteDataFromSearchTree(tree, key);
            switch (executionCode)
            {
            case 1:
                printf_s("SearchTree is empty\n");
                break;
            case 2:
                printf_s("There is not the key\n");
                break;
            default:
                printf_s("Delete is successfully\n");
                break;
            }
            break;
        }
        default:
            break;
        }
    }
    deleteSearchTree(tree);
    return 0;
}