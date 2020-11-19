#include <stdlib.h>
#include "tree.h"

typedef struct NODE
{
	char* item;
	struct NODE* father;
	struct NODE* leftSon;
	struct NODE* rightSon;
} NODE;

typedef struct TREE
{
	NODE* pointer;
} TREE;

TREE* createTree(void)
{
	NODE* node = (NODE*)malloc(sizeof(NODE));
	if (node == NULL)
	{
		return NULL;
	}

	node->item = NULL;
	node->father = NULL;
	node->leftSon = NULL;
	node->rightSon = NULL;
	TREE* tree = (TREE*)malloc(sizeof(TREE));
	if (tree == NULL)
	{
		return NULL;
	}

	tree->pointer = node;
	return tree;
}

int goToFather(TREE* tree)
{
	if (tree == NULL)
	{
		return 1;
	}

	if (tree->pointer->father == NULL) 
	{
		return 1;
	}

	tree->pointer = tree->pointer->father;
	return 0;
}

int goToLeftSon(TREE* tree)
{
	if (tree == NULL) 
	{
		return 1;
	}

	if (tree->pointer->leftSon == NULL)
	{
		return 1;
	}

	tree->pointer = tree->pointer->leftSon;
	return 0;
}

int goToRightSon(TREE* tree)
{
	if (tree == NULL) {
		return 1;
	}

	if (tree->pointer->rightSon == NULL) 
	{
		return 1;
	}

	tree->pointer = tree->pointer->rightSon;
	return 0;
}

int createLeftSone(TREE* tree)
{
	if (tree == NULL) 
	{
		return 1;
	}

	NODE* node = (NODE*)malloc(sizeof(NODE));
	if (node == NULL) 
	{
		return 1;
	}

	node->item = NULL;
	node->father = tree->pointer;
	node->leftSon = NULL;
	node->rightSon = NULL;
	tree->pointer->leftSon = node;
	tree->pointer = node;
	return 0;
}

int createRightSon(TREE* tree)
{
	if (tree == NULL) {
		return 1;
	}

	NODE* node = (NODE*)malloc(sizeof(NODE));
	if (node == NULL)
	{
		return 1;
	}

	node->item = NULL;
	node->father = tree->pointer;
	node->leftSon = NULL;
	node->rightSon = NULL;
	tree->pointer->rightSon = node;
	tree->pointer = node;
	return 0;
}

int addItemToNode(TREE* tree, char* input)
{
	if (tree == NULL || input == NULL)
	{
		return 1;
	}

	if (tree->pointer->item != NULL)
	{
		free(tree->pointer->item);
	}

	tree->pointer->item = input;
	return 0;
}

int deleteNode(TREE* tree)
{
	if (tree == NULL)
	{
		return 1;
	}

	if (tree->pointer == NULL)
	{
		return 1;
	}

	if (tree->pointer->item != NULL)
	{
		free(tree->pointer->item);
	}

	if (tree->pointer->father != NULL)
	{
		NODE* father = tree->pointer->father;
		free(tree->pointer);
		tree->pointer = father;
		return 0;
	}

	free(tree->pointer);
	tree->pointer = NULL;
	return 0;
}