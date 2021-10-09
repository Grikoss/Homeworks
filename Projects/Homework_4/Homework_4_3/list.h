#pragma once

#include <stdbool.h>

typedef struct List List;

typedef struct Element Element;

//������ ����
List* createNewList(void);

//������� ����
int deleteList(List* list);

//��������� �������
int addNewElement(List* list, char* name, char* telephone);

//���������� ����� � �������, ����� ���� ��������� � ����.��������, ���� ����.�������� �� ����������,
//������������ � ������ �����
int getElements(List* list, char** name, char** telephone);

//����� �������� �� ������� ��������
char* searchElement(List* list, char* input, bool isSearchByName);

//���������� ���������
int getQuantity(List* list);

//����� ��������� �� ������(getElements)
int resetPointer(List* list);