#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_ON_ARRAY_H_
#define QUEUE_ON_ARRAY_H_


/*Размер очереди*/
#define SIZE_QUEUE_PRIORITY 5
/*Описание исключительных ситуаций*/
const int okQueuePriority = 0;			// Все нормально
const int fullQueuePriority = 1;		// Очередь переполнена
const int emptyQueuePriority = 2;		// Очередь пуста
/**********************************/
/*Переменная ошибок*/
extern int errorQueuePriority;
/*Базовый тип очереди*/
typedef struct {
int data;							// Данные
int priority;						// Приоритет
} queuePriorityBaseType;
/*Дескриптор очереди*/
typedef struct {
	queuePriorityBaseType buf[SIZE_QUEUE_PRIORITY];	// Буфер очереди
	unsigned uk;									// Указатель на хвост
} QueuePriority;
/********************/
int errorQueuePriority;

/*Инициализация очереди*/
void initQueuePriority(QueuePriority *F);

/*Включение в очередь*/
void putQueuePriority(QueuePriority *F, queuePriorityBaseType E);

/*Исключение из очереди*/
void getQueuePriority(QueuePriority *F, queuePriorityBaseType *E);

/*Предикат: полна ли очередь*/
int isFullQueuePriority(QueuePriority *F);

/*Предикат: пуста ли очередь*/
int isEmptyQueuePriority(QueuePriority *F);

#endif /* QUEUE_ON_ARRAY_H_ */
