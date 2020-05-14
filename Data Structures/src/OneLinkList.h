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

// ������������� �������������� ������
void initOneLinkList(OneLinkList* lst);

// ������� � ������������� ������
void insertToOneLinkList(OneLinkList* lst, int data);

// �������� �������� �� �������������� ������
T removeFromOneLinkList(OneLinkList* lst, T data);

// ���������� ����
void printNode(Node* n);

// ���������� ������������� ������
void printList(OneLinkList *lst);

// ����������� ������
OneLinkList copyOneLinkList(OneLinkList* lst);

// ��������� ������������ �� ������ �� �����������
boolean SortedOneLinsList(OneLinkList* lst);

#endif /* ONELINKLIST_H_ */
