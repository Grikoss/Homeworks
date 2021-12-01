#include <stdbool.h>
#include <stdio.h>
#include "countingTest.h"
#include "counting.h"
#include "cyclicListTest.h"

int main(int argc, char* argv[])
{
	if (isListBehavesIncorrectly())
	{
		return 1;
	}
	if (isGetNumberofTheLastRemainingBehavesIncorrectly())
	{
		return 2;
	}
	if (argc > 1)
	{
		return 0;
	}
	printf("Enter number of standing:\n");
	int numberOfStanding = 0;
	while (scanf_s("%d", &numberOfStanding) != 1)
	{
		while (scanf_s("%*c") != 0);
	}
	printf("Enter step:\n");
	int step = 0;
	while (scanf_s("%d", &step) != 1)
	{
		while (scanf_s("%*c") != 0);
	}
	printf("The number of the last remaining:\n%d\n", getNumberofTheLastRemaining(numberOfStanding, step));
	return 0;
}