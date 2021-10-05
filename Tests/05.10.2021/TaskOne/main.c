#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sumOfDigits(int value)
{
	value = abs(value);
	int sum = 0;
	while (value > 0)
	{
		sum = sum + (value % 10);
		value = value / 10;
	}

	return sum;
}

bool testSumOfDigigts(void) 
{
	bool result = false;
	result = result || (0 != sumOfDigits(0));
	result = result || (5 != sumOfDigits(-23));
	result = result || (10 != sumOfDigits(109));
	result = result || (81 != sumOfDigits(999999999));
}

int digitsWithTheLargestSum(int* inputArrayOfValues, int inputSize, int** outputArrayOfValues, int* outputSize)
{
	if (inputSize <= 0 || inputArrayOfValues == NULL) {
		return 1;
	}

	int maxSum = 0;
	for (int i = 0; i < inputSize; ++i) 
	{
		if (sumOfDigits(inputArrayOfValues[i]) > maxSum) 
		{
			maxSum = sumOfDigits(inputArrayOfValues[i]);
		}
	}

	int* arrayOfValues = NULL;
	int size = 0;
	int counter = 0;
	for (int i = 0; i < inputSize; ++i) {
		if (sumOfDigits(inputArrayOfValues[i]) == maxSum)
		{
			++size;
			int* pointer = realloc(arrayOfValues, sizeof(int) * size);
			if (pointer == NULL)
			{
				if (arrayOfValues != NULL)
				{
					free(arrayOfValues);
				}
				
				return 1;
			}

			arrayOfValues = pointer;

			arrayOfValues[counter] = inputArrayOfValues[i];
			++counter;
		}
	}

	*outputSize = size;
	*outputArrayOfValues = arrayOfValues;
	return 0;
}

bool testDigitWithTheLargestSum(void)
{
	int inputArrayOfValuesOne[] = { 0, -304, 7000, 502, 4, 5, -1, 2 };
	int inputArrayOfValuesTwo[] = { 999999999, 3432, -454, 232, 544, 0 };
	int* outputArrayOfValuesOne = NULL;
	int* outputArrayOfVAluesTwo = NULL;
	int outputSizeOne = 0;
	int outputSizeTWo = 0;
	digitsWithTheLargestSum(inputArrayOfValuesOne, 8, &outputArrayOfValuesOne, &outputSizeOne);
	digitsWithTheLargestSum(inputArrayOfValuesTwo, 6, &outputArrayOfVAluesTwo, &outputSizeTWo);
	bool result = false;
	result = result || (digitsWithTheLargestSum(NULL, 0, NULL, NULL) != 1);
	if (outputSizeOne != 3)
	{
		free(outputArrayOfValuesOne);
		free(outputArrayOfVAluesTwo);
		return true;
	}

	result = result || (outputArrayOfValuesOne[0] != -304);
	result = result || (outputArrayOfValuesOne[1] != 7000);
	result = result || (outputArrayOfValuesOne[2] != 502);

	if (outputArrayOfVAluesTwo != 1)
	{
		free(outputArrayOfValuesOne);
		free(outputArrayOfVAluesTwo);
		return true;
	}

	result = result || (outputArrayOfVAluesTwo[0] != 999999999);
	free(outputArrayOfValuesOne);
	free(outputArrayOfVAluesTwo);
	return result;
}

int main()
{
	if (testSumOfDigigts() || testDigitWithTheLargestSum()) 
	{
		return 1;
	}

	return 0;
}