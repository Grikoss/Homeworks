#include <stdlib.h>
#include <stdio.h>
#include "../stack/stackTest.h"
#include "ABBalanceCheckTest.h"
#include "ABBalanceCheck.h"

#define SIZE 30

int main()
{
    if (stackTest())
    {
        return 1;
    }

    if (aABalanceCheckTest())
    {
        return 2;
    }

    char string[SIZE] = { 0 };
    printf("Enter string:\n");
    scanf_s("%[^\n]", string, SIZE);
    printf(aABalanceCheck(string, SIZE) ? "The balance of brackets is observed\n" : "The balance of brackets is not observed\n");
    return 0;
}