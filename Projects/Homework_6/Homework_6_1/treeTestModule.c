#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "treeTestModule.h"

void runTreeTestModule(void) {
	TREE* tree = createTree();

	if (goToFather(tree) != 1)
	{
		printf("Test one goToFather failed\n");
	}
	else
	{
		if (goToLeftSon(tree) != 1)
		{
			printf("Test one goToLeftSon failed\n");
		}
		else
		{
			if (goToRightSon(tree) != 1)
			{
				printf("Test one goToRightSon failed\n");
			}
		}
	}

	if (goToFather(NULL) != 1)
	{
		printf("Test two goToFather failed\n");
	}
	else
	{
		if (goToLeftSon(NULL) != 1)
		{
			printf("Test two goToLeftSon failed\n");
		}
		else
		{
			if (goToRightSon(NULL) != 1)
			{
				printf("Test two goToRightSon failed\n");
			}
		}
	}

	if (createLeftSone(NULL) != 1)
	{
		printf("Test createLeftSone failed\n");
	}
	else
	{
		if (createLeftSone(tree) != 0)
		{
			printf("Test createLeftSone failed\n");
		}
	}

	if (goToFather(tree) != 0) {
		printf("Test three goToFather failed\n");
	}

	if (createRightSon(NULL) != 1)
	{
		printf("Test createRightSon failed\n");
	}
	else
	{
		if (createRightSon(tree) != 0)
		{
			printf("Test createRightSon failed\n");
		}
	}

	goToFather(tree);
	if (goToLeftSon(tree) != 0) {
		printf("Test three on goToRightSon failed\n");
	}

	char* string = (char*)malloc(sizeof(char));
	if (addItemToNode(NULL, NULL) != 1)
	{
		printf("Test addItemToNode failed\n");
	}
	else
	{
		if (addItemToNode(tree, string) != 0)
		{
			printf("Test addItemToNode failed\n");
		}
	}

	if (deleteNode(NULL) != 1)
	{
		printf("Test one deleteNode failed\n");
	}
	else
	{
		if (deleteNode(tree) != 0)
		{
			printf("Test one deleteNode failed\n");

		}
	}

	goToRightSon(tree);
	deleteNode(tree);
	deleteNode(tree);
	if (deleteNode(tree) != 1)
	{
		printf("Test two deleteNode failed\n");
	}

	free(tree);
}