#include "OneLinkList.h"

// ������������� �������������� ������
void initOneLinkList(OneLinkList* lst){
	lst->head = NULL;
	lst->size = 0;
}

// ������� � ������������� ������
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

// �������� �������� �� �������������� ������
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

// ����������� ������
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

// ��������� ������������ �� ������ �� �����������
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

// ���������� ����
void printNode(Node* n){
	if(n == NULL){
		printf("[]");
		return;
	}
	printf("[%d] ", n->dat);
}

// ���������� ������������� ������
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
