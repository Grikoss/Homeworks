#include <stdio.h>
#include "treeTest.h"
#include "tree.h"

int main()
{
    if (isParceTreeBehavesIncorrectly())
    {
        return 1;
    }
    FILE* file = NULL;
    fopen_s(&file, "input.txt", "r");
    if (file == NULL)
    {
        return 2;
    }
    char buffer[1000] = { 0 };
    fscanf_s(file, "%[^\n]", buffer, 1000);
    fclose(file);
    ParseTree* tree = createParceTree(buffer);
    getStringFromParceTree(tree, buffer, 1000);
    printf_s("%s\n", buffer);
    int result = 0;
    printf_s(getResultFromParceTree(tree, &result) == 1 ? "Division by zero\n" : "Result = %d\n", result);
    deleteParceTree(tree);
    return 0;
}