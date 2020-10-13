#pragma once

//Складывает два числа в доп.коде и записывает в третий булевый массив
void binarySummator(bool arrayOne[], bool arrayTwo[], bool resultArray[]);

//Преобразует код в доп.код(принимает булевый массив)
void binaryConverterOfExtraCode(bool array[]);

//Преобразует интовое значение в доп.код и сохраняет его в булевом массиве
void binaryUnpacker(int value, bool array[]);

//Преобразует булевый массив обратно в интовое значение
int binaryPacker(bool array[]);