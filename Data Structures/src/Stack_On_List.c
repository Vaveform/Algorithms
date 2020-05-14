#include "Stack_On_List.h"

// Инициализация стека на основе списка
void initStackOnList(StackOnList* stack){
	stack->head = NULL;
	stack->size = 0;
}

// Добавление элемента в стек
boolean pushToStackOnList(StackOnList* stack, T value){
	Node* tmp = (Node*) malloc(sizeof(Node));
	if(tmp == NULL){
		printf("Stack overflow\n");
		return false;
	}
	tmp->dat = value;
	tmp->next = stack->head;

	stack->head = tmp;
	stack->size++;
	return true;
}

// Удаление из верхушки стека
T popStackOnList(StackOnList* stack){
	if(stack->size == 0){
		printf("Stack empty \n");
		return -1;
	}
	Node* tmp = stack->head;
	T data = stack->head->dat;
	stack->head = stack->head->next;
	stack->size--;
	free(tmp);
	return data;
}


// Check string on closed brackets
boolean isBalanced(StackOnList* stack, char* s, int string_size){
	boolean Balanced = true;
	for(size_t i = 0; i < string_size; i++){
		if(s[i] == '(' || s[i] == '{' || s[i] == '['){
			pushToStackOnList(stack, s[i]);
		}
		else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
			if(stack->size == 0){
				Balanced = false;
				break;
			}
			else if((stack->head->dat == '(' && s[i] == ')') ||
			(stack->head->dat == '{' && s[i] == '}') ||
			(stack->head->dat == '[' && s[i] == ']')){
				popStackOnList(stack);
			}
			else{
				Balanced = false;
				break;
			}
		}
		else{
			continue;
		}
	}
	if(Balanced == 1 && stack->size == 0){
		return true;
	}
	else{
		return false;
	}
}
