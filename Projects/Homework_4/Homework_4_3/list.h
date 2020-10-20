#pragma once

#include <stdbool.h>

typedef char* dataType;

typedef struct List List;

/*
* ��� ������� ���������� ��� ������:
* 0 - ������� ���������
* 1 - �������� � ����������/������������� ������
* 2 - �������� ������� ������
*/

// ��������� ����� �� ���������, �������� ��������� �� ��������� list
int createList(List** output);

// ��������� ��������� � ��������� ����������, � ������� ��������� ��������� ��������
int checkEmpty(List* list, bool* isEmpty);

// ��������� ����� ��������� �� ����, ������� ���������
int deleteList(List** list);

// ��������� ��������� �� ����, � ����� ������, ������� ����� ������ � ���������
int addNewElement(List* list, dataType name, dataType telephone);