#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

#ifndef ONELINKLIST_H_
#define ONELINKLIST_H_

typedef struct {
	Node* head;
	int size;
} OneLinkList;

// Инициализация односвязанного списка
void initOneLinkList(OneLinkList* lst);

// Вставка в односвязанный список
void insertToOneLinkList(OneLinkList* lst, int data);

// Удаление элемента из односвязанного списка
T removeFromOneLinkList(OneLinkList* lst, T data);

// Напечатать ноду
void printNode(Node* n);

// Напечатать односвязанный список
void printList(OneLinkList *lst);

// Скопировать список
OneLinkList copyOneLinkList(OneLinkList* lst);

// Проверить отсортирован ли список по возрастанию
boolean SortedOneLinsList(OneLinkList* lst);

#endif /* ONELINKLIST_H_ */
