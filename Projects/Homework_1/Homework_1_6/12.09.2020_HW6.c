#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void doABarrelRoll(int arrayOfValues[], int begin, int end) {
	int step = (end - begin + 1) / 2;
	for (int i = 0; i < step; ++i) {
		arrayOfValues[begin + i] += arrayOfValues[end - i];
		arrayOfValues[end - i] = arrayOfValues[begin + i] - arrayOfValues[end - i];
		arrayOfValues[begin + i] -= arrayOfValues[end - i];
	}
}

void main() {
	printf("Enter the characteristics of the array (m n):\n ");
	int lengthSegmentM = 0;
	int lengthSegmentN = 0;
	scanf("%d %d", &lengthSegmentM, &lengthSegmentN);
	int lengthSegment = lengthSegmentM + lengthSegmentN;
	printf("Enter %d array elements:\n ", lengthSegment);
	int arrayOfValues[1000];
	for (int i = 0; i < 1000; ++i) {
		arrayOfValues[i] = 0;
	}

	for (int i = 1; i <= lengthSegment; ++i) {
		scanf("%d", &arrayOfValues[i]);
	}
	
	doABarrelRoll(arrayOfValues, 1, lengthSegmentM);
	doABarrelRoll(arrayOfValues, (lengthSegmentM + 1), lengthSegment);
	doABarrelRoll(arrayOfValues, 1, lengthSegment);
	for (int i = 1; i <= lengthSegment; ++i) {
		printf("%d ", arrayOfValues[i]);
	}

}