#pragma once

//��������� ������ � ������� ���������, ������� ����� �������� �������
void swapFunctionForArray(int array[], int numberOne, int numberTwo);

//���������� �������� ��������� ������, ��������� � �������� ������
int insertionSort(int array[], int startIndex, int endIndex);

//����� ��������� �������� ��� �������(�� ����, ����� ��� ��� ������������, ����� ������ ��� ������� � ������)
double selectionOfKeyElement(int array[], int startIndex, int endIndex, bool* isSuccessful);

//��� ������, ��������� ������, ��������� � �������� ������
int quickSort(int array[], int startIndex, int endIndex);