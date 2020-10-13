#pragma once

//ѕринимает массив и индексы элементов, которые нужно помен€ть местами
void swapFunctionForArray(int array[], int numberOne, int numberTwo);

//—ортировка вставкой принимает массив, начальный и конечный индекс
int insertionSort(int array[], int startIndex, int endIndex);

//¬ыбор ключевого элемента дл€ кусорта(не знаю, зачем вам его использовать, нужен только дл€ кусорта и тестов)
double selectionOfKeyElement(int array[], int startIndex, int endIndex, bool* isSuccessful);

//—ам кусорт, принимает массив, начальный и конечный индекс
int quickSort(int array[], int startIndex, int endIndex);