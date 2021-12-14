#include "kmpTest.h"

int main(int argc, char* argv[])
{
    if (isKMPBehavesIncorrectly())
    {
        return 1;
    }
    if (argc > 1)
    {
        return 0;
    }
}