#pragma once

#ifndef MATRIX_ALGORITHMS_H_
#define MATRIX_ALGORITHMS_H_

#include <stdio.h>
#include <stdlib.h>

#define T double

T* init_two_dementional_matrix(int n, T* matrix_ptr);

void input_two_dementional_matrix(int n, T* matrix_ptr);

void print_two_dementional_matrix(int n, T* matrix_ptr);

void free_two_dementional_ptr_matrix(T* matrix_ptr);

void transpose_two_dementional_matrix(int n, T* matrix_ptr);

#endif /* MATRIX_ALGORITHMS_H_ */
