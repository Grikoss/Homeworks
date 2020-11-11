#pragma once

#include <stdbool.h>

typedef char dataType;

typedef struct List List;

typedef struct Element Element;

//������ ����
List* createNewList(void);

//���������, �������� �� ������� �������
bool isEnd(Element* element);

//������� ����
int deleteList(List* list);

//��������� �������
int addNewElement(List* list, char* name, char* telephone);

//������� ������, ���������� �������� �����
dataType** getElements(List* list);

//����� �������� �� ������� ��������
dataType* searchElement(List* list, dataType* input, bool isSearchByName);

//���������� ���������
int getQuantity(List* list);