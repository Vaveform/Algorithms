#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "math.h"

float mean(int* array, int len);

int* initArray(int* array, int len);

int** initMatrix(int** array, const int row, const int col);

void fillMatrix(int** array, const int row, const int col);

void fillArray(int* array, int len);

void printMatrix(int** array, const int row, const int col);

void printArray(int* array, int len);

void changeCols(int** array, int row, int col, int from, int to);

void swap(int* left, int* right);

void freeMatrix(int** array, int row);

void freeArray(int* array);

double MathFunc(double value);

void TrabbPradoKnuthAlgorithm(double (*Func) (double));

void fillMatrixRandomNumbers(int** array, const int row, const int col, int begin, int end);

void fillArrayRandomNumbers(int* array, int len, int begin, int end);
