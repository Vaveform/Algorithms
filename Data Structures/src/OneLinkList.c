#include "OneLinkList.h"

// Инициализация односвязанного списка
void initOneLinkList(OneLinkList* lst){
	lst->head = NULL;
	lst->size = 0;
}

// Вставка в односвязанный список
void insertToOneLinkList(OneLinkList* lst, int data){
	Node* new = (Node*) malloc(sizeof(Node));
	new->dat = data;
	new->next = NULL;

	Node* current = lst->head;
	if(current == NULL){
		lst->head = new;
		lst->size++;
	}
	else{
		while(current->next != NULL){
			current = current->next;
		}
		current->next = new;
		lst->size++;
	}
}

// Удаление элемента из односвязанного списка
T removeFromOneLinkList(OneLinkList* lst, T data){
	Node* current = lst->head;
	Node* parent = NULL;
	if(current == NULL){
		return NULL;
	}
	while(current->next != NULL && current->dat != data){
		parent = current;
		current = current->next;
	}
	if(current->dat != data){
		return NULL;
	}
	if(current == lst->head){
		lst->head = current->next;
		lst->size--;
		return current;
	}
	parent->next = current->next;
	lst->size--;
	T result = current->dat;
	free(current);
	return result;
}

// Скопировать список
OneLinkList copyOneLinkList(OneLinkList* lst){
	OneLinkList list;
	initOneLinkList(&list);
	Node* current = lst->head;
	while(list.size < lst->size && current != NULL){
		insertToOneLinkList(&list, current->dat);
		current = current->next;
	}
	return list;
}

// Проверить отсортирован ли список по возрастанию
boolean SortedOneLinsList(OneLinkList* lst){
	if(lst->size <= 1){
		return true;
	}
	else{
		Node* current = lst->head;
		Node* next = lst->head->next;
		while(next != NULL){
			if(current->dat <= next->dat){
				current = current->next;
				next = current->next;
			}
			else{
				return false;
			}
		}
		return true;
	}
}

// Напечатать ноду
void printNode(Node* n){
	if(n == NULL){
		printf("[]");
		return;
	}
	printf("[%d] ", n->dat);
}

// Напечатать односвязанный список
void printList(OneLinkList *lst){
	Node* current = lst->head;
	if(current == NULL){
		printNode(current);
	}
	else{
		do{
			printNode(current);
			current = current->next;
		}
		while(current != NULL);
	}
}
