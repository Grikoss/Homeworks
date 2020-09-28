#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int stringIn(char strMain[], char strSub[]) {
	const int lengthMain = strlen(strMain);
	const int lengthSub = strlen(strSub);
	int count = 0;
	for (int i = 0; i < lengthMain - lengthSub + 1; ++i) {
		if (strMain[i] == strSub[0]) {
			int check = 1;
			int continuationI = i + 1;
			for (int j = 1; j < lengthSub; ++j) {
				if (strSub[j] == strMain[continuationI]) {
					++check;
				}
				else {
					break;
				}

				++continuationI;
			}

			if (check == lengthSub) {
				++count;
			}
		}
	}

	return count;
}

void main() {
	printf("Enter string and substring:\n");
	char strMain[1000];
	char strSub[1000];
	scanf("%s %s", &strMain, &strSub);
	int count = stringIn(strMain, strSub);
	printf("Number of occurrences of a substring in a string = ");
	printf("%d", count);
}