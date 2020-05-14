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

// Инициализация стека на основе списка
void initStackOnList(StackOnList* stack);

// Добавление элемента в стек
boolean pushToStackOnList(StackOnList* stack, T value);

// Удаление из верхушки стека
T popStackOnList(StackOnList* stack);

// Check string on closed brackets
boolean isBalanced(StackOnList* stack, char* s, int string_size);

#endif /* STACK_ON_LIST_H_ */
