#include <stdbool.h>
#include <stdio.h>
#include "cyclicList.h"
#include "cyclicListTest.h"

int main()
{
	if (isListBehavesIncorrect())
	{
		return 1;
	}
	return 0;
}