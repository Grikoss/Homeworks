#pragma once

// Reading from a file, do not forget to open the file in the desired mode
char* readFromFile(FILE* file);

// Writing to a file opened in the desired mode, you also need to specify a literal after the line (a space or a transition to the next line)
int writeToFile(FILE* file, char* input, char literal);