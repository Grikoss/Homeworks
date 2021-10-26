#pragma once

// Return execution code, converted string into output
// Execution cods:
// 0 - ok; 1 - string = NULL; 2, 3 - memory; 4 - opening parenthesis is missing; 5 - closing parenthesis is missing;
// If execution code = 0 then ownership of output memory is transferred to the user, otherwise the output remains untouched
int sortStation(const char* string, char** output);