#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArraysFunctions.h"
#include "SortFunctions.h"
#include "SearchFunctions.h"


int main(void) {
	const int size = 300000;
	int* array = initArray(array, size);
	fillArrayRandomNumbers(array, size, 0, 1000);
	//printArray(array, size);
	double start = clock();
	CountingSort(array, size, 1000);
	printf("%.4lf\n", (clock() - start));
	//printArray(array, size);
	freeArray(array);
}
