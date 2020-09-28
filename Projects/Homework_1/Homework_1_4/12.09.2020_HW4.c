#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void arePrimes(int num) {
	const int sqrtNum = sqrt(num);
	int arrayOfNums[100001];
	for (int i = 0; i <= num; ++i) {
		arrayOfNums[i] = 0;
	}

	for (int divisor = 2; divisor <= sqrtNum; ++divisor) {
		for (int dividend = num; dividend > divisor; --dividend) {
			if (dividend % divisor == 0) {
				arrayOfNums[dividend] = 1;
			}
		}
	}

	for (int i = 1; i <= num; ++i) {
		if (arrayOfNums[i] == 0) {
			printf("%d\n", i);
		}
	}
}

void main() {
	printf("Enter integer value of no more than 100000\n");
	int value = 0;
	scanf("%d", &value);
	printf("Prime numbers:\n");
	arePrimes(value);
}