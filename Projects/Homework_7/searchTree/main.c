#include <stdlib.h>
#include <stdio.h>
#include "searchTreeTest.h"
#include "searchTree.h"

#define SIZE 100

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
		printf_s("Choose option:\n");
		printf_s("0 - exit\n1 - add string by key\n2 - print string by key\n3 - check is there key\n4 - delete string by key\n");
		while (mode > 4 || mode < 0)
		{
			scanf_s("%d", &mode);
			while (scanf_s("%*c") != 0);
		}
		if (mode == 0)
		{
			break;
		}
		int key = 0;
		char buffer[SIZE] = { 0 };
		printf_s("Enter the key:\n");
		while (scanf_s("%d", &key) == 0)
		{
			while (scanf_s("%*c") != 0);
		}
		while (scanf_s("%*c") != 0);
		switch (mode)
		{
		case 1:
			printf_s("Enter string:\n");
			scanf_s("%[^\n]", buffer, SIZE);
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
				printf_s("There is not the key\n");
				break;
			default:
				printf_s("Data: %s\n", buffer);
				break;
			}
			break;
		}
		case 3:
			printf_s(isThereKeyInSearchTree(tree, key) ? "There is the key\n" : "there is not the key\n");
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