#pragma once


//чтение из файла, не забудьте открыть файл в нужном режиме
char* readFromFile(FILE* file);

//запись в файл, открытый в нужном режиме, так же нужно указать литерал после строчки(пробел или переход на след строку)
int writeToFile(FILE* file, char* input, char literal);