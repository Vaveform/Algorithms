#include <stdio.h>
#include <stdlib.h>

#include "Stack_On_List.h"
#include "OneLinkList.h"

int main() {
	// Test function balance bracket string
//	StackOnList stack;
//	initStackOnList(&stack);
//	char* test_string1 = "(2+(2*2))";
//	const int size_string1 = 9;
//	const int size_string2 = 5;
//	char* test_string2 = "([(])";
//	boolean result_balanced1 = isBalanced(&stack, test_string1, size_string1);
//	boolean result_balanced2 = isBalanced(&stack, test_string2, size_string2);
//	// If result = 1 - string balanced, if result = 0 - string unbalanced
//	printf("result_balanced1: %d; result_balanced2: %d\n", result_balanced1, result_balanced2);
	// Test copy function of one link list
	OneLinkList first;
	OneLinkList second;
	initOneLinkList(&first);
	insertToOneLinkList(&first, 5);
	insertToOneLinkList(&first, 9);
	insertToOneLinkList(&first, 55);
	insertToOneLinkList(&first, 61);
	insertToOneLinkList(&first, 156);
	printf("fist list before deleting:");
	printList(&first);
	printf("\n");
	printf("Copying list ...\n");
	second = copyOneLinkList(&first);
	printf("Copied!!!\n");
	removeFromOneLinkList(&first, 5);
	removeFromOneLinkList(&first, 55);
	removeFromOneLinkList(&first, 61);
	removeFromOneLinkList(&first, 9);
	removeFromOneLinkList(&first, 156);
	printf("fist list after deleting:");
	printList(&first);
	printf("\n");
	printf("Copied list:");
	printList(&second);
	printf("\n");
	boolean check_sorted = SortedOneLinsList(&second);
	printf("list sorted? %d", check_sorted);
	return 0;
}
