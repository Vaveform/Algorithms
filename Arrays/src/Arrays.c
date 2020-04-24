#include <stdio.h>
#include <stdlib.h>
#include "ArraysFunctions.h"


int main(void) {
	const int rows = 3;
	const int columns = 3;
	int** my_array;
	my_array = initArray(my_array, rows, columns);
	fillArray(my_array, rows, columns);
	printArray(my_array, rows, columns);
	printf("\n");
	MatrixBubbleSort(my_array, rows, columns);
	printArray(my_array, 3, 3);
	freeMatrix(my_array, 3);
	TrabbPradoKnuthAlgorithm(MathFunc);
}
