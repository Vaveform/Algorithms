#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_ON_ARRAY_H_
#define QUEUE_ON_ARRAY_H_


/*������ �������*/
#define SIZE_QUEUE_PRIORITY 5
/*�������� �������������� ��������*/
const int okQueuePriority = 0;			// ��� ���������
const int fullQueuePriority = 1;		// ������� �����������
const int emptyQueuePriority = 2;		// ������� �����
/**********************************/
/*���������� ������*/
extern int errorQueuePriority;
/*������� ��� �������*/
typedef struct {
int data;							// ������
int priority;						// ���������
} queuePriorityBaseType;
/*���������� �������*/
typedef struct {
	queuePriorityBaseType buf[SIZE_QUEUE_PRIORITY];	// ����� �������
	unsigned uk;									// ��������� �� �����
} QueuePriority;
/********************/
int errorQueuePriority;

/*������������� �������*/
void initQueuePriority(QueuePriority *F);

/*��������� � �������*/
void putQueuePriority(QueuePriority *F, queuePriorityBaseType E);

/*���������� �� �������*/
void getQueuePriority(QueuePriority *F, queuePriorityBaseType *E);

/*��������: ����� �� �������*/
int isFullQueuePriority(QueuePriority *F);

/*��������: ����� �� �������*/
int isEmptyQueuePriority(QueuePriority *F);

#endif /* QUEUE_ON_ARRAY_H_ */
