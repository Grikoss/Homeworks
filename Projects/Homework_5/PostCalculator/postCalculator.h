#pragma once

// Return execution code, space and \n as splitters of "words", if "word" begins with an operator and his length is 1 then it is interpreted as operator.
// In other cases, the "word" is interpreted as a number
// Numbers are interpreted using the function atoi
// Execution codes: 0 - ok; 1 - memory; 2 - division by zero; 3 - too many operators; 4 - string is empty; 5 - too many numbers;
int postCalculate(const char* string, int* result);