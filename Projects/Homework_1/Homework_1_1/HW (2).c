
#include <stdio.h>
#include <math.h>

// Задачка 1
//Функция нахождения неполного частного
void incompleteQuotient(int dividend, int divider, int* private, int* correct) {
	*private = 0;
	*correct = 0;
	//проверка корректности ввода
	if (divider == 0) {
		return;
	}

	*correct = 1;
	int sign = 0;
	if ((dividend < 0) && (divider > 0)) {
		sign = 1;
	}

	if ((dividend > 0) && (divider < 0)) {
		sign = 2;
	}

	if ((dividend < 0) && (divider < 0)) {
		sign = 3;
	}

	dividend = abs(dividend);
	divider = abs(divider);
	while (dividend >= divider) {
		dividend -= divider;
		++* private;
	}

	if (sign == 1) {
		*private = -*private - 1;
	}

	if (sign == 2) {
		*private = -*private;
	}

	if (sign == 3) {
		++*private;
	}
}

//тело программы
int main() {
	printf("Counting incomplete quotient\nEnter two integer values \n");
	int value1 = 0;
	int value2 = 0;
	scanf("%d %d", &value1, &value2);
	int correct = 0;
	int private = 0;
	incompleteQuotient(value1, value2, &private, &correct);
	if (correct == 1) {
		printf("Incomplete quotient = %d", private);
	}
	else {
		printf("Invalid input");
	}
}