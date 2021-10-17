#pragma once

// Return execution code, space and '\n' as splitters of "words", if "word" begin with operator then it is all interpreted as the operator.
// In other cases, the "word" is interpreted as a number
int postCalculator(const char* string, const int length, int* result);