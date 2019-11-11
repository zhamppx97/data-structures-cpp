#include <stdio.h>
#include <stdlib.h>
#include "Header_Stack.h"
#include "Source_Stack.cpp"

int main(int argc, const char *argv[])
{
	int element, stack_val, menu_number, pop_number, push_number;
	printf("Please enter elements of stack : ");
	scanf("%d", &element);
	printf("Please enter %d elements of integers : ", element);
	
	Pstack pstack1;
	pstack1 = createStack(element);
	for (int i = 0; i < element; i++)
	{
		scanf("%d", &stack_val);
		push(stack_val, pstack1);
	}
	
	/*push(10, pstack1);
	push(23, pstack1);
	push(3, pstack1);
	push(4, pstack1);
	push(5, pstack1);
	push(61, pstack1);
	push(17, pstack1);
	push(53, pstack1);
	push(6, pstack1);
	push(71, pstack1);
	pop(pstack1);
	pop(pstack1);
	pop(pstack1);
	push(1, pstack1);
	printf("Hello, World!\n");*/
	
	printf("\nThis is results of stack.\n");
	for (int i = 0; i < element; i++)
	{
		printf("| %d |\n", pstack1 -> array[i]);
	}
	printf("Top of stack is : %d\n", topOfStack(pstack1));
	printf("Size of stack is : %d\n", sizeOfStack(pstack1));
	printf("Space of stack is : %d\n", spaceOfStack(pstack1));
	printf("----- Menu -----\n");
	printf("1.Pop\n");
	printf("Please select number of menu : ");
	scanf("%d", &menu_number);
	switch(menu_number)
	{
		case 1: printf("You seleted menu 1.Pop\n");
		printf("Please select number of pop : ");
		scanf("%d", &pop_number);
		for (int i = 0; i < pop_number; i++)
		{
			pop(pstack1);
		}
		printf("Please enter number for push : ");
		scanf("%d", &push_number);
		push(push_number, pstack1);
		printf("\nThis is results of stack after pop.\n");
	    for (int i = 0; i < element; i++)
	    {
		    printf("| %d |\n", pstack1 -> array[i]);
	    }
	    printf("Top of stack after pop is : %d\n", topOfStack(pstack1));
	    printf("Size of stack after pop is : %d\n", sizeOfStack(pstack1));
	    printf("Space of stack after pop is : %d\n", spaceOfStack(pstack1));
		break;
		
		default: printf("Wrong choice!");
		break;
	}
	return 0;
}
