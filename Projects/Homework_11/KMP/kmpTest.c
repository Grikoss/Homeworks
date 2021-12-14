#include <stdbool.h>
#include <stdlib.h>
#include "kmpTest.h"
#include "kmp.h"

bool isKMPBehavesIncorrectly(void)
{
    bool result = getPositionOfFirstOccurrence(NULL, NULL) >= 0;
    result = result || getPositionOfFirstOccurrence(NULL, "a") >= 0;
    result = result || getPositionOfFirstOccurrence("a", NULL) >= 0;
    result = result || getPositionOfFirstOccurrence("aaaa", "aaaaaaaaaaaaa") != 3;
    result = result || getPositionOfFirstOccurrence("aaaaaaaaaaa", "aa") >= 0;
    result = result || getPositionOfFirstOccurrence("aba", "abbbabbababbbaabb") != 9;
    result = result || getPositionOfFirstOccurrence("B", "BBBB") != 0;
    result = result || getPositionOfFirstOccurrence("", "dsdsds") >= 0;
    result = result || getPositionOfFirstOccurrence("s", "") >= 0;
    return result;
}