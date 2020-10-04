#include<stdio.h>
#include <locale.h>
void printIntegerAsBinary(int number) {
	for (int i = 0; i < 32; ++i) {
		printf(((number & 0b10000000000000000000000000000000) != 0) ? "1" : "0");
		number <<= 1;
	}
	
	printf("\n");
}


void main() {
	setlocale(LC_ALL, "Russian");
	printf("������� ��� �����:\n");
	int numberOne = 0;
	int numberTwo = 0;
	scanf_s("%i", &numberOne);
	scanf_s("%i", &numberTwo);
	printf("������ ����� � �������������� �������� ����: ");
	printIntegerAsBinary(numberOne);
	printf("������ ����� � ������������� �������� ����: ");
	printIntegerAsBinary(numberTwo);
	int sum = 0;
	sum = numberOne + numberTwo;
	printf("����� � ������������� �������� ����: ");
	printIntegerAsBinary(sum);
	printf("����� � ���������� ���� = %i", sum);
}