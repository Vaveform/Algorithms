#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

#ifndef STACK_ON_LIST_H_
#define STACK_ON_LIST_H_

typedef struct {
	Node* head;
	int size;
} StackOnList;

// ������������� ����� �� ������ ������
void initStackOnList(StackOnList* stack);

// ���������� �������� � ����
boolean pushToStackOnList(StackOnList* stack, T value);

// �������� �� �������� �����
T popStackOnList(StackOnList* stack);

// Check string on closed brackets
boolean isBalanced(StackOnList* stack, char* s, int string_size);

#endif /* STACK_ON_LIST_H_ */
