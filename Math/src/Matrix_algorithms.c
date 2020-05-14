#include "Matrix_algorithms.h"

T* init_two_dementional_matrix(int n, T* matrix_ptr){
	matrix_ptr = (T*)calloc(n * n, sizeof(T));
	return matrix_ptr;
}

void input_two_dementional_matrix(int n, T* matrix_ptr){
	printf("Input matrix:\n");
	for(int i = 0; i < n*n; i++){
		printf("Input matrix[%d][%d]: ", i / n, i % n);
		scanf("%lf", &matrix_ptr[i]);
	}
}

void print_two_dementional_matrix(int n, T* matrix_ptr){
	for(int i = 0; i < n*n; i++){
		if(i % n == 0 && i != 0){
			printf("\n%f ", matrix_ptr[i]);
		}
		else{
			printf("%f ", matrix_ptr[i]);
		}
	}
}

void free_two_dementional_ptr_matrix(T* matrix_ptr){
	free(matrix_ptr);
}

void transpose_two_dementional_matrix(int n, T* matrix_ptr){
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			int tmp = matrix_ptr[i * n + j];
			matrix_ptr[i * n + j] = matrix_ptr[j * n + i];
			matrix_ptr[j * n + i] = tmp;
		}
	}
}

