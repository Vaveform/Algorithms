#include <stdio.h>
#include <stdlib.h>
#include "Matrix_algorithms.h"

int main(void) {
	const int N = 5;
	T* matrix;
	matrix = init_two_dementional_matrix(N, matrix);
	input_two_dementional_matrix(N, matrix);
	print_two_dementional_matrix(N, matrix);
	transpose_two_dementional_matrix(N, matrix);
	printf("\nAfter transpose:\n");
	print_two_dementional_matrix(N, matrix);
	free_two_dementional_ptr_matrix(matrix);
	getch();
	return 0;
}
