#pragma once

// Return execution code, space and \n as splitters of "words", if "word" begin with operator and his length is 1 then it is interpreted as operator.
// In other cases, the "word" is interpreted as a number
// Numbers are interpreted using the function atoi
// Execution codes: 0 - ok; 1 - memory; 2 - too many operators; 3 - too many numbers or string is empty;
int postCalculator(const char* string, const int length, int* result);