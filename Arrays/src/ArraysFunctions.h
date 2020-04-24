#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int searchNum(int* array, int len, int value);

float mean(int* array, int len);

int** initArray(int** array, const int row, const int col);

void fillArray(int** array, const int row, const int col);

void printArray(int** array, const int row, const int col);

void changeCols(int** array, int row, int col, int from, int to);

void swap(int* left, int* right);

void freeMatrix(int** array, int row);

void MatrixBubbleSort(int** arr, int ROW, int COL);

double MathFunc(double value);

void TrabbPradoKnuthAlgorithm(double (*Func) (double));
