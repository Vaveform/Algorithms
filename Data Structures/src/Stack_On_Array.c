#include "Stack_On_Array.h"

int cursor = -1;
T Stack[STACK_SIZE];

// Add new element to top of stack
bolean push(T data){
	if(cursor < STACK_SIZE){
		cursor++;
		Stack[cursor] = data;
		return true;
	}
	else{
		printf("Stack overflow\n");
		return false;
	}
}

// Remove element from top of stack
T pop(){
	if(cursor != -1){
		// Firstly return Stack[cursor] then cursor-- : You can use temporary variable to save Stack[cursor]
		// And then cursor-- and after that return temporary variable
		return Stack[cursor--];
	}
	else{
		//printf("Stack empty: ");
		return -1;
	}
}

// Print stack to console
void Print_Stack(){
	int result = pop();
	while(result != -1){
		printf("%d", result);
		result = pop();
	}

}

// Not recursion algorithm
void Decimal_to_Binary_in_Stack(int decimal){
	for(int i = decimal; i > 0; i /= 2){
		push(i % 2);
	}
}

