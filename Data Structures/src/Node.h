#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifndef NODE_H_
#define NODE_H_

#define T int
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node{
	T dat;
	struct Node *next;
} Node;


#endif /* NODE_H_ */
