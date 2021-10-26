#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "sortStation.h"
#include "sortStationTest.h"

bool isSortStationTestBehavesIncorrectly()
{
    char* output = NULL;
    bool result = ((sortStation("5)+5", &output) != 4) || output != NULL);
    result = result || ((sortStation("(5+5", &output) != 5) || output != NULL);
    sortStation("5+5", &output);
    result = result || (strcmp("5 5 + ", output) != 0);
    free(output);
    sortStation("-5+5", &output);
    result = result || (strcmp("-5 5 + ", output) != 0);
    free(output);
    sortStation("5 + 5 * 5 + 5 * 5 + 5 * 5", &output);
    result = result || (strcmp("5 5 5 * + 5 5 * + 5 5 * + ", output) != 0);
    free(output);
    sortStation("                    ", &output);
    result = result || (strcmp("", output) != 0);
    free(output);
    sortStation("5 + 5 * dfdfdsfdsfs5 + 5 *fdfdfdfd 5 + 5 *fdsfsdfdsf 5", &output);
    result = result || (strcmp("5 5 5 * + 5 5 * + 5 5 * + ", output) != 0);
    free(output);
    sortStation("(2+2)*2", &output);
    result = result || (strcmp("2 2 + 2 * ", output) != 0);
    free(output);
    sortStation("5 5", &output);
    result = result || (strcmp("5 5 ", output) != 0);
    free(output);
    sortStation("5 + 5 +", &output);
    result = result || (strcmp("5 5 + + ", output) != 0);
    free(output);
    return  result || sortStation(NULL, &output) != 1;
}