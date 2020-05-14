#include "Queue_On_Array.h"

/*Инициализация очереди*/
void initQueuePriority(QueuePriority *F) {
	F->uk = 0;
	errorQueuePriority = okQueuePriority;
}
/*Включение в очередь*/
void putQueuePriority(QueuePriority *F, queuePriorityBaseType E) {
/*Если очередь переполнена*/
	if (isFullQueuePriority(F)) {
		return;
	}
	/*Иначе*/
	F->buf[F->uk] = E;
	F->uk++;
}

/*Исключение из очереди*/
void getQueuePriority(QueuePriority *F, queuePriorityBaseType *E) {
	/*Если очередь пуста*/
	if (isEmptyQueuePriority(F)) {
		return;
	}
	/*Иначе поиск элемента с максимальным приоритетом*/
	queuePriorityBaseType max = F->buf[0];			// Максимальным примем 1-й элемент
	int maxPos = 0;									// Позиция элемента в макс. приоритетом
	for (unsigned i = 1; i < F->uk; i++) {			// Для всех элементов начиная со второго выполнить
		if (F->buf[i].priority > max.priority) {		// поиск элемента с максимальным приоритетом
			max = F->buf[i];
			maxPos = i;
		}
	}
	/*Максимальный найден. Производим исключение*/
	*E = max;											// Запись данных в переменную
	F->buf[maxPos] = F->buf[--F->uk];					// Установка на позицию исключаемого элемента последнего
	// Уменьшение длины очереди
}

/*Предикат: полна ли очередь*/
int isFullQueuePriority(QueuePriority *F) {
	if (F->uk == SIZE_QUEUE_PRIORITY) {
		errorQueuePriority = fullQueuePriority;
		return 1;
	}
	return 0;
}

/*Предикат: пуста ли очередь*/
int isEmptyQueuePriority(QueuePriority *F) {
	if (F->uk == 0) {
		errorQueuePriority = emptyQueuePriority;
		return 1;
	}
	return 0;
}


