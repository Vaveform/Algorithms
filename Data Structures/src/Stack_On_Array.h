#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_ON_ARRAY_H_
#define STACK_ON_ARRAY_H_

// Type implementation
#define T int
// Max stack size
#define STACK_SIZE 1000
// Defining bolean type
#define true 1 == 1
#define false 1 != 1

int typedef bolean;

// Add new element to top of stack
bolean push(T data);

// Remove element from top of stack
T pop();

// Print stack to console
void Print_Stack();

// Not recursion algorithm
void Decimal_to_Binary_in_Stack(int decimal);

#endif /* STACK_ON_ARRAY_H_ */
