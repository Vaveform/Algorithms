#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArraysFunctions.h"
#include "SortFunctions.h"
#include "SearchFunctions.h"

int main(void) {
	const int size = 30;
	int* array = initArray(array, size);
	fillArrayRandomNumbers(array, size, 0, 100);
	printArray(array, size);
	double start = clock();
	bucketSort(array, size);
	printf("%.4lf\n", (clock() - start));
	printArray(array, size);
	freeArray(array);
}
