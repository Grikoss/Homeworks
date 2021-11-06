#include "listTest.h"
#include "stackOfListTest.h"

int main()
{
	if (isListBehavesIncorrect())
	{
		return 1;
	}
	if (isStackBehavesIncorrectly())
	{
		return 2;
	}
	return 0;
}