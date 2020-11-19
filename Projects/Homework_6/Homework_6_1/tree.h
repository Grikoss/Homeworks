#pragma once

typedef struct TREE TREE;

//Создаёт дерево
TREE* createTree(void);

//Перемещает указатель на предка (0 - успешно, 1 - он отсутствует)
int goToFather(TREE* tree);

//Перемещает указатель на левого потомка (0 - успешно, 1 - он отсутствует)
int goToLeftSon(TREE* tree);

//Перемещает указатель на правого потомка (0 - успешно, 1 - он отсутствует)
int goToRightSon(TREE* tree);

//Создаёт левого потомка и перемещает указатель на него
int createLeftSone(TREE* tree);

//Создаёт правого потомка и перемещает указатель на него
int createRightSon(TREE* tree);

//Добавить айтем в узел
int addItemToNode(TREE* tree, char* input);

//Удаляет текущий узел, перемещает указатель на его предка, если он есть
int deleteNode(TREE* tree);