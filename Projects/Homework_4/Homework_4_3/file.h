#pragma once


//������ �� �����, �� �������� ������� ���� � ������ ������
char* readFromFile(FILE* file);

//������ � ����, �������� � ������ ������, ��� �� ����� ������� ������� ����� �������(������ ��� ������� �� ���� ������)
int writeToFile(FILE* file, char* input, char literal);