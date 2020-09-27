#include <stdio.h>
#include <math.h>

//������� 2
int luckyTickets(void) {
	int arrayOfSums[28];
	const int maxSum = 27;
	//������������� �������
	for (int i = 0; i <= maxSum; ++i) {
		arrayOfSums[i] = 0;
	}

	//������� ���������� ������� �������� ����
	const int maxNum = 9;
	for (int n1 = 0; n1 <= maxNum; ++n1) {
		for (int n2 = 0; n2 <= maxNum; ++n2) {
			for (int n3 = 0; n3 <= maxNum; ++n3) {
				++arrayOfSums[n1 + n2 + n3];
			}
		}
	}

	//������� ���������� ���������
	int numticket = 0;
	for (int i = 0; i <= maxSum; ++i) {
		numticket += (arrayOfSums[i] * arrayOfSums[i]);
	}

	return numticket;
}

void main() {
	printf("%d", luckyTickets());
}
